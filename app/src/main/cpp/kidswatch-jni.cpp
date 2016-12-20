//
// Created by tao.j on 2016/12/19.
//
#include <jni.h>
#include <string.h>
#include "kidswatch-jni.h"

jstring StringFromJNI(JNIEnv *env, jobject object){
    char hello[] = "Hello, Kids Watch!";
    return env->NewStringUTF(hello);
}
static void Login(JNIEnv *env, jobject object, jstring imei);


const static char *ClassPathName =
        "com/kwp/KidsWatchLib";


static JNINativeMethod nativeMethods[] = {
        {"getStringFromJNI", "()Ljava/lang/String;", (void*) StringFromJNI},
        {"login", "(Ljava/lang/String;)V", (void*) Login}
};

static void Login(JNIEnv *env, jobject object, jstring imei){
    const char *imeiChars = env->GetStringUTFChars(imei, JNI_FALSE);
    LOGD("Login, imei:%s", imeiChars);
    jclass clazz = env->GetObjectClass(object);
    jmethodID  jmethodID2 = env->GetMethodID(clazz, "loginCallback", "(I)V");
    env->CallVoidMethod(object, jmethodID2, 100);
}

static int RegisterNativeMethods(JNIEnv *env, const char *className,
                                 JNINativeMethod *gMethods, int numMethods) {
    LOGD("RegisterNativeMethods");
    jclass clazz;
    clazz = env->FindClass(className);
    if (clazz == NULL) {
        LOGE("Native registration unable to find class '%s'", className);
        return JNI_FALSE;
    }

    if (env->RegisterNatives(clazz, gMethods, numMethods) < 0) {
        LOGE("RegisterNatives failed for '%s'", className);
        return JNI_FALSE;
    }

    jmethodID methodID = env->GetStaticMethodID(clazz, "getStringFromJava", "(IZLjava/lang/String;[B)Ljava/lang/String;");
    jstring hello = env->NewStringUTF("hello");
    jbyteArray data = env->NewByteArray(8);

    jbyte jbyte1[8];
    jbyte1[0] = 1;
    jbyte1[1] = 12;
    jbyte1[2] = 2;
    jbyte1[3] = 3;
    jbyte1[4] = 4;
    jbyte1[5] = 5;
    jbyte1[6] = 36;
    jbyte1[7] = 37;

    env->SetByteArrayRegion(data, 0, 8, jbyte1);
    jstring object = (jstring) env->CallStaticObjectMethod(clazz, methodID, 23, false, hello, data);
    const char *chars = env->GetStringUTFChars(object, JNI_FALSE);
    LOGD("RegisterNatives '%s'", chars);

    return JNI_TRUE;
}


jint JNI_OnLoad(JavaVM* vm, void* reserved) {
        LOGD("JNI_OnLoad");
        JNIEnv* env;
        if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
            LOGE("Error: GetEnv failed in JNI_OnLoad");
            return JNI_ERR;
        }
        if (!RegisterNativeMethods(env, ClassPathName, nativeMethods,
                                   sizeof(nativeMethods) / sizeof(nativeMethods[0]))) {
            LOGE("Error: could not register native methods");
            return JNI_ERR;
        }

        return JNI_VERSION_1_6;
}