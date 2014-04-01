//
//  DemoScene.cpp
//  NutRock_Demo
//
//  Created by guxin on 11/19/13.
//
//

#include "DemoScene.h"
#include "DemoController.h"
#include "VisibleRect.h"

DemoScene::DemoScene(bool bPortrait)
{
    
    CCScene::init();
}

void DemoScene::onEnter() {
    CCScene::onEnter();
    CCLabelTTF* label = CCLabelTTF::create("MainMenu", "Arial", 20);
    CCMenuItemLabel* pMenuItem = CCMenuItemLabel::create(label, this, menu_selector(DemoScene::MainMenuCallback));
    
    CCMenu* pMenu =CCMenu::create(pMenuItem, NULL);
    
    pMenu->setPosition( CCPointZero );
    pMenuItem->setPosition(ccp( VisibleRect::right().x - 50, VisibleRect::bottom().y + 25));
    
    addChild(pMenu, 1);
}

void DemoScene::MainMenuCallback(CCObject* pSender) {
    CCScene* pScene = CCScene::create();
    CCLayer* pLayer = new DemoController();
    pLayer->autorelease();
    
    pScene->addChild(pLayer);
    CCDirector::sharedDirector()->replaceScene(pScene);
}