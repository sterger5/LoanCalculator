#include "printSchedule.h" // 包含头文件，声明了打印还款计划的函数原型

// 函数定义：打印还款计划表
void printSchedule(vector<tuple<double, double, double, double>>& vec)
{
    cout << "期数\t剩余本金\t每月应还总额\t每月应还本金\t每月应还利息" << endl;
    // 遍历存储还款计划的tuple向量
    for (const auto& repayment : vec) // 对于还款计划表中的每一项...
    {
        cout << setw(5) << get<0>(repayment)          // 输出期数，宽度固定为5，右对齐
            << setw(15) << fixed << setprecision(2) << get<1>(repayment) // 输出剩余本金，保留两位小数，总宽度15
            << setw(15) << fixed << setprecision(2) << get<2>(repayment) + get<3>(repayment) // 每月应还总额
            << setw(15) << fixed << setprecision(2) << get<2>(repayment)  // 每月应还本金
            << setw(15) << fixed << setprecision(2) << get<3>(repayment) << endl; // 每月应还利息
    }
}