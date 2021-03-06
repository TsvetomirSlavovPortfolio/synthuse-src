/*
 * Copyright 2014, Synthuse.org
 * Released under the Apache Version 2.0 License.
 *
 * last modified by ejakubowski7@gmail.com
*/

#include "stdafx.h"
#include "org_synthuse_MsgHook.h"

/*
 * Class:     org_synthuse_MsgHook
 * Method:    initialize
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_synthuse_MsgHook_initialize(JNIEnv *env, jobject obj, jstring jdll32bitname, jstring jdll64bitname)
{
	const char *tdll32bitname = env->GetStringUTFChars(jdll32bitname, 0);//convert string
	
	memset((void *)&dll32bitName, '\0', sizeof(TCHAR) * MAX_TEST_SIZE); // set TCHAR array to all 0
	int tstrLen = MultiByteToWideChar(CP_UTF8, 0, tdll32bitname, (int)strlen(tdll32bitname), NULL, 0); //get t len
	MultiByteToWideChar(CP_UTF8, 0, tdll32bitname, (int)strlen(tdll32bitname), dll32bitName, tstrLen); // convert char to tchar

	env->ReleaseStringUTFChars(jdll32bitname, tdll32bitname); //release string

	const char *tdll64bitname = env->GetStringUTFChars(jdll64bitname, 0);//convert string
	
	memset((void *)&dll64bitName, '\0', sizeof(TCHAR) * MAX_TEST_SIZE); // set TCHAR array to all 0
	tstrLen = MultiByteToWideChar(CP_UTF8, 0, tdll64bitname, (int)strlen(tdll64bitname), NULL, 0); //get t len
	MultiByteToWideChar(CP_UTF8, 0, tdll64bitname, (int)strlen(tdll64bitname), dll64bitName, tstrLen); // convert char to tchar

	env->ReleaseStringUTFChars(jdll64bitname, tdll64bitname); //release string
	return true;
}

/*
 * Class:     org_synthuse_MsgHook
 * Method:    createMsgHookWindow
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_org_synthuse_MsgHook_createMsgHookWindow(JNIEnv *env, jobject obj)
{
	CreateMsgHookWindow(NULL);
	return true;
}

/*
 * Class:     org_synthuse_MsgHook
 * Method:    setMsgHookWindowTargetHwnd
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_synthuse_MsgHook_setMsgHookWindowTargetHwnd(JNIEnv *env, jobject obj, jint jhwnd)
{
	_stprintf_s(targetHwndStr, _T("%ld"), (long)jhwnd);
	return true;
}

/*
 * Class:     org_synthuse_MsgHook
 * Method:    setMsgHookWindowTargetClass
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_synthuse_MsgHook_setMsgHookWindowTargetClass(JNIEnv *env, jobject obj, jstring jclassname)
{
	const char *classname = env->GetStringUTFChars(jclassname, 0);//convert string
	
	memset((void *)&targetClassname, '\0', sizeof(TCHAR) * MAX_TEST_SIZE); // set TCHAR array to all 0
	int tstrLen = MultiByteToWideChar(CP_UTF8, 0, classname, (int)strlen(classname), NULL, 0); //get t len
	MultiByteToWideChar(CP_UTF8, 0, classname, (int)strlen(classname), targetClassname, tstrLen); // convert char to tchar

	env->ReleaseStringUTFChars(jclassname, classname); //release string
	return true;
}

JNIEXPORT jboolean JNICALL Java_org_synthuse_MsgHook_setMsgHookWindowTargetPid(JNIEnv *env, jobject obj, jint jpid)
{
	_stprintf_s(targetProcessId, _T("%ld"), (long)jpid);
	return true;
}

/*
 * Class:     org_synthuse_MsgHook
 * Method:    setMessageHook
 * Signature: (JJ)Z
 */
//JNIEXPORT jboolean JNICALL Java_org_synthuse_MsgHook_setMessageHook(JNIEnv *env, jobject obj, jlong jhWnd, jlong jthreadId)
JNIEXPORT jboolean JNICALL Java_org_synthuse_MsgHook_setMessageHook(JNIEnv *env, jobject obj, jint jhWnd, jint jthreadId)
{
	return SetMsgHook((HWND)jhWnd, (DWORD)jthreadId);
}

/*
 * Class:     org_synthuse_MsgHook
 * Method:    removeMessageHook
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_org_synthuse_MsgHook_removeMessageHook(JNIEnv *env, jobject obj)
{
	return RemoveHook();
}