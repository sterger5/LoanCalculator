#include "Loan.h"

// ʵ�ֵȶ�𳥻���ʽ�Ļ���ƻ�չʾ
void EquivalentPrincipal::showSchedule()
{
    // ����getEPPschedule�������ɵȶ��Ļ���ƻ���
    repaymentSchedule = getEPPschedule(m_loanAmount, m_annualInterestRate / 12.0, m_Periods, 1);

    // ��ӡ����ƻ���
    printSchedule(repaymentSchedule);
}

// ʵ�ֵȶϢ������ʽ�Ļ���ƻ�չʾ
void EqualMonthlyInstallments::showSchedule()
{
    // ����getEMIschedule�������ɵȶϢ�Ļ���ƻ���
    repaymentSchedule = getEMIschedule(m_loanAmount, m_annualInterestRate / 12.0, m_Periods, 1);

    // ��ӡ����ƻ���
    printSchedule(repaymentSchedule);
}

// �ȶ�����Ĺ��캯������ʼ�������˻�����Ϣ
EquivalentPrincipal::EquivalentPrincipal(string Name, double loanAmount, int Periods, double annualInterestRate)
{
    m_Name = Name;
    m_loanAmount = loanAmount;
    m_Periods = Periods;
    m_annualInterestRate = annualInterestRate;
}

// �ȶϢ����Ĺ��캯������ʼ�������˻�����Ϣ
EqualMonthlyInstallments::EqualMonthlyInstallments(string Name, double loanAmount, int Periods, double annualInterestRate)
{
    m_Name = Name;
    m_loanAmount = loanAmount;
    m_Periods = Periods;
    m_annualInterestRate = annualInterestRate;
}

// ��ȡ��ǰ����Ļ���ƻ�
vector<tuple<double, double, double, double>> Loan::getSchedule()
{
    return repaymentSchedule;
}