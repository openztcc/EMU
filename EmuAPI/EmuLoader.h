#pragma once

#include "EmuMod.h"

class EmuLoader
{
public:
	EmuLoader(void);
	~EmuLoader(void);
	void loadMod(EmuMod modToLoad);
	std::vector<EmuMod> loadedMods;

};
