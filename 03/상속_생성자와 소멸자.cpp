#include <iostream>
# include <cstring>
using namespace std;

class 학생 {
private:
	char* name;

public:
	학생(char *myname) {
		name = new char[strlen(myname)+1];
		strcpy(name, myname);
		cout << "학생(부모class) 객체 생성!" << endl;
	}

	~학생() {
		delete[] name; // 동적 할당된 메모리 공간을 해제한다. 
		cout << "학생(부모class) 객체 소멸!" << endl;
	}

	void WhatYourName() const {
		cout << "내 이름은 바로 " << name << endl;
	}
};

class 대학생 :public 학생 {
private:
	char* major;

public:
	대학생(char* myname, char* mymajor) 
		: 학생(myname) {
		major = new char[strlen(mymajor)+1];
		strcpy(major, mymajor);
		cout << "대학생(자식class) 객체 생성!" << endl;
	}

	~대학생() {
		delete[] major;
		cout << "대학생(자식class) 객체 소멸!" << endl;
	}

	void WhoAreYou() const {
		WhatYourName();
		cout << "내 전공은 바로 " << major << endl;
	}
};

int main() {
	대학생 소현("KimSoHyeon", "Astrophysics");
	소현.WhoAreYou();
	대학생 브로콜리("Broccoli", "ComputerScience");
	브로콜리.WhoAreYou();
	return 0;
}

/*
[실행 결과]

학생(부모class) 객체 생성!
대학생(자식class) 객체 생성!
내 이름은 바로 KimSoHyeon
내 전공은 바로 Astrophysics
학생(부모class) 객체 생성!
대학생(자식class) 객체 생성!
내 이름은 바로 Broccoli
내 전공은 바로 ComputerScience
대학생(자식class) 객체 소멸!
학생(부모class) 객체 소멸!
대학생(자식class) 객체 소멸!
학생(부모class) 객체 소멸!

[실행 코드 분석]
1. 컴파일러에 따라 실행 코드의 객체 생성 과정에서 오류가 발생한다. ( https://csacademy.com/workspace/ 를 활용했다.)
2. derived class의 객체를 생성할 때, base class의 생성자가 먼저 실행된다. 이후 derived class 생성자의 남은 부분들이 실행된다. 
3. 메인 함수가 종료될 때, 두 대학생 객체의 소멸자가 호출된다. 이때 나중에 생성된 객체(브로콜리)의 소멸자가 먼저 호출된다. 
4. 생성과 반대로, derived class의 객체가 소멸될 때는 base가 아닌 derived class의 소멸자가 먼저 실행됨을 확인할 수 있다. 
5. 소멸자를 통해 생성자에서 동적 할당된 메모리 공간을 해제한다. 

*/
