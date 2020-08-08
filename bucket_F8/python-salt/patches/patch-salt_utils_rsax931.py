--- salt/utils/rsax931.py.orig	2020-08-07 19:14:59 UTC
+++ salt/utils/rsax931.py
@@ -62,7 +62,8 @@ def _find_libcrypto():
                 # This could be /opt/tools/lib (Global Zone) or
                 # /opt/local/lib (non-Global Zone), thus the two checks
                 # below
-                lib = glob.glob("/opt/local/lib/libcrypto.so*")
+                lib = glob.glob('__PREFIX__/lib/libcrypto.so*')
+                lib = lib or glob.glob("/opt/local/lib/libcrypto.so*")
                 lib = lib or glob.glob("/opt/tools/lib/libcrypto.so*")
                 lib = lib[0] if lib else None
             elif salt.utils.platform.is_aix():
