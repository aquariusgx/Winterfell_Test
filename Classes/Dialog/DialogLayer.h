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
USING_NS_CC_EXT;

class GeneralLayer :
public CCLayer
{
public:
    GeneralLayer(CCLayer* layer);
    
    ~GeneralLayer();
    void closeLayer();

private:
    CCLayer* layer;
private:
    void closeOr(CCObject* pSender);
    void stopAction();
    //按钮响应事件
    void touchUpInside(CCObject* pSender, CCControlEvent event);
};

#endif /* defined(__Winterfell_Test__GeneralDialogScene__) */
