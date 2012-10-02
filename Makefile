DEBUG = 0

KSP :=  /lib/modules/$(shell uname -r)/build \
	/usr/src/linux-$(shell uname -r) \
	/usr/src/linux-$(shell uname -r | sed 's/-.*//') \
	/usr/src/kernel-headers-$(shell uname -r) \
	/usr/src/kernel-source-$(shell uname -r) \
	/usr/src/linux-$(shell uname -r | sed 's/\([0-9]*\.[0-9]*\)\..*/\1/') \
	/usr/src/linux

test_dir = $(shell [ -e $(dir)/include/linux ] && echo $(dir))
KSP := $(foreach dir, $(KSP), $(test_dir))

KSRC := $(firstword $(KSP))
ifeq (,$(KSRC))
  $(error Linux kernel source not found)
endif

# check kernel version
KVER := $(shell uname -r | cut -c1-3 | sed 's/2\.[56]/2\.6/')
KERVER2=$(shell uname -r | cut -d. -f2)

ifeq ($(KVER), 2.6)
  # 2.6 kernel
  TARGET = rhinefet.ko
  BUILTIN = via-rhine.ko
else
  TARGET = rhinefet.o
  BUILTIN = via-rhine.o
endif

INSTDIR := $(shell find /lib/modules/$(shell uname -r) -name $(TARGET) -printf "%h\n" | sort | head -1)
ifeq (,$(INSTDIR))
        ifeq (,$(KERVER2))
                ifneq (,$(wildcard /lib/modules/$(shell uname -r)/kernel))
                        INSTDIR := /lib/modules/$(shell uname -r)/kernel/drivers/net
                else
                        INSTDIR := /lib/modules/$(shell uname -r)/net
                endif
        else
                ifneq ($(KERVER2),2)
                        INSTDIR := /lib/modules/$(shell uname -r)/kernel/drivers/net
                else
                        INSTDIR := /lib/modules/$(shell uname -r)/net
                endif
        endif
endif

SRC = rhine_main.c rhine_proc.c rhine_wol.c rhine_hw.c

# build rule
ifeq ($(KVER), 2.6)
# 2.6 kernel

obj-m += rhinefet.o
rhinefet-objs := rhine_main.o rhine_proc.o rhine_wol.o rhine_hw.o

default:
	make -C $(KSRC) SUBDIRS=$(shell pwd) modules

else
# 2.2/2.4 kernel

OBJS := rhine_main.o rhine_proc.o rhine_wol.o rhine_hw.o

VERSION_FILE := $(KSRC)/include/linux/version.h
CONFIG_FILE  := $(KSRC)/include/linux/config.h

ifeq (,$(wildcard $(VERSION_FILE)))
  $(error Linux kernel source not configured - missing version.h)
endif

ifeq (,$(wildcard $(CONFIG_FILE)))
  $(error Linux kernel source not configured - missing config.h)
endif

ifneq (,$(findstring egcs-2.91.66, $(shell cat /proc/version)))
  CC := kgcc gcc cc
else
  CC := gcc cc
endif

test_cc = $(shell which $(cc) > /dev/null 2>&1 && echo $(cc))
CC := $(foreach cc, $(CC), $(test_cc))
CC := $(firstword $(CC))

CFLAGS += -Wall -DLINUX -D__KERNEL__ -DMODULE -DEXPORT_SYMTAB -D__NO_VERSION__ -O2 -pipe
CFLAGS += -I$(KSRC)/include -I. -Wstrict-prototypes -fomit-frame-pointer
CFLAGS += $(shell [ -f $(KSRC)/include/linux/modversions.h ] && \
            echo "-DMODVERSIONS -include $(KSRC)/include/linux/modversions.h")

.SILENT: $(TARGET) clean

# look for SMP in config.h
SMP := $(shell $(CC) $(CFLAGS) -E -dM $(CONFIG_FILE) | \
	grep CONFIG_SMP | awk '{ print $$3 }')

ifneq ($(SMP),1)
  SMP := 0
endif

ifeq ($(DEBUG),1)
  CFLAGS += -DRHINE_DBG
endif

ifeq ($(SMP), 1)
  CFLAGS += -D__SMP__
endif

# check x86_64
SUBARCH := $(shell uname -m)
ifeq ($(SUBARCH),x86_64)
  CFLAGS += -mcmodel=kernel -mno-red-zone
endif

$(TARGET): $(filter-out $(TARGET), $(SRC:.c=.o))
	$(LD) -r $^ -o $@
	echo; echo
	echo "**************************************************"
	echo "Build options:"
	echo "   VERSION    $(shell uname -r)"
	echo -n "   SMP        "
	if [ "$(SMP)" = "1" ]; \
		then echo "Enabled"; else echo "Disabled"; fi
	echo "**************************************************"

endif # ifeq ($(KVER),2.6)

ifeq ($(KVER), 2.6)
  install: default
else
  install: clean $(TARGET)
endif
	mkdir -p $(MOD_ROOT)$(INSTDIR)
	install -m 644 -o root $(TARGET) $(MOD_ROOT)$(INSTDIR)
	@if [ -f $(MOD_ROOT)$(INSTDIR)/$(BUILTIN) ] ; then \
		echo "*****  Move official driver $(BUILTIN) to $(BUILTIN).backup file" ; \
		echo "mv $(MOD_ROOT)$(INSTDIR)/$(BUILTIN) $(MOD_ROOT)$(INSTDIR)/$(BUILTIN).backup";\
		mv $(MOD_ROOT)$(INSTDIR)/$(BUILTIN) $(MOD_ROOT)$(INSTDIR)/$(BUILTIN).backup ; \
		echo ;\
	fi ;
	@if [ -f $(MOD_ROOT)$(INSTDIR)/linuxfet.o ] ; then \
		echo "*****  Move previous driver linuxfet.o to linuxfet.o.backup" ; \
		echo "mv $(MOD_ROOT)$(INSTDIR)/linuxfet.o $(MOD_ROOT)$(INSTDIR)/linuxfet.o.backup";\
		mv $(MOD_ROOT)$(INSTDIR)/linuxfet.o $(MOD_ROOT)$(INSTDIR)/linuxfet.o.backup ; \
		echo ;\
	fi ;

ifeq (,$(MOD_ROOT))
	/sbin/depmod -a || true
else
	/sbin/depmod -b $(MOD_ROOT) -a || true
endif

uninstall:
	rm -f $(INSTDIR)/$(TARGET)
	@if [ -f $(MOD_ROOT)$(INSTDIR)/$(BUILTIN).backup ] ; then \
		echo "*****  Restore official driver $(BUILTIN) from $(MOD_ROOT)$(INSTDIR)".; \
		echo "mv $(MOD_ROOT)$(INSTDIR)/$(BUILTIN).backup $(MOD_ROOT)$(INSTDIR)/$(BUILTIN)";\
		mv $(MOD_ROOT)$(INSTDIR)/$(BUILTIN).backup $(MOD_ROOT)$(INSTDIR)/$(BUILTIN) ;\
	fi
	/sbin/depmod -a

clean:
	rm -f $(SRC:.c=.o) rhinefet.o rhinefet.ko rhinefet.mod.c rhinefet.mod.o *~
