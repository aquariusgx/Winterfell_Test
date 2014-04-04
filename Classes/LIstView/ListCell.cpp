//
//  AchievementCell.cpp
//  Winterfell_Test
//
//  Created by 史晋鹏 on 14-4-1.
//
//

#include "ListCell.h"
#include "Demos.h"

bool ListCell::init()
{
    return true;
}

ListCell::~ListCell()
{
    CC_SAFE_RELEASE(Num);
    CC_SAFE_RELEASE(content);
}

//Menu响应事件绑定
SEL_MenuHandler ListCell::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
    //绑定响应事件
    //CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onPressButton", HelloCocosBuilder::onPressButton);
    return NULL;
}

//按钮响应事件绑定
SEL_CCControlHandler ListCell::onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "getAwardBtnClicked", ListCell::getAwardBtnClicked);
    return NULL;
}

//绑定变量
bool ListCell::onAssignCCBMemberVariable(CCObject * pTarget, const char* pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "content", CCLabelTTF*, content);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "Num", CCLabelTTF*, Num);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "cellBackGround", CCSprite*, cellBackGround);
    
    return NULL;
}

//场景加载完成后处理函数
void ListCell::onNodeLoaded(CCNode* pNode, CCNodeLoader* pNodeLoader)
{
    CCLOG("ListView::onNodeLoaded");
    Num->setTag(5);
    content->setTag(4);
    cellBackGround->setTag(1);
}

void ListCell::getAwardBtnClicked(CCObject* obj)
{
    CCLOG("ListView::getAwardBtnClicked");
    m_data[getTag()] = "点击改变";
    content->setString(m_data[getTag()].c_str());
    for (int i = 0; i < sizeof(m_data) / sizeof(std::string); i++)
    {
        CCLOG("m_data[i] = %s  ", m_data[i].c_str() );
    }
    CCLOG("cell tag：%d",getTag());
}

