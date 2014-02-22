#include "pch.h"
#include "CScene.h"
#include "data/CData.h"
#include "data/SceneXml.h"
#include "WaterRTT.h"
#include "../../road/Road.h"


CScene::CScene(App* app1)
	:app(app1)
	,sun(0), pr(0),pr2(0)
	,grass(0), trees(0)
	,terrain(0), mTerrainGroup(0), mTerrainGlobals(0)
	,horizon(0), mHorizonGroup(0), mHorizonGlobals(0)
	,mWaterRTT(0)
	,road(0)
	,vdrTrack(0)
{
	data = new CData();
	sc = new Scene();
	mWaterRTT = new WaterRTT();
}

CScene::~CScene()
{
	delete road;

	OGRE_DELETE mHorizonGroup;
	OGRE_DELETE mHorizonGlobals;

	OGRE_DELETE mTerrainGroup;
	OGRE_DELETE mTerrainGlobals;

	delete mWaterRTT;
	delete sc;
	delete data;
}


void CScene::DestroyRoad()
{
	if (!road)  return;
	road->DestroyRoad();
	delete road;  road = 0;
}


void CScene::destroyScene()
{
	mWaterRTT->destroy();

	DestroyRoad();

	DestroyTrees();

	DestroyWeather();

	delete[] sc->td.hfHeight;
}
