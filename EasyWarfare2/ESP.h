#pragma once
#include "Structs.h"

class ESP
{
private:
	entity_t * cg_entities;
	cg_t * cg;
	cgs_t * cgs;
	refdef_t * refdef;
	clientinfo_t * clients;

	tApplyRect ApplyRect;
	tGetFontType GetFontType;
	tDrawEngineText DrawEngineText;

	RGBA_COLOR_t Color;

	void eDrawText(float x, float y, RGBA_COLOR_t* Color, const char* Text);

	bool WorldToScreen(vec3_t WorldLocation, float *fScreenX, float *fScreenY);
	float GetDistance(vec3_t p1, vec3_t p2);
public:
	ESP(RGBA_COLOR_t color);
	~ESP();

	void DrawPlayerNames();
	void DrawBoxes();
};