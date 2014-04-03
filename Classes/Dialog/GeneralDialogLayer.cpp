//
//  GeneralDialogScene.cpp
//  Winterfell_Test
//
//  Created by 史晋鹏 on 14-4-2.
//
//

#include "GeneralDialogLayer.h"
#include "GeneralDialog.h"

USING_NS_CC;
USING_NS_CC_EXT;




GeneralDialogLayer::GeneralDialogLayer()
{
    
    addChild(GeneralDialogLoader::createCell());
    
}

GeneralDialogLayer::~GeneralDialogLayer()
{
    
}

bool GeneralDialogLayer::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    CCLOG("ListViewLayer::ccTouchBegan");
    return true;
}

void GeneralDialogLayer::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
    CCLOG("ListViewLayer::ccTouchMoved");
}

void GeneralDialogLayer::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
    CCLOG("ListViewLayer::ccTouchEnded");
}

void GeneralDialogLayer::menuCallBack(CCObject* pSender)
{
    
}