// search
typedef struct packet_target_info
{
  ...
} TPacketGCTargetInfo;

// replace FULL function with this:
typedef struct packet_target_info
{
	BYTE	header;
	DWORD	dwVID;
	DWORD	race;
	DWORD	dwVnum;
#ifdef ENABLE_ITEM_COUNT_LIMIT_SYSTEM // Kann entfernt werden falls ihr sowas nicht nutzt. WICHTIG: Datentyp an euren anpassen (WORD count; oder BYTE count;)
	WORD	count;
#else
	BYTE	count;
#endif
	DWORD	rarity;
} TPacketGCTargetInfo;
