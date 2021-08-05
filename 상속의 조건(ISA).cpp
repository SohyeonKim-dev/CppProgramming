# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <cstring>
using namespace std;

class ��ǻ�� {
private:
	char owner[50];
public:
	��ǻ��(char* name) {
		strcpy(owner, name);
		cout << "��ǻ�� ��ü ����!" << endl;
	}
	~��ǻ��() {
		cout << "��ǻ�� ��ü �Ҹ�!" << endl;
	}

	void Calculate() {
		cout << "��û ������ ����մϴ�." << endl;
	}
};

class ��Ʈ�� : public ��ǻ�� {
private:
	int Battery;
public:
	��Ʈ�� (char* name, int initChag)
		: ��ǻ��(name), Battery(initChag) {
		cout << "��Ʈ�� ��ü ����!" << endl;
	}

	~��Ʈ��() {
		cout << "��Ʈ�� ��ü �Ҹ�!" << endl;
	}

	void Charging() {
		Battery = Battery + 5;
	}

	void UseBattery() {
		Battery = Battery -1 ;
	}

	int GetBatteryInfo() {
		return Battery;
	}

	void MovingCal() {
		if (GetBatteryInfo() < 1) {
			cout << "������ �ʿ��մϴ�." << endl;
			return;
		}
		cout << "�̵��ϸ鼭 " << endl;
		Calculate();
		UseBattery();
	}
};

class �º�PC : public ��Ʈ�� {
private:
	char regstPenModel[50];
public:
	�º�PC(char* name, int initChag, char* pen)
		: ��Ʈ��(name, initChag) {
		strcpy(regstPenModel, pen);
		cout << "�º�PC ��ü ����!" << endl;
	}

	~�º�PC() {
		cout << "�º�PC ��ü �Ҹ�!" << endl;
	}

	void Write(char* penInfo) {
		if (GetBatteryInfo() < 1) {
			cout << "������ �ʿ��մϴ�." << endl;
			return;
		}
		if (strcmp(regstPenModel, penInfo) != 0) {
			cout << "��ϵ� ���� �ƴմϴ�." << endl;
			return;
		}
		cout << "�ʱ� ������ ó���մϴ�." << endl;
		UseBattery();
	}
};

int main() {
	��Ʈ�� notebook1("�����", 5);
	�º�PC tabletPC1("����ݸ�", 10, "BroPen");
	notebook1.MovingCal();
	tabletPC1.Write("BroPen");
	return 0;
}

/*

[���� ���]

��ǻ�� ��ü ����!
��Ʈ�� ��ü ����!
��ǻ�� ��ü ����!
��Ʈ�� ��ü ����!
�º�PC ��ü ����!
�̵��ϸ鼭
��û ������ ����մϴ�.
�ʱ� ������ ó���մϴ�.
�º�PC ��ü �Ҹ�!
��Ʈ�� ��ü �Ҹ�!
��ǻ�� ��ü �Ҹ�!
��Ʈ�� ��ü �Ҹ�!
��ǻ�� ��ü �Ҹ�!

[���� �ڵ� �м�]

1. ��ü�� ������ ��, �����ڰ� ȣ��Ǵ� ������ ��ǻ�� -> ��Ʈ�� -> �º�PC ���̴�.
2. ��ü�� �Ҹ�� ��, �Ҹ��ڰ� ȣ��Ǵ� ������ �º�PC -> ��Ʈ�� -> ��ǻ�� ���̴�.
3. �Ҹ��ڸ� �����Կ� �־, ���� �Ҵ��� �̷������ �ʾ����Ƿ�, delete�� ����ϸ� ������ �߻��Ѵ�. 
4. �����Ϸ��� ���� �ڵ� ���� ���ΰ� �޶�����. �ռ� ���� ����� (https://csacademy.com/workspace/)���� ������ ����� �������� �ۼ��Ǿ���. 
	: Visual Studio������ ������ �߻��Ѵ�. 
5. ����� ���� (is a) 
	: ��Ʈ�� is a ��ǻ��
	: �º�PC is a ��Ʈ��
	: �º�PC is a ��ǻ��
	( Derived class is a Base class )
	( �ڽ� class is a �θ� class )

	+ ����� ��Ʃ��� ���� �ذ�! 
	1. ������Ʈ -> �Ӽ� -> �����Ӽ� => C/C++ => ��� â�� �ִ� �ؼ���� �ƴϿ��� �����ϸ� ���� �߻�X!!
		: strcpy���� ���� �߻�
	2. # define _CRT_SECURE_NO_WARNINGS �� ����ϸ� �ذ�ȴ�.
*/