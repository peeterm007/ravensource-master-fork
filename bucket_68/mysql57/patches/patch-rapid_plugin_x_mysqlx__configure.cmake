--- rapid/plugin/x/mysqlx_configure.cmake.orig	2019-06-10 14:43:20 UTC
+++ rapid/plugin/x/mysqlx_configure.cmake
@@ -35,6 +35,7 @@ CONFIGURE_FILE(${MYSQLX_PROJECT_DIR}/src
 CONFIGURE_FILE(${MYSQLX_PROJECT_DIR}/src/mysqlx_version.h.in
                ${CMAKE_CURRENT_BINARY_DIR}/generated/mysqlx_version.h )
 
+IF(FALSE)
 INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/generated/mysqlx_error.h
         DESTINATION ${INSTALL_INCLUDEDIR}
         COMPONENT Developement)
@@ -46,3 +47,4 @@ INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR
 INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/generated/mysqlx_version.h
         DESTINATION ${INSTALL_INCLUDEDIR}
         COMPONENT Developement)
+ENDIF()
