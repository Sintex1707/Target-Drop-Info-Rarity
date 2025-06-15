// add at the end of file before }
#ifdef ENABLE_SEND_TARGET_INFO_EXTENDED
	PyModule_AddIntConstant(poModule, "ENABLE_SEND_TARGET_INFO_EXTENDED", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_SEND_TARGET_INFO_EXTENDED", 0);
#endif
