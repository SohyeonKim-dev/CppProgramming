# include <iostream>
using namespace std;

class First {
public:
	void FirstFunc() {
		cout << "ù��° �Լ� ȣ��" << endl;
	}
	virtual void SimpleFunc() {
		cout << "ù��° ������ �Լ� ȣ��" << endl;
	}
};

class Second : public First {
public:
	void SecondFunc() {
		cout << "�ι�° �Լ� ȣ��" << endl;
	}
	virtual void SimpleFunc() {
		cout << "�ι�° ������ �Լ� ȣ��" << endl;
	}
};

class Third : public Second {
public:
	void ThirdFunc() {
		cout << "����° �Լ� ȣ��" << endl;
	}
	virtual void SimpleFunc() {
		cout << "����° ������ �Լ� ȣ��" << endl;
	}
};

int main() {
	Third obj;
	obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();

	Second* sptr = &obj;
	sptr->FirstFunc();
	sptr->SecondFunc();
	sptr->SimpleFunc();

	First& fref = obj;
	fref.FirstFunc();
	fref.SimpleFunc();
	return 0;
}

/*

[���� ���]
ù��° �Լ� ȣ��
�ι�° �Լ� ȣ��
����° �Լ� ȣ��
����° ������ �Լ� ȣ��
ù��° �Լ� ȣ��
�ι�° �Լ� ȣ��
����° ������ �Լ� ȣ��
ù��° �Լ� ȣ��
����° ������ �Լ� ȣ��

[�ڵ� �м�]
1. First�� �����ڴ� First ��ü Ȥ�� �� Ŭ������ ����ϴ� Ŭ������ ��ü�� ������ �� �ִ�. 
	: �̰͵� ������ ���ɼ�ó��, ��ӽ� ������ �� �ִ� �������� ��������. (����)
2. ���� �Լ��� ���䵵 �����ϰ� �����. (���� ��ü�� �����ϴ� ��ü class�� ����� �ҷ��´�.)
	: virtual ��� ���ϸ�, �������� �ڷ����� ������� �ܼ��ϰ� �������̵��� �Լ��� ��� ȣ��ȴ�. 
	+ ���� �Լ� - ���� ���� �Լ� (=0;) - �߻� Ŭ���� (���� ���� �Լ��� �ϳ� �̻� ����� ���� class)
		Ex) Employee Ŭ���� : ��ü ������ �����ϱ� ���Ͽ� (�����Ϸ��� ���� ǥ������ ������, �� ���� �۵��ϱ⿡ ���� ������!)

*/