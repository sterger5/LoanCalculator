#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
#include<tuple>
#include<cmath>
#include<array>
using namespace std;

vector<tuple<double,double,double,double>> getEMIschedule(double Principal, double monthlyRate, int Periods,int Period);