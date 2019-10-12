unix:SUB_FOLDER_PREFIX = linux
win32:SUB_FOLDER_PREFIX = win

contains(QT_ARCH, i386) {
    SUB_FOLDER_SUFFIX = 32
} else {
    SUB_FOLDER_SUFFIX = 64
}

CTP_FOLDER = $$LAZZYQUANT_ROOT/ctp/$$SUB_FOLDER_PREFIX$$SUB_FOLDER_SUFFIX

INCLUDEPATH *= $$CTP_FOLDER

unix:LIBS += -L$$CTP_FOLDER -l:thostmduserapi_se.so
win32:LIBS += $$CTP_FOLDER/thostmduserapi_se.lib
