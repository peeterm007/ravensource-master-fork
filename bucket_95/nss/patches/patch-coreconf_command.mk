--- coreconf/command.mk.orig	2020-05-01 21:08:55 UTC
+++ coreconf/command.mk
@@ -12,7 +12,7 @@ AS            = $(CC)
 ASFLAGS      += $(CFLAGS)
 CCF           = $(CC) $(CFLAGS)
 LINK_DLL      = $(LD) $(OS_DLLFLAGS) $(DLLFLAGS) $(XLDFLAGS)
-CFLAGS        = $(OPTIMIZER) $(OS_CFLAGS) $(WARNING_CFLAGS) $(XP_DEFINE) \
+CFLAGS       += $(OPTIMIZER) $(OS_CFLAGS) $(WARNING_CFLAGS) $(XP_DEFINE) \
                 $(DEFINES) $(INCLUDES) $(XCFLAGS)
 CSTD          = -std=c99
 CXXSTD        = -std=c++11
