TICK_REPLAYER_FOLDER = $$LAZZYQUANT_ROOT/tick_replayer

SOURCES *= \
    $$TICK_REPLAYER_FOLDER/tick_replayer.cpp

HEADERS *= \
    $$TICK_REPLAYER_FOLDER/common_tick.h \
    $$TICK_REPLAYER_FOLDER/tick_replayer.h

INCLUDEPATH *= $$TICK_REPLAYER_FOLDER
