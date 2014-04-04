//
//  ListViewTest.h
//  Winterfell_Test
//
//  Created by 史晋鹏 on 14-4-4.
//
//

#ifndef __Winterfell_Test__ListViewTest__
#define __Winterfell_Test__ListViewTest__

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC_EXT;

USING_NS_CC;


class GeneralDialogTest : public CCLayer
{
public:
    
    
    CREATE_FUNC(GeneralDialogTest);
    bool init();
    GeneralDialogTest();
    ~GeneralDialogTest();
    //    按下按钮事件回调
    void touchDownAction(CCObject * sender , CCControlEvent* controlEvent);
    //    按钮在其内部拾起事件回调
    void touchUpInsideAction(CCObject * sender , CCControlEvent*  controlEvent);
    //    按钮在其外部拾起事件回调
    void touchUpOutsideAction(CCObject * sender , CCControlEvent* controlEvent);
private:
    //按钮响应事件
    void touchUpInside(CCObject* pSender, CCControlEvent event);


};

#endif /* defined(__Winterfell_Test__ListViewTest__) */
