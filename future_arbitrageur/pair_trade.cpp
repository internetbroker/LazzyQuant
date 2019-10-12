#include "depth_market.h"
#include "pair_trade.h"

#include <QDebug>

PairTrade::PairTrade(const QString &strategyID, const QStringList &instruments, int maxPosition, int minPosition, double openThreshold, double closeThreshold, DepthMarketCollection *pDMC) :
    BaseStrategy(strategyID, pDMC),
    maxPosition(maxPosition),
    minPosition(minPosition),
    openThreshold(openThreshold),
    closeThreshold(closeThreshold)
{
    firstIdx = pDMC->getIdxByInstrument(instruments[0]);
    secondIdx = pDMC->getIdxByInstrument(instruments[1]);

    first = &(pDepthMarkets->pMarket[firstIdx]);
    second = &(pDepthMarkets->pMarket[secondIdx]);
}

PairTrade::~PairTrade()
{
    //
}

void PairTrade::onInstrumentChanged(int idx)
{
    if (firstIdx == idx || secondIdx == idx) {

        if (qAbs(first->time - second->time) < 100) {
            qDebug() << first->lastPrice / second->lastPrice;
        }

    }
}
