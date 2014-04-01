//
//  VisibleRect.h
//  NutRock_Demo
//
//  Created by guxin on 11/20/13.
//
//

#ifndef __NutRock_Demo__VisibleRect__
#define __NutRock_Demo__VisibleRect__

#include "cocos2d.h"
USING_NS_CC;

class VisibleRect
{
public:
    static CCRect getVisibleRect();
    
    static CCPoint left();
    static CCPoint right();
    static CCPoint top();
    static CCPoint bottom();
    static CCPoint center();
    static CCPoint leftTop();
    static CCPoint rightTop();
    static CCPoint leftBottom();
    static CCPoint rightBottom();
private:
    static void lazyInit();
    static CCRect s_visibleRect;
};

#endif /* defined(__NutRock_Demo__VisibleRect__) */
