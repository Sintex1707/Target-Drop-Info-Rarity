// search 
				Py_BuildValue("(iii)", pInfoTargetPacket.race, pInfoTargetPacket.dwVnum, pInfoTargetPacket.count));

// replace
#ifdef ENABLE_SEND_TARGET_INFO_EXTENDED
				Py_BuildValue("(iiii)", pInfoTargetPacket.race, pInfoTargetPacket.dwVnum, pInfoTargetPacket.count, pInfoTargetPacket.rarity));
#else
				Py_BuildValue("(iii)", pInfoTargetPacket.race, pInfoTargetPacket.dwVnum, pInfoTargetPacket.count));
#endif
