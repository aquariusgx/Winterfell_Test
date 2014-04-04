//
//  ActionContent.h
//  Winterfell_Test
//
//  Created by 史晋鹏 on 14-4-4.
//
//

#ifndef __Winterfell_Test__ActionContent__
#define __Winterfell_Test__ActionContent__

#include "cocos2d.h"

USING_NS_CC;


typedef enum
{
   ACTION_POPUP,
}ACTIONCONTENT;

class ActionContent
{
public:
    static CCAction* actionContent(ACTIONCONTENT index);
private:
    //弹出动作
    static CCAction* popupAction();
};

#endif /* defined(__Winterfell_Test__ActionContent__) */
