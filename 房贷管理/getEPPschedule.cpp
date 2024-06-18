#include"getEPPschedule.h"

vector<tuple<double,double,double,double>> getEPPschedule(double Principal, double monthlyRate, int Periods, int Period)
{
	vector<tuple<double,double,double,double>> EPP_Schedule;

	double monthlyPrincipal = Principal / Periods;//月供本金
	double remainPrincipal = Principal;//剩余本金

	for (; Period <= Periods; Period++)//循环计算每一期的还款详情
	{
		double Interest = remainPrincipal * monthlyRate;//计算月供利息=剩余本金×月利率

		remainPrincipal -= monthlyPrincipal;//更新待还本金

		//每一期还款详情的储存到容器中
		EPP_Schedule.emplace_back(Period, remainPrincipal, monthlyPrincipal, Interest);	
	}
	return EPP_Schedule;
}