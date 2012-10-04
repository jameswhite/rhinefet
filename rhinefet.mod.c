#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x514d6c8f, "module_layout" },
	{ 0x14214dc8, "kmalloc_caches" },
	{ 0x220ae547, "pci_bus_read_config_byte" },
	{ 0x12da5bb2, "__kmalloc" },
	{ 0xa23288f5, "mem_map" },
	{ 0x6980fe91, "param_get_int" },
	{ 0xd0d8621b, "strlen" },
	{ 0x199885b9, "dev_set_drvdata" },
	{ 0x3e45e9ff, "register_inetaddr_notifier" },
	{ 0x45259e07, "dma_set_mask" },
	{ 0x705a9cda, "pci_disable_device" },
	{ 0x9186fe0f, "netif_carrier_on" },
	{ 0x43ab66c3, "param_array_get" },
	{ 0x4aabc7c4, "__tracepoint_kmalloc" },
	{ 0x48a2059c, "netif_carrier_off" },
	{ 0x1f046546, "remove_proc_entry" },
	{ 0xd73eb854, "x86_dma_fallback_dev" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x53ee0708, "pci_release_regions" },
	{ 0xff964b25, "param_set_int" },
	{ 0x3c2c5af5, "sprintf" },
	{ 0x45947727, "param_array_set" },
	{ 0xb1d71d34, "pci_dev_driver" },
	{ 0x7d11c268, "jiffies" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xf83a74f7, "netif_rx" },
	{ 0xa30442aa, "pci_set_master" },
	{ 0x1d0e8be2, "alloc_etherdev_mq" },
	{ 0x3628f5f7, "dev_alloc_skb" },
	{ 0xee3a8f15, "kmem_cache_alloc_notrace" },
	{ 0xd390e9df, "pci_restore_state" },
	{ 0x88941a06, "_raw_spin_unlock_irqrestore" },
	{ 0xb72397d5, "printk" },
	{ 0xf609aa30, "_raw_spin_trylock" },
	{ 0x5152e605, "memcmp" },
	{ 0x8731977f, "free_netdev" },
	{ 0x89ff38c, "register_netdev" },
	{ 0x16305289, "warn_slowpath_null" },
	{ 0x40f378e7, "pci_bus_write_config_dword" },
	{ 0x36750341, "__pci_enable_wake" },
	{ 0x9e9d6286, "dma_release_from_coherent" },
	{ 0x859c6dc7, "request_threaded_irq" },
	{ 0x401629e8, "init_net" },
	{ 0x93a40856, "dma_alloc_from_coherent" },
	{ 0x3980aac1, "unregister_reboot_notifier" },
	{ 0x17e2b60c, "dev_kfree_skb_irq" },
	{ 0x7dceceac, "capable" },
	{ 0x8ff4079b, "pv_irq_ops" },
	{ 0x3af98f9e, "ioremap_nocache" },
	{ 0x760b437a, "unregister_inetaddr_notifier" },
	{ 0x8465680f, "pci_bus_read_config_word" },
	{ 0x1cc6719a, "register_reboot_notifier" },
	{ 0xd62c7d75, "pci_bus_read_config_dword" },
	{ 0xf333a2fb, "_raw_spin_lock_irq" },
	{ 0x3368c094, "eth_type_trans" },
	{ 0xc3dd8ada, "create_proc_entry" },
	{ 0x40b9e95d, "pci_unregister_driver" },
	{ 0x587c70d8, "_raw_spin_lock_irqsave" },
	{ 0x42b3b201, "pci_set_power_state" },
	{ 0xf74b5cd2, "pci_bus_write_config_byte" },
	{ 0x37a0cba, "kfree" },
	{ 0x122ea57c, "pci_request_regions" },
	{ 0xedc03953, "iounmap" },
	{ 0x8da249fa, "__pci_register_driver" },
	{ 0xa4ebb18a, "pci_get_device" },
	{ 0x78e0d029, "unregister_netdev" },
	{ 0x2304d853, "pci_choose_state" },
	{ 0xe1eb1d40, "__netif_schedule" },
	{ 0x480cdf25, "consume_skb" },
	{ 0x5cd09174, "skb_put" },
	{ 0xe167ef60, "pci_enable_device" },
	{ 0xf3c163ad, "dev_get_drvdata" },
	{ 0x4cff7b82, "dma_ops" },
	{ 0xf20dabd8, "free_irq" },
	{ 0xa8697f3e, "pci_save_state" },
	{ 0xe914e41e, "strcpy" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("pci:v00001106d00003043sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d00003065sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d00003106sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d00003053sv*sd*bc*sc*i*");
