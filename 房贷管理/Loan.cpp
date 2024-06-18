#include"Loan.h"
void EquivalentPrincipal::showSchedule()
{
	//调用函数生成计划表
	repaymentSchedule = getEPPschedule(m_loanAmount, m_annualInterestRate / 12, m_Periods, 1);

	//打印计划表
	printSchedule(repaymentSchedule);
}

void EqualMonthlyInstallments::showSchedule()
{
	//调用函数生成计划表
	repaymentSchedule = getEMIschedule(m_loanAmount, m_annualInterestRate / 12, m_Periods, 1);

	//打印计划表
	printSchedule(repaymentSchedule);
}

EquivalentPrincipal::EquivalentPrincipal(string Name, double loanAmount, int Periods, double annualInterestRate)
{
	m_Name = Name;
	m_loanAmount = loanAmount;
	m_Periods = Periods;
	m_annualInterestRate = annualInterestRate;
}

EqualMonthlyInstallments::EqualMonthlyInstallments(string Name, double loanAmount, int Periods, double annualInterestRate)
{
	m_Name = Name;
	m_loanAmount = loanAmount;
	m_Periods = Periods;
	m_annualInterestRate = annualInterestRate;
}

vector<tuple<double, double, double, double>> Loan::getSchedule()
{
	return repaymentSchedule;
}
