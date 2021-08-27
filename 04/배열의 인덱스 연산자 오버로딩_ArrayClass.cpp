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

[���� ���]
11
22
33
44
55
Array index out of bound exception!!


[���� �ڵ� �м�]
- c++���� �迭�� ��谪�� üũ���� �ʴ´�. 
- ���� array�� �迭 �ε��� ���� ��踦 Ȯ���ϴ� ����� ������ ���� ������ �� �ִ�. 
- �ش� ��ü�� �Ҹ��ڿ����� ���� �Ҵ�� �޸�(arr)�� �����Ѵ�. 
- �ݺ����� ���� �迭�� ��ҿ� �����Ѵ�. �̶�, ������ ����� �ε��� ���� ���Ͽ�, ������� ��µȴ�.

*/