#pragma once
#include <minwindef.h>

// @credits: https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/vphysics_interfaceV30.h

struct surfacephysicsparams_t
{
	float flFriction;
	float flElasticity;
	float flDensity;
	float flThickness;
	float flDampening;
}; // Size: 0x14

struct surfaceaudioparams_t
{
	float flReflectivity;             // like elasticity, but how much sound should be reflected by this surface
	float flHardnessFactor;           // like elasticity, but only affects impact sound choices
	float flRoughnessFactor;          // like friction, but only affects scrape sound choices   
	float flRoughThreshold;           // surface roughness > this causes "rough" scrapes, < this causes "smooth" scrapes
	float flHardThreshold;            // surface hardness > this causes "hard" impacts, < this causes "soft" impacts
	float flHardVelocityThreshold;    // collision velocity > this causes "hard" impacts, < this causes "soft" impacts   
	float flHighPitchOcclusion;       // a value betweeen 0 and 100 where 0 is not occluded at all and 100 is silent (except for any additional reflected sound)
	float flMidPitchOcclusion;
	float flLowPitchOcclusion;
}; // Size: 0x24

struct surfacesoundnames_t
{
	unsigned short uWalkStepLeft;
	unsigned short uWalkStepRight;
	unsigned short uRunStepLeft;
	unsigned short uRunStepRight;
	unsigned short uImpactSoft;
	unsigned short uImpactHard;
	unsigned short uScrapeSmooth;
	unsigned short uScrapeRough;
	unsigned short uBulletImpact;
	unsigned short uRolling;
	unsigned short uBreakSound;
	unsigned short uStrainSound;
}; // Size: 0x18

struct surfacesoundhandles_t
{
	unsigned short uWalkStepLeft;
	unsigned short uWalkStepRight;
	unsigned short uRunStepLeft;
	unsigned short uRunStepRight;
	unsigned short uImpactSoft;
	unsigned short uImpactHard;
	unsigned short uScrapeSmooth;
	unsigned short uScrapeRough;
	unsigned short uBulletImpact;
	unsigned short uRolling;
	unsigned short uBreakSound;
	unsigned short uStrainSound;
}; // Size: 0x18

struct surfacegameprops_t
{
	float				flMaxSpeedFactor;
	float				flJumpFactor;
	float				flPenetrationModifier;
	float				flDamageModifier;
	unsigned short	    hMaterial;
	BYTE			    dClimbable;
	BYTE			    pad0[0x4];
}; // Size: 0x17

struct surfacedata_t
{
	surfacephysicsparams_t	physics;
	surfaceaudioparams_t	audio;
	surfacesoundnames_t		sounds;
	surfacegameprops_t		game;
	surfacesoundhandles_t	soundhandles;
}; // Size: 0x7F

class IPhysicsSurfaceProps
{
public:
	virtual					~IPhysicsSurfaceProps() { }
	virtual int				ParseSurfaceData(const char* szFileName, const char* szTextFile) = 0;
	virtual int				SurfacePropCount() const = 0;
	virtual int				GetSurfaceIndex(const char* szSurfacePropName) const = 0;
	virtual void			GetPhysicsProperties(int iSurfaceDataIndex, float* flDensity, float* flThickness, float* flFriction, float* flElasticity) const = 0;
	virtual surfacedata_t*  GetSurfaceData(int iSurfaceDataIndex) = 0;
	virtual const char*     GetString(unsigned short shStringTableIndex) const = 0;
	virtual const char*     GetPropName(int iSurfaceDataIndex) const = 0;
	virtual void			SetWorldMaterialIndexTable(int* iMapArray, int iMapSize) = 0;
	virtual void			GetPhysicsParameters(int iSurfaceDataIndex, surfacephysicsparams_t* pParamsOut) const = 0;
};