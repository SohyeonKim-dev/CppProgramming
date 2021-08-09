#include <iostream>
using namespace std;

class Point {
private :
	int xpos;
	int ypos;

public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) { }

	void ShowPosition() const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}

	friend ostream& operator << (ostream&, const Point&);
	friend istream& operator >> (istream&, Point& pos);
};

ostream& operator << (ostream& os, const Point& pos) {
	os << "[" << pos.xpos << ", " << pos.ypos << "]" << endl;
	return os;
}

istream& operator >> (istream& is, Point& pos) {
	is >> pos.xpos >> pos.ypos;
	return is;
}

int main() {
	Point pos1;
	cout << "x, y ��ǥ ������� �Է��ϼ���. ^_^ : ";
	cin >> pos1;
	cout << pos1;

	Point pos2;
	cout << "x, y ��ǥ ������� �Է��ϼ���. ^_^ : ";
	cin >> pos2;
	cout << pos2;
	return 0;
}

/*

[���� ��� (����)]

x, y ��ǥ ������� �Է��ϼ���. ^_^ : 3 4
[3, 4]
x, y ��ǥ ������� �Է��ϼ���. ^_^ : 2 8
[2, 8]

[�ڵ� �м�]

1. ostream�� istream�� ������ �����ε����� �������� �����Ѵٴ� ���� Ȯ���� �� �־���. 
	: ���� ostream��ü cout(os)�� ���� << ������ �����ε��� ���캸��. 
	�̴� ����� ���Ǹ� ���� ��ǥ�� [a, b]�� ���·� ����� �� �ֵ��� �����ش�. 
	(friend ������ ���� ���� �Լ��ӿ��� ��� ������ ������ �� �ִ�.)
	�ش� �����ڴ� ���� �ڵ忡���� ���� cout << (ostream)��ü ; �� ������� ����Ѵ�. 
	�̶� ������ �����ε� �Լ��� ���� ���ǿ� ����, x��ǥ�� y��ǥ�� ���Ŀ� ���߾� ����Ѵ�. 
	������ << �����ڰ� �Բ� ���Ǿ����� ��������. ( Ex) os << "[" << pos.xpos ...; )

2. istream& operator >> (istream& is, Point& pos) {
	is >> pos.xpos >> pos.ypos;
	return is;
}
	: istream ��ü(cin, is)�� ���� >> ������ �����ε� �Լ��� ��ó��, <<�� �ٸ� ���¸� ���δ�. 
	�̴� cin�� ����ϴ� ������ �ڿ����� ���ø��� �����ϰ� ������ �� �ִ�. 
	�켱, >> ������ �����ε� �Լ��� istream ������ ��ü is�� Point ��ü pos�� �Է¹ް�, 
	istream& (������) ��ü�� ��ȯ�Ѵ�. (�� �Լ��� ���ٸ� ���� ����� �Ұ����� ���̴�.)
	is��ü�� ���Ͽ�, xpos�� ypos ���� ���ʴ�� �Է¹޾� pos ��ü�� ��� ������ ���� �����Ѵ�.
	���� ����� istream�� ��ü is �� ���������� ��ȯ�Ѵ�. 
	�̶� ��ü�� ����� �����Ͽ�, �������� ������ �������Ƿ�, ostream�� <<�� �޸�
	�Է� parameter�� Point& ��ü pos �տ� const�� ���� �ʴ´�.
	(����� ��ü�� ��� ������ �����ϸ� �ȵǱ� ������! -> ���� ���� ������ ä ��¸� �ϴ� ���� �����ϰ���.)

*/