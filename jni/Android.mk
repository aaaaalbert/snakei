LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := snakei
LOCAL_SRC_FILES := snakei.c

include $(BUILD_SHARED_LIBRARY)

