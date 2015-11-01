#pragma once
class CGame
{
public:
	CGame();
	~CGame();

	// Pointers to original vars/functions
	entity_t *cg_entities[MAX_ENTITIES];
	clientinfo_t *clientInfo[MAX_CLIENTS];
	cg_t * cg;
	cgs_t * cgs;
	refdef_t * refdef;

	void DrawESP(RGBA_COLOR_t *Color, bool distance, bool name, bool box);
private:
	// ESP math
	bool WorldToScreen(vec3_t WorldLocation, float *fScreenX, float *fScreenY);
	float GetDistance(vec3_t p1, vec3_t p2);
};

