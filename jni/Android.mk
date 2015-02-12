LOCAL_PATH := $(call my-dir)

APP_PLATFORM := android-9

PYTHONVER := 2.7
PYTHONLIB := ../$(LOCAL_PATH)/../python$(PYTHONVER)-libs
PYTHONLIBINC := $(LOCAL_PATH)/../python$(PYTHONVER)-libs

include $(CLEAR_VARS)

LOCAL_MODULE := python2.7
LOCAL_SRC_FILES := $(PYTHONLIB)/lib/libpython2.7.so
LOCAL_EXPORT_C_INCLUDES := $(PYTHONLIB)/include/

include $(PREBUILT_SHARED_LIBRARY)



include $(CLEAR_VARS)

LOCAL_C_INCLUDES := $(PYTHONLIBINC)/include/

COMPILED_LIBRARIES := python2.7 #native_app_glue

LOCAL_MODULE    := snakei
LOCAL_SRC_FILES := snakei.c
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../python2.7-libs/include/python2.7/ $(LOCAL_PATH)/../../../devel/android-ndk-r10d/platforms/android-9/arch-arm/usr/include
LOCAL_LDLIBS := -Lpython2.7-libs/lib -llog #-lpython$(PYTHONVER) #-ldl -lz -lm -landroid -llog
# Use this instead of -lpython$(VER) in LOCAL_LDLIBS:
LOCAL_SHARED_LIBRARIES := libpython$(PYTHONVER)

#LOCAL_STATIC_LIBRARIES := android_native_app_glue

include $(BUILD_SHARED_LIBRARY)

$(call import-module,android/native_app_glue)

