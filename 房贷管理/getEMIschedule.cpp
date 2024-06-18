#include "getEMIschedule.h"

// 定义计算等额本息还款计划的函数
std::vector<std::tuple<double, double, double, double>> getEMIschedule(
    double Principal, double monthlyRate, int Periods, int Period /* = 1 */)
{
    // 初始化一个vector来存储每期的还款信息
    std::vector<std::tuple<double, double, double, double>> EMI_Schedule;

    // 计算等额本息公式中的分子部分：月利率乘以(1+月利率)的(总期数-当前期数+1)次方
    double Numberactor = monthlyRate * std::pow(1 + monthlyRate, Periods - Period + 1);

    // 计算等额本息公式中的分母部分：上述结果减去1
    double Denominator = std::pow(1 + monthlyRate, Periods - Period + 1) - 1;

    // 根据等额本息公式计算每期应还款额（含本金和利息）
    double monthlyPayment = Principal * (Numberactor / Denominator);

    // 初始化剩余本金为贷款本金总额
    double remainPrincipal = Principal;

    // 遍历还款周期，从指定的期数开始直到总期数结束
    for (; Period <= Periods; ++Period)
    {
        // 计算当期的利息 = 剩余本金 × 月利率
        double monthlyInterest = remainPrincipal * monthlyRate;

        // 更新剩余本金，减去本期已还的本金（月供总额 - 当期利息）
        remainPrincipal -= (monthlyPayment - monthlyInterest);

        // 将当前期的信息（期数、剩余本金、当期偿还本金、当期利息）存入vector中
        EMI_Schedule.emplace_back(Period, remainPrincipal, monthlyPayment - monthlyInterest, monthlyInterest);
    }

    // 完成循环后，返回计算好的还款计划表
    return EMI_Schedule;
}