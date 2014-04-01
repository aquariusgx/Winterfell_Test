//
//  LoginModel.h
//  NutRock
//
//  Created by mac on 13-11-18.
//
//

#ifndef __NutRock__LoginModel__
#define __NutRock__LoginModel__

#include "cocos2d.h"
USING_NS_CC;
#include "ContractToolPotocol.h"


class LoginModel : public CCObject,public ContractToolDelegate
{
public:
    bool init();
    static LoginModel* sharedLoginModel();
    
    void noteRequest(CCString* ownerNumber);
    int getNoteNo();
    int getOwnerNo();
    void contractsUpload();
    
    void UpLoadAvator(const char *path);
    
    int ccDeflateMemory(unsigned char *in, unsigned int inLength, unsigned char **out);
    
    //ContractToolDelegate的方法
    virtual void getContractSuccess(CCArray* arr);
    virtual void getContractFailed(ContractFailedCode errorCode);

    
private:
    static LoginModel* loginModel;
};

#endif /* defined(__NutRock__LoginModel__) */
