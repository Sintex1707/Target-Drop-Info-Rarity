// search
typedef struct packet_target_info
{
	BYTE	header;
	DWORD	dwVID;
	DWORD	race;
	DWORD	dwVnum;
	WORD	count;
} TPacketGCTargetInfo;

// replace FULL function with this:
typedef struct packet_target_info
{
	BYTE	header;
	DWORD	dwVID;
	DWORD	race;
	DWORD	dwVnum;
	WORD	count;
#ifdef ENABLE_SEND_TARGET_INFO_EXTENDED
	DWORD	rarity;
#endif
} TPacketGCTargetInfo;
