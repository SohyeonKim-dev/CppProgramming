# include <iostream>
using namespace std;

class First {
private:
	int num1;
	int num2;
public:
	First(int n1=0, int n2=0) : num1(n1), num2(n2) { }

	void ShowData() {
		cout << num1 << ", " << num2 << endl;
	}

	First& operator= (const First& ref) {
		cout << "First& operator =()" << endl;
		num1 = ref.num1;
		num2 = ref.num2;
		return *this;
	}
};

class Second : public First {
private:
	int num3;
	int num4;
public:
	Second(int n1, int n2, int n3, int n4)
		: First(n1, n2), num3(n3), num4(n4) { }

	void ShowData() {
		First::ShowData();
		cout << num3 << ", " << num4 << endl;
	}

	/*
	
	Second& operator=(const Second& ref) {
		cout << "Second& operator=()" << endl;
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
	}

	*/
};

int main() {
	Second object_second(111, 222, 333, 444);
	Second object_copied(0, 0, 0, 0);
	object_copied = object_second;
	object_copied.ShowData();
	return 0;
}

/*

[실행 결과]

First& operator =()
111, 222
333, 444

[주석 해제 시 실행 결과]

Second& operator=()
0, 0
333, 444

[코드 분석]

1. 유도(자식) 클래스에서 대입 연산자를 정의한 경우, 부모 클래스의 멤버에 대한 복사 연산이 제대로 이루어지지 않는다. 
	: (유도 클래스에서 디폴트 대입 연산자를 호출한 경우, 자동으로 기본(베이스, 부모)클래스의 대입 연산자 호출됨)
	즉, 유도 클래스의 대입 연산자 정의 시 명시적으로 기초 클래스의 대입 연산자 호출문을 삽입하지 않을 시, 
	기초 클래스의 대입 연산자는 호출되지 않아, 기초 클래스의 멤버 변수는 멤버 대 멤버의 복사 대상에서 제외된다. 
	-> 따라서 유도 클래스의 대입 연산자를 직접 정의해야 하는 경우, 꼭 기초 클래스의 대입 연산자를 명시적으로 호출해야 한다. 

2.	Second& operator= (const Second& ref) {
		cout << "Second& operator=()" << endl;
		First::operator=(ref);								// 이 문장을 통해 오류 해결 가능!
		num3 = ref.num3;
		nem4 = ref.num4;
		return *this;
		}

3. Second 참조형 변수 ref는 First operator의 입력 parameter로 정의된 First형 참조자에 문제 없이 입력 가능함
	: "c++에서 ~형 참조자는 ~형 객체 또는 ~형을 직접 혹은 간접적으로 상속하는 모든 객체를 참조할 수 있다."
	-> 즉 First형 참조자는 다 받을 수 있다! (상속 관계의 객체를 다 때려넣을 수 있음)


*/
