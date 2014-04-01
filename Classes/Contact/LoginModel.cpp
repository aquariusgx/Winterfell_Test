//
//  LoginModel.cpp
//  NutRock
//
//  Created by mac on 13-11-18.
//
//

#include "LoginModel.h"
#include <curl/curl.h>

#include <stdlib.h>
#include <time.h>

#include "cocos-ext.h"
USING_NS_CC_EXT;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#include <jni.h>
#include "platform/android/jni/JniHelper.h"

#else
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)



#endif
#endif

static int noteNo; //存储在本地的短信验证码
static CCString* ownerNoStr; //用户本人的电话号码

//单例模式
LoginModel* LoginModel::loginModel = NULL;
LoginModel* LoginModel::sharedLoginModel() {
	if (loginModel == NULL) {
		loginModel = new LoginModel();
		if (loginModel && loginModel->init()) {
			loginModel->autorelease();
		} else {
			CC_SAFE_DELETE(loginModel);
			loginModel = NULL;
		}
	}
	return loginModel;
}
bool LoginModel::init() {
	return true;
}

/**
 *  本地生成一个短信短信验证码，并发送给服务端
 *
 *  @param ownerNumber 接收短信验证码的手机号码
 */
void LoginModel::noteRequest(CCString* ownerNumber) {

	
}

/**
 *  返回原来生成好的四位正整数的短信验证码
 *
 *  @return 四位正整数的短信验证码
 */
int LoginModel::getNoteNo() {
	return noteNo;
}

/**
 *  请求上传通讯录
 */
void LoginModel::contractsUpload() {
    
}

/**
 *  通讯录获取失败
 *
 *  @param errorCode 失败识别号
 */
void LoginModel::getContractFailed(ContractFailedCode errorCode) {
	CCLOG("获取通讯录失败：%d", errorCode);
}
