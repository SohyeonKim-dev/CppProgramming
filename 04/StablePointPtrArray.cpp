# include <iostream>
# include <cstdlib>
using namespace std;

class Point {
private:
	int xpos;
	int ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) { }
	friend ostream& operator << (ostream& os, const Point& pos);
};

ostream& operator << (ostream& os, const Point& pos) {
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

typedef Point* POINT_PTR;

class BoundCheckPointPtrArray {
private:
	POINT_PTR* arr;
	int arrlen;

	//BoundCheckPointPtrArray(const BoundCheckPointPtrArray& arr) { }
	//BoundCheckPointPtrArray & operator = (const BoundCheckPointPtrArray& arr) { }

public:
	BoundCheckPointPtrArray(int len) : arrlen(len) {
		arr = new POINT_PTR[len];
	}
	POINT_PTR& operator [] (int idx) {
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}

	POINT_PTR& operator [] (int idx) const {
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}

	int GetArrLen() const {
		return arrlen;
	}

	~BoundCheckPointPtrArray() {
		delete[] arr;
	}
};

int main() {
	BoundCheckPointPtrArray arr(3);
	arr[0] = new Point(4, 7);
	arr[1] = new Point(2, 11);
	arr[2] = new Point(9, 2);

	for (int i = 0; i < arr.GetArrLen(); i++) {
		cout << *(arr[i]);
	}

	delete arr[0];
	delete arr[1];
	delete arr[2];
	return 0;
}

/*
[실행 결과]

[4, 7]
[2, 11]
[9, 2]

[코드 분석]

- 주소를 저장하는 경우, new & delete 사용으로 더 복잡해 보이지만, 
깊은 복사냐 얕은 복사냐 하는 문제를 신경 안써도 되므로 더 편리하다고 한다. 
- 객체 저장 코드와의 가장 큰 차이는, 역시나 메모리 할당 및 해제이다. 
- typedef Point* POINT_PTR; 을 통하여 자료형 정의를 하는 부분이 신기했다.
: 저장의 대상, 또는 연산의 주 대상이 포인터인 경우, 
  이렇듯 별도의 자료형을 정의하는 것이 좋다고 한다. 

	//BoundCheckPointPtrArray(const BoundCheckPointPtrArray& arr) { }
	//BoundCheckPointPtrArray & operator = (const BoundCheckPointPtrArray& arr) { }
		: 얘네 주석처리해도 정상적으로 돌아가는데, 왜쓰는거지?

*/