//
//  GeneralDialogScene.h
//  Winterfell_Test
//
//  Created by 史晋鹏 on 14-4-2.
//
//

#ifndef __Winterfell_Test__GeneralDialogScene__
#define __Winterfell_Test__GeneralDialogScene__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;


class GeneralDialogLayer :
public CCLayer
{
public:
    GeneralDialogLayer();
    
    ~GeneralDialogLayer();
    
    void menuCallBack(CCObject* pSender);
    
    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
    virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
    virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);
};

#endif /* defined(__Winterfell_Test__GeneralDialogScene__) */
