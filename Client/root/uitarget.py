# search
					nameLine = ui.TextLine()
					nameLine.SetParent(self)
					nameLine.SetPosition(32 + 5, 0)
					nameLine.Show()
					self.nameLine = nameLine

# add
					if app.ENABLE_SEND_TARGET_INFO_EXTENDED:
						rarity = ui.TextLine()
						rarity.SetParent(self)
						rarity.SetPosition(32 + 5, 11)
						rarity.Show()
						self.rarity = rarity

# search
				def SetText(self, text):
					self.nameLine.SetText(text)

# add
				if app.ENABLE_SEND_TARGET_INFO_EXTENDED:
					def SetRarity(self, rarity):
						if rarity <= 0:
							return

						real_rarity = rarity / 10000
						self.rarity.SetText(str(self.GetRarity(real_rarity)))

					def GetRarity(self, rarity):
						if rarity >= 100:
							return localeInfo.RARITY_GUARANTEED
						elif rarity < 100 and rarity >= 70:
							return localeInfo.RARITY_COMMON
						elif rarity < 70 and rarity >= 50:
							return localeInfo.RARITY_UNCOMMON
						elif rarity < 50 and rarity >= 30:
							return localeInfo.RARITY_MYTHIC
						elif rarity < 30 and rarity >= 11:
							return localeInfo.RARITY_RARE
						elif rarity <= 10:
							return localeInfo.RARITY_LEGENDARY
							
						return ""

# search
			def AppendItem(self, listBox, vnums, count):

# replace
			def AppendItem(self, listBox, vnums, count, rarity = 0):

# search
				if count <= 1:
					myItem.SetText(itemName)
				else:
					myItem.SetText("%dx %s" % (count, itemName))

# add
				if app.ENABLE_SEND_TARGET_INFO_EXTENDED:
					myItem.SetRarity(rarity)

# search
          for curItem in constInfo.MONSTER_INFO_DATA[race]["items"]: #kann bei euch so heißen: for curItem in MONSTER_INFO_DATA[race]["items"]:
							if curItem.has_key("vnum_list"):
								height += self.AppendItem(itemListBox, curItem["vnum_list"], curItem["count"])
							else:
								height += self.AppendItem(itemListBox, curItem["vnum"], curItem["count"])

# replace
						for curItem in constInfo.MONSTER_INFO_DATA[race]["items"]: #kann bei euch anders heißen, ändert am besten nur den if/else Teil
							if curItem.has_key("vnum_list"):
								height += self.AppendItem(itemListBox, curItem["vnum_list"], curItem["count"], curItem["rarity"])
							else:
								height += self.AppendItem(itemListBox, curItem["vnum"], curItem["count"], curItem["rarity"])

