//
//  GeneralDialogScene.cpp
//  Winterfell_Test
//
//  Created by 史晋鹏 on 14-4-2.
//
//

#include "DialogContentLayer.h"
#include "DialogLayer.h"

USING_NS_CC;
USING_NS_CC_EXT;



CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();


GeneralLayer::GeneralLayer(CCLayer* node)
{
    layer = node;
    
    CCAction* popup = CCSequence::create(
                                              CCScaleTo::create(0.06, 0.7),
                                              
                                              CCScaleTo::create(0.08, 0.95),
                                              
                                              CCScaleTo::create(0.08, 0.9),
                                              
                                              NULL);
    layer->runAction(popup);
    layer->setPosition(ccp(0, (960-374)/2));
    addChild(layer);

    //正常状态按钮
    CCScale9Sprite *backgroundButton = CCScale9Sprite::create("button.png");
    //按下效果
    CCScale9Sprite *backgroundHighlightedButton = CCScale9Sprite::create("buttonHighlighted.png");
    //按钮的大小根据标题变化
    CCLabelTTF *titleButton = CCLabelTTF::create("Touch Me!", "Marker Felt", 30);
    //按钮颜色
    titleButton->setColor(ccc3(159, 168, 176));
    
    CCControlButton* controlButton = CCControlButton::create(titleButton, backgroundButton);
    controlButton->setBackgroundSpriteForState(backgroundHighlightedButton, CCControlStateHighlighted);
    controlButton->setTitleColorForState(ccWHITE, CCControlStateHighlighted);
    
    //        controlButton->setAnchorPoint(ccp(0.5f, 1));
    controlButton->setPosition(ccp(640/2, 80));
    addChild(controlButton);
    /* 当鼠标处于按下并曾经点中按钮的状态下，鼠标松开且在按钮范围内，则触发一次 */
    controlButton->addTargetWithActionForControlEvents(this, cccontrol_selector(GeneralLayer::touchUpInside), CCControlEventTouchUpInside);

}

GeneralLayer::~GeneralLayer()
{
    
}

void GeneralLayer::touchUpInside(CCObject* pSender, CCControlEvent event)
{
    CCCallFunc* pCallback = CCCallFunc::create(this, callfunc_selector(GeneralLayer::stopAction));
    CCAction* popupLayer = CCSequence::create(
                                              CCScaleTo::create(0.08, 0.9),
                                              
                                              CCScaleTo::create(0.08, 0.95),
                                              
                                              CCScaleTo::create(0.06, 0.7),
                                              pCallback,
                                              NULL);
    layer->runAction(popupLayer);
}

void GeneralLayer::stopAction()
{
    removeFromParentAndCleanup(true);
}

void GeneralLayer::closeLayer()
{
    removeFromParentAndCleanup(true);
}
