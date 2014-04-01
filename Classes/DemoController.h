//
//  DemoController.h
//  NutRock_Demo
//
//  Created by guxin on 11/19/13.
//
//

#ifndef __NutRock_Demo__DemoController__
#define __NutRock_Demo__DemoController__

#include "cocos2d.h"

USING_NS_CC;

class DemoController : public CCLayer
{
public:
    DemoController();
    ~DemoController();
    
    void menuCallback(CCObject * pSender);
    void closeCallback(CCObject * pSender);
    
//    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
//    virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
    
private:
    CCPoint m_tBeginPos;
    CCMenu* m_pItemMenu;
};

#endif /* defined(__NutRock_Demo__DemoController__) */
