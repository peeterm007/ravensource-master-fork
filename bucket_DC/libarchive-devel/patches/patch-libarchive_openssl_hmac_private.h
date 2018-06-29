--- libarchive/archive_openssl_hmac_private.h.orig	2017-10-01 00:17:22 UTC
+++ libarchive/archive_openssl_hmac_private.h
@@ -28,7 +28,8 @@
 #include <openssl/hmac.h>
 #include <openssl/opensslv.h>
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || \
+    (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x2070000fL)
 #include <stdlib.h> /* malloc, free */
 #include <string.h> /* memset */
 static inline HMAC_CTX *HMAC_CTX_new(void)
