--- toolkit/components/protobuf/src/google/protobuf/stubs/port.h.orig	2022-09-22 18:17:47 UTC
+++ toolkit/components/protobuf/src/google/protobuf/stubs/port.h
@@ -59,7 +59,7 @@
 #else
 #ifdef __APPLE__
 #include <machine/endian.h>  // __BYTE_ORDER
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/endian.h>  // __BYTE_ORDER
 #elif (defined(sun) || defined(__sun)) && (defined(__SVR4) || defined(__svr4__))
 #include <sys/isa_defs.h>  // __BYTE_ORDER
