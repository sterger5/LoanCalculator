#include"getEMIschedule.h"

vector<tuple<double,double,double,double>> getEMIschedule(double Principal, double monthlyRate, int Periods,int Period)
{
	vector<tuple<double, double, double, double>> EMI_Schedule;
	double Numberactor = monthlyRate * pow(1 + monthlyRate, Periods - Period + 1);//计算公式中的分子
	double Denominator = pow(1 + monthlyRate, Periods - Period + 1) - 1;//计算分母
	double monthlyPayment = Principal * (Numberactor / Denominator);//计算月供(本金+利息)
	double remainPrincipal = Principal;//剩余本金
	for (; Period <= Periods; Period++)
	{
		double monthlyInterest = remainPrincipal * monthlyRate;//计算月供利息=剩余本金×月利率

		remainPrincipal -= (monthlyPayment - monthlyInterest);//更新剩余本金

		EMI_Schedule.emplace_back(Period, remainPrincipal, monthlyPayment-monthlyInterest, monthlyInterest);
		//每一期的结果储存到向量容器中
	}

	return EMI_Schedule;
}


