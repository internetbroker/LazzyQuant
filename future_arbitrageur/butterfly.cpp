#include "depth_market.h"
#include "butterfly.h"

#include <QDebug>

static inline bool areCloseEnough(qint64 a, qint64 b, qint64 c, qint64 diff)
{
    return qMax(qMax(a, b), c) - qMin(a, qMin(b, c)) < diff;
}

Butterfly::Butterfly(const QString &strategyID, const QStringList &instruments, int maxPosition, int minPosition, double openThreshold, double closeThreshold, DepthMarketCollection *pDMC) :
    BaseStrategy(strategyID, pDMC),
    maxPosition(maxPosition),
    minPosition(minPosition),
    openThreshold(openThreshold),
    closeThreshold(closeThreshold)
{
    firstIdx = pDMC->getIdxByInstrument(instruments[0]);
    secondIdx = pDMC->getIdxByInstrument(instruments[1]);
    thirdIdx = pDMC->getIdxByInstrument(instruments[2]);

    first = &(pDepthMarkets->pMarket[firstIdx]);
    second = &(pDepthMarkets->pMarket[secondIdx]);
    third = &(pDepthMarkets->pMarket[thirdIdx]);
}

Butterfly::~Butterfly()
{
    //
}

void Butterfly::onInstrumentChanged(int idx)
{
    if (firstIdx == idx || secondIdx == idx || thirdIdx == idx) {
        check010();
        check101();
    }
}

void Butterfly::check010()
{
    const auto diff = second->bidPrice * 2.0 - first->askPrice - third->askPrice;
    const bool openClose = (position >= 0);
    const auto threshold = openClose ? openThreshold : closeThreshold;
    if (diff > threshold && areCloseEnough(first->time, second->time, third->time, 420)) {
        const auto liquidity = qMin(qMin(first->askVolume, third->askVolume), second->bidVolume / 2);
        auto vol = qMin(liquidity / 2, (openClose ? (maxPosition - position) : (-position)));
        if (vol > 0) {
            buyInstrument(firstIdx, vol);
            sellInstrument(secondIdx, vol * 2);
            buyInstrument(thirdIdx, vol);

            position += vol;
            savePosition();

            qDebug().nospace() << (openClose ? "Open" : "Close") << "010 butterfly! diff =" << diff << "\n"
                << pDepthMarkets->getInstrumentByIdx(firstIdx) << "\n" << *first << "\n"
                << pDepthMarkets->getInstrumentByIdx(secondIdx) << "\n" << *second << "\n"
                << pDepthMarkets->getInstrumentByIdx(thirdIdx) << "\n" << *third;

            pDepthMarkets->takeLiquidityByIdx(firstIdx, true);
            pDepthMarkets->takeLiquidityByIdx(secondIdx, false);
            pDepthMarkets->takeLiquidityByIdx(thirdIdx, true);
        }
    }
}

void Butterfly::check101()
{
    const auto diff = first->bidPrice + third->bidPrice - second->askPrice * 2.0;
    const bool openClose = (position <= 0);
    const auto threshold = openClose ? openThreshold : closeThreshold;
    if (diff > threshold && areCloseEnough(first->time, second->time, third->time, 420)) {
        const auto liquidity = qMin(qMin(first->bidVolume, third->bidVolume), second->askVolume / 2);
        auto vol = qMin(liquidity / 2, (openClose ? (position - minPosition) : (position)));
        if (vol > 0) {
            sellInstrument(firstIdx, vol);
            buyInstrument(secondIdx, vol * 2);
            sellInstrument(thirdIdx, vol);

            position -= vol;
            savePosition();

            qDebug().nospace() << (openClose ? "Open" : "Close") << "101 butterfly! diff =" << diff << "\n"
                << pDepthMarkets->getInstrumentByIdx(firstIdx) << "\n" << *first << "\n"
                << pDepthMarkets->getInstrumentByIdx(secondIdx) << "\n" << *second << "\n"
                << pDepthMarkets->getInstrumentByIdx(thirdIdx) << "\n" << *third;

            pDepthMarkets->takeLiquidityByIdx(firstIdx, false);
            pDepthMarkets->takeLiquidityByIdx(secondIdx, true);
            pDepthMarkets->takeLiquidityByIdx(thirdIdx, false);
        }
    }
}
