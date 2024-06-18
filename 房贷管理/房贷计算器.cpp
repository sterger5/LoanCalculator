#include"Loan.h"
#include"Prepay.h"

int main()
{
	int repaymentMethodFlag;//标签，用于记录还款方式
	string Name;//借款人姓名
	int loanAmount, Periods;//贷款金额、期数
	double annualInterestRate;//年利率
	Loan* debtor = NULL;
	cout << "借款人姓名："; cin >> Name;
	cout << "贷款金额(元)："; cin >> loanAmount;
	cout << "还款期数(月)："; cin >> Periods;
	cout << "年利率："; cin >> annualInterestRate;
	cout << "选择还款方式，1为等额本息，2为等额本金："; cin >> repaymentMethodFlag;

	if (repaymentMethodFlag==1)
	{
		debtor = new EqualMonthlyInstallments(Name,loanAmount,Periods,annualInterestRate);//贷款类指针指向等额本息
		debtor->showSchedule();
	}
	else if (repaymentMethodFlag==2)
	{
		debtor = new EquivalentPrincipal(Name, loanAmount, Periods, annualInterestRate);//贷款类指针指向等额本金
		debtor->showSchedule();
	}

	//决定期限不变还是月供不变
	int planFlag = 0;
	int prepayTime;//是否需要提前还款的标签
	cout << "是否需要提前还款？(不需要输入1，需要输入2)："; cin >> planFlag;


	if (planFlag ==2)
	{
		double newRate, prepayAmount;
		auto vec = debtor->getSchedule();
		cout << "请输入提前还款的月份："; cin >> prepayTime;
		cout << "请选择提前还款的方式(1、全部还清，2、部分还清)："; cin >> planFlag;

		if (planFlag == 1)
		{
			Prepay* Prepayer = new FullPrepay(prepayTime, vec);
			Prepayer->showSchedule();
		}
		else if (planFlag == 2)
		{
			cout << "请输入提前还款的金额："; cin >> prepayAmount;
			cout << "请输入新的年利率："; cin >> newRate;
			//决定等额本息还是等额本金
			int wayFlag;
			cout << "请选择提前方案(1、月供减少，期限不变，2、月供不变，期限缩短)："; cin >> planFlag;
			if (planFlag == 1)
			{
				cout << "请选择后续偿还方式(1、等额本息，2、等额本金)："; cin >> wayFlag;
				if (wayFlag == 1)
				{
					cout << endl;
					Prepay* Prepayer = new PartEMIprepay(prepayAmount, prepayTime, newRate, vec, 1, debtor->getPeriods());
					Prepayer->showSchedule();
				}
				else if (wayFlag == 2)
				{
					cout << endl;
					Prepay* Prepayer = new PartEPPprepay(prepayAmount, prepayTime, newRate, vec, 1, debtor->getPeriods());
					Prepayer->showSchedule();
				}
			}
			else if (planFlag == 2)
			{
				cout << "请选择后续偿还方式(1、等额本息，2、等额本金)："; cin >> wayFlag;
				if (wayFlag == 1)
				{
					cout << endl;
					Prepay* Prepayer = new PartEMIprepay(prepayAmount, prepayTime, newRate, vec, 2, debtor->getPeriods());
					Prepayer->showSchedule();
				}
				else if (wayFlag == 2)
				{
					cout << endl;
					Prepay* Prepayer = new PartEPPprepay(prepayAmount, prepayTime, newRate, vec, 2, debtor->getPeriods());
					Prepayer->showSchedule();
				}
			}
		}
	}
	
	return 0;
}