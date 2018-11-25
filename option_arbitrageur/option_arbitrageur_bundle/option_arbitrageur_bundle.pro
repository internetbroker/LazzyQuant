QT += core xml concurrent
QT -= gui

TARGET = option_arbitrageur
CONFIG += console c++14
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    ../../common/common_utility.cpp \
    ../../common/multiple_timer.cpp \
    ../../common/connection_manager.cpp \
    ../../common/trading_calendar.cpp \
    ../../common/message_handler.cpp \
    ../../market_watcher/market_watcher.cpp \
    ../../market_watcher/tick_receiver.cpp \
    ../../trade_executer/ctp_executer.cpp \
    ../../trade_executer/trade_handler.cpp \
    ../../trade_executer/order.cpp \
    ../option_arbitrageur.cpp \
    ../option_pricing.cpp \
    ../option_helper.cpp \
    ../high_frequency.cpp \
    ../risk_free.cpp \
    ../depth_market.cpp \
    ../base_strategy.cpp \
    ../option_index.cpp

HEADERS += ../../config.h \
    ../../common/common_utility.h \
    ../../common/multiple_timer.h \
    ../../common/connection_manager.h \
    ../../common/trading_calendar.h \
    ../../common/message_handler.h \
    ../../market_watcher/market_watcher.h \
    ../../market_watcher/tick_receiver.h \
    ../../trade_executer/ctp_executer.h \
    ../../trade_executer/trade_handler.h \
    ../../trade_executer/order.h \
    ../option_arbitrageur.h \
    ../option_pricing.h \
    ../option_helper.h \
    ../high_frequency.h \
    ../risk_free.h \
    ../depth_market.h \
    ../base_strategy.h \
    ../option_index.h

INCLUDEPATH += \
    ../ \
    ../../ \
    ../../common/ \
    ../../market_watcher/ \
    ../../sinyee_replayer/ \
    ../../trade_executer/

unix:CTP_FOLDER_PREFIX = linux
win32:CTP_FOLDER_PREFIX = win

contains(QT_ARCH, i386) {
    CTP_FOLDER_SUFFIX = 32
} else {
    CTP_FOLDER_SUFFIX = 64
}

HEADERS += \
    ../../ctp/$$CTP_FOLDER_PREFIX$$CTP_FOLDER_SUFFIX/ThostFtdcMdApi.h \
    ../../ctp/$$CTP_FOLDER_PREFIX$$CTP_FOLDER_SUFFIX/ThostFtdcTraderApi.h \
    ../../ctp/$$CTP_FOLDER_PREFIX$$CTP_FOLDER_SUFFIX/ThostFtdcUserApiDataType.h \
    ../../ctp/$$CTP_FOLDER_PREFIX$$CTP_FOLDER_SUFFIX/ThostFtdcUserApiStruct.h

INCLUDEPATH += ../../ctp/$$CTP_FOLDER_PREFIX$$CTP_FOLDER_SUFFIX/

unix:LIBS += \
    $$PWD/../../ctp/$$CTP_FOLDER_PREFIX$$CTP_FOLDER_SUFFIX/thostmduserapi.so \
    $$PWD/../../ctp/$$CTP_FOLDER_PREFIX$$CTP_FOLDER_SUFFIX/thosttraderapi.so

win32:LIBS += \
    $$PWD/../../ctp/$$CTP_FOLDER_PREFIX$$CTP_FOLDER_SUFFIX/thostmduserapi.lib \
    $$PWD/../../ctp/$$CTP_FOLDER_PREFIX$$CTP_FOLDER_SUFFIX/thosttraderapi.lib
