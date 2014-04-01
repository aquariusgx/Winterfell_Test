//
//  AndroidContactCallBack.cpp
//  NutRock
//
//  专供android回调
//
//  Created by mac on 13-11-22.
//
//

#include "AndroidContactCallBack.h"
#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#endif



extern "C" {

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
void Java_com_yotogame_nutrock_JniMsgHelper_contactCallbackTest(JNIEnv *env, jobject thiz) {
	CCLOG("contact 回调");
}
#endif

}
