//
//  AchievementCell.cpp
//  Winterfell_Test
//
//  Created by 史晋鹏 on 14-4-1.
//
//

#include "ListView.h"

bool ListView::init()
{
    return true;
}

ListView::~ListView()
{
    CC_SAFE_RELEASE(cellBackGround);
    CC_SAFE_RELEASE(titleLabel);
    CC_SAFE_RELEASE(ttf);
    CC_SAFE_RELEASE(getAwardBtn);
}

//Menu响应事件绑定
SEL_MenuHandler ListView::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
    //绑定响应事件
    //CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onPressButton", HelloCocosBuilder::onPressButton);
    return NULL;
}

//按钮响应事件绑定
SEL_CCControlHandler ListView::onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "getAwardBtnClicked", ListView::getAwardBtnClicked);
    return NULL;
}

//绑定变量
bool ListView::onAssignCCBMemberVariable(CCObject * pTarget, const char* pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "cellBackGround", CCSprite*, cellBackGround);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "getAwardBtn", CCControlButton*, getAwardBtn);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "titleLabel", CCLabelBMFont*, titleLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "ttf", CCLabelTTF*, ttf);
    return NULL;
}

//场景加载完成后处理函数
void ListView::onNodeLoaded(CCNode* pNode, CCNodeLoader* pNodeLoader)
{
    
}

void ListView::getAwardBtnClicked(CCObject* obj)
{
    CCLOG("ListView::getAwardBtnClicked");
    this->ttf->setString("解锁成功");
}

