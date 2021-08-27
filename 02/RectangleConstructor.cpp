# include <iostream>
# include "Point.h"
# include "Rectangle.h"
using namespace std;

int main() {
	Rectangle rec(1, 2, 3, 4);
	rec.ShowRecInfo();
	return 0;

/*
* 
* [실행 결과]
* 
좌 상단: [1, 2]
우 하단: [3, 4]

[객체의 생성 과정]
1. 메모리 공간 할당 (동적 or 정적)
2. 이니셜라이저(:)를 이용한 멤버 변수의 초기화 -> 초기화 함수 or 생성자 몸체에서 멤버 변수를 초기화 할 수도 있다.
3. 생성자의 몸체 부분 실행 -> {} 비어있을 수도 있다. 

*/

}
