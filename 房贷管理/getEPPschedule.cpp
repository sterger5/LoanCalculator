#include "getEPPschedule.h"

// 计算等额本金还款计划的函数
std::vector<std::tuple<double, double, double, double>> getEPPschedule(
    double Principal, double monthlyRate, int Periods, int Period /* = 1 */)
{
    // 初始化存储等额本金还款计划的vector
    std::vector<std::tuple<double, double, double, double>> EPP_Schedule;

    // 计算每期应还本金
    double monthlyPrincipal = Principal / (Periods - Period + 1);

    // 初始化剩余本金
    double remainPrincipal = Principal;

    // 遍历还款周期，计算每期的还款详情
    for (; Period <= Periods; ++Period)
    {
        // 计算当期利息 = 剩余本金 × 月利率
        double Interest = remainPrincipal * monthlyRate;

        // 更新剩余本金，减去本期偿还的本金
        remainPrincipal -= monthlyPrincipal;

        // 将当前期的还款信息（期数、剩余本金、当期偿还本金、当期利息）存入vector中
        EPP_Schedule.emplace_back(Period, remainPrincipal, monthlyPrincipal, Interest);
    }

    // 完成计算后，返回等额本金还款计划表
    return EPP_Schedule;
}