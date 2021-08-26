# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <cstring>
using namespace std;

class 컴퓨터 {
private:
	char owner[50];
public:
	컴퓨터(char* name) {
		strcpy(owner, name);
		cout << "컴퓨터 객체 생성!" << endl;
	}
	~컴퓨터() {
		cout << "컴퓨터 객체 소멸!" << endl;
	}

	void Calculate() {
		cout << "요청 내용을 계산합니다." << endl;
	}
};

class 노트북 : public 컴퓨터 {
private:
	int Battery;
public:
	노트북 (char* name, int initChag)
		: 컴퓨터(name), Battery(initChag) {
		cout << "노트북 객체 생성!" << endl;
	}

	~노트북() {
		cout << "노트북 객체 소멸!" << endl;
	}

	void Charging() {
		Battery = Battery + 5;
	}

	void UseBattery() {
		Battery = Battery -1 ;
	}

	int GetBatteryInfo() {
		return Battery;
	}

	void MovingCal() {
		if (GetBatteryInfo() < 1) {
			cout << "충전이 필요합니다." << endl;
			return;
		}
		cout << "이동하면서 " << endl;
		Calculate();
		UseBattery();
	}
};

class 태블릿PC : public 노트북 {
private:
	char regstPenModel[50];
public:
	태블릿PC(char* name, int initChag, char* pen)
		: 노트북(name, initChag) {
		strcpy(regstPenModel, pen);
		cout << "태블릿PC 객체 생성!" << endl;
	}

	~태블릿PC() {
		cout << "태블릿PC 객체 소멸!" << endl;
	}

	void Write(char* penInfo) {
		if (GetBatteryInfo() < 1) {
			cout << "충전이 필요합니다." << endl;
			return;
		}
		if (strcmp(regstPenModel, penInfo) != 0) {
			cout << "등록된 펜이 아닙니다." << endl;
			return;
		}
		cout << "필기 내용을 처리합니다." << endl;
		UseBattery();
	}
};

int main() {
	노트북 notebook1("김소현", 5);
	태블릿PC tabletPC1("브로콜리", 10, "BroPen");
	notebook1.MovingCal();
	tabletPC1.Write("BroPen");
	return 0;
}

/*

[실행 결과]

컴퓨터 객체 생성!
노트북 객체 생성!
컴퓨터 객체 생성!
노트북 객체 생성!
태블릿PC 객체 생성!
이동하면서
요청 내용을 계산합니다.
필기 내용을 처리합니다.
태블릿PC 객체 소멸!
노트북 객체 소멸!
컴퓨터 객체 소멸!
노트북 객체 소멸!
컴퓨터 객체 소멸!

[실행 코드 분석]

1. 객체가 생성될 때, 생성자가 호출되는 순서는 컴퓨터 -> 노트북 -> 태블릿PC 순이다.
2. 객체가 소멸될 때, 소멸자가 호출되는 순서는 태블릿PC -> 노트북 -> 컴퓨터 순이다.
3. 소멸자를 정의함에 있어서, 동적 할당이 이루어지지 않았으므로, delete를 사용하면 오류가 발생한다. 
4. 컴파일러에 따라 코드 동작 여부가 달라진다. 앞선 실행 결과도 (https://csacademy.com/workspace/)에서 시행한 결과를 바탕으로 작성되었다. 
	: Visual Studio에서는 오류가 발생한다. 
5. 상속의 조건 (is a) 
	: 노트북 is a 컴퓨터
	: 태블릿PC is a 노트북
	: 태블릿PC is a 컴퓨터
	( Derived class is a Base class )
	( 자식 class is a 부모 class )

	+ 비쥬얼 스튜디오 오류 해결! 
	1. 프로젝트 -> 속성 -> 구성속성 => C/C++ => 언어 창에 있는 준수모드 아니오로 변경하면 오류 발생X!!
		: strcpy에서 오류 발생
	2. # define _CRT_SECURE_NO_WARNINGS 을 사용하면 해결된다.
*/
