--- plugin/password_validation/validate_password.cc.orig	2018-09-10 10:17:55 UTC
+++ plugin/password_validation/validate_password.cc
@@ -16,6 +16,8 @@
 #include <my_sys.h>
 #include <string>
 #include <mysql/plugin_validate_password.h>
+/* solve clash between libc++ bitset::test() and test macro from my_global.h */
+#undef test
 #include <set>
 #include <ios>       // std::streamoff
 #include <iostream>
