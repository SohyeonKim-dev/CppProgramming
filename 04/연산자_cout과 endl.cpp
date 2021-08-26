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

[실행 결과]
3.14
123

[코드 분석]

1. 연산자 오버로딩 시 멤버 함수의 반환형이 ostream& operator << ( ~ )와 같이 정의되는 이유 
	: 이는 연쇄적인 (연속적인) << 연산자 사용을 위하여 정의되었다. 
	앞선 코드를 통해 cout이 ostream 객체라는 것을 확인할 수 있다. 
	따라서 cout << 1 << 2 << endl; 와 같은 코드를 예시로 들어 설명해본다면, 
	cout << 1 은 cout.operator<<(1)로 이해할 수 있다. 
	이때 해당 연산의 결과가 다시 cout과 동일한 타입의 객체, 즉 ostream 객체로 반환되어야 
	다음에 이어질 (cout << 1).operator<<(2) 연산이 가능해진다. 
	(한번의 << 연산만 일어날 경우, printf를 활용하여, void 반환형의 함수도 정의가 가능하다.) 
	따라서 해당 연산자 오버로딩 함수의 반환형은 ostream (참조형)으로 설정되어야 한다. 

2. 앞선 논의를 연장시켜, 함수 정의의 마지막 부분 return *this; 코드를 살펴보자. 
	: this 포인터는 현 객체의 주소를 가리킨다. 이 this pointer의 앞에 *가 붙었으므로,
	이는 현객체의 실체를 의미한다. 즉 연산이 이루어진 cout (ostream)객체가 다시 반환된다. 
	이를 통해 연속적인 ostream 객체에 대한 << (오버로딩)연산 수행이 가능하다. 

3. 	ostream& endl(ostream& ostm) {
	ostm << '\n';
	fflush(stdout);
	return ostm;
}
	: 해당 코드를 통해 endl은 ostream&를 반환형으로 갖는 전역함수임을 알 수 있다. 
	endl 함수는 ostream 객체 ostm을 참조형으로 받는다. 
	해당 함수는 줄바꿈과 더불어, 버퍼를 비우는 역할도 수행한다. 
	이후 다시 ostream 객체를 참조형으로 반환한다. 

*/
