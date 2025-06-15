// search
void CInputMain::TargetInfoLoad(LPCHARACTER ch, const char* c_pData)
{
  ...
}

// change FULL function with this 
void CInputMain::TargetInfoLoad(LPCHARACTER ch, const char* c_pData)
{
	TPacketCGTargetInfoLoad* p = (TPacketCGTargetInfoLoad*)c_pData;
	TPacketGCTargetInfo pInfo;
	pInfo.header = HEADER_GC_TARGET_INFO;
	static std::vector<LPITEM> s_vec_item;

	s_vec_item.clear();

	LPCHARACTER m_pkChrTarget = CHARACTER_MANAGER::instance().Find(p->dwVID);

	if (!ch || !m_pkChrTarget)
		return;

	if (!ch->GetDesc())
		return;

	if ((m_pkChrTarget->IsMonster() || m_pkChrTarget->IsStone()) &&
		ITEM_MANAGER::instance().CreateDropItemVector(m_pkChrTarget, ch, s_vec_item))
	{
		if (s_vec_item.empty())
		{
			s_vec_item.clear();
			return;
		}
		else
		{
			for (const auto& item : s_vec_item)
			{
				pInfo.dwVID = m_pkChrTarget->GetVID();
				pInfo.race = m_pkChrTarget->GetRaceNum();
				pInfo.dwVnum = item->GetVnum();
#ifdef ENABLE_ITEM_COUNT_LIMIT_SYSTEM  // Kann entfernt werden bzw angepasst werden auf euren Datentyp (WORD, BYTE etc.)
				pInfo.count = static_cast<WORD>(item->GetCount());
#else
				pInfo.count = static_cast<BYTE>(item->GetCount());
#endif
#ifdef ENABLE_SEND_TARGET_INFO_EXTENDED
				pInfo.rarity = item->GetRarity();  // Rarity Methode
#endif  
				ch->GetDesc()->Packet(&pInfo, sizeof(TPacketGCTargetInfo));
			}
		}
	}

	s_vec_item.clear();
}
