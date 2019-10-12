#ifndef QUANT_TRADER_DBUS_H
#define QUANT_TRADER_DBUS_H

class AbstractManager;
class TradeLogger;
struct QuantTraderOptions;

class QuantTraderDbus
{
    AbstractManager *pManager = nullptr;
    TradeLogger *pLogger = nullptr;

public:
    explicit QuantTraderDbus(const QuantTraderOptions &options);
    ~QuantTraderDbus();

};

#endif // QUANT_TRADER_DBUS_H
