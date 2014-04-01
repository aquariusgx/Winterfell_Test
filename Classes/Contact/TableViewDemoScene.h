//
//  ContactDemoScene.h
//  NutRock_Demo
//
//  Created by mac on 13-11-26.
//
//

#ifndef __NutRock_Demo__ContactDemoScene__
#define __NutRock_Demo__ContactDemoScene__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "DemoScene.h"

USING_NS_CC;

class TableViewContactDemoScene : public DemoScene
{
public:
    virtual void runThisTest();
};

class ListViewLayer :
public CCLayer,
public extension::CCTableViewDataSource,
public extension::CCTableViewDelegate
{
public:
    ListViewLayer();
    
    ~ListViewLayer();
    
    //virtual bool init();
    
    virtual void scrollViewDidScroll(cocos2d::extension::CCScrollView* view);
    
    virtual void scrollViewDidZoom(cocos2d::extension::CCScrollView* view);
    
    //处理触摸事件，可以计算点击的是哪一个子项
    virtual void tableCellTouched(cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell);
    //每一项的宽度和高度
    virtual cocos2d::CCSize cellSizeForTable(cocos2d::extension::CCTableView *table);
    //生成列表每一项的内容
    virtual cocos2d::extension::CCTableViewCell* tableCellAtIndex(cocos2d::extension::CCTableView *table, unsigned int idx);
    //一共多少项
    virtual unsigned int numberOfCellsInTableView(cocos2d::extension::CCTableView *table);
    
    //CREATE_FUNC(ListViewLayer);
    
    void menuCallBack(CCObject* pSender);
    
    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
    virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
    virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);
private:
    bool m_bTable;
    bool m_bSlider;
};

#endif /* defined(__NutRock_Demo__ContactDemoScene__) */
