//
//  ActionContent.cpp
//  Winterfell_Test
//
//  Created by 史晋鹏 on 14-4-4.
//
//

#include "ActionContent.h"


CCAction* ActionContent::popupAction()
{
    return CCSequence::create(
                                         CCScaleTo::create(0.06, 0.7),
                                         
                                         CCScaleTo::create(0.08, 0.95),
                                         
                                         CCScaleTo::create(0.08, 0.9),
                                         
                                         NULL);
}

CCAction* ActionContent::actionContent(ACTIONCONTENT index)
{
    switch(index)
    {
        case ACTION_POPUP:
            return popupAction();
            break;
        
    }
}
