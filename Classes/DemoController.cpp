//
//  DemoController.cpp
//  NutRock_Demo
//
//  Created by guxin on 11/19/13.
//
//

#include "DemoController.h"
#include "Demos.h"
#include "DemoScene.h"
#include "VisibleRect.h"
#include "DemoLayer.h"

#define LINE_SPACE          40

static CCPoint s_tCurPos = CCPointZero;

static DemoScene* CreateDemoScene(int nIdx)
{
    CCDirector::sharedDirector()->purgeCachedData();
    
    DemoScene* pScene = NULL;
    
    switch (nIdx)
    {
        case DEMO_LIST:
            pScene = new TableViewContactDemoScene();
            break;
        case DEMO_DIALOG:
        {
            pScene = new GeneralDialogScene();
        }
            break;
        default:
            break;
    }
    
    return pScene;
}

DemoController::DemoController(): m_tBeginPos(CCPointZero)
{
    // add menu items for tests
    m_pItemMenu = CCMenu::create();
    for (int i = 0; i < TESTS_COUNT; ++i)
    {
        // #if (CC_TARGET_PLATFORM == CC_PLATFORM_MARMALADE)
        //         CCLabelBMFont* label = CCLabelBMFont::create(g_aTestNames[i].c_str(),  "fonts/arial16.fnt");
        // #else
        CCLabelTTF* label = CCLabelTTF::create(g_aTestNames[i].c_str(), "Arial", 24);
        // #endif
        CCMenuItemLabel* pMenuItem = CCMenuItemLabel::create(label, this, menu_selector(DemoController::menuCallback));
        
        m_pItemMenu->addChild(pMenuItem, i + 10000);
        pMenuItem->setPosition( ccp( VisibleRect::center().x, (VisibleRect::top().y - (i + 1) * LINE_SPACE) ));
    }
    
    m_pItemMenu->setContentSize(CCSizeMake(VisibleRect::getVisibleRect().size.width, (TESTS_COUNT + 1) * (LINE_SPACE)));
    m_pItemMenu->setPosition(s_tCurPos);
    addChild(m_pItemMenu);
    
    setTouchEnabled(true);
    
}

void DemoController::menuCallback(CCObject * pSender)
{
    // get the userdata, it's the index of the menu item clicked
    CCMenuItem* pMenuItem = (CCMenuItem *)(pSender);
    int nIdx = pMenuItem->getZOrder() - 10000;
    
    // create the test scene and run it
    DemoScene* pScene = CreateDemoScene(nIdx);
    CCLog("nidx = %d", nIdx);
    if (pScene)
    {
        pScene->runThisTest();
        pScene->release();
    }
}

DemoController::~DemoController()
{
}
