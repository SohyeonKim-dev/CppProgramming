# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <cstring>
using namespace std;

class Employee {
private:
	char name[100];
public:
	Employee(char* name) {
		strcpy(this->name, name);		// this �����͸� Ȱ���Ͽ� ����ü�� ����� �Է� parameter�� ������.
	}

	void ShowYourName() const {
		cout << "name: " << name << endl;
	}

	virtual int GetPay() const {
		return 0;
	}

	virtual void ShowSalaryInfo() const { }
};

class PermanentWorker : public Employee {
private:
	int salary;
public:
	PermanentWorker(char* name, int money)
		: Employee(name), salary(money){ }

	int GetPay() const {				// �굵 �ڵ����� virtual �Լ� ����?
		return salary;
	}

	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl;
	}
};

class TemporaryWorker : public Employee {
private:
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(char* name, int pay)
		: Employee(name), workTime(0), payPerHour(pay) { }

	void AddWorkTime(int time) {
		workTime = workTime + time;
	}

	int GetPay() const {
		return workTime * payPerHour;
	}

	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl;
	}
};

class SalesWorker : public PermanentWorker {
private:
	int salesResult;
	double bonusRatio;
public:
	SalesWorker(char * name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) { }

	void AddSalesResult(int value) {
		salesResult = salesResult + value;
	}

	int GetPay() const {
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
	}

	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl;
	}
};

class EmployeeHandler {
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0) { }

	void AddEmployee(Employee* emp) {
		empList[empNum++] = emp;		
	}

	void ShowAllSalaryInfo() const {
		for (int i = 0; i < empNum; i++) {
			empList[i]->ShowSalaryInfo();
		}
	}

	void ShowTotalSalary() const {
		int sum = 0;
		for (int i = 0; i < empNum; i++) {
			sum = sum + empList[i]->GetPay();
		}
		cout << "salary sum: " << sum << endl;
	}

	~EmployeeHandler() {
		for (int i = 0; i < empNum; i++) {
			delete empList[i];
		}
	}
};

int main() {
	//���� ������ �������� ����� ��Ʈ�� Ŭ���� ��ü ���� 
	EmployeeHandler handler;

	// ������ ��� 
	handler.AddEmployee(new PermanentWorker("�����", 10000));
	handler.AddEmployee(new PermanentWorker("����ݸ�", 15000));

	// �ӽ��� ���
	TemporaryWorker* alba = new TemporaryWorker("����", 9200);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	// ������ ��� 
	SalesWorker* seller = new SalesWorker("ȣ����", 9000, 0.2);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);

	// �̹��޿� �����ؾ� �� �޿��� ���� 
	handler.ShowAllSalaryInfo();

	// �̹� �޿� �����ؾ� �� �ݾ��� ����
	handler.ShowTotalSalary();
	return 0;
}

/*
[���� ���]

name: �����
salary: 10000
name: ����ݸ�
salary: 15000
name: ����
salary: 46000
name: ȣ����
salary: 10400
salary sum: 81400

[���� �ڵ� �м�] 
1. �����Լ�(virtual function)�� ����

*/