#include "stdafx.h"

Iw4mp::Iw4mp()
{
	this->InitHook();
}

Iw4mp::~Iw4mp()
{
	// TODO: Unhook everything.
}

void Iw4mp::DrawTextWrapper(float x, float y, RGBA_COLOR_t* Color, const char* Text)
{
	void* Font = this->GetFontType(FONT_SMALL_DEV, 0); // 2nd parameter maybe strlen
	this->DrawEngineText((char*)Text, 0x7FFFFFFF, Font, x, y, 1.0f, 1.0f, 0.0f, Color, 0);

}

void Iw4mp::InitHook()
{
	this->RE_RenderScene = (tRenderScene)DetourFunction((PBYTE)RENDERSCENE_ADDR, (PBYTE)nRE_RenderScene);

	this->ApplyRect = (tApplyRect)APPLYRECT_ADDR;
	this->GetFontType = (tGetFontType)GETFONT_ADDR;
	this->DrawEngineText = (tDrawEngineText)DRAWTEXT_ADDR;
}
