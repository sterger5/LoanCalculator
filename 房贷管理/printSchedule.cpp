#include "printSchedule.h" // ����ͷ�ļ��������˴�ӡ����ƻ��ĺ���ԭ��

// �������壺��ӡ����ƻ���
void printSchedule(vector<tuple<double, double, double, double>>& vec)
{
    cout << "����\tʣ�౾��\tÿ��Ӧ���ܶ�\tÿ��Ӧ������\tÿ��Ӧ����Ϣ" << endl;
    // �����洢����ƻ���tuple����
    for (const auto& repayment : vec) // ���ڻ���ƻ����е�ÿһ��...
    {
        cout << setw(5) << get<0>(repayment)          // �����������ȹ̶�Ϊ5���Ҷ���
            << setw(15) << fixed << setprecision(2) << get<1>(repayment) // ���ʣ�౾�𣬱�����λС�����ܿ��15
            << setw(15) << fixed << setprecision(2) << get<2>(repayment) + get<3>(repayment) // ÿ��Ӧ���ܶ�
            << setw(15) << fixed << setprecision(2) << get<2>(repayment)  // ÿ��Ӧ������
            << setw(15) << fixed << setprecision(2) << get<3>(repayment) << endl; // ÿ��Ӧ����Ϣ
    }
}