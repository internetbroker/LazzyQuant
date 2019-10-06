#ifndef MARKET_H
#define MARKET_H

#include <QPair>
#include <QStringList>

class QTime;

struct Market {
    QString label;
    QStringList codes;
    QStringList descs;
    QStringList regexs;
    QList<QList<QPair<QTime, QTime>>> tradetimeses;
};

void loadCommonMarketData();
Market loadMkt(const QString &file_name);

/*!
 * \brief 从各个交易市场里查找此合约的交易时间范围.
 * \param instrumentID 合约代码.
 * \return 交易时间范围.
 */
QList<QPair<QTime, QTime>> getTradingTimeRanges(const QString &instrumentID);
QList<QTime> getEndPoints(const QString &instrumentID);

#endif // MARKET_H
