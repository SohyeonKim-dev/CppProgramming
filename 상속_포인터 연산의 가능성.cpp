# include <iostream>
using namespace std;

class First {
public: 
	void FirstFunc() {
		cout << "첫번째 class의 멤버 함수" << endl;
	}
};

class Second : public First {
public:
	void SecondFunc() {
		cout << "두번째 class의 멤버 함수" << endl;
	}
};

class Third : public Second {
public:
	void ThirdFunc() {
		cout << "세번째 class의 멤버 함수" << endl;
	}
};

int main() {
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;
}

/*

[실행 코드 분석]

1. new 연산에 의해 생성된 객체, Third 형 or Third class를 상속하는 class 객체를 가리키는 포인터 tptr
2. Second 형 or Second class를 상속하는 class 객체를 가리키는 포인터 sptr
	: tptr은 Third형 포인터이므로, 이는 Second class를 상속하는 class 객체를 가리키므로 가능하다. 
3. First 형 or First class를 상속하는 클래스 객체를 가리키는 포인터 fptr (혹은 그러한 객체의 주소를 저장하는 변수)
	: sptr은 Second형 포인터. 즉 first class를 상속하는 클래스 객체를 가리키는 포인터이므로 가능하다. 

	다음 코드들을 자세히 살펴보자. 

tptr -> FirstFunc();		1		// tptr은 Third형 포인터이다. 즉 모든 class의 멤버에 접근 가능하다.
tptr -> SecondFunc();		1		// (상속 관계를 생각해보면, 가장 많은 멤버를 보유(?)함을 알 수 있으니까!)
tptr -> ThirdFunc();		1

sptr -> FirstFunc();		1
sptr -> SecondFunc();		1		// sptr은 자신을 상속하는 Third class의 멤버에는 접근할 수 없지. 
sptr -> ThirdFunc();		0		// 포인터의 접근 가능성과 헷갈리면 안된다! (정 반대임)

fptr -> FirstFunc();		1		// 가장 부모, base 클래스인 First 클래스는 상속받는 추가적인 멤버들이 없다. 
fptr -> SecondFunc();		0		// 따라서 자기 자신의 멤버 이외의 다른 클래스의 멤버 함수에는 다음과 같이 접근 불가능
fptr -> ThirdFunc();		0

[ 결론 ]

1. 포인터 형에 해당하는 클래스에 정의된 (상속받은) 멤버에만 접근이 가능하다.
2. "C++ 컴파일러는 포인터를 이용한 연산의 가능성 여부를 판단할 때, 포인터의 자료형을 기준으로 판단하지,
	실제 가리키는 객체의 자료형을 기준으로 판단하지 않는다. "

	[예시 코드]

	int main () {
		Base * bptr = new Derived();		1
		Derived * dptr = bptr;				0 (컴파일 에러)
 	}

	[코드 분석]

	1. Derived class는 Base class의 자식 클래스. 
		따라서 base 클래스의 포인터 변수로 Derived 객체의 참조가 가능하다!
		문제없이 컴파일된다. 

	2. 하지만 두번째 코드에서는 컴파일 에러가 발생한다. 
		*** 컴파일러는 앞서 bptr이 실제로 가리키는 객체가 base객체가 아니라 derived객체라는 것을 기억하지 않는다!! ***
		"bptr은 base형 포인터니까, bptr이 가리키는 객체는 base 객체일 수 있다는 거잖아! 
		 그럴 경우에는 이 문장이 성립하지 않으니 컴파일 에러를 발생하겠어!" wow
		(이를 Base * bptr = dptr ; 로 작성하면 문제 없이 컴파일된다.)

		복습 -> c++ 컴파일러는 포인터를 이용한 연산의 가능성 여부를 판단할 때, 
				포인터의 자료형을 기준으로 판단하지.
				실제 가리키는 객체의 자료형을 기준으로 판단하지 않는다. (실체를 기억하지 않는다.)

*/