// search
	public:
		void SetSIGVnum(DWORD dwSIG)
		{
			m_dwSIGVnum = dwSIG;
		}
		DWORD	GetSIGVnum() const
		{
			return m_dwSIGVnum;
		}

// add
#ifdef ENABLE_SEND_TARGET_INFO_EXTENDED
	public:
		void		SetRarity(DWORD rarity) { dwRarity = rarity; }
		DWORD		GetRarity() { return dwRarity; }
	protected: // Achtung, dass ihr unter dem protected: DWORD dwRarity keine leere Funktion stehen habt, ansonsten darüber "public:" einfügen
		DWORD		dwRarity;
#endif
