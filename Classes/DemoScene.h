//
//  DemoScene.h
//  NutRock_Demo
//
//  Created by guxin on 11/19/13.
//
//

#ifndef __NutRock_Demo__DemoScene__
#define __NutRock_Demo__DemoScene__

#include "cocos2d.h"

USING_NS_CC;

class DemoScene : public CCScene
{
public:
    DemoScene(bool bPortrait = false);
    virtual void onEnter();
    virtual void runThisTest() = 0;
    virtual void MainMenuCallback(CCObject* pSender);
};

typedef CCLayer* (*NEWTESTFUNC)();

#define TESTLAYER_CREATE_FUNC(className) \
static CCLayer* create##className() \
{ return new className(); }

#define CF(className) create##className

#endif
