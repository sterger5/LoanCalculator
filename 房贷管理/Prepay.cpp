#pragma once
#include <iostream>
#include <vector>
#include <iomanip> // ���ڸ�ʽ�����
#include <tuple> // ������Ԫ�����͵����ݽṹ
#include <cmath> // �ṩ��ѧ����
#include <numeric> // �ṩ�ۻ������������
#include "getEMIschedule.h" // �ȶϢ����ƻ����ɺ�������
#include "getEPPschedule.h" // �ȶ�𻹿�ƻ����ɺ�������
#include "printSchedule.h" // ��ӡ����ƻ���������

using namespace std; // ʹ�ñ�׼�����ռ�

// Ԥ���࣬��ΪԤ�����ͣ�ȫ��Ԥ�������ֵȶϢԤ�������ֵȶ��Ԥ�����Ļ���
class Prepay {
protected:
    int m_prepayTime = 1; // Ԥ��������ʱ��㣨�ڼ����£�
    double m_remainAmount; // ʣ�౾��
    double m_prepayAmount; // Ԥ�����
    vector<tuple<double, double, double, double>> m_newSchedule; // ���º�Ļ���ƻ���
    double m_newRate; // ���º�����ʣ�����еĻ���

public:
    // ����ʣ�౾��
    double getRemainAmount(vector<tuple<double, double, double, double>>& Schedule);

    // ���麯��������չʾ����ƻ���������Ҫʵ��
    virtual void showSchedule() {}
};

// ȫ��Ԥ���࣬�̳���Prepay
class FullPrepay : public Prepay {
public:
    // ���캯��������Ԥ��ʱ����ԭ����ƻ�
    FullPrepay(int prepayTime, vector<tuple<double, double, double, double>>& Schedule);

    // ʵ��չʾ����ƻ�
    void showSchedule();
};

// ���ֵȶϢԤ���࣬�̳���Prepay
class PartEMIprepay : public Prepay {
private:
    int m_planFlag; // ������ʶ
    int m_newPeriods; // ���º�Ļ�������
public:
    // ���캯��������Ԥ����Ԥ��ʱ��㡢�����ʡ�ԭ����ƻ���������ʶ���µĻ�������
    PartEMIprepay(double prepayAmount, int prepayTime, double newRate,
        vector<tuple<double, double, double, double>>& Schedule, int planFlag, int newPeriods);

    // ʵ��չʾ����ƻ�
    void showSchedule();
};

// ���ֵȶ��Ԥ���࣬�̳���Prepay
class PartEPPprepay : public Prepay {
private:
    int m_planFlag; // ������ʶ
    int m_newPeriods; // ���º�Ļ�������
public:
    // ���캯��������Ԥ����Ԥ��ʱ��㡢�����ʡ�ԭ����ƻ���������ʶ���µĻ�������
    PartEPPprepay(double prepayAmount, int prepayTime, double newRate,
        vector<tuple<double, double, double, double>>& Schedule, int planFlag, int newPeriods);

    // ʵ��չʾ����ƻ�
    void showSchedule();
};