From: Antonio Larrosa <larrosa@kde.org>
Date: Mon, 6 Mar 2017 18:02:31 +0100
Subject: clamp index values to fix index overflow in IMA.cpp

This fixes #33
(also reported at https://bugzilla.opensuse.org/show_bug.cgi?id=1026981
and https://blogs.gentoo.org/ago/2017/02/20/audiofile-global-buffer-overflow-in-decodesample-ima-cpp/)
---
 libaudiofile/modules/IMA.cpp | 4 ++--
 1 file changed, 2 insertions(+), 2 deletions(-)

--- libaudiofile/modules/IMA.cpp
+++ libaudiofile/modules/IMA.cpp
@@ -169,7 +169,7 @@ int IMA::decodeBlockWAVE(const uint8_t *encoded, int16_t *decoded)
 		if (encoded[1] & 0x80)
 			m_adpcmState[c].previousValue -= 0x10000;
 
-		m_adpcmState[c].index = encoded[2];
+		m_adpcmState[c].index = clamp(encoded[2], 0, 88);
 
 		*decoded++ = m_adpcmState[c].previousValue;
 
@@ -210,7 +210,7 @@ int IMA::decodeBlockQT(const uint8_t *encoded, int16_t *decoded)
 			predictor -= 0x10000;
 
 		state.previousValue = clamp(predictor, MIN_INT16, MAX_INT16);
-		state.index = encoded[1] & 0x7f;
+		state.index = clamp(encoded[1] & 0x7f, 0, 88);
 		encoded += 2;
 
 		for (int n=0; n<m_framesPerPacket; n+=2)
