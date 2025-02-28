--- dao/ScsiIf-netbsd.cc.orig	2018-05-15 13:30:52 UTC
+++ dao/ScsiIf-netbsd.cc
@@ -22,9 +22,7 @@
 #include <unistd.h>
 
 #include "ScsiIf.h"
-
-/* can't include trackdb/util.h */
-extern void message(int level, const char *fmt, ...);
+#include "log.h"
 
 #include "decodeSense.cc"
 
@@ -91,7 +89,7 @@ int ScsiIf::init()
 {
 	if (impl_->name_ == NULL) return 1;
 	if ((impl_->fd_ = open(impl_->name_, O_RDWR, 0)) < 0) {
-		message(-2, "init: %s", strerror(errno));
+		log_message(-2, "init: %s", strerror(errno));
 		return 1;
 	}
 	if (inquiry()) return 2;
@@ -193,29 +191,29 @@ void ScsiIf::printError()
 		p += snprintf(p, s + sizeof(s) - p, ", BUF=%p", impl_->screq_.databuf);
 		p += snprintf(p, s + sizeof(s) - p, ", LEN=%lu", impl_->screq_.datalen);
 		p += snprintf(p, s + sizeof(s) - p, ", TO=%lu", impl_->screq_.timeout);
-		message(-2, s);
+		log_message(-2, s);
 	}
 	if (impl_->error_ != NULL) {
-		message(-2, impl_->error_);
+		log_message(-2, impl_->error_);
 	} else switch (impl_->screq_.retsts) {
 		case SCCMD_OK: switch (impl_->screq_.status) {
-			case 0x00: message(-2, "GOOD"); break;
-			case 0x02: message(-2, "CHECK CONDITION"); break;
-			case 0x04: message(-2, "CONDITION MET"); break;
-			case 0x08: message(-2, "BUSY"); break;
-			case 0x10: message(-2, "INTERMEDIATE"); break;
-			case 0x14: message(-2, "INTERMEDIATE, CONDITION MET"); break;
-			case 0x18: message(-2, "RESERVATION CONFLICT"); break;
-			case 0x22: message(-2, "COMMAND TERMINATED"); break;
-			case 0x28: message(-2, "QUEUE FULL"); break;
-			default: message(-2, "undefined status");
+			case 0x00: log_message(-2, "GOOD"); break;
+			case 0x02: log_message(-2, "CHECK CONDITION"); break;
+			case 0x04: log_message(-2, "CONDITION MET"); break;
+			case 0x08: log_message(-2, "BUSY"); break;
+			case 0x10: log_message(-2, "INTERMEDIATE"); break;
+			case 0x14: log_message(-2, "INTERMEDIATE, CONDITION MET"); break;
+			case 0x18: log_message(-2, "RESERVATION CONFLICT"); break;
+			case 0x22: log_message(-2, "COMMAND TERMINATED"); break;
+			case 0x28: log_message(-2, "QUEUE FULL"); break;
+			default: log_message(-2, "undefined status");
 		} break;
-		case SCCMD_TIMEOUT: message(-2, "timeout"); break;
-		case SCCMD_BUSY: message(-2, "busy"); break;
+		case SCCMD_TIMEOUT: log_message(-2, "timeout"); break;
+		case SCCMD_BUSY: log_message(-2, "busy"); break;
 		case SCCMD_SENSE: decodeSense(impl_->screq_.sense,
 		                              impl_->screq_.senselen_used); break;
-		case SCCMD_UNKNOWN: message(-2, "unknown error"); break;
-		default: message(-2, "undefined retsts"); break;
+		case SCCMD_UNKNOWN: log_message(-2, "unknown error"); break;
+		default: log_message(-2, "undefined retsts"); break;
 	}
 }
 
@@ -259,7 +257,7 @@ int ScsiIf::inquiry()
 	return inq(impl_->fd_, vendor_, product_, revision_);
 }
 
-ScsiIf::ScanData *ScsiIf::scan(int *len)
+ScsiIf::ScanData *ScsiIf::scan(int *len, char *devpath)
 {
 	DIR *dirp;
 	struct dirent *dp;
@@ -289,6 +287,9 @@ ScsiIf::ScanData *ScsiIf::scan(int *len)
 			strcat(s, dp->d_name);
 			if ((fd = open(s, O_RDWR, 0)) >= 0) {
 				if (ioctl(fd, SCIOCIDENTIFY, &saddr) >= 0) {
+#if 1
+					scanData[*len].dev = s;
+#else
 					switch (saddr.type) {
 						case TYPE_SCSI:
 							scanData[*len].bus = saddr.addr.scsi.scbus;
@@ -305,6 +306,7 @@ ScsiIf::ScanData *ScsiIf::scan(int *len)
 							scanData[*len].id =
 							scanData[*len].lun = -1;
 					}
+#endif
 					if (inq(fd, scanData[*len].vendor,
 					            scanData[*len].product,
 					            scanData[*len].revision) == 0) (*len)++;
