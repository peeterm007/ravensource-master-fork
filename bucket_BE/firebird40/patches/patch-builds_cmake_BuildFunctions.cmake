--- builds/cmake/BuildFunctions.cmake.orig	2022-08-10 09:04:28 UTC
+++ builds/cmake/BuildFunctions.cmake
@@ -73,7 +73,7 @@ if (UNIX)
             if (APPLE)
                 set(wl_option "-exported_symbols_list")
             endif()
-            set_target_properties(${target} PROPERTIES LINK_FLAGS -Wl,${wl_option},${CMAKE_BINARY_DIR}/builds/posix/${def_file})
+            #set_target_properties(${target} PROPERTIES LINK_FLAGS -Wl,${wl_option},${CMAKE_BINARY_DIR}/builds/posix/${def_file})
         endif()
     endfunction(set_exported_symbols)
 endif(UNIX)
@@ -289,7 +289,7 @@ function(create_command command type out
     set(cmd_name ${cmd_name}${conf}${ext})
     set(cmd_name ${CMAKE_BINARY_DIR}/src/${cmd_name})
     
-    set(content)
+    set(content "#!/bin/sh\n")
     foreach(e ${env})
         set(content "${content}${pre_cmd}${export} ${e}\n")
     endforeach()
