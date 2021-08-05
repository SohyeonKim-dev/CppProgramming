# include <iostream>
using namespace std;

class First {
public: 
	void FirstFunc() {
		cout << "ù��° class�� ��� �Լ�" << endl;
	}
};

class Second : public First {
public:
	void SecondFunc() {
		cout << "�ι�° class�� ��� �Լ�" << endl;
	}
};

class Third : public Second {
public:
	void ThirdFunc() {
		cout << "����° class�� ��� �Լ�" << endl;
	}
};

int main() {
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;
}

/*

[���� �ڵ� �м�]

1. new ���꿡 ���� ������ ��ü, Third �� or Third class�� ����ϴ� class ��ü�� ����Ű�� ������ tptr
2. Second �� or Second class�� ����ϴ� class ��ü�� ����Ű�� ������ sptr
	: tptr�� Third�� �������̹Ƿ�, �̴� Second class�� ����ϴ� class ��ü�� ����Ű�Ƿ� �����ϴ�. 
3. First �� or First class�� ����ϴ� Ŭ���� ��ü�� ����Ű�� ������ fptr (Ȥ�� �׷��� ��ü�� �ּҸ� �����ϴ� ����)
	: sptr�� Second�� ������. �� first class�� ����ϴ� Ŭ���� ��ü�� ����Ű�� �������̹Ƿ� �����ϴ�. 

	���� �ڵ���� �ڼ��� ���캸��. 

tptr -> FirstFunc();		1		// tptr�� Third�� �������̴�. �� ��� class�� ����� ���� �����ϴ�.
tptr -> SecondFunc();		1		// (��� ���踦 �����غ���, ���� ���� ����� ����(?)���� �� �� �����ϱ�!)
tptr -> ThirdFunc();		1

sptr -> FirstFunc();		1
sptr -> SecondFunc();		1		// sptr�� �ڽ��� ����ϴ� Third class�� ������� ������ �� ����. 
sptr -> ThirdFunc();		0		// �������� ���� ���ɼ��� �򰥸��� �ȵȴ�! (�� �ݴ���)

fptr -> FirstFunc();		1		// ���� �θ�, base Ŭ������ First Ŭ������ ��ӹ޴� �߰����� ������� ����. 
fptr -> SecondFunc();		0		// ���� �ڱ� �ڽ��� ��� �̿��� �ٸ� Ŭ������ ��� �Լ����� ������ ���� ���� �Ұ���
fptr -> ThirdFunc();		0

[ ��� ]

1. ������ ���� �ش��ϴ� Ŭ������ ���ǵ� (��ӹ���) ������� ������ �����ϴ�.
2. "C++ �����Ϸ��� �����͸� �̿��� ������ ���ɼ� ���θ� �Ǵ��� ��, �������� �ڷ����� �������� �Ǵ�����,
	���� ����Ű�� ��ü�� �ڷ����� �������� �Ǵ����� �ʴ´�. "

	[���� �ڵ�]

	int main () {
		Base * bptr = new Derived();		1
		Derived * dptr = bptr;				0 (������ ����)
 	}

	[�ڵ� �м�]

	1. Derived class�� Base class�� �ڽ� Ŭ����. 
		���� base Ŭ������ ������ ������ Derived ��ü�� ������ �����ϴ�!
		�������� �����ϵȴ�. 

	2. ������ �ι�° �ڵ忡���� ������ ������ �߻��Ѵ�. 
		*** �����Ϸ��� �ռ� bptr�� ������ ����Ű�� ��ü�� base��ü�� �ƴ϶� derived��ü��� ���� ������� �ʴ´�!! ***
		"bptr�� base�� �����ʹϱ�, bptr�� ����Ű�� ��ü�� base ��ü�� �� �ִٴ� ���ݾ�! 
		 �׷� ��쿡�� �� ������ �������� ������ ������ ������ �߻��ϰھ�!" wow
		(�̸� Base * bptr = dptr ; �� �ۼ��ϸ� ���� ���� �����ϵȴ�.)

		���� -> c++ �����Ϸ��� �����͸� �̿��� ������ ���ɼ� ���θ� �Ǵ��� ��, 
				�������� �ڷ����� �������� �Ǵ�����.
				���� ����Ű�� ��ü�� �ڷ����� �������� �Ǵ����� �ʴ´�. (��ü�� ������� �ʴ´�.)

*/