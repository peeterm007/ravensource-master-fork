--- include/drm/drm.h.orig	2019-10-16 21:36:48 UTC
+++ include/drm/drm.h
@@ -699,7 +699,11 @@ struct drm_set_client_cap {
 };
 
 #define DRM_RDWR O_RDWR
+#ifdef __sun__
+#define DRM_CLOEXEC 0
+#else
 #define DRM_CLOEXEC O_CLOEXEC
+#endif
 struct drm_prime_handle {
 	__u32 handle;
 
