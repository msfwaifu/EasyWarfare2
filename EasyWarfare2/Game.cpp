#include "stdafx.h"

CGame::CGame()
{
	// Init all pointers
	for (int entityNum = 0; entityNum < MAX_ENTITIES; entityNum++)
		this->cg_entities[entityNum] = (entity_t *)((uintptr_t)ENTITY_ADDR + (entityNum * ENTITY_SIZE));

	for (int clientNum = 0; clientNum < MAX_CLIENTS; clientNum++)
		this->clientInfo[clientNum] = (clientinfo_t *)((uintptr_t)CLIENT_ADDR + (clientNum * CLIENT_SIZE));

	this->cg = (cg_t *)CG_ADDR;
	this->cgs = (cgs_t *)CGS_ADDR;
	this->refdef = (refdef_t*)REFDEF_ADDR;
}

CGame::~CGame()
{
}

void CGame::DrawESP(RGBA_COLOR_t *Color, bool distance, bool name, bool box)
{
	if (!cg->IsPlaying)
		return;

	for (int i = 0; i < MAX_ENTITIES; i++)
	{
		if (cg_entities[i]->eType == ET_PLAYER && cg_entities[i]->iAlive)
		{
			if (clientInfo[cg_entities[i]->clientNum]->iTeam2 != clientInfo[cg->ClientNumber]->iTeam2) {
				float fScreenX = 0.0, fScreenY = 0.0;
				if (WorldToScreen(cg_entities[i]->vOrigin, &fScreenX, &fScreenY)) {
					if (distance) {
						float distance = 0.0;
						char strDist[10]; // 10 should be large enough
						distance = GetDistance(cg_entities[i]->vOrigin, refdef->vOrigin);
						snprintf(strDist, 10, "%f", distance);
						iw4mp->DrawTextWrapper(fScreenX - (sizeof(clientInfo[cg_entities[i]->clientNum]->szName) / 2), fScreenY, Color, strDist);
					}
					if (name) {
						char strName[16];
						snprintf(strName, 16, "%s", clientInfo[cg_entities[i]->clientNum]->szName);
						iw4mp->DrawTextWrapper(fScreenX - (sizeof(clientInfo[cg_entities[i]->clientNum]->szName) / 2), fScreenY + 10, Color, strName);
					}
					if (box) {
						// Draw box
					}
				}
			}
		}
	}
}

bool CGame::WorldToScreen(vec3_t WorldLocation, float *fScreenX, float *fScreenY)
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

float CGame::GetDistance(vec3_t p1, vec3_t p2)
{
	vec3_t  v;
	VectorSubtract(p2, p1, v);
	return VectorLength(v);
}
