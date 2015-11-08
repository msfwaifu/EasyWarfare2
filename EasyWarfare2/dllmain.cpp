#include "stdafx.h"

Iw4mp *iw4mp = NULL;
CGame *cgame = NULL;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
		cgame = new CGame();
		iw4mp = new Iw4mp();
	}

	return TRUE;
}
