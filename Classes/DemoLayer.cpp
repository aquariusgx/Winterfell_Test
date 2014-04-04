//
//  ContactDemoScene.cpp
//  NutRock_Demo
//
//  Created by mac on 13-11-26.
//
//

#include "DemoLayer.h"
#include "ListViewLayer.h"
#include "GeneralDialogTest.h"

void TableViewContactDemoScene::runThisTest()
{
    
    CCLayer * pLayer = new ListViewLayer();
    addChild(pLayer);
    pLayer->release();
    
    CCDirector::sharedDirector()->replaceScene(this);
}

void GeneralDialogScene::runThisTest()
{
   
    CCLayer* pLayer = GeneralDialogTest::create();
    pLayer->setPosition(ccp(0, 0));

    pLayer->setContentSize(CCSizeMake(640, 960));
    addChild(pLayer);
    //pLayer->release();
    CCDirector::sharedDirector()->replaceScene(this);
    
}