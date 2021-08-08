# include <iostream>
using namespace std;

class Point {
private:
	int xpos;
	int ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) { }

	void ShowPosition() {
		cout << "[ " << xpos << ", " << ypos << " ]" << endl;
	}

	Point& operator++ () {					// 전위 연산자, 멤버함수 
		xpos = xpos + 1;
		ypos = ypos + 1;
		return *this;						// 현재 객체를 ref로 반환한다. (별명, 참조형)
	}

	const Point operator++(int) {			// 후위 연산자, 멤버함수, const 반환형 -> 반환 임시 객체가 const
		const Point retobj(xpos, ypos);		// const 객체 생성 (함수 내부에서 retobj 객체의 상수화)
		xpos = xpos + 1;
		ypos = ypos + 1;					// 후위 연산 시행 (이런 방식으로 연산이 이루어지는구나)
		return retobj;						// retobj -> 임시 객체를 const로 반환한다.
	}										// const 함수는 아니다! (멤버 변수의 변경이 없는 함수) -> 뒤에 const 

	friend Point& operator-- (Point& ref);
	friend const Point operator-- (Point& ref, int);		// friend 선언들 -> private에 접근하기 위해
};

Point& operator--(Point& ref) {				// 전위 연산자, 전역 함수 (참조형 반환, 참조형 parameter)
	ref.xpos -= 1;							// friend로 인하여 private 멤버에 직접 접근 가능 
	ref.ypos -= 1;
	return ref;								// ref를 참조형으로(별명으로) 반환한다. 
}

const Point operator--(Point& ref, int) {	// 후위 연산자(int를 parameter로 뒤에 넣어준다.) 전역 함수 
	const Point retobj(ref);				// const형 객체 생성 (return에 활용하려고)
	ref.xpos -= 1;							// 객체의 private 멤버 변형 (const함수가 아님!!)
	ref.ypos -= 1;							// 마찬가지로 privqte 멤버에 접근 가능 (by friend 선언)
	return retobj;							// 임시 객체를 const로 생성하여 반환한다. 
}

int main() {
	Point pos(3, 5);
	Point cpy;
	cpy = pos--;
	cpy.ShowPosition();
	pos.ShowPosition();

	cpy = pos++;
	cpy.ShowPosition();
	pos.ShowPosition();


	++(++pos);
	pos.ShowPosition();
	--(--pos);
	pos.ShowPosition();
	//++(pos++);
	//--(pos--);
	//(pos++)++;
	//(pos--)--;
	return 0;
}

/*

[실행 결과]

[ 3, 5 ]
[ 2, 4 ]
[ 2, 4 ]
[ 3, 5 ]
[ 5, 7 ]
[ 3, 5 ]

[코드 분석]

1. ++(pos++);
	: 후위 연산자를 시행한 뒤, return type이 const로 지정되었다. 
	따라서 const형 임시 객체가 반한되고, 이 상수형 객체는 함수가 멤버 변수를 변경하는가의 여부와 무관하게
	const형 함수에 의한 연산만 가능하다. 
	이때 후위 연산자와 전위 연산자 모두 cosnt형 함수가 아니므로, 더이상 pos에 연산자 오버로딩을 적용할 수 없다. 
	주의할 점은 후위 연산자 정의 시, 반환형이 const라는 것과 const 함수를 헷갈리지 않는 것이다. 
	const함수의 const는 뒷부분에, 반환형 const는 앞부분에 붙는다!
	따라서 후위 연산자 함수의 경우 const 반환형에는 해당하지만, const 함수는 아니다!
	따라서 3번과 4번의 경우에도 컴파일 에러가 발생한다. 

2. --(pos--);
	: 후위 연산자 -- 의 오버로딩된 함수를 통하여 Point형 const 임시 객체가 생성된다. 
	이후 전위 연산 --을 시행하기 위해, 오버로딩된 함수를 살펴보면 
	해당 멤버 함수는 const 함수가 아니므로, const 객체에서 호출이 불가능하다. 
	따라서 컴파일 에러가 발생한다. 

3. (pos++)++;
	: 연산자 오버로딩 함수를 통해 (pos++)연산이 완료되면
	Point형 const 임시객체가 생성된다. 
	const형 객체를 대상으로는 const 함수만 호출 가능하다.
	따라서 후위 연산자 ++ 함수는 const 함수가 아니므로 (멤버를 변화시키므로 애초에 불가능하다.)
	해당 문자는 컴파일 에러가 발생한다. 

4. (pos--)--;
	: 3번과 동일한 이유로 컴파일 에러가 발생한다. 

	오늘의 깨달음 : const 반환형 함수와, const 함수 (멤버의 변형 금지)를 명확히 구분하자.

	+ 왜 후위 연산자 정의에서는 반환형에 ref(참조자)를 사용하지 않을까?
	- 참조자는 복사를 통해 새로운 객체를 생성하지 않고, 이에 별명을 붙이는 것이다. 
	- 전위 연산자에서는 입력과 반환 모두 ref 형으로 정의된다. 
	- 실제로 해당 객체의 멤버를 증가시키고, 현 객체를 다시 참조형으로 반환한다. 
	- 하지만 후위 연산자는 새로운 const형 객체를 생성해둔 뒤, 멤버 조작과 무관하게 이를 반환한다. 
	- 멤버 변수를 조작한 결과와는 별개로 다른 객체를 반환해야 하므로 반환형에는 ref를 쓸 수 없다. 
	- 하지만, 입력된 객체는 참조형으로 받아, 해당 객체의 멤버를 직접 조작하여 저장해둔다. 
	- 이후 객체에 접근하여 멤버 함수를 통해 멤버 변수를 출력해보면, 후위 연산 과정이 저장됨을 확인할 수 있다. 

*/