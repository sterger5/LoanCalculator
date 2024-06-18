#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
#include<tuple>
#include<cmath>
#include<numeric>
#include"getEMIschedule.h"
#include"getEPPschedule.h"
#include"printSchedule.h"

using namespace std;

class Prepay
{
protected:
	int m_prepayTime = 1;
	double m_remainAmount;//Ê£Óà±¾½ð
	double m_prepayAmount;
	vector<tuple<double, double, double, double>> m_newSchedule;
	double m_newRate;
public:
	double getRemainAmount(vector<tuple<double, double, double, double>>& Schedule);
	virtual void showSchedule() {};
};

class FullPrepay :public Prepay
{
private:

public:
	FullPrepay(int prepayTime, vector<tuple<double, double, double, double>>& Schedule);
	void showSchedule();
};

class PartEMIprepay :public Prepay
{
private:
	int m_planFlag;
	int m_newPeriods;
public:
	PartEMIprepay(double prepayAmount, int prepayTime, double newRate,
		vector<tuple<double, double, double, double>>& Schedule, int planFlag, int newPeriods);
	void showSchedule();
};

class PartEPPprepay :public Prepay
{
private:
	int m_planFlag;
	int m_newPeriods;
public:
	PartEPPprepay(double prepayAmount, int prepayTime, double newRate,
		vector<tuple<double, double, double, double>>& Schedule, int planFlag, int newPeriods);
	void showSchedule();
};