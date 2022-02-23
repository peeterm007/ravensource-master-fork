--- deps/v8/src/base/utils/random-number-generator.cc.orig	2022-02-10 04:59:26 UTC
+++ deps/v8/src/base/utils/random-number-generator.cc
@@ -55,7 +55,7 @@ RandomNumberGenerator::RandomNumberGener
   result = rand_s(&second_half);
   DCHECK_EQ(0, result);
   SetSeed((static_cast<int64_t>(first_half) << 32) + second_half);
-#elif V8_OS_MACOSX || V8_OS_FREEBSD || V8_OS_OPENBSD
+#elif V8_OS_MACOSX || V8_OS_FREEBSD || V8_OS_OPENBSD || V8_OS_DRAGONFLYBSD
   // Despite its prefix suggests it is not RC4 algorithm anymore.
   // It always succeeds while having decent performance and
   // no file descriptor involved.
