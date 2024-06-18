#include"Prepay.h"

double Prepay::getRemainAmount(vector<tuple<double, double, double, double>>& Schedule)
{
	return get<1>(Schedule[m_prepayTime - 1]);
}

FullPrepay::FullPrepay(int prepayTime, vector<tuple<double, double, double, double>>& Schedule)
{
	m_remainAmount = getRemainAmount(Schedule);
	m_prepayAmount = m_remainAmount;
	m_prepayTime = prepayTime;
	m_newSchedule = Schedule;
}

PartEMIprepay::PartEMIprepay(double prepayAmount, int prepayTime, double newRate,
	vector<tuple<double, double, double, double>>& Schedule, int planFlag, int newPeriods)
{
	m_prepayAmount = prepayAmount;
	m_prepayTime = prepayTime;
	m_remainAmount = getRemainAmount(Schedule);
	m_newSchedule = Schedule;
	m_planFlag = planFlag;
	m_newRate = newRate;
	m_newPeriods = newPeriods;
}

PartEPPprepay::PartEPPprepay(double prepayAmount, int prepayTime, double newRate,
	vector<tuple<double, double, double, double>>& Schedule, int planFlag, int newPeriods)
{
	m_prepayAmount = prepayAmount;
	m_prepayTime = prepayTime;
	m_remainAmount = getRemainAmount(Schedule);
	m_newSchedule = Schedule;
	m_planFlag = planFlag;
	m_newRate = newRate;
	m_newPeriods = newPeriods;
}

void FullPrepay::showSchedule()
{
	m_newSchedule[m_prepayTime] = make_tuple(get<0>(m_newSchedule[m_prepayTime]), 0.0,
		get<1>(m_newSchedule[m_prepayTime-1]), 0.0);

	m_newSchedule.resize(m_prepayTime + 1);

	printSchedule(m_newSchedule);
}

void PartEMIprepay::showSchedule()
{
	if (m_planFlag == 1)
	{
		auto tempVec = getEMIschedule(m_remainAmount - m_prepayAmount, m_newRate / 12, m_newPeriods, m_prepayTime);

		m_newSchedule.resize(m_prepayTime);

		m_newSchedule.insert(m_newSchedule.end(), tempVec.begin(), tempVec.end());

		printSchedule(m_newSchedule);
	}
	else if (m_planFlag == 2)
	{
		double monthlyPay = get<2>(m_newSchedule[m_prepayTime]) + get<3>(m_newSchedule[m_prepayTime]);

		double Principal = m_remainAmount - m_prepayAmount;

		double monthlyRate = m_newRate / 12;

		m_newPeriods = log(1 + 1 / (monthlyPay / (Principal * monthlyRate) - 1)) / log(1 + monthlyRate) + m_prepayTime;

		auto tempVec = getEMIschedule(m_remainAmount - m_prepayAmount, m_newRate / 12, m_newPeriods, m_prepayTime + 1);

		m_newSchedule.resize(m_prepayTime);

		m_newSchedule.insert(m_newSchedule.end(), tempVec.begin(), tempVec.end());

		printSchedule(m_newSchedule);
	}
}

void PartEPPprepay::showSchedule()
{
	if (m_planFlag == 1)
	{
		auto tempVec = getEPPschedule(m_remainAmount - m_prepayAmount, m_newRate / 12, m_newPeriods, m_prepayTime);

		m_newSchedule.resize(m_prepayTime);

		m_newSchedule.insert(m_newSchedule.end(), tempVec.begin(), tempVec.end());

		printSchedule(m_newSchedule);
	}
	else if (m_planFlag == 2)
	{
		double newPrincipal = m_remainAmount - m_prepayAmount;

		m_newPeriods = newPrincipal / get<2>(m_newSchedule[0]) + m_prepayTime;

		auto tempVec = getEPPschedule(m_remainAmount - m_prepayAmount, m_newRate / 12, m_newPeriods, m_prepayTime + 1);

		m_newSchedule.resize(m_prepayTime);

		m_newSchedule.insert(m_newSchedule.end(), tempVec.begin(), tempVec.end());

		printSchedule(m_newSchedule);
	}
}