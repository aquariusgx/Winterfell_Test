//
//  GeneralDialog.cpp
//  Winterfell_Test
//
//  Created by 史晋鹏 on 14-4-2.
//
//

#include "DialogContentLayer.h"
#include "DialogLayer.h"

DialogLayer::~DialogLayer()
{
    CC_SAFE_RELEASE(title);
    CC_SAFE_RELEASE(content);
    CC_SAFE_RELEASE(procssVar);
    CC_SAFE_RELEASE(BackGround);
}

//Menu响应事件绑定
SEL_MenuHandler DialogLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
    //绑定响应事件
    //CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onPressButton", HelloCocosBuilder::onPressButton);
    return NULL;
}

//按钮响应事件绑定
SEL_CCControlHandler DialogLayer::onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName)
{
//    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "getAwardBtnClicked", GeneralDialog::getAwardBtnClicked);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onCloseClick", DialogLayer::closeBtn);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onOk", DialogLayer::okBtn);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onCancel", DialogLayer::cancelBtn);
    return NULL;
}

//绑定变量
bool DialogLayer::onAssignCCBMemberVariable(CCObject * pTarget, const char* pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "Title", CCLabelTTF*, title);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "content", CCLabelTTF*, content);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "procssVar", CCSprite*, procssVar);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "BackGround", CCSprite*, BackGround);
    return NULL;
}

//场景加载完成后处理函数
void DialogLayer::onNodeLoaded(CCNode* pNode, CCNodeLoader* pNodeLoader)
{
    CCLOG("GeneralDialog::onNodeLoaded");
    pProgressTimer = CCProgressTimer::create(procssVar);
   
    pProgressTimer->setType(kCCProgressTimerTypeBar);
    //原点位置
    pProgressTimer->setMidpoint(ccp(0,0));
    //从右往左减少
    pProgressTimer->setBarChangeRate(ccp(1, 0));
    pProgressTimer->setPercentage(60);
    pProgressTimer->setPosition(288, 144);
    BackGround->addChild(pProgressTimer);
}

void DialogLayer::closeBtn(CCObject* obj)
{
    CCLOG("GeneralDialog::closeBtn");
    CCCallFunc* pCallback = CCCallFunc::create(this, callfunc_selector(DialogLayer::stopAction));
    CCAction* popupLayer = CCSequence::create(
                                              CCScaleTo::create(0.08, 0.9),
                                              
                                              CCScaleTo::create(0.08, 0.95),
                                              
                                              CCScaleTo::create(0.06, 0.7),
                                              pCallback,
                                              NULL);
    runAction(popupLayer);
}

void DialogLayer::stopAction()
{
    GeneralLayer* layer =  (GeneralLayer*)getParent();
    layer->closeLayer();
}

void DialogLayer::okBtn(CCObject* obj)
{
    CCLOG("GeneralDialog::okBtn");
    content->setString("okBtn");
    if (pProgressTimer->getPercentage() <= 100)
    {
        pProgressTimer->setPercentage(pProgressTimer->getPercentage()+5);
    }
}

void DialogLayer::cancelBtn(CCObject* obj)
{
    CCLOG("GeneralDialog::cancelBtn");
    content->setString("cencalBtn");
    if (pProgressTimer->getPercentage() > 0)
    {
        pProgressTimer->setPercentage(pProgressTimer->getPercentage()-5);
    }
}
