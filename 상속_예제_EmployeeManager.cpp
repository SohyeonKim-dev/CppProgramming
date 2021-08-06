# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <cstring>
using namespace std;

class Employee {
private:
	char name[100];
public:
	Employee(char* name) {
		strcpy(this->name, name);		// this 포인터를 활용하여 현객체의 멤버와 입력 parameter를 구분함.
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

	int GetPay() const {				// 얘도 자동으로 virtual 함수 적용?
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
	//직원 관리를 목적으로 설계된 컨트롤 클래스 객체 생성 
	EmployeeHandler handler;

	// 정규직 등록 
	handler.AddEmployee(new PermanentWorker("김소현", 10000));
	handler.AddEmployee(new PermanentWorker("브로콜리", 15000));

	// 임시직 등록
	TemporaryWorker* alba = new TemporaryWorker("나비", 9200);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	// 영업직 등록 
	SalesWorker* seller = new SalesWorker("호랑이", 9000, 0.2);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);

	// 이번달에 지급해야 할 급여의 정보 
	handler.ShowAllSalaryInfo();

	// 이번 달에 지불해야 할 금액의 총합
	handler.ShowTotalSalary();
	return 0;
}

/*
[실행 결과]

name: 김소현
salary: 10000
name: 브로콜리
salary: 15000
name: 나비
salary: 46000
name: 호랑이
salary: 10400
salary sum: 81400

[실행 코드 분석] 
1. 가상함수(virtual function)의 도입

*/