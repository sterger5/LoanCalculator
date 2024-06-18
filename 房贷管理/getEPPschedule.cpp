#include "getEPPschedule.h"

// ����ȶ�𻹿�ƻ��ĺ���
std::vector<std::tuple<double, double, double, double>> getEPPschedule(
    double Principal, double monthlyRate, int Periods, int Period /* = 1 */)
{
    // ��ʼ���洢�ȶ�𻹿�ƻ���vector
    std::vector<std::tuple<double, double, double, double>> EPP_Schedule;

    // ����ÿ��Ӧ������
    double monthlyPrincipal = Principal / (Periods - Period + 1);

    // ��ʼ��ʣ�౾��
    double remainPrincipal = Principal;

    // �����������ڣ�����ÿ�ڵĻ�������
    for (; Period <= Periods; ++Period)
    {
        // ���㵱����Ϣ = ʣ�౾�� �� ������
        double Interest = remainPrincipal * monthlyRate;

        // ����ʣ�౾�𣬼�ȥ���ڳ����ı���
        remainPrincipal -= monthlyPrincipal;

        // ����ǰ�ڵĻ�����Ϣ��������ʣ�౾�𡢵��ڳ������𡢵�����Ϣ������vector��
        EPP_Schedule.emplace_back(Period, remainPrincipal, monthlyPrincipal, Interest);
    }

    // ��ɼ���󣬷��صȶ�𻹿�ƻ���
    return EPP_Schedule;
}