# include <iostream>
using namespace std;

class First {
public:
	void FirstFunc() {
		cout << "첫번째 함수 호출" << endl;
	}
	virtual void SimpleFunc() {
		cout << "첫번째 간단한 함수 호출" << endl;
	}
};

class Second : public First {
public:
	void SecondFunc() {
		cout << "두번째 함수 호출" << endl;
	}
	virtual void SimpleFunc() {
		cout << "두번째 간단한 함수 호출" << endl;
	}
};

class Third : public Second {
public:
	void ThirdFunc() {
		cout << "세번째 함수 호출" << endl;
	}
	virtual void SimpleFunc() {
		cout << "세번째 간단한 함수 호출" << endl;
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

[실행 결과]
첫번째 함수 호출
두번째 함수 호출
세번째 함수 호출
세번째 간단한 함수 호출
첫번째 함수 호출
두번째 함수 호출
세번째 간단한 함수 호출
첫번째 함수 호출
세번째 간단한 함수 호출

[코드 분석]
1. First형 참조자는 First 객체 혹은 이 클래스를 상속하는 클래스의 객체를 참조할 수 있다. 
	: 이것도 포인터 가능성처럼, 상속시 넓혀갈 수 있는 개념으로 이해하자. (동일)
2. 가상 함수의 개념도 유사하게 적용됨. (실제 객체가 참조하는 객체 class의 멤버를 불러온다.)
	: virtual 사용 안하면, 참조자의 자료형을 기반으로 단순하게 오버라이딩된 함수들 모두 호출된다. 
	+ 가상 함수 - 순수 가상 함수 (=0;) - 추상 클래스 (순수 가상 함수를 하나 이상 멤버로 갖는 class)
		Ex) Employee 클래스 : 객체 생성을 방지하기 위하여 (컴파일러는 에러 표시하지 않지만, 즉 정상 작동하기에 오류 방지용!)

*/