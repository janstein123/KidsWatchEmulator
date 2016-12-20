package com.kwp;

import android.util.Log;

/**
 * Created by tao.j on 2016/12/15.
 */

public class KidsWatchLib {

    private static final String TAG = "KidsWatchLib";

    public static native String getStringFromJNI();

    public static String getStringFromJava(int a, boolean b, String s, byte[] data){
        Log.d(TAG, "getStringFromJava, a="+a+", b="+b+", s="+s);
        if (data != null){
            for (byte d: data){
                Log.d(TAG, "getStringFromJava, d="+d);
            }
        }
        return "Nice to meet you!";
    }

    public native void login(String imei);

    public void loginCallback(int result){
        Log.d(TAG, "loginCallback, result="+result);
    }

    static {
        System.loadLibrary("kidswatch-jni");
    }
}
