--- cmake/install_layout.cmake.orig	2021-04-23 15:06:40 UTC
+++ cmake/install_layout.cmake
@@ -375,19 +375,15 @@ SET(ROUTER_INSTALL_LOGDIR_STANDALONE
 SET(ROUTER_INSTALL_RUNTIMEDIR_STANDALONE "run")
 
 SET(ROUTER_INSTALL_BINDIR_STANDALONE      "bin")
-IF(LINUX)
-  SET(ROUTER_INSTALL_LIBDIR_STANDALONE    "lib/mysqlrouter/private")
-ELSE()
   SET(ROUTER_INSTALL_LIBDIR_STANDALONE    "lib")
-ENDIF()
 IF(WIN32)
   SET(ROUTER_INSTALL_PLUGINDIR_STANDALONE "lib")
 ELSE()
   SET(ROUTER_INSTALL_PLUGINDIR_STANDALONE "lib/mysqlrouter")
 ENDIF()
-SET(ROUTER_INSTALL_LOGROTATEDIR_STANDALONE  ".")
+SET(ROUTER_INSTALL_LOGROTATEDIR_STANDALONE  "etc/logrotate.d")
 SET(ROUTER_INSTALL_LOGROTATEFILE_STANDALONE "mysqlrouter-log-rotate")
-SET(ROUTER_INSTALL_DOCDIR_STANDALONE "docs")
+SET(ROUTER_INSTALL_DOCDIR_STANDALONE "share/doc/mysql")
 
 #
 # TARGZ layout
