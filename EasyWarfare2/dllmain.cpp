#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include "detours.h"

#include "Structs.h"
#include "ESP.h"

tRenderScene oRenderScene;

ESP* pESP;

/* RenderScene detour. */
int nRenderScene(int a, int b, int c, double d, float e, int f, int g, float h, int i, int j)
{
	pESP->DrawPlayerNames();

	return oRenderScene(a, b, c, d, e, f, g, h, i, j);
}

DWORD HookThread(LPVOID lpArgs)
{
	DWORD dwBase = NULL;
	for (; dwBase == NULL; Sleep(100))
		dwBase = (DWORD)GetModuleHandleA("iw4mp.exe");
	oRenderScene = (tRenderScene)DetourFunction((PBYTE)RENDERSCENE_ADDR, (PBYTE)nRenderScene);

	return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
		AllocConsole();
		freopen("CONIN$", "r", stdin);
		freopen("CONOUT$", "w", stdout);
		freopen("CONOUT$", "w", stderr);

		RGBA_COLOR_t RedColor = { 1.0f, 0.0f, 0.0f, 1.0f };
		pESP = new ESP(RedColor);

		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)HookThread, NULL, NULL, NULL);
	}

	return TRUE;
}