#pragma once

typedef float vec3_t[3];

#define CGS_ADDR	 0x89D3A0
#define CG_ADDR		 0x8A0E50
#define ENTITY_ADDR  0x9A4090
#define ENTITY_SIZE  0x204
#define MAX_ENTITIES 2048
#define REFDEF_ADDR  0x90B5C8
#define CLIENT_ADDR  0x99785C
#define CLIENT_SIZE  0x52C

#define RENDERSCENE_ADDR 0x0059AAF0
#define APPLYRECT_ADDR	 0x004DF2D0 // Untested
#define GETFONT_ADDR	 0x0040f6d0
#define DRAWTEXT_ADDR	 0x004113D0

#define FONT_SMALL_DEV    "fonts/smallDevFont"
#define FONT_BIG_DEV      "fonts/bigDevFont"
#define FONT_CONSOLE      "fonts/consoleFont"
#define FONT_BIG          "fonts/bigFont"
#define FONT_SMALL        "fonts/smallFont"
#define FONT_BOLD         "fonts/boldFont"
#define FONT_NORMAL       "fonts/normalFont"
#define FONT_EXTRA_BIG    "fonts/extraBigFont"
#define FONT_OBJECTIVE    "fonts/objectiveFont"  

typedef struct {
	float r, g, b, a;
} RGBA_COLOR_t;

typedef int(__cdecl* tApplyRect)(void* scrPlace, float* x, float* y, float* w, float* h, int horzAlign, int vertAlign);
typedef void* (*tGetFontType)(char* FontName, int Unknown1);
typedef int(*tDrawEngineText)(char* Text, int Unknown1, void* Font, float X, float Y, float Unknown2, float Unknown3, float Unknown4, RGBA_COLOR_t* Color, int Unknown5);
typedef int(*tRenderScene)(int a, int b, int c, double d, float e, int f, int g, float h, int i, int j);

enum EntTypes {
	ET_GENERAL,
	ET_PLAYER,
	ET_PLAYER_CORPSE,
	ET_ITEM,
	ET_MISSILE,
	ET_INVISIBLE,
	ET_SCRIPTMOVER,
	ET_SOUND_MOVER,
	ET_FX,
	ET_LOOP_FX,
	ET_PRIMARY_LIGHT,
	ET_TURRET,
	ET_HELICOPTER,
	ET_PLANE,
	ET_VEHICLE,
	ET_VEHICLE_COLLMAP,
	ET_VEHICLE_CORPSE,
	ET_VEHICLE_SPAWNER,
};

typedef struct {
	char _0x0000[24];
	vec3_t vOrigin; 
	char _0x0024[72];
	__int32 IsZooming;
	char _0x0070[12];
	vec3_t vOldOrigin; 
	char _0x0088[84];
	__int32 clientNum; 
	__int32 eType; 
	__int32 eFlags; 
	char _0x00E8[12];
	vec3_t vNewOrigin;
	char _0x0100[108];
	__int32 pickupItemID; 
	__int32 clientNum2; 
	char _0x0174[52];
	unsigned char weaponID; 
	char _0x01A9[51];
	__int32 iAlive; 
	char _0x01E0[32];
	__int32 clientNum3; 
} entity_t; 

typedef struct {
	__int32 snapshot;
	char unknown0[96];
	__int32 IsPlaying; 
	char unknown1[32];
	__int32 localweaponnum; 
	char unknown2[36];
	__int32 Pose; 
	char unknown3[80];
	__int32 ClientNumber; 
	char unknown4[72];
	__int32 health; 
	char unknown5[408];
	__int32 mag; 
	char unknown6[124];
	__int32 clip; 
} cg_t;

typedef struct {
	char	_p00[8];
	__int32 Screen_Width;
	__int32 Screen_Height;
	float ScreenXBias;
	__int32 serverCommandSequence;
	__int32 processedSnapshotNum;
	__int32 LocalServer;
	char GameType[4];
	char unknown36[28];
	char ServerName[64];
	char unknown320[196];
	__int32 Max_Clients;
	char unknown324[4];
	char MapName[64];
	char unknown388[4];
	__int32 Active_Vote;
} cgs_t;

typedef struct  {
	__int32 x;
	__int32 y;
	__int32 iWidth;
	__int32 iHeight; 
	float fovX; 
	float fovY; 
	vec3_t vOrigin;
	vec3_t vViewAxis[3];
	char _0x0048[4];
	vec3_t vViewAngles;
	__int32 iTime;
	__int32 iMenu; 
	char _0x0060[16128];
	vec3_t refdefViewAngles;
	char _0x3F6C[276];
} refdef_t; 

typedef struct {
	__int32 IsValid; //0x0000 
	__int32 IsValid2; //0x0004 
	__int32 clientNum; //0x0008 
	char szName[16]; //0x000C 
	__int32 iTeam; //0x001C 
	__int32 iTeam2; //0x0020 
	__int32 iRank; //0x0024 rank+1 
	char _0x0028[4];
	__int32 iPerk; //0x002C 
	__int32 iKills; //0x0030
	__int32 iScore; //0x0034 
	char _0x0038[968];
	vec3_t vAngles; //0x0400 
	char _0x040C[136];
	__int32 IsShooting; //0x0494 
	char _0x0498[4];
	__int32 IsZoomed; //0x049C 
	char _0x04A0[68];
	__int32 weaponID; //0x04E4 
	char _0x04E8[24];
	__int32 weaponID2; //0x0500 
	char _0x0504[40];
} clientinfo_t;