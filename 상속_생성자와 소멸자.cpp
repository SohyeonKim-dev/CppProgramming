#include <iostream>
# include <cstring>
using namespace std;

class �л� {
private:
	char* name;

public:
	�л�(char *myname) {
		name = new char[strlen(myname)+1];
		strcpy(name, myname);
		cout << "�л�(�θ�class) ��ü ����!" << endl;
	}

	~�л�() {
		delete[] name; // ���� �Ҵ�� �޸� ������ �����Ѵ�. 
		cout << "�л�(�θ�class) ��ü �Ҹ�!" << endl;
	}

	void WhatYourName() const {
		cout << "�� �̸��� �ٷ� " << name << endl;
	}
};

class ���л� :public �л� {
private:
	char* major;

public:
	���л�(char* myname, char* mymajor) 
		: �л�(myname) {
		major = new char[strlen(mymajor)+1];
		strcpy(major, mymajor);
		cout << "���л�(�ڽ�class) ��ü ����!" << endl;
	}

	~���л�() {
		delete[] major;
		cout << "���л�(�ڽ�class) ��ü �Ҹ�!" << endl;
	}

	void WhoAreYou() const {
		WhatYourName();
		cout << "�� ������ �ٷ� " << major << endl;
	}
};

int main() {
	���л� ����("KimSoHyeon", "Astrophysics");
	����.WhoAreYou();
	���л� ����ݸ�("Broccoli", "ComputerScience");
	����ݸ�.WhoAreYou();
	return 0;
}

/*
[���� ���]

�л�(�θ�class) ��ü ����!
���л�(�ڽ�class) ��ü ����!
�� �̸��� �ٷ� KimSoHyeon
�� ������ �ٷ� Astrophysics
�л�(�θ�class) ��ü ����!
���л�(�ڽ�class) ��ü ����!
�� �̸��� �ٷ� Broccoli
�� ������ �ٷ� ComputerScience
���л�(�ڽ�class) ��ü �Ҹ�!
�л�(�θ�class) ��ü �Ҹ�!
���л�(�ڽ�class) ��ü �Ҹ�!
�л�(�θ�class) ��ü �Ҹ�!

[���� �ڵ� �м�]
1. �����Ϸ��� ���� ���� �ڵ��� ��ü ���� �������� ������ �߻��Ѵ�. ( https://csacademy.com/workspace/ �� Ȱ���ߴ�.)
2. derived class�� ��ü�� ������ ��, base class�� �����ڰ� ���� ����ȴ�. ���� derived class �������� ���� �κе��� ����ȴ�. 
3. ���� �Լ��� ����� ��, �� ���л� ��ü�� �Ҹ��ڰ� ȣ��ȴ�. �̶� ���߿� ������ ��ü(����ݸ�)�� �Ҹ��ڰ� ���� ȣ��ȴ�. 
4. ������ �ݴ��, derived class�� ��ü�� �Ҹ�� ���� base�� �ƴ� derived class�� �Ҹ��ڰ� ���� ������� Ȯ���� �� �ִ�. 
5. �Ҹ��ڸ� ���� �����ڿ��� ���� �Ҵ�� �޸� ������ �����Ѵ�. 

*/