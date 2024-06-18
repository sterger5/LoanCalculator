#include"printSchedule.h"

void printSchedule(vector<tuple<double,double,double,double>>& vec)
{
	cout << "期数\t剩余本金\t每月应还总额\t每月应还本金\t每月应还利息" << endl;
	for (const auto& repayment : vec)//遍历储存计划表容器，输出计划表
	{

		cout << setw(5) << get<0>(repayment)
			<< setw(15) << fixed << setprecision(2) << get<1>(repayment)
			<< setw(15) << fixed << setprecision(2) << get<2>(repayment) + get<3>(repayment)
			<< setw(15) << fixed << setprecision(2) << get<2>(repayment)
			<< setw(15) << fixed << setprecision(2) << get<3>(repayment) << endl;
	}
}