#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray {
private:
	int* arr;
	int arrlen;
public:
	BoundCheckIntArray(int len) : arrlen(len) {
		arr = new int[len];
	}

	int& operator[] (int idx) {
		if (idx<0 || idx>=arrlen) {
			cout << "Array index out of bound exception!!" << endl;
			exit(1);
		}
		return arr[idx];
	}

	~BoundCheckIntArray() {
		delete[] arr;
	}
};

int main() {
	BoundCheckIntArray arr(5);
	for (int i = 0; i < 5; i++) {
		arr[i] = (i + 1) * 11;
	}
	
	for (int i = 0; i < 6; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}

/*

[실행 결과]
11
22
33
44
55
Array index out of bound exception!!


[실행 코드 분석]
- c++에는 배열의 경계값을 체크하지 않는다. 
- 따라서 array의 배열 인덱스 값의 경계를 확인하는 기능을 다음과 같이 구현할 수 있다. 
- 해당 객체의 소멸자에서는 동적 할당된 메모리(arr)를 해제한다. 
- 반복문을 통해 배열의 요소에 접근한다. 이때, 범위를 벗어나는 인덱스 값에 대하여, 경고문구가 출력된다.

*/
