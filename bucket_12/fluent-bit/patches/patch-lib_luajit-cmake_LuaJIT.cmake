--- lib/luajit-cmake/LuaJIT.cmake.orig	2022-11-22 14:33:00 UTC
+++ lib/luajit-cmake/LuaJIT.cmake
@@ -329,6 +329,8 @@ elseif(${CMAKE_SYSTEM_NAME} STREQUAL Hai
   set(TARGET_OS_FLAGS ${TARGET_OS_FLAGS} -DLUAJIT_OS=LUAJIT_OS_POSIX)
 elseif(${CMAKE_SYSTEM_NAME} MATCHES "(Open|Free|Net)BSD")
   set(TARGET_OS_FLAGS ${TARGET_OS_FLAGS} -DLUAJIT_OS=LUAJIT_OS_BSD)
+elseif(${CMAKE_SYSTEM_NAME} MATCHES "DragonFly")
+  set(TARGET_OS_FLAGS ${TARGET_OS_FLAGS} -DLUAJIT_OS=LUAJIT_OS_BSD)
 elseif(${CMAKE_SYSTEM_NAME} STREQUAL iOS)
   set(TARGET_OS_FLAGS ${TARGET_OS_FLAGS} -DLUAJIT_OS=LUAJIT_OS_OSX -DTARGET_OS_IPHONE=1)
 else()
