--- include/SDL_endian.h.orig	2022-11-01 12:47:12 UTC
+++ include/SDL_endian.h
@@ -59,10 +59,10 @@ _m_prefetch(void *__P)
 #ifdef __linux__
 #include <endian.h>
 #define SDL_BYTEORDER  __BYTE_ORDER
-#elif defined(__OpenBSD__) || defined(__DragonFly__)
+#elif defined(__OpenBSD__)
 #include <endian.h>
 #define SDL_BYTEORDER  BYTE_ORDER
-#elif defined(__FreeBSD__) || defined(__NetBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 #include <sys/endian.h>
 #define SDL_BYTEORDER  BYTE_ORDER
 /* predefs from newer gcc and clang versions: */
