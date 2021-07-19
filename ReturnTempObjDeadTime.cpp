# include <iostream>
using namespace std;

class SoHyeon {
private:
	int num;
public:
	SoHyeon(int n) : num(n) {									// 생성자 1. class와 이름 동일 2. return 없음
		cout << "New Object: " << this << endl;					// this pointer -> 현 객체의 주소
	}

	SoHyeon(const SoHyeon & copy) : num(copy.num) {				// (default) 복사 생성자 1. class와 이름 동일 2. return 없음
		cout << "New Copy Object: " << this << endl;			// (3) 주로 parameter const reference(&) 사용한다. 
	}															// 마찬가지로 this 로 인해 현 객체(소현타입)의 주소를 반환하게 된다. 
														        
	~ SoHyeon () {												// 소멸자 1. ~class명 2. return, input parameter X 3. 죽을때 실행
		cout << "Destroy Object: " << this << endl;
	}
};																// class 정의는 여기서 끝난다. 

SoHyeon OutFunc(SoHyeon ob) {
	//cout << "Parm ADR: " << &ob << endl;
	cout << "I am out funcObj: " << &ob << endl;
	return ob;
}

/*
return type이 소현이다.
input parameter의 타입도 소현이다. 
class내부에 선언이 존재하지 않으므로, 멤버 함수는 아니다.
다만 소현 타입의 입력과 반환을 갖는다. 
해당 구문을 출력한 이후, &ob를 통해 입력받은 객체의 주소를 반환한다. 
이후 해당 객체를 return하며 함수가 종료된다. 

*/

int main() {
	SoHyeon obj(7);												// 소현 타입의 객체, obj가 생성된다. (멤버변수 초기화도 이루어짐)
	OutFunc(obj);												// 아까 함수 밖에서 정의해둔, 소현 타입의 in/output 함수이다. 
																// OutFunc는 왜 쓸까? 멤버 함수도 아닌데 따로 정의해둔 이유는? 
																// 임시 객체의 소멸에 관해 설명하기 위해 등장하는 것 같으니,
																// 코드 분석 파트에서 알아보도록 하자. 
																// 앞서 생성한 객체 obj를 OutFunc에 넣어준다.

	cout << endl;												// 보기 좋게 띄워주기 ^_^
	SoHyeon tempRef = OutFunc(obj);								// 이번에는 OutFunc(obj:초기화) 객체를 소현 타입의 tempRef에 대입한다.
	cout << "Return obj " << &tempRef << endl;					// 이후 생성된 tempRef의 주소를 출력한다. 
	return 0;													// main 함수가 종료된다. 
}

/*

[1st 실행 결과]
New Object: 00EFF8EC										
New Copy Object: 00EFF7D4									
Parm ADR: 00EFF7D4											 
New Copy Object: 00EFF808
Destroy Object: 00EFF7D4
Destroy Object: 00EFF808

New Copy Object: 00EFF7D4
Parm ADR: 00EFF7D4
New Copy Object: 00EFF8E0
Destroy Object: 00EFF7D4
Return obj 00EFF8E0
Destroy Object: 00EFF8E0
Destroy Object: 00EFF8EC

*/

/*
[2nd 실행 결과: 코드 수정함]

New Object: 00B8F8B0											// SoHyeon obj(7) -> 새로운 객체가 생성(생성자 호출)
New Copy Object: 00B8F798										// OutFunc에 obj가 전달되는 과정에서 복사생성자 호출된다. (ob 생성)
I am out funcObj: 00B8F798										// OutFunc의 몸체가 실행됨. 매개변수 ob의 주소 반환
New Copy Object: 00B8F7CC										// OutFunc이 매개변수 ob를 return하면서 복사생성자 2nd 호출
Destroy Object: 00B8F798										// 매개변수 ob의 사망 (obj가 죽은거 아님! 얘는 main이랑 같이 죽음)
Destroy Object: 00B8F7CC										// (참조X) 임시객체의 수명은 단 한 줄. 
																// 따라서 해당 문장 시행 종료와 함께 사망함

New Copy Object: 00B8F798										// 매개변수 ob생성 -> 마찬가지로 obj가 전달되는 과정에서 복사생성자 호출
I am out funcObj: 00B8F798										// OutFunc 몸체 실행, 매개변수 ob의 주소 출력
New Copy Object: 00B8F8A4										// OutFunc의 return에 의해 임시객체 생성
Destroy Object: 00B8F798										// 매개변수 ob의 사망 (OutFunc 함수의 종료(return)와 함께)
Return obj 00B8F8A4												// tempRef의 주소가 임시객체의 주소와 동일하다. 
Destroy Object: 00B8F8A4										// main 함수의 종료와 함께 임시객체(tempRef) 소멸
Destroy Object: 00B8F8B0										// 앞서 생성했던 obj 소멸
*/

/*

[실행 코드 분석]

* 복사 생성자의 생성 
* 1. 새 객체에 기존 객체를 대입(초기화)
* 2. 함수의 매개변수로 전달
* 3. 함수의 return (이때 참조형 반환은 X)

* 임시 객체의 특성
* 1. 임시 객체는 다음 행으로 넘어가면 바로 소멸
* 2. But 참조자로 인하여 참조되는 임시 객체는 바로 소멸되지 않는다. 
* 
* tempRef라는 새로운 객체를 생성하여, 반환되는 객체를 가지고 대입한다. (/)
* 반환되는 임시 객체에 tempRef라는 이름을 할당한다. (O) ㅇㅁㅇ;;
* 위의 코드를 통해 임시 객체의 소멸 타이밍을 확인해보자. 
* 
* + OutFunc과 복사 생성자의 차이? 
* 새로운 소현타입의 객체를 다룬다는 점에서 두 함수는 비슷해보인다. 
* 
* 복사 생성자는 new 소현을 생성하여, 기존 소현을 parameter로 넣어주면, new 소현의 멤버 변수가 초기화된다. 
* 단순한 생성자와는 차이가 있다. 
* 
* OutFunc은 기존 소현을 입력 parameter로 받고, 소현 타입을 반환하는 함수이다. 
* 이때 이 함수는 class밖에서 선언/정의되므로 멤버 함수는 아니다.
* 이 함수는 소현 타입의 ob를 매개변수로 받는다.
* 함수의 몸체에서 "I am out funcObj: " 라는 구문과 매개변수 ob의 주소를 출력한다.
* 이후, 해당 함수는 return ob에 의해 임시 객체를 생성하고 종료된다. 이때 매개변수 ob는 소멸된다.
* 생성된 임시 객체는 참조자에 의해 참조되거나, 혹은 앞선 코드와 같이 이름을 갖게 되면 소멸하지 않고 살아남을 수 있다. 
* 
* 복사 생성자는 새로운 소현 타입의 객체가 기존의 소현 타입에 의해 생성될 때, 호출된다.
* 이와 달리, OutFunc 함수는 main함수에서 특정 입력 parameter와 함께 호출될 때, 
* 이 매개변수에 의해 초기화 된 임시 객체를 생성시킨다. (return한다.)
* 이때 이 임시 객체의 생존 여부는 함수 자체로만 결정되는 것은 아니다.
* 참조자 반환으로 함수가 선언될 경우, 살아남는다. 하지만 함수 외적으로, 이름을 할당받는 경우도 생긴다.
* 하지만 그렇지 않은 경우, 이 함수의 return에 의해 생성된 임시객체는 함수 종료와 함께 즉시 소멸된다. 
* 
*/