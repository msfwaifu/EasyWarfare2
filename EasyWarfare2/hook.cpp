#include "stdafx.h"

int nRE_RenderScene(int a, int b, int c, double d, float e, int f, int g, float h, int i, int j)
{
	// Draw ESP
	RGBA_COLOR_t RedColor = {1.0, 0.0, 0.0, 1.0};
	cgame->DrawESP(&RedColor, true, true, true);

	return iw4mp->RE_RenderScene(a, b, c, d, e, f, g, h, i, j);
}