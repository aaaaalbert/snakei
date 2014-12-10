LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := snakei
LOCAL_SRC_FILES := snakei.c

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../python2.7-libs/include/python2.7/

include $(BUILD_SHARED_LIBRARY)

