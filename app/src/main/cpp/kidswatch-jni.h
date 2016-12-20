/*
 * Copyright (C) 2013 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef KIDSWATCH_H
#define KIDSWATCH_H


#include <jni.h>
#include <string.h>
#include <android/log.h>

#define LOGV(msg...) __android_log_print(ANDROID_LOG_VERBOSE, "kidswatch-jni", msg)
#define LOGD(msg...) __android_log_print(ANDROID_LOG_DEBUG, "kidswatch-jni", msg)
#define LOGE(msg...) __android_log_print(ANDROID_LOG_ERROR, "kidswatch-jni", msg)
#define LOGW(msg...) __android_log_print(ANDROID_LOG_WARN, "kidswatch-jni", msg)

#endif // KIDSWATCH_H
