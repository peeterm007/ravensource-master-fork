--- cmake/QtRpathHelpers.cmake.orig	2022-11-16 07:54:24 UTC
+++ cmake/QtRpathHelpers.cmake
@@ -5,6 +5,8 @@ function(qt_internal_get_relative_rpath_
         set(rpath_rel_base "@loader_path")
     elseif(LINUX OR SOLARIS OR FREEBSD OR HURD)
         set(rpath_rel_base "$ORIGIN")
+    elseif(CMAKE_SYSTEM_NAME MATCHES "FreeBSD|DragonFly")
+        set(rpath_rel_base "$ORIGIN")
     else()
         set(rpath_rel_base "NO_KNOWN_RPATH_REL_BASE")
     endif()
