#include "depth_market.h"
#include "base_strategy.h"

BaseStrategy::BaseStrategy(DepthMarketCollection *pDMC, QObject *parent) :
    QObject(parent),
    pDepthMarkets(pDMC)
{
    //
}

BaseStrategy::~BaseStrategy()
{
    qDebug() << "~BaseStrategy()";
}

void BaseStrategy::buyUnderlying(int underlyingIdx, int vol, double price, int orderType)
{
    const QString underlyingID = pDepthMarkets->getUnderlyingIDByIdx(underlyingIdx);
    emit buyLimit(underlyingID, vol, price, orderType);
}

void BaseStrategy::sellUnderlying(int underlyingIdx, int vol, double price, int orderType)
{
    const QString underlyingID = pDepthMarkets->getUnderlyingIDByIdx(underlyingIdx);
    emit sellLimit(underlyingID, vol, price, orderType);
}

void BaseStrategy::buyOption(int underlyingIdx, OPTION_TYPE type, int kIdx, int vol, double price, int orderType)
{
    const QString optionID = pDepthMarkets->makeOptionByIdx(underlyingIdx, type, kIdx);
    emit buyLimit(optionID, vol, price, orderType);
}

void BaseStrategy::sellOption(int underlyingIdx, OPTION_TYPE type, int kIdx, int vol, double price, int orderType)
{
    const QString optionID = pDepthMarkets->makeOptionByIdx(underlyingIdx, type, kIdx);
    emit sellLimit(optionID, vol, price, orderType);
}
