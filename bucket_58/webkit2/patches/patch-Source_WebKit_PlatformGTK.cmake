--- Source/WebKit/PlatformGTK.cmake.orig	2022-09-14 11:58:10 UTC
+++ Source/WebKit/PlatformGTK.cmake
@@ -42,7 +42,7 @@ add_definitions(-DLOCALEDIR="${CMAKE_INS
 add_definitions(-DDATADIR="${CMAKE_INSTALL_FULL_DATADIR}")
 add_definitions(-DLIBDIR="${LIB_INSTALL_DIR}")
 
-if (NOT DEVELOPER_MODE AND NOT CMAKE_SYSTEM_NAME MATCHES "Darwin")
+if (NOT DEVELOPER_MODE AND NOT CMAKE_SYSTEM_NAME MATCHES "Darwin|SunOS")
     WEBKIT_ADD_TARGET_PROPERTIES(WebKit LINK_FLAGS "-Wl,--version-script,${CMAKE_CURRENT_SOURCE_DIR}/webkitglib-symbols.map")
 endif ()
 
