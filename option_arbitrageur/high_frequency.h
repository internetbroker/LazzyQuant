#ifndef HIGH_FREQUENCY_H
#define HIGH_FREQUENCY_H

#include "base_strategy.h"

class OptionPricing;

class HighFrequency : public BaseStrategy
{
    Q_OBJECT

    const OptionPricing *pPricingEngine;

public:
    HighFrequency(OptionPricing *pPricing, DepthMarketCollection *pDMC, QObject *parent = nullptr);
    ~HighFrequency();

    void onUnderlyingChanged(int underlyingIdx);
    void onOptionChanged(int underlyingIdx, OPTION_TYPE type, int kIdx);

};

#endif // HIGH_FREQUENCY_H
