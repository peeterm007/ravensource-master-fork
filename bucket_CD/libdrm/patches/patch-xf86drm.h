--- xf86drm.h.orig	2021-11-08 16:35:03 UTC
+++ xf86drm.h
@@ -59,6 +59,9 @@ extern "C" {
 #else /* One of the *BSDs */
 
 #include <sys/ioccom.h>
+#ifdef __sun__
+#define _IOC(inout,group,num,len)	(inout | ((len & IOCPARM_MASK) << 16) | ((group) << 8) | (num))
+#endif
 #define DRM_IOCTL_NR(n)         ((n) & 0xff)
 #define DRM_IOC_VOID            IOC_VOID
 #define DRM_IOC_READ            IOC_OUT
