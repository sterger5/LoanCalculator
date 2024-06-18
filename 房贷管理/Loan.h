#pragma once
#include<iostream>
#include<vector>
#include<tuple>
#include<iomanip>
#include"getEMIschedule.h"
#include"getEPPschedule.h"
#include"printSchedule.h"
using namespace std;
class Loan//��������˴����˵Ļ�����Ϣ
{
protected:
	string m_Name;//����
	double m_loanAmount;//������
	int m_Periods;//����
	double m_annualInterestRate;//������
	vector<tuple<double, double, double, double>> repaymentSchedule;//ÿһ�ڵĻ������飬������vector������
public:
	virtual void showSchedule() {};
	vector<tuple<double, double, double, double>> getSchedule();
	int getPeriods()
	{
		return m_Periods;
	}
};

class EquivalentPrincipal :public Loan//�ȶ�𳥻�
{
public:
	void showSchedule();//���㲢չʾ����ƻ���
	EquivalentPrincipal(string Name,double loanAmount, int Periods, double annualInterestRate);
};

class EqualMonthlyInstallments :public Loan//�ȶϢ����
{
public:
	void showSchedule();//���㲢��ʾ�ƻ���
	EqualMonthlyInstallments(string Name, double loanAmount, int Periods, double annualInterestRate);
};