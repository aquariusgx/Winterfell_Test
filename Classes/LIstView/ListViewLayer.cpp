//
//  ListView.cpp
//  Winterfell_Test
//
//  Created by 史晋鹏 on 14-4-3.
//
//

#include "ListViewLayer.h"
#include "ListCell.h"
#include "Demos.h"

//listView个数
int tabNum = 20;

ListViewLayer::ListViewLayer()
{
    CCLOG("ListViewLayer::ListViewLayer");
    CCTableView* pTableView = CCTableView::create(this, CCSizeMake(800, 500));
    pTableView->setDirection(kCCScrollViewDirectionVertical);
    pTableView->setPosition(ccp(60,300));
    pTableView->setDelegate(this);
    pTableView->setTag(10000);
    pTableView->setVerticalFillOrder(kCCTableViewFillTopDown);
    this->addChild(pTableView);
    
    for (int i = 0; i < sizeof(m_data) / sizeof(std::string); i++)
    {
        m_data[i] = "解锁6只宠物";
    }

    CCControlSlider *slider = CCControlSlider::create("sliderTrack.png","sliderProgress.png" ,"sliderThumb.png");
    slider->setMinimumValue( -(116*tabNum-500) );   // 单个cell的高度 × cell的总数 - CCTableView的高度
    slider->setMaximumValue(0);
    slider->setPosition(ccp(600, 550));
    slider->setRotation(90);
    slider->setValue(-(116*tabNum-500));            // 默认为0
    slider->setTag(10001);
    addChild(slider);
    
    // 监听滑动条
    slider->addTargetWithActionForControlEvents(this, cccontrol_selector(ListViewLayer::valueChanged), CCControlEventValueChanged);
    pTableView->reloadData();
    
}

ListViewLayer::~ListViewLayer()
{
    
}



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
    CCLOG("ListViewLayer::tableCellAtIndex = %d", idx);

    if (!pCell) {
       
        pCell = (CCTableViewCell*)ListViewLoader::createCell();
        pCell->setTag(idx);
        CCSprite* sprite = (CCSprite*)pCell->getChildByTag(1);
        CCLabelTTF* text = (CCLabelTTF*) sprite->getChildByTag(5);
        CCString *pString = CCString::createWithFormat("%d", idx);
        text->setString(pString->getCString());
        CCLabelTTF* content = (CCLabelTTF*) sprite->getChildByTag(4);
        pString = CCString::createWithFormat("%s", m_data[idx].c_str());
        content->setString(pString->getCString());
        
//         pCell = new CCTableViewCell();
//         pCell->autorelease();
//         CCSprite *pSprite = CCSprite::create("achi_cell_bg.png");
//         pSprite->setAnchorPoint(CCPointZero);
//         pSprite->setPosition(CCPointZero);
//         pCell->addChild(pSprite);
//        
//        CCLabelTTF *pLabel = CCLabelTTF::create(pString->getCString(), "Arial", 20);
//        pLabel->setPosition(ccp(20, 30));
//        pLabel->setAnchorPoint(CCPointZero);
//        pLabel->setColor(ccc3(0, 0, 0));
//        pLabel->setTag(123);
//        pCell->addChild(pLabel);
        
//         CCSprite *sprite = CCSprite::create("image/奖杯.png");
//         sprite->setPosition(ccp(80, 30));
//         sprite->setAnchorPoint(CCPointZero);
//         pCell->addChild(sprite);
        
//         CCMenuItemImage *itemImage = CCMenuItemImage::create("image/按钮_宠物_up.png", "image/按钮_宠物_down.png", this, menu_selector(ListViewLayer::menuCallBack));
//         CCMenu *menu = CCMenu::create(itemImage,NULL);
//         
//         //注意CCMenu是无法修改锚点的，其默认位置是在其几何中心
//         menu->setPosition(ccp(300,60));
//         
//         //可以通过修改CCMenuItemImage的锚点的位置
//         //        itemImage->setAnchorPoint(CCPointZero);
//         //        menu->setPosition(ccp(180,6));
//         
//         pCell->addChild(menu, 2);
        
    }
    else
    {
        
        //pCell->removeChildByTag(idx);//这个地方的RemoveAllChildren很重要，一定要记得remove，不认就会导致列表下标和显示重复混乱（没测试过）
        pCell->setTag(idx);

        CCSprite* sprite = (CCSprite*)pCell->getChildByTag(1);
        
        CCLabelTTF* num = (CCLabelTTF*) sprite->getChildByTag(5);
        CCString *pString = CCString::createWithFormat("%d", idx);
        num->setString(pString->getCString());
        CCLabelTTF* content = (CCLabelTTF*) sprite->getChildByTag(4);
        pString = CCString::createWithFormat("%s", m_data[idx].c_str());
        content->setString(pString->getCString());
        
    }
    
    return pCell;
}

unsigned int ListViewLayer::numberOfCellsInTableView(CCTableView *table)
{
    return tabNum;
}

void ListViewLayer::scrollViewDidScroll(CCScrollView *view)
{
    //CCLOG("ListViewLayer::scrollViewDidScroll");
 
    CCTableView *tableView = (CCTableView *)getChildByTag(10000);
    if (tableView)
    {
        //CCLOG("%f", tableView->getContentOffset().x);
        if(tableView->getContentOffset().y >10 )
        {
            //if (tabNum > 5)
            {
//                //tableView->removeAllChildren();
//                CCLOG("tableView->getContentOffset().y = %f", tableView->getContentOffset().y);
//                
//                tabNum = 30;
//                tableView->reloadData();
//                tableView->setContentOffset(ccp(0, tableView->getContentOffset().y + 10*116));
        
                
            }
        }
        m_bSlider = false;
        if ( m_bTable  )
        {
            //CCTableView *tableView = (CCTableView *)getChildByTag(10000);
            CCControlSlider *slider = (CCControlSlider *)getChildByTag(10001);
            slider->setValue(tableView->getContentOffset().y);
        }
        m_bSlider = true;
    }
    
}

// 滑动条回调
void ListViewLayer::valueChanged( CCObject *sender, CCControlEvent controlEvent )
{
    m_bTable = false;
    if ( m_bSlider )
    {
        CCTableView *tableView = (CCTableView *)getChildByTag(10000);
        CCControlSlider *slider = (CCControlSlider *)getChildByTag(10001);
        tableView->setContentOffset(CCSizeMake(0, slider->getValue()));
    }
    m_bTable = true;
}

void ListViewLayer::scrollViewDidZoom(CCScrollView *view)
{
    CCLOG("ListViewLayer::scrollViewDidZoom");
}

