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
	cout << "x, y 좌표 순서대로 입력하세요. ^_^ : ";
	cin >> pos1;
	cout << pos1;

	Point pos2;
	cout << "x, y 좌표 순서대로 입력하세요. ^_^ : ";
	cin >> pos2;
	cout << pos2;
	return 0;
}

/*

[실행 결과 (예시)]

x, y 좌표 순서대로 입력하세요. ^_^ : 3 4
[3, 4]
x, y 좌표 순서대로 입력하세요. ^_^ : 2 8
[2, 8]

[코드 분석]

1. ostream과 istream의 연산자 오버로딩에서 차이점이 존재한다는 것을 확인할 수 있었다. 
	: 먼저 ostream객체 cout(os)에 대한 << 연산자 오버로딩을 살펴보자. 
	이는 사용의 편의를 위해 좌표를 [a, b]의 형태로 출력할 수 있도록 도와준다. 
	(friend 선언을 통해 전역 함수임에도 멤버 변수에 접근할 수 있다.)
	해당 연산자는 실행 코드에서와 같이 cout << (ostream)객체 ; 의 방식으로 사용한다. 
	이때 연산자 오버로딩 함수의 내부 정의에 의해, x좌표와 y좌표를 형식에 맞추어 출력한다. 
	기존의 << 연산자가 함께 사용되었음을 주의하자. ( Ex) os << "[" << pos.xpos ...; )

2. istream& operator >> (istream& is, Point& pos) {
	is >> pos.xpos >> pos.ypos;
	return is;
}
	: istream 객체(cin, is)에 대한 >> 연산자 오버로딩 함수는 위처럼, <<와 다른 형태를 보인다. 
	이는 cin을 사용하는 경험을 자연스레 떠올리면 수월하게 이해할 수 있다. 
	우선, >> 연산자 오버로딩 함수는 istream 참조형 객체 is와 Point 객체 pos를 입력받고, 
	istream& (참조형) 객체를 반환한다. (이 함수만 본다면 연쇄 사용은 불가능할 것이다.)
	is객체에 대하여, xpos와 ypos 값을 차례대로 입력받아 pos 객체의 멤버 변수에 각각 대입한다.
	이후 변경된 istream형 객체 is 를 참조형으로 반환한다. 
	이때 객체의 멤버에 접근하여, 직접적인 변형이 가해지므로, ostream의 <<와 달리
	입력 parameter의 Point& 객체 pos 앞에 const가 붙지 않는다.
	(상수형 객체는 멤버 변수를 변형하면 안되기 때문에! -> 기존 값을 보존한 채 출력만 하는 경우는 가능하겠지.)

*/
