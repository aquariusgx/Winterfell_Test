//
//  ContactDemoScene.cpp
//  NutRock_Demo
//
//  Created by mac on 13-11-26.
//
//

#include "DemoLayer.h"
#include "ListViewLayer.h"
#include "GeneralDialogLayer.h"

void TableViewContactDemoScene::runThisTest()
{
    
    CCLayer * pLayer = new ListViewLayer();
    addChild(pLayer);
    pLayer->release();
    
    CCDirector::sharedDirector()->replaceScene(this);
}

void GeneralDialogScene::runThisTest()
{
    
    CCLayer * pLayer = new GeneralDialogLayer();
    addChild(pLayer);
    pLayer->release();
    CCDirector::sharedDirector()->replaceScene(this);
    
}