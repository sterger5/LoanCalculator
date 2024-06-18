#include "Loan.h"

// 实现等额本金偿还方式的还款计划展示
void EquivalentPrincipal::showSchedule()
{
    // 调用getEPPschedule函数生成等额本金的还款计划表
    repaymentSchedule = getEPPschedule(m_loanAmount, m_annualInterestRate / 12.0, m_Periods, 1);

    // 打印还款计划表
    printSchedule(repaymentSchedule);
}

// 实现等额本息偿还方式的还款计划展示
void EqualMonthlyInstallments::showSchedule()
{
    // 调用getEMIschedule函数生成等额本息的还款计划表
    repaymentSchedule = getEMIschedule(m_loanAmount, m_annualInterestRate / 12.0, m_Periods, 1);

    // 打印还款计划表
    printSchedule(repaymentSchedule);
}

// 等额本金贷款的构造函数，初始化贷款人基本信息
EquivalentPrincipal::EquivalentPrincipal(string Name, double loanAmount, int Periods, double annualInterestRate)
{
    m_Name = Name;
    m_loanAmount = loanAmount;
    m_Periods = Periods;
    m_annualInterestRate = annualInterestRate;
}

// 等额本息贷款的构造函数，初始化贷款人基本信息
EqualMonthlyInstallments::EqualMonthlyInstallments(string Name, double loanAmount, int Periods, double annualInterestRate)
{
    m_Name = Name;
    m_loanAmount = loanAmount;
    m_Periods = Periods;
    m_annualInterestRate = annualInterestRate;
}

// 获取当前贷款的还款计划
vector<tuple<double, double, double, double>> Loan::getSchedule()
{
    return repaymentSchedule;
}