#include "getEMIschedule.h"

// �������ȶϢ����ƻ��ĺ���
std::vector<std::tuple<double, double, double, double>> getEMIschedule(
    double Principal, double monthlyRate, int Periods, int Period /* = 1 */)
{
    // ��ʼ��һ��vector���洢ÿ�ڵĻ�����Ϣ
    std::vector<std::tuple<double, double, double, double>> EMI_Schedule;

    // ����ȶϢ��ʽ�еķ��Ӳ��֣������ʳ���(1+������)��(������-��ǰ����+1)�η�
    double Numberactor = monthlyRate * std::pow(1 + monthlyRate, Periods - Period + 1);

    // ����ȶϢ��ʽ�еķ�ĸ���֣����������ȥ1
    double Denominator = std::pow(1 + monthlyRate, Periods - Period + 1) - 1;

    // ���ݵȶϢ��ʽ����ÿ��Ӧ�������������Ϣ��
    double monthlyPayment = Principal * (Numberactor / Denominator);

    // ��ʼ��ʣ�౾��Ϊ������ܶ�
    double remainPrincipal = Principal;

    // �����������ڣ���ָ����������ʼֱ������������
    for (; Period <= Periods; ++Period)
    {
        // ���㵱�ڵ���Ϣ = ʣ�౾�� �� ������
        double monthlyInterest = remainPrincipal * monthlyRate;

        // ����ʣ�౾�𣬼�ȥ�����ѻ��ı����¹��ܶ� - ������Ϣ��
        remainPrincipal -= (monthlyPayment - monthlyInterest);

        // ����ǰ�ڵ���Ϣ��������ʣ�౾�𡢵��ڳ������𡢵�����Ϣ������vector��
        EMI_Schedule.emplace_back(Period, remainPrincipal, monthlyPayment - monthlyInterest, monthlyInterest);
    }

    // ���ѭ���󣬷��ؼ���õĻ���ƻ���
    return EMI_Schedule;
}