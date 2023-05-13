#pragma once

#include "ModLoader.h"

class EmuController
{
public:
	EmuController(void);
	~EmuController(void);

	ModLoader modLoader;
};
