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

class KtMarket final {
    QList<Market> markets;

    KtMarket();
    Q_DISABLE_COPY(KtMarket)
    Market loadMkt(const QString &file_name);

public:
    static KtMarket *getInstance();
    QList<QPair<QTime, QTime>> getTradingTimeRanges(const QString &instrumentID);
    QList<QTime> getEndPoints(const QString &instrumentID);
};

/*!
 * \brief 从各个交易市场里查找此合约的交易时间范围.
 * \param instrumentID 合约代码.
 * \return 交易时间范围.
 */
QList<QPair<QTime, QTime>> getTradingTimeRanges(const QString &instrumentID);

/*!
 * \brief 查询并获取此合约的每个交易时段的结束时间点列表.
 * \param instrumentID 合约代码.
 * \return 每个交易时段的结束时间点列表(未排序)
 */
QList<QTime> getEndPoints(const QString &instrumentID);

#endif // MARKET_H
