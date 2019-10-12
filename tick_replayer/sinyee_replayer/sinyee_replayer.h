#ifndef SINYEE_REPLAYER_H
#define SINYEE_REPLAYER_H

#include "time_mapper.h"
#include "tick_replayer.h"

struct CONFIG_ITEM;

class SinYeeReplayer : public TickReplayer
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.lazzyquant.tick_replayer")

    QString sinYeeDataPath;

public:
    explicit SinYeeReplayer(const CONFIG_ITEM &config, QObject *parent = nullptr);

protected:
    void appendTicksToList(const QString &date, const QString &instrument) override;

};

#endif // SINYEE_REPLAYER_H
