#pragma once
#include <iostream>
#include <vector>
#include <iomanip> // 用于格式化输出
#include <tuple> // 允许创建元组类型的数据结构
#include <cmath> // 提供数学函数
#include <numeric> // 提供累积函数，如求和
#include "getEMIschedule.h" // 等额本息还款计划生成函数声明
#include "getEPPschedule.h" // 等额本金还款计划生成函数声明
#include "printSchedule.h" // 打印还款计划函数声明

using namespace std; // 使用标准命名空间

// 预付类，作为预付类型（全款预付、部分等额本息预付、部分等额本金预付）的基类
class Prepay {
protected:
    int m_prepayTime = 1; // 预付发生的时间点（第几个月）
    double m_remainAmount; // 剩余本金
    double m_prepayAmount; // 预付金额
    vector<tuple<double, double, double, double>> m_newSchedule; // 更新后的还款计划表
    double m_newRate; // 更新后的利率（如果有的话）

public:
    // 计算剩余本金
    double getRemainAmount(vector<tuple<double, double, double, double>>& Schedule);

    // 纯虚函数，用于展示还款计划，子类需要实现
    virtual void showSchedule() {}
};

// 全款预付类，继承自Prepay
class FullPrepay : public Prepay {
public:
    // 构造函数，接收预付时间点和原还款计划
    FullPrepay(int prepayTime, vector<tuple<double, double, double, double>>& Schedule);

    // 实现展示还款计划
    void showSchedule();
};

// 部分等额本息预付类，继承自Prepay
class PartEMIprepay : public Prepay {
private:
    int m_planFlag; // 方案标识
    int m_newPeriods; // 更新后的还款期数
public:
    // 构造函数，接收预付金额、预付时间点、新利率、原还款计划、方案标识和新的还款期数
    PartEMIprepay(double prepayAmount, int prepayTime, double newRate,
        vector<tuple<double, double, double, double>>& Schedule, int planFlag, int newPeriods);

    // 实现展示还款计划
    void showSchedule();
};

// 部分等额本金预付类，继承自Prepay
class PartEPPprepay : public Prepay {
private:
    int m_planFlag; // 方案标识
    int m_newPeriods; // 更新后的还款期数
public:
    // 构造函数，接收预付金额、预付时间点、新利率、原还款计划、方案标识和新的还款期数
    PartEPPprepay(double prepayAmount, int prepayTime, double newRate,
        vector<tuple<double, double, double, double>>& Schedule, int planFlag, int newPeriods);

    // 实现展示还款计划
    void showSchedule();
};