#include "depth_market.h"
#include "option_pricing.h"
#include "high_frequency.h"

HighFrequency::HighFrequency(OptionPricing *pPricing, DepthMarketCollection *pDMC, QObject *parent) :
    BaseStrategy(pDMC, parent),
    pPricingEngine(pPricing)
{
}

HighFrequency::~HighFrequency()
{
    qDebug() << "~HighFrequency()";
}

void HighFrequency::onUnderlyingChanged(int underlyingIdx)
{
    Q_UNUSED(underlyingIdx)
}

void HighFrequency::onOptionChanged(int underlyingIdx, OPTION_TYPE type, int kIdx)
{
    Q_UNUSED(underlyingIdx)
    Q_UNUSED(type)
    Q_UNUSED(kIdx)
}
