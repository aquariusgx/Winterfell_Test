//
//  ListViewTest.cpp
//  Winterfell_Test
//
//  Created by 史晋鹏 on 14-4-4.
//
//

#include "GeneralDialogTest.h"
#include "DialogContentLayer.h"
#include "DialogLayer.h"

//USING_NS_CC;
USING_NS_CC_EXT;

GeneralDialogTest::GeneralDialogTest()
{

}

bool GeneralDialogTest::init()
{
    if (CCLayer::init())
    {
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
        controlButton->setPosition(ccp(640/2, 960/5));
        addChild(controlButton);
        /* 当鼠标处于按下并曾经点中按钮的状态下，鼠标松开且在按钮范围内，则触发一次 */
        controlButton->addTargetWithActionForControlEvents(this, cccontrol_selector(GeneralDialogTest::touchUpInside), CCControlEventTouchUpInside);
        return true;
    }
    return false;
}

GeneralDialogTest::~GeneralDialogTest()
{
    
    
}
void GeneralDialogTest::touchUpInside(CCObject* pSender, CCControlEvent event)
{
    CCLOG("GeneralDialogTest::touchUpInside");
    CCLayer* layer = new GeneralLayer((CCLayer*)DialogLayerLoader::createCell());
    layer->setPosition(ccp(0, 0));
    addChild(layer);
}

