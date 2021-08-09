# include <iostream>

namespace mystd {
	using namespace std;

	class ostream {
	public:
		ostream& operator << (char* str) {
			printf("%s", str);
			return *this;
		}

		ostream& operator << (char str) {
			printf("%c", str);
			return *this;
		}

		ostream& operator << (int num) {
			printf("%d", num);
			return *this;
		}

		ostream& operator <<  (double e) {
			printf("%g", e);
			return *this;
		}

		ostream& operator << (ostream& (*fp)(ostream& ostm)) {
			return fp(*this);
		}
	};

	ostream& endl(ostream& ostm) {
		ostm << '\n';
		fflush(stdout);
		return ostm;
	}

	ostream cout;
}

int main() {
	using mystd::cout;
	using mystd::endl;
	cout << 3.14 << endl << 123 << endl;
	return 0;
}

/*

[���� ���]
3.14
123

[�ڵ� �м�]

1. ������ �����ε� �� ��� �Լ��� ��ȯ���� ostream& operator << ( ~ )�� ���� ���ǵǴ� ���� 
	: �̴� �������� (��������) << ������ ����� ���Ͽ� ���ǵǾ���. 
	�ռ� �ڵ带 ���� cout�� ostream ��ü��� ���� Ȯ���� �� �ִ�. 
	���� cout << 1 << 2 << endl; �� ���� �ڵ带 ���÷� ��� �����غ��ٸ�, 
	cout << 1 �� cout.operator<<(1)�� ������ �� �ִ�. 
	�̶� �ش� ������ ����� �ٽ� cout�� ������ Ÿ���� ��ü, �� ostream ��ü�� ��ȯ�Ǿ�� 
	������ �̾��� (cout << 1).operator<<(2) ������ ����������. 
	(�ѹ��� << ���길 �Ͼ ���, printf�� Ȱ���Ͽ�, void ��ȯ���� �Լ��� ���ǰ� �����ϴ�.) 
	���� �ش� ������ �����ε� �Լ��� ��ȯ���� ostream (������)���� �����Ǿ�� �Ѵ�. 

2. �ռ� ���Ǹ� �������, �Լ� ������ ������ �κ� return *this; �ڵ带 ���캸��. 
	: this �����ʹ� �� ��ü�� �ּҸ� ����Ų��. �� this pointer�� �տ� *�� �پ����Ƿ�,
	�̴� ����ü�� ��ü�� �ǹ��Ѵ�. �� ������ �̷���� cout (ostream)��ü�� �ٽ� ��ȯ�ȴ�. 
	�̸� ���� �������� ostream ��ü�� ���� << (�����ε�)���� ������ �����ϴ�. 

3. 	ostream& endl(ostream& ostm) {
	ostm << '\n';
	fflush(stdout);
	return ostm;
}
	: �ش� �ڵ带 ���� endl�� ostream&�� ��ȯ������ ���� �����Լ����� �� �� �ִ�. 
	endl �Լ��� ostream ��ü ostm�� ���������� �޴´�. 
	�ش� �Լ��� �ٹٲް� ���Ҿ�, ���۸� ���� ���ҵ� �����Ѵ�. 
	���� �ٽ� ostream ��ü�� ���������� ��ȯ�Ѵ�. 

*/