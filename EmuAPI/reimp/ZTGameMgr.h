#ifndef ZTGAMEMGR_h
#define ZTGAMEMGR_h

#include <Windows.h> // must always be above detours.h
#include <detours.h>
#include "EmuBase.h"
#include "BFUIMgr.h"

typedef __int32 int32_t;
typedef void (__thiscall *_addCash)(void* thisptr, float amount); // define original addCash function
typedef void (__thiscall *_BFUIMgrSetControlForeColor)(void*, int, DWORD); // define original BFUIMgrSetControlForeColor function
typedef void (__cdecl *_BFInternatSetMoneyText)(int, int, char); // define original BFUIMgrSetControlForeColor function


struct GXRGB {
    int r;
    int g;
    int b;
};

class ZTGameMgr
{
public:
	char pad_0000[12]; //0x0000
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
	float N000000C2[12]; //0x0224
	float admissions_income[12]; //0x0254
	float concessions_benefits[12]; //0x0284
	float N000000C5[12]; //0x02B4
	float N000000C6[12]; //0x02E4
	float N000000C7[12]; //0x0314
	float N000000C8[12]; //0x0344
	float N000000C9[12]; //0x0374
	float N000000CA[12]; //0x03A4
	float N000000CB[12]; //0x03D4
	float zoo_profits[12]; //0x0404
	float zoo_values[12]; //0x0434
	float zoo_ratings[12]; //0x0464
	float N000000D0[12]; //0x0494
	float N000000D1[12]; //0x04C4
	float N000000D2[12]; //0x04F4
	float N000000D3[12]; //0x0524
	float N000000D4[12]; //0x0554
	float N000000D5[12]; //0x0584
	float N000000D6[12]; //0x05B4
	float N000000D7[12]; //0x05E4
	float number_of_guests[12][4]; //0x0614
	float N000000D9[12]; //0x0644
	float N000000DA[12]; //0x0674
	float N000000DB[12]; //0x06A4
	float N000000DC[12]; //0x06D4
	float N000000DD[12]; //0x0704
	float N000000DE[12]; //0x0734
	float N000000DF[12]; //0x0764
	float N000000E0[12]; //0x0794
	float N000000E1[12]; //0x07C4
	float N000000E2[12]; //0x07F4
	float N000000E3[12]; //0x0824
	float N000000F2[12]; //0x0854
	float N000000F3[12]; //0x0884
	float N000000F4[12]; //0x08B4
	float N000000F5[12]; //0x08E4
	float N000000F6[12]; //0x0914
	float N000000F7[12]; //0x0944
	float N000000F8[12]; //0x0974
	float N000000F9[12]; //0x09A4
	float N000000FA[12]; //0x09D4
	float N000000FB[12]; //0x0A04
	float N000000FC[12]; //0x0A34
	float N000000FD[12]; //0x0A64
	float N000000FE[12]; //0x0A94
	char pad_0AC4[1520]; //0x0AC4

    ZTGameMgr();
    ~ZTGameMgr();
    void addCash(float);
	void ZTUIMainSetMoneyText();
	static void __fastcall addCash_Detour(void* ptr, float amount);
	static void BFUIMgrSetControlForeColor(void* ptr, int param_1, DWORD color);
	static void BFInternatSetMoneyText(int, int, char);
	static void init();
	static ZTGameMgr &shared_instance() {
		static ZTGameMgr instance;
		return instance;
	}

}; //Size: 0x10B4

#endif // ZTGAMEMGR_h