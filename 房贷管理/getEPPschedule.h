#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
#include<tuple>
#include<cmath>
#include<numeric>
#include<array>
using namespace std;

vector<tuple<double,double,double,double>> getEPPschedule(double Principal, double monthlyRate, int Periods, int Period);