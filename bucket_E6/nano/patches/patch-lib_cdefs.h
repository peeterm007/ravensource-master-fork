--- lib/cdefs.h.orig	2021-02-24 10:02:11 UTC
+++ lib/cdefs.h
@@ -329,7 +329,7 @@
 # endif
 #elif !defined __GLIBC__
 # undef __nonnull
-# define __nonnull(params) _GL_ATTRIBUTE_NONNULL (params)
+# define __nonnull(...)
 #endif
 
 /* If fortification mode, we warn about unused results of certain
