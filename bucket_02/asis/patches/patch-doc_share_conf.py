--- doc/share/conf.py.orig	2020-02-29 15:19:01 UTC
+++ doc/share/conf.py
@@ -39,18 +39,18 @@ def get_gnat_version():
             line = (vinfo.readline()).strip()
             return line
     except Exception:
-        print 'Error opening or reading version_information file'
+        print ('Error opening or reading version_information file')
         sys.exit(1)
 
 
 # First retrieve the name of the documentation we are building
 doc_name = os.environ.get('DOC_NAME', None)
 if doc_name is None:
-    print 'DOC_NAME environment variable should be set'
+    print ('DOC_NAME environment variable should be set')
     sys.exit(1)
 
 if doc_name not in DOCS:
-    print '%s is not a valid documentation name' % doc_name
+    print ('%s is not a valid documentation name' % doc_name)
     sys.exit(1)
 
 
@@ -59,7 +59,7 @@ exclude_patterns = []
 for d in os.listdir(root_source_dir):
     if d not in ('share', doc_name, doc_name + '.rst'):
         exclude_patterns.append(d)
-        print 'ignoring %s' % d
+        print ('ignoring %s' % d)
 
 extensions = []
 templates_path = ['_templates']
@@ -101,5 +101,5 @@ texinfo_documents = [
 
 
 def setup(app):
-    app.add_lexer('ada', ada_pygments.AdaLexer())
-    app.add_lexer('gpr', ada_pygments.GNATProjectLexer())
+    app.add_lexer('ada', ada_pygments.AdaLexer)
+    app.add_lexer('gpr', ada_pygments.GNATProjectLexer)
