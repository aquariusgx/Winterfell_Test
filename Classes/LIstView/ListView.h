//
//  AchievementCell.h
//  Winterfell_Test
//
//  Created by 史晋鹏 on 14-4-1.
//
//

#ifndef __Winterfell_Test__AchievementCell__
#define __Winterfell_Test__AchievementCell__

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

class ListView :
public CCTableViewCell,
public CCBSelectorResolver,
public CCBMemberVariableAssigner,
public CCNodeLoaderListener
{
public:
    CREATE_FUNC(ListView);
    virtual ~ListView();
    
    bool init();
    //--TODO --  CCBMemberVariableAssigner
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);
    //--TODO --  CCBSelectorResolver
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    //--TODO --  CCNodeLoaderListener 当此场景加载完成后，如果需要做一些操作，则在此方法中添加
    void onNodeLoaded(CCNode* pNode, CCNodeLoader* pNodeLoader);
    
    CCSprite* cellBackGround;
    CCLabelBMFont* titleLabel;
    CCLabelTTF* ttf;
    CCControlButton* getAwardBtn;
    
    void getAwardBtnClicked(CCObject* obj);

};



class ListViewLoader : public CCNodeLoader //注意：CCTableViewCell这里是使用CCNodeLoader，不是CCLayerLoader
{
public:
    
    static CCNode* createCell() {
        CCNodeLoaderLibrary::sharedCCNodeLoaderLibrary()->registerCCNodeLoader("AchievementCell", ListViewLoader::loader());
        CCBReader* reader = new CCBReader(CCNodeLoaderLibrary::sharedCCNodeLoaderLibrary());
        CCNode * node = reader->readNodeGraphFromFile("achievementCell.ccbi");
        reader->release();
        return node;
    }
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ListViewLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(ListView);
};

#endif /* defined(__Winterfell_Test__AchievementCell__) */
