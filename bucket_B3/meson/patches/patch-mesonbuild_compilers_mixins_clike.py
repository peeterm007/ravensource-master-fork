--- mesonbuild/compilers/mixins/clike.py.orig	2021-08-18 11:22:33 UTC
+++ mesonbuild/compilers/mixins/clike.py
@@ -83,7 +83,7 @@ class CLikeCompilerArgs(arglist.Compiler
         # This covers all ld.bfd, ld.gold, ld.gold, and xild on Linux, which
         # all act like (or are) gnu ld
         # TODO: this could probably be added to the DynamicLinker instead
-        if isinstance(self.compiler.linker, (GnuLikeDynamicLinkerMixin, SolarisDynamicLinker, CompCertDynamicLinker)):
+        if isinstance(self.compiler.linker, (GnuLikeDynamicLinkerMixin, CompCertDynamicLinker)):
             group_start = -1
             group_end = -1
             for i, each in enumerate(new):
