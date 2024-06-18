#include"printSchedule.h"

void printSchedule(vector<tuple<double,double,double,double>>& vec)
{
	cout << "����\tʣ�౾��\tÿ��Ӧ���ܶ�\tÿ��Ӧ������\tÿ��Ӧ����Ϣ" << endl;
	for (const auto& repayment : vec)//��������ƻ�������������ƻ���
	{

		cout << setw(5) << get<0>(repayment)
			<< setw(15) << fixed << setprecision(2) << get<1>(repayment)
			<< setw(15) << fixed << setprecision(2) << get<2>(repayment) + get<3>(repayment)
			<< setw(15) << fixed << setprecision(2) << get<2>(repayment)
			<< setw(15) << fixed << setprecision(2) << get<3>(repayment) << endl;
	}
}