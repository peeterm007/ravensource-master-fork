https://git.gnupg.org/cgi-bin/gitweb.cgi?p=gnupg.git;a=commitdiff;h=7011286ce6e1fb56c2989fdafbd11b931c489faa

From 7011286ce6e1fb56c2989fdafbd11b931c489faa Mon Sep 17 00:00:00 2001
From: NIIBE Yutaka <gniibe@fsij.org>
Date: Fri, 14 Oct 2022 09:58:41 +0900
Subject: [PATCH] dirmngr: Fix build with no LDAP support.

* dirmngr/server.c [USE_LDAP] (start_command_handler): Conditionalize.

--

GnuPG-bug-id: 6239
Signed-off-by: NIIBE Yutaka <gniibe@fsij.org>
---
 dirmngr/server.c | 2 ++
 1 file changed, 2 insertions(+)

--- dirmngr/server.c.orig
+++ dirmngr/server.c
@@ -3137,8 +3137,10 @@ start_command_handler (assuan_fd_t fd, unsigned int session_id)
                ctrl->refcount);
   else
     {
+#if USE_LDAP
       ks_ldap_free_state (ctrl->ks_get_state);
       ctrl->ks_get_state = NULL;
+#endif
       release_ctrl_ocsp_certs (ctrl);
       xfree (ctrl->server_local);
       dirmngr_deinit_default_ctrl (ctrl);
-- 
2.11.0


