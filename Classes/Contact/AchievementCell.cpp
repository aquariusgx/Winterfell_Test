//
//  AchievementCell.cpp
//  Winterfell_Test
//
//  Created by 史晋鹏 on 14-4-1.
//
//

#include "AchievementCell.h"

bool AchievementCell::init()
{
    return true;
}

AchievementCell::~AchievementCell()
{
    CC_SAFE_RELEASE(cellBackGround);
    CC_SAFE_RELEASE(titleLabel);
    CC_SAFE_RELEASE(ttf);
    CC_SAFE_RELEASE(getAwardBtn);
}

//绑定按钮方式1
SEL_MenuHandler AchievementCell::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName) {
    //绑定响应事件
    //CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onPressButton", HelloCocosBuilder::onPressButton);
    return NULL;
}

//绑定按钮方式2
SEL_CCControlHandler AchievementCell::onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName) {
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "getAwardBtnClicked", AchievementCell::getAwardBtnClicked);
    return NULL;
}

//绑定变量
bool AchievementCell::onAssignCCBMemberVariable(CCObject * pTarget, const char* pMemberVariableName, CCNode * pNode) {
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "cellBackGround", CCSprite*, cellBackGround);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "getAwardBtn", CCControlButton*, getAwardBtn);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "titleLabel", CCLabelBMFont*, titleLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "ttf", CCLabelTTF*, ttf);
    return NULL;
}

void AchievementCell::onNodeLoaded(CCNode* pNode, CCNodeLoader* pNodeLoader)
{
    
}

void AchievementCell::getAwardBtnClicked(CCObject* obj)
{
    CCLOG("AchievementCell::getAwardBtnClicked");
}

