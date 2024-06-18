#include"Loan.h"
#include"Prepay.h"

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
	cout << "ѡ�񻹿ʽ��1Ϊ�ȶϢ��2Ϊ�ȶ��"; cin >> repaymentMethodFlag;

	if (repaymentMethodFlag==1)
	{
		debtor = new EqualMonthlyInstallments(Name,loanAmount,Periods,annualInterestRate);//������ָ��ָ��ȶϢ
		debtor->showSchedule();
	}
	else if (repaymentMethodFlag==2)
	{
		debtor = new EquivalentPrincipal(Name, loanAmount, Periods, annualInterestRate);//������ָ��ָ��ȶ��
		debtor->showSchedule();
	}

	//�������޲��仹���¹�����
	int planFlag = 0;
	int prepayTime;//�Ƿ���Ҫ��ǰ����ı�ǩ
	cout << "�Ƿ���Ҫ��ǰ���(����Ҫ����1����Ҫ����2)��"; cin >> planFlag;


	if (planFlag ==2)
	{
		double newRate, prepayAmount;
		auto vec = debtor->getSchedule();
		cout << "��������ǰ������·ݣ�"; cin >> prepayTime;
		cout << "��ѡ����ǰ����ķ�ʽ(1��ȫ�����壬2�����ֻ���)��"; cin >> planFlag;

		if (planFlag == 1)
		{
			Prepay* Prepayer = new FullPrepay(prepayTime, vec);
			Prepayer->showSchedule();
		}
		else if (planFlag == 2)
		{
			cout << "��������ǰ����Ľ�"; cin >> prepayAmount;
			cout << "�������µ������ʣ�"; cin >> newRate;
			//�����ȶϢ���ǵȶ��
			int wayFlag;
			cout << "��ѡ����ǰ����(1���¹����٣����޲��䣬2���¹����䣬��������)��"; cin >> planFlag;
			if (planFlag == 1)
			{
				cout << "��ѡ�����������ʽ(1���ȶϢ��2���ȶ��)��"; cin >> wayFlag;
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
				cout << "��ѡ�����������ʽ(1���ȶϢ��2���ȶ��)��"; cin >> wayFlag;
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