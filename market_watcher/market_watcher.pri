COMMON_FOLDER = $$LAZZYQUANT_ROOT/common
MARKET_WATCHER_FOLDER = $$LAZZYQUANT_ROOT/market_watcher

SOURCES *= \
    $$COMMON_FOLDER/market.cpp \
    $$COMMON_FOLDER/common_utility.cpp \
    $$COMMON_FOLDER/multiple_timer.cpp \
    $$COMMON_FOLDER/trading_calendar.cpp \
    $$COMMON_FOLDER/time_mapper.cpp \
    $$MARKET_WATCHER_FOLDER/market_watcher.cpp \
    $$MARKET_WATCHER_FOLDER/tick_receiver.cpp

HEADERS *= \
    $$COMMON_FOLDER/market.h \
    $$COMMON_FOLDER/common_utility.h \
    $$COMMON_FOLDER/multiple_timer.h \
    $$COMMON_FOLDER/trading_calendar.h \
    $$COMMON_FOLDER/time_mapper.h \
    $$MARKET_WATCHER_FOLDER/market_watcher.h \
    $$MARKET_WATCHER_FOLDER/tick_receiver.h

INCLUDEPATH *= \
    $$COMMON_FOLDER \
    $$MARKET_WATCHER_FOLDER
