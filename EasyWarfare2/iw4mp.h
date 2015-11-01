#pragma once

class Iw4mp
{
public:
	Iw4mp();
	~Iw4mp();

	// Original functions
	tRenderScene RE_RenderScene;
	tApplyRect ApplyRect;
	tDrawEngineText DrawEngineText;
	tGetFontType GetFontType;

	// DrawEngineText wrapper
	void DrawTextWrapper(float x, float y, RGBA_COLOR_t* Color, const char* Text);
private:
	void InitHook();

};

