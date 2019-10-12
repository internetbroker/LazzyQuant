#ifndef TIME_MAPPER_H
#define TIME_MAPPER_H

#include <QtGlobal>

/*!
 * \brief 设置一个交易日后, 可将某个交易时间映射到相应的(日期+时间).
 */
class TimeMapper
{
    qint64 lastNightBase = 0;
    qint64 morningBase = 0;
    qint64 tradingDayBase = 0;

public:
    TimeMapper() = default;

    /*!
     * \brief 设置交易日.
     *
     * \param tradingDay 交易日(格式yyyyMMdd).
     */
    void setTradingDay(const QString &tradingDay);

    /*!
     * \brief 将某个交易时间映射到相应的(日期+时间).
     *
     * \param inTime 交易时间(不含日期).
     * \return 交易时间(日期+时间).
     */
    qint64 mapTime(int inTime) const;

    /*!
     * \brief 同mapTime, 方便调用.
     *
     * \param inTime 交易时间(不含日期).
     * \return 交易时间(日期+时间).
     */
    qint64 operator()(int inTime) const { return mapTime(inTime); }

};

#endif // TIME_MAPPER_H
