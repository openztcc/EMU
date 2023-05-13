#pragma once

class EmuGameLoop
{
public:
	EmuGameLoop(void);
	~EmuGameLoop(void);
	DWORD deltaTime;

private:
	void createLoop();
	void executeLoop();
};
