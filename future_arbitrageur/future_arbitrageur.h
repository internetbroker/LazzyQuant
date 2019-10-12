#ifndef FUTURE_ARBITRAGEUR_H
#define FUTURE_ARBITRAGEUR_H

#include <QObject>

class DepthMarketCollection;
class BaseStrategy;

class FutureArbitrageur : public QObject
{
    Q_OBJECT
public:
    explicit FutureArbitrageur(QObject *parent = nullptr);
    ~FutureArbitrageur();

    void setupStrategies();

    DepthMarketCollection *pMarketCollection;
    QList<BaseStrategy *> pStrategyList;

public slots:
    void setTradingDay(const QString &tradingDay);
    void onMarketData(const QString &instrumentID, qint64 time, double lastPrice, int volume,
                      double askPrice1, int askVolume1, double bidPrice1, int bidVolume1);
    void onMarketClose();

};

#endif // FUTURE_ARBITRAGEUR_H
