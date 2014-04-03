//
//  ListView.cpp
//  Winterfell_Test
//
//  Created by 史晋鹏 on 14-4-3.
//
//

#include "ListViewLayer.h"
#include "ListView.h"

//listView个数
int tabNum = 10;

ListViewLayer::ListViewLayer()
{
    CCTableView* pTableView = CCTableView::create(this, CCSizeMake(800, 500));
    pTableView->setDirection(kCCScrollViewDirectionVertical);
    pTableView->setPosition(ccp(60,300));
    pTableView->setDelegate(this);
    pTableView->setTag(10000);
    pTableView->setVerticalFillOrder(kCCTableViewFillTopDown);
    this->addChild(pTableView);
    pTableView->reloadData();
}

ListViewLayer::~ListViewLayer()
{
    
}

/*
 bool ListViewLayer::init()
 {
 bool bRet = false;
 do
 {
 CC_BREAK_IF( !CCLayer::init() );
 
 CCTableView* pTableView = CCTableView::create(this, CCSizeMake(800, 500));
 pTableView->setDirection(kCCScrollViewDirectionVertical);
 pTableView->setPosition(ccp(60,300));
 pTableView->setDelegate(this);
 pTableView->setTag(10000);
 pTableView->setVerticalFillOrder(kCCTableViewFillTopDown);
 this->addChild(pTableView);
 pTableView->reloadData();
 
 bRet = true;
 }while(0);
 
 return bRet;
 }
 */

void ListViewLayer::tableCellTouched(CCTableView* table, CCTableViewCell* cell)
{
    CCLog("cell touched at index: %i", cell->getIdx());
}

CCSize ListViewLayer::cellSizeForTable(CCTableView *table)
{
    return CCSizeMake(548, 116);
}

CCTableViewCell* ListViewLayer::tableCellAtIndex(CCTableView *table, unsigned int idx)
{
//    CCString *pString = CCString::createWithFormat("%d", idx);
    
    CCTableViewCell *pCell = table->dequeueCell();
    if (!pCell) {
        
        pCell = (CCTableViewCell*)ListViewLoader::createCell();
        pCell->setTag(idx);
        /*
         pCell = new CCTableViewCell();
         pCell->autorelease();
         CCSprite *pSprite = CCSprite::create("achi_cell_bg.png");
         pSprite->setAnchorPoint(CCPointZero);
         pSprite->setPosition(CCPointZero);
         pCell->addChild(pSprite);
         
         CCLabelTTF *pLabel = CCLabelTTF::create(pString->getCString(), "Arial", 20);
         pLabel->setPosition(ccp(20, 30));
         pLabel->setAnchorPoint(CCPointZero);
         pLabel->setColor(ccc3(0, 0, 0));
         pLabel->setTag(123);
         pCell->addChild(pLabel);
         
         CCSprite *sprite = CCSprite::create("image/奖杯.png");
         sprite->setPosition(ccp(80, 30));
         sprite->setAnchorPoint(CCPointZero);
         pCell->addChild(sprite);
         
         CCMenuItemImage *itemImage = CCMenuItemImage::create("image/按钮_宠物_up.png", "image/按钮_宠物_down.png", this, menu_selector(ListViewLayer::menuCallBack));
         CCMenu *menu = CCMenu::create(itemImage,NULL);
         
         //注意CCMenu是无法修改锚点的，其默认位置是在其几何中心
         menu->setPosition(ccp(300,60));
         
         //可以通过修改CCMenuItemImage的锚点的位置
         //        itemImage->setAnchorPoint(CCPointZero);
         //        menu->setPosition(ccp(180,6));
         
         pCell->addChild(menu, 2);
         */
    }
    else
    {
        //pCell->setTag(idx);
        //pCell->removeChildByTag(idx);//这个地方的RemoveAllChildren很重要，一定要记得remove，不认就会导致列表下标和显示重复混乱（没测试过）
        /*
         CCLabelTTF *pLabel = (CCLabelTTF*)pCell->getChildByTag(123);
         pLabel->setString(pString->getCString());
         */
    }
    
    return pCell;
}

unsigned int ListViewLayer::numberOfCellsInTableView(CCTableView *table)
{
    return tabNum;
}

void ListViewLayer::scrollViewDidScroll(CCScrollView *view)
{
    CCLOG("ListViewLayer::scrollViewDidScroll");
    if (true)
    {
        CCTableView *tableView = (CCTableView *)getChildByTag(10000);
        if (tableView)
        {
            //CCLOG("%f", tableView->getContentOffset().y);
            if(tableView->getContentOffset().y >10 )
            {
                //if (tabNum > 5)
                {
                    //tableView->removeAllChildren();
                    tabNum = 30;
                    
                    tableView->reloadData();
                }
            }
        }
    }
    
}

void ListViewLayer::scrollViewDidZoom(CCScrollView *view)
{
    CCLOG("ListViewLayer::scrollViewDidZoom");
}

bool ListViewLayer::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    CCLOG("ListViewLayer::ccTouchBegan");
    return true;
}

void ListViewLayer::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
    CCLOG("ListViewLayer::ccTouchMoved");
}

void ListViewLayer::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
    CCLOG("ListViewLayer::ccTouchEnded");
}

void ListViewLayer::menuCallBack(CCObject* pSender)
{
    
}