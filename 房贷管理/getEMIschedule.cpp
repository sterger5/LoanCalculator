#include"getEMIschedule.h"

vector<tuple<double,double,double,double>> getEMIschedule(double Principal, double monthlyRate, int Periods,int Period)
{
	vector<tuple<double, double, double, double>> EMI_Schedule;
	double Numberactor = monthlyRate * pow(1 + monthlyRate, Periods - Period + 1);//���㹫ʽ�еķ���
	double Denominator = pow(1 + monthlyRate, Periods - Period + 1) - 1;//�����ĸ
	double monthlyPayment = Principal * (Numberactor / Denominator);//�����¹�(����+��Ϣ)
	double remainPrincipal = Principal;//ʣ�౾��
	for (; Period <= Periods; Period++)
	{
		double monthlyInterest = remainPrincipal * monthlyRate;//�����¹���Ϣ=ʣ�౾���������

		remainPrincipal -= (monthlyPayment - monthlyInterest);//����ʣ�౾��

		EMI_Schedule.emplace_back(Period, remainPrincipal, monthlyPayment-monthlyInterest, monthlyInterest);
		//ÿһ�ڵĽ�����浽����������
	}

	return EMI_Schedule;
}


