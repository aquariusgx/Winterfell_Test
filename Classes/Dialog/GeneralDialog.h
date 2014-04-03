//
//  GeneralDialog.h
//  Winterfell_Test
//
//  Created by 史晋鹏 on 14-4-2.
//
//

#ifndef __Winterfell_Test__GeneralDialog__
#define __Winterfell_Test__GeneralDialog__

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

class GeneralDialog :
public CCLayer,
public CCBSelectorResolver,
public CCBMemberVariableAssigner,
public CCNodeLoaderListener
{
public:
    CREATE_FUNC(GeneralDialog);
    
    virtual ~GeneralDialog();
    
    //--TODO --  CCBMemberVariableAssigner
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);
    //--TODO --  CCBSelectorResolver
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    
    void onNodeLoaded(CCNode* pNode, CCNodeLoader* pNodeLoader);
    //标题
    CCLabelTTF* title;
    //背景
    CCSprite* BackGround;
    //内容
    CCLabelTTF* content;
    //进度条图片
    CCSprite* procssVar;
    //进度条
    CCProgressTimer *pProgressTimer;
    
    void closeBtn(CCObject* obj);
    void okBtn(CCObject* obj);
    void cancelBtn(CCObject* obj);
    
};



class GeneralDialogLoader : public CCLayerLoader
{
public:
    static CCNode* createCell()
    {
        CCNodeLoaderLibrary::sharedCCNodeLoaderLibrary()->registerCCNodeLoader("GeneralDialog", GeneralDialogLoader::loader());
        CCBReader* reader = new CCBReader(CCNodeLoaderLibrary::sharedCCNodeLoaderLibrary());
        CCNode * node = reader->readNodeGraphFromFile("GeneralDialog.ccbi");
        reader->release();
        return node;
    }
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(GeneralDialogLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(GeneralDialog);
};


#endif /* defined(__Winterfell_Test__GeneralDialog__) */
