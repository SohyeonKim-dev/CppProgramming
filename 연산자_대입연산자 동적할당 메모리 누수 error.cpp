# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <cstring>
using namespace std;

class Person {
private:
	char* name;
	int age;

public:
	Person(char* myname, int myage) {
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}

	void ShowPersonInfo() const {
		cout << "My name is : " << name << endl;
		cout << "My age is : " << age << endl;
	}

	~Person() {
		delete[] name;										// 동적 할당이 이루어진 멤버에 대한 메모리 해제만 해주면 된다!
		cout << " Called Destructor!" << endl;
	}
};

int main() {
	Person man1 ("KimSoHyeon", 21);
	Person man2 ("Broccoli", 31);
	man1 = man2;

	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}

/*

[실행 결과]
My name is : Broccoli
My age is : 31
My name is : Broccoli
My age is : 31
 Called Destructor!

[실행 코드]
1. 위의 실행 결과를 통해 소멸자가 한번만 호출되는 디폴트 대입 연산자의 문제점을 발견할 수 있다. 
	: 메모리 누수로 인한 문제를 해결하기 위해, 복사 생성자와 마찬가지로 대입 연산자를 직접 정의하여 오류를 해결한다.

	아래와 같이 대입 연산자를 정의한다. (Shallow copy -> Deep copy)

	Person& operator= (const &Person ref) {
	delete [] name;									// 여기서 메모리 해제를 통해 메모리 leak을 해결한다. 
	int len  = strlen(ref.name)+1 ;					// 아래 내용의 멤버대 멤버 대입은 동일하게 이루어진다. 
	name = new char[len];							// new연산을 통해 메모리 공간의 동적 할당이 이루어진다. 
	strcpy (name, ref.name);
	age = ref.age; 
	return *this;									// 현객체 반환 
	}

2. 문제 상황을 구체적으로 분석해보자면, 
	: 동적 할당된 하나의 문자열 'name'에 대하여, 두 개의 객체가 이를 동시에 참조하게 된다. 
	1차적으로 man1의 고유 멤버였던 문자열에 대한 메모리 누수가 발생한다. 
	이후 man2 객체가 우선 소멸되면서, 2번째 문자열에 대한 소멸이 함께 발생한다. 
	다음으로 이루어지는 man1 객체의 멤버인 name의 소멸 과정에서,
	name이 가리키는 문자열은 전에 man2객체가 소멸하는 과정에서 이미 소멸시켜버렸다. 
	따라서 이미 소멸된 문자열을 재소멸하는 문제가 발생한다. (정작 원래 본인이 가지고 있던 문자열은 메모리누수 발생)
	따라서 생성자 내에서 동적 할당이 이루어지는 경우, 디폴트 대입 연산자는 두가지 문제를 지니므로,
	위와 같이 직접 대입 연산자를 정의해야 한다. 

	(1) 깊은 복사를 진행하도록 정의한다. 

	- 얕은 복사: 객체의 참조값(주소) 복사
		: 원본 객체와 동일한 메모리 주소를 참조
		해당 메모리 주소의 값이 변경되면 같이 변경된다. 

	- 깊은 복사: 객체의 실제 값 복사
		: 전부를 복사하여 새 주소에 담기 때문에 참조를 공유하지 않는다.
		원본된 객체의 변화가, copy 객체에 영향을 미치지 않는다. (서로 독립적인 객체로 행동함)

	(2) 메모리 누수가 발생하지 않도록, 복사 과정에 앞서 메모리 해제의 과정을 거친다. 
	-> 따라서 멤버별 복사, 대입 과정이 일어나기 전에 미리 기존에 동적 할당된 메모리(name)에 대하여
	메모리 해제 (delete [] name;) 를 정의해준 것이다! 

*/