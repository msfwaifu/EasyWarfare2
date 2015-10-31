#include "ESP.h"
#include "vector.h"

#include <stdio.h>
#include <string.h>
#include <math.h>

ESP::ESP(RGBA_COLOR_t color)
{
	this->cg_entities = (entity_t *)ENTITY_ADDR;
	this->clients = (clientinfo_t *)CLIENT_ADDR;
	this->cg = (cg_t*)CG_ADDR;
	this->cgs = (cgs_t*)CGS_ADDR;
	this->refdef = (refdef_t*)REFDEF_ADDR;
	this->ApplyRect = (tApplyRect) APPLYRECT_ADDR;
	this->GetFontType = (tGetFontType)GETFONT_ADDR;
	this->DrawEngineText = (tDrawEngineText)DRAWTEXT_ADDR;
	this->Color = color;
}

ESP::~ESP()
{
}

void ESP::DrawPlayerNames()
{
	if (!cg->IsPlaying)
		return;

	for (int i = 0; i < MAX_ENTITIES; i++ )
	{
		if (cg_entities[i].eType == ET_PLAYER && cg_entities[i].iAlive)
		{
			if (clients[cg_entities[i].clientNum].iTeam2 != clients[cg->ClientNumber].iTeam2) {
				float fScreenX = 0.0, fScreenY = 0.0, distance = 0.0;
				char strDist[10];
				distance = GetDistance(cg_entities[i].vOrigin, refdef->vOrigin);
				snprintf(strDist, 10, "%f", distance);
				if (WorldToScreen(cg_entities[i].vOrigin, &fScreenX, &fScreenY))
					eDrawText(fScreenX - (sizeof(clients[cg_entities[i].clientNum].szName) / 2), fScreenY, &Color, strDist);
			}
		}
	}
}

void ESP::DrawBoxes()
{
	// TODO
}

void ESP::eDrawText(float x, float y, RGBA_COLOR_t* Color, const char* Text) 
{
	void* Font = GetFontType(FONT_SMALL_DEV, 0);
	DrawEngineText((char*)Text, 0x7FFFFFFF, Font, x, y, 1.0f, 1.0f, 0.0f, Color, 0);
}

bool ESP::WorldToScreen(vec3_t WorldLocation, float *fScreenX, float *fScreenY)
{
	float forward, right, up;
	vec3_t delta;

	VectorSubtract(WorldLocation, refdef->vOrigin, delta);
	forward = DotProduct(delta, refdef->vViewAxis[0]);
	if (forward <= 0.f) {
		return false;
	}

	right = DotProduct(delta, refdef->vViewAxis[1]);
	up = DotProduct(delta, refdef->vViewAxis[2]);
	*fScreenX = floor(refdef->iWidth * 0.5f * (1.f - (right / refdef->fovX / forward)));
	*fScreenY = floor(refdef->iHeight * 0.5f * (1.f - (up / refdef->fovY / forward)));
	return true;
}

float ESP::GetDistance(vec3_t p1, vec3_t p2)
{
	vec3_t  v;
	VectorSubtract(p2, p1, v);
	return VectorLength(v);
}