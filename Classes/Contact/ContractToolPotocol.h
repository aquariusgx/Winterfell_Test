//
//  IosContractToolPotocol.h
//  NutRock
//
//  Created by mac on 13-11-20.
//
//

#ifndef NutRock_IosContractToolPotocol_h
#define NutRock_IosContractToolPotocol_h

#include "cocos2d.h"
USING_NS_CC;


typedef enum {
	ContractFailedCode_Denied, //用户设置拒绝访问通讯录
	ContractFailedCode_Restricted, //用户的通讯录设置为私密信息
	ContractFailedCode_NotDetermined, //用户还没设置通讯录的访问权限
	ContractFailedCode_Other     //其它原因
} ContractFailedCode;

class ContractToolDelegate
{
public:
    virtual void getContractSuccess(CCArray* arr) = 0; // c++ delegate记得要将virtual函数写个默认的实现，不然delegate就是纯虚类，编译的时候会找不到typeinfo
    virtual void getContractFailed(ContractFailedCode errorCode) = 0;
};


#endif
