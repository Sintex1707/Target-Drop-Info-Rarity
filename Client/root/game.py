# search
		def BINARY_AddTargetMonsterDropInfo(self, raceNum, itemVnum, itemCount):

# replace
		def BINARY_AddTargetMonsterDropInfo(self, raceNum, itemVnum, itemCount, rarity = 0):

# search
			if isUpgradeable or isMetin:
				curList.append({"vnum_list":[itemVnum], "count":itemCount})
			else:
				curList.append({"vnum":itemVnum, "count":itemCount})

# replace
			if isUpgradeable or isMetin:
				curList.append({"vnum_list":[itemVnum], "count":itemCount, "rarity":rarity})
			else:
				curList.append({"vnum":itemVnum, "count":itemCount, "rarity":rarity})
