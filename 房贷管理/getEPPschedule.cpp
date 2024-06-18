#include"getEPPschedule.h"

vector<tuple<double,double,double,double>> getEPPschedule(double Principal, double monthlyRate, int Periods, int Period)
{
	vector<tuple<double,double,double,double>> EPP_Schedule;

	double monthlyPrincipal = Principal / Periods;//�¹�����
	double remainPrincipal = Principal;//ʣ�౾��

	for (; Period <= Periods; Period++)//ѭ������ÿһ�ڵĻ�������
	{
		double Interest = remainPrincipal * monthlyRate;//�����¹���Ϣ=ʣ�౾���������

		remainPrincipal -= monthlyPrincipal;//���´�������

		//ÿһ�ڻ�������Ĵ��浽������
		EPP_Schedule.emplace_back(Period, remainPrincipal, monthlyPrincipal, Interest);	
	}
	return EPP_Schedule;
}