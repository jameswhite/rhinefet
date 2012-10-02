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
	{ 0xec5ba0f9, "module_layout" },
	{ 0x28849590, "kmalloc_caches" },
	{ 0xd3298867, "pci_bus_read_config_byte" },
	{ 0x12da5bb2, "__kmalloc" },
	{ 0x7ee91c1d, "_spin_trylock" },
	{ 0x1cdc15e7, "mem_map" },
	{ 0xb279da12, "pv_lock_ops" },
	{ 0x6980fe91, "param_get_int" },
	{ 0xd0d8621b, "strlen" },
	{ 0x3e45e9ff, "register_inetaddr_notifier" },
	{ 0xe6985f63, "pci_disable_device" },
	{ 0x9356c08f, "netif_carrier_on" },
	{ 0x43ab66c3, "param_array_get" },
	{ 0x4661e311, "__tracepoint_kmalloc" },
	{ 0x52d18aae, "netif_carrier_off" },
	{ 0x3eb0c046, "remove_proc_entry" },
	{ 0xdfb6e4ed, "x86_dma_fallback_dev" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x9a23873c, "pci_release_regions" },
	{ 0xad9d8f3b, "pci_enable_wake" },
	{ 0xff964b25, "param_set_int" },
	{ 0x712aa29b, "_spin_lock_irqsave" },
	{ 0x3c2c5af5, "sprintf" },
	{ 0x45947727, "param_array_set" },
	{ 0x2848f594, "pci_dev_driver" },
	{ 0x7d11c268, "jiffies" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x1824e91f, "netif_rx" },
	{ 0xca197dc3, "pci_set_master" },
	{ 0xef3da6b, "alloc_etherdev_mq" },
	{ 0x192d1ac4, "pci_set_dma_mask" },
	{ 0xc02c0d91, "dev_alloc_skb" },
	{ 0xd6656a9e, "pci_restore_state" },
	{ 0xb72397d5, "printk" },
	{ 0xecde1418, "_spin_lock_irq" },
	{ 0xaceb62ef, "free_netdev" },
	{ 0xc621098f, "register_netdev" },
	{ 0x16305289, "warn_slowpath_null" },
	{ 0xa55b2eeb, "pci_bus_write_config_dword" },
	{ 0x4b07e779, "_spin_unlock_irqrestore" },
	{ 0x29625e53, "dma_release_from_coherent" },
	{ 0xfda85a7d, "request_threaded_irq" },
	{ 0xd1d548fb, "init_net" },
	{ 0x3b820abe, "dma_alloc_from_coherent" },
	{ 0x3980aac1, "unregister_reboot_notifier" },
	{ 0xdc96f6c7, "dev_kfree_skb_irq" },
	{ 0x7dceceac, "capable" },
	{ 0x142c23f8, "kmem_cache_alloc" },
	{ 0xc946787f, "pv_irq_ops" },
	{ 0x3af98f9e, "ioremap_nocache" },
	{ 0x760b437a, "unregister_inetaddr_notifier" },
	{ 0xf081d065, "pci_bus_read_config_word" },
	{ 0x1cc6719a, "register_reboot_notifier" },
	{ 0x7d40de6f, "pci_bus_read_config_dword" },
	{ 0x419c0352, "eth_type_trans" },
	{ 0x63d72664, "create_proc_entry" },
	{ 0xa415cf1e, "pci_unregister_driver" },
	{ 0xb797a7e3, "pci_set_power_state" },
	{ 0x7c1da31b, "pci_bus_write_config_byte" },
	{ 0x37a0cba, "kfree" },
	{ 0xd37787f8, "pci_request_regions" },
	{ 0xedc03953, "iounmap" },
	{ 0x5e99d379, "__pci_register_driver" },
	{ 0x7e25398, "pci_get_device" },
	{ 0x9e62cc2a, "unregister_netdev" },
	{ 0xf968860e, "pci_choose_state" },
	{ 0x7394b9f4, "__netif_schedule" },
	{ 0xb3097ef5, "consume_skb" },
	{ 0x53349499, "skb_put" },
	{ 0xd746da45, "pci_enable_device" },
	{ 0xabf94579, "dma_ops" },
	{ 0xf20dabd8, "free_irq" },
	{ 0xf4c0cfcc, "pci_save_state" },
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

MODULE_INFO(srcversion, "35852AA24ECD31EBF0FC796");
