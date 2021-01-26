--- deps/v8/src/trap-handler/trap-handler.h.orig	2021-01-25 23:04:45 UTC
+++ deps/v8/src/trap-handler/trap-handler.h
@@ -25,6 +25,8 @@ namespace trap_handler {
 #define V8_TRAP_HANDLER_SUPPORTED true
 #elif V8_TARGET_ARCH_X64 && V8_OS_FREEBSD
 #define V8_TRAP_HANDLER_SUPPORTED true
+#elif V8_TARGET_ARCH_X64 && V8_OS_DRAGONFLYBSD
+#define V8_TRAP_HANDLER_SUPPORTED true
 #else
 #define V8_TRAP_HANDLER_SUPPORTED false
 #endif
