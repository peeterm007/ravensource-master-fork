--- sql/mysqld.cc.orig	2022-11-02 12:37:20 UTC
+++ sql/mysqld.cc
@@ -4466,8 +4466,9 @@ static void init_ssl()
         sql_print_warning("SSL error: %s",buf);
       }
     }
-    else
+    else {
       ERR_remove_state(0);
+    }
   }
   else
   {
