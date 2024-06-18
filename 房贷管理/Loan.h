#pragma once
#include<iostream>
#include<vector>
#include<tuple>
#include<iomanip>
#include"getEMIschedule.h"
#include"getEPPschedule.h"
#include"printSchedule.h"
using namespace std;
class Loan//此类包含了贷款人的基本信息
{
protected:
	string m_Name;//姓名
	double m_loanAmount;//贷款金额
	int m_Periods;//期数
	double m_annualInterestRate;//年利率
	vector<tuple<double, double, double, double>> repaymentSchedule;//每一期的还款详情，储存在vector容器中
public:
	virtual void showSchedule() {};
	vector<tuple<double, double, double, double>> getSchedule();
	int getPeriods()
	{
		return m_Periods;
	}
};

class EquivalentPrincipal :public Loan//等额本金偿还
{
public:
	void showSchedule();//计算并展示还款计划表
	EquivalentPrincipal(string Name,double loanAmount, int Periods, double annualInterestRate);
};

class EqualMonthlyInstallments :public Loan//等额本息偿还
{
public:
	void showSchedule();//计算并显示计划表
	EqualMonthlyInstallments(string Name, double loanAmount, int Periods, double annualInterestRate);
};