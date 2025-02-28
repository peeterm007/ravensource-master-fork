--- hw/xfree86/os-support/bsd/bsd_init.c.orig	2022-12-19 10:53:03 UTC
+++ hw/xfree86/os-support/bsd/bsd_init.c
@@ -230,6 +230,9 @@ xf86OpenConsole()
              * Add cases for other *BSD that behave the same.
              */
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__sparc64__)
+	    pci_system_init_dev_mem(fd);
+#endif
             uname(&uts);
             i = atof(uts.release) * 100;
             if (i >= 310)
