#include"Loan.h"

int main()
{
	int repaymentMethodFlag;//��ǩ�����ڼ�¼���ʽ
	string Name;//���������
	int loanAmount, Periods;//���������
	double annualInterestRate;//������
	Loan* debtor = NULL;
	cout << "�����������"; cin >> Name;
	cout << "������(Ԫ)��"; cin >> loanAmount;
	cout << "��������(��)��"; cin >> Periods;
	cout << "�����ʣ�"; cin >> annualInterestRate;
	cout << "ѡ�񻹿ʽ��0Ϊ�ȶϢ��1Ϊ�ȶ��"; cin >> repaymentMethodFlag;

	if (!repaymentMethodFlag)
	{
		debtor = new EqualMonthlyInstallments(Name,loanAmount,Periods,annualInterestRate);//������ָ��ָ��ȶϢ
		debtor->showSchedule();
	}
	else if (repaymentMethodFlag)
	{
		debtor = new EquivalentPrincipal(Name, loanAmount, Periods, annualInterestRate);//������ָ��ָ��ȶ��
		debtor->showSchedule();
	}

	int prepaymentFlag = 0;//�Ƿ���Ҫ��ǰ����ı�ǩ
	cout << "�Ƿ���Ҫ��ǰ���(����Ҫ����0����Ҫ����1)��"; cin >> prepaymentFlag;
	

	return 0;
}