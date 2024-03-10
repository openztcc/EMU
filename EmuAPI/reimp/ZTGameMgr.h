#ifndef ZTGAMEMGR_h
#define ZTGAMEMGR_h

#include <Windows.h> // must always be above detours.h
#include <detours.h>
#include "EmuBase.h"
#include "BFUIMgr.h"

typedef __int32 int32_t;
typedef void (__thiscall *_addCash)(void* thisptr, float amount); // define original addCash function
typedef void (__cdecl *_setCash)(int); // define original setCash function
typedef void (__fastcall *_startMenuMusic)(void*); // define original startMenuMusic function

struct GXRGB {
    int r;
    int g;
    int b;
};

class ZTGameMgr
{
	class MenuMusicHandler 
	{
		// 20 bytes
		void update(unsigned int); // 0x41a13a

	};
public:
	char pad_0004[12];
	float zoo_budget; //0x000C
	char pad_0010[32]; //0x0010
	int num_animals; //0x0030
	char pad_0034[4]; //0x0034
	int num_species; //0x0038
	char pad_003C[24]; //0x003C
	int guest_count; //0x0054
	char pad_0058[364]; //0x0058
	float animal_purchase_costs[12]; //0x01C4
	float construction_costs[12]; //0x01F4
	char pad_0224[48]; //0x0224
	float admissions_income[12]; //0x0254
	float concessions_benefits[12]; //0x0284
	char pad_02B4[336]; //0x02B4
	float zoo_profits[12]; //0x0404
	float zoo_values[12]; //0x0434
	float zoo_ratings[12]; //0x0464
	char pad_0494[384]; //0x0494
	float number_of_guests[12]; //0x0614
	char pad_0644[2928]; //0x0644 TODO: subtract current date
	SYSTEMTIME current_date; //0x1194 (8 bytes)
	// virtual ~ZTGameMgr();
	// virtual void setNewGameDefaults(void*, char) {};
	// virtual void save(char**) {};
	// virtual void load() {};
	// virtual void update(int) {};
	// virtual void updateSim(unsigned int) {};

    ZTGameMgr();
    ~ZTGameMgr();
    void addCash(float);
	void setCash(int);
	void subtractCash(float);
	_FILETIME* getDate(_FILETIME* date);
	void startMenuMusic(); // 0x004bded9
	void startMenuMusicFade(int); // 0x004cc59d
	unsigned int save(char**); // 0x47acc5
	void setNewGameDefaults(void*, char); // 0x0058f39c
	void stop(int); // 0x004fa123



	static _FILETIME* __fastcall getDate_Detour(void* ptr, _FILETIME* date);
	static void __fastcall addCash_Detour(void* ptr, float amount);
	static void __cdecl setCash_Detour(int amount);
	static void __fastcall subtractCash_Detour(void* ptr, float amount);
	static void __fastcall startMenuMusic_Detour(int param_1);
	static void init();
	static DWORD getZTGameMgr();
	static ZTGameMgr &shared_instance() {
		static ZTGameMgr instance;
		return instance;
	}
}; //Size: 0x10B4 4528

#endif // ZTGAMEMGR_h