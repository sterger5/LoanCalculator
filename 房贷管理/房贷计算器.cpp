#include"Loan.h"

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
	cout << "选择还款方式，0为等额本息，1为等额本金："; cin >> repaymentMethodFlag;

	if (!repaymentMethodFlag)
	{
		debtor = new EqualMonthlyInstallments(Name,loanAmount,Periods,annualInterestRate);//贷款类指针指向等额本息
		debtor->showSchedule();
	}
	else if (repaymentMethodFlag)
	{
		debtor = new EquivalentPrincipal(Name, loanAmount, Periods, annualInterestRate);//贷款类指针指向等额本金
		debtor->showSchedule();
	}

	int prepaymentFlag = 0;//是否需要提前还款的标签
	cout << "是否需要提前还款？(不需要输入0，需要输入1)："; cin >> prepaymentFlag;
	

	return 0;
}