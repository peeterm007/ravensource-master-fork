--- tools/install.py.orig	2021-09-22 18:38:24 UTC
+++ tools/install.py
@@ -156,7 +156,7 @@ def files(action):
   action(['deps/v8/tools/gdbinit'], 'share/doc/node/')
   action(['deps/v8/tools/lldb_commands.py'], 'share/doc/node/')
 
-  if 'freebsd' in sys.platform or 'openbsd' in sys.platform:
+  if 'skipme' in sys.platform:
     action(['doc/node.1'], 'man/man1/')
   else:
     action(['doc/node.1'], 'share/man/man1/')
