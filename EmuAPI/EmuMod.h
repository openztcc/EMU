#pragma once

class EmuMod
{
public:
	EmuMod(void);
	~EmuMod(void);

protected:
	virtual void start() = 0;
	virtual void update(DWORD deltaTime) = 0;
};
