#ifndef BUTTERFLY_H
#define BUTTERFLY_H

#include "base_strategy.h"

class DepthMarket;

/*!
 * \brief 蝶式价差套利.
 */
class Butterfly : public BaseStrategy
{
public:
    Butterfly(const QString &strategyID, const QStringList &instruments, int maxPosition, int minPosition, double openThreshold, double closeThreshold, DepthMarketCollection *pDMC);
    ~Butterfly();

    void onInstrumentChanged(int idx);

protected:
    int firstIdx;       //!< 近月合约索引.
    int secondIdx;      //!< 中间月份合约索引.
    int thirdIdx;       //!< 远月合约索引.

    int maxPosition;
    int minPosition;

    double openThreshold;
    double closeThreshold;

    DepthMarket *first;
    DepthMarket *second;
    DepthMarket *third;

    void check010();    //!< 中间月份合约价格的两倍大于相邻近月合约价格与相邻远月合约价格之和.
    void check101();    //!< 中间月份合约价格的两倍小于相邻近月合约价格与相邻远月合约价格之和.
};

#endif // BUTTERFLY_H
