//
//#include "EmuGameLoop.h"
//#include "EmuController.h"
//#include <mmsystem.h>
//
//EmuGameLoop::EmuGameLoop(void)
//{
//	deltaTime = 0;
//}
//
//EmuGameLoop::~EmuGameLoop(void)
//{
//}


//void EmuGameLoop::createLoop()
//{
//	while (true)
//	{
//		executeLoop();
//	}
//}

//void EmuGameLoop::createLoop()
//{
//	DWORD currentTime = timeGetTime();
//	deltaTime = currentTime - deltaTime;
//
//	for (auto mod : EmuController.modLoader.loadedMods)
//	{
//		mod.update(deltaTime);
//	}
//}