# include <iostream>
using namespace std;

class First {
private:
	int num1;
	int num2;
public:
	First(int n1=0, int n2=0) : num1(n1), num2(n2) { }

	void ShowData() {
		cout << num1 << ", " << num2 << endl;
	}

	First& operator= (const First& ref) {
		cout << "First& operator =()" << endl;
		num1 = ref.num1;
		num2 = ref.num2;
		return *this;
	}
};

class Second : public First {
private:
	int num3;
	int num4;
public:
	Second(int n1, int n2, int n3, int n4)
		: First(n1, n2), num3(n3), num4(n4) { }

	void ShowData() {
		First::ShowData();
		cout << num3 << ", " << num4 << endl;
	}

	/*
	
	Second& operator=(const Second& ref) {
		cout << "Second& operator=()" << endl;
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
	}

	*/
};

int main() {
	Second object_second(111, 222, 333, 444);
	Second object_copied(0, 0, 0, 0);
	object_copied = object_second;
	object_copied.ShowData();
	return 0;
}

/*

[���� ���]

First& operator =()
111, 222
333, 444

[�ּ� ���� �� ���� ���]

Second& operator=()
0, 0
333, 444

[�ڵ� �м�]

1. ����(�ڽ�) Ŭ�������� ���� �����ڸ� ������ ���, �θ� Ŭ������ ����� ���� ���� ������ ����� �̷������ �ʴ´�. 
	: (���� Ŭ�������� ����Ʈ ���� �����ڸ� ȣ���� ���, �ڵ����� �⺻(���̽�, �θ�)Ŭ������ ���� ������ ȣ���)
	��, ���� Ŭ������ ���� ������ ���� �� ��������� ���� Ŭ������ ���� ������ ȣ�⹮�� �������� ���� ��, 
	���� Ŭ������ ���� �����ڴ� ȣ����� �ʾ�, ���� Ŭ������ ��� ������ ��� �� ����� ���� ��󿡼� ���ܵȴ�. 
	-> ���� ���� Ŭ������ ���� �����ڸ� ���� �����ؾ� �ϴ� ���, �� ���� Ŭ������ ���� �����ڸ� ��������� ȣ���ؾ� �Ѵ�. 

2.	Second& operator= (const Second& ref) {
		cout << "Second& operator=()" << endl;
		First::operator=(ref);								// �� ������ ���� ���� �ذ� ����!
		num3 = ref.num3;
		nem4 = ref.num4;
		return *this;
		}

3. Second ������ ���� ref�� First operator�� �Է� parameter�� ���ǵ� First�� �����ڿ� ���� ���� �Է� ������
	: "c++���� ~�� �����ڴ� ~�� ��ü �Ǵ� ~���� ���� Ȥ�� ���������� ����ϴ� ��� ��ü�� ������ �� �ִ�."
	-> �� First�� �����ڴ� �� ���� �� �ִ�! (��� ������ ��ü�� �� �������� �� ����)


*/