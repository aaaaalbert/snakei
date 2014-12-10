LOCAL_PATH := $(call my-dir)

PYTHONVER := 2.7
PYTHONLIB := ../$(LOCAL_PATH)/../python$(PYTHONVER)-libs
PYTHONLIBINC := $(LOCAL_PATH)/../python$(PYTHONVER)-libs


$(warning $(PYTHONLIB))
$(warning $(PYTHONLIBINC))

include $(CLEAR_VARS)

LOCAL_MODULE := python2.7
LOCAL_SRC_FILES := $(PYTHONLIB)/lib/libpython2.7.so
LOCAL_EXPORT_C_INCLUDES := $(PYTHONLIB)/include/

include $(PREBUILT_SHARED_LIBRARY)



include $(CLEAR_VARS)

LOCAL_C_INCLUDES := $(PYTHONLIBINC)/include/
COMPILED_LIBRARIES := python2.7

LOCAL_MODULE    := snakei
LOCAL_SRC_FILES := snakei.c
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../python2.7-libs/include/python2.7/
LOCAL_LDLIBS := -Lpython2.7-libs/lib #-lpython$(PYTHONVER) #-ldl -lz -lm -landroid -llog
# Use this instead of -lpython$(VER) in LOCAL_LDLIBS:
LOCAL_SHARED_LIBRARIES := libpython$(PYTHONVER)

include $(BUILD_SHARED_LIBRARY)

#$(call import-module,android/native_app_glue)
