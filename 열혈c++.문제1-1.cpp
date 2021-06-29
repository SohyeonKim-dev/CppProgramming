// 문제 01-1 [c++ 기반의 데이터 입출력]

#include <iostream>
int main() {
	
	//문제 1: 5가지 정수의 합
	int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0;
	std::cout << "1번째 정수 입력: ";
	std::cin >> a1;
	std::cout << "2번째 정수 입력: ";
	std::cin >> a2;
	std::cout << "3번째 정수 입력: ";
	std::cin >> a3;
	std::cout << "4번째 정수 입력: ";
	std::cin >> a4;
	std::cout << "5번째 정수 입력: ";
	std::cin >> a5;
	std::cout << "합계: " << a1 + a2 + a3 + a4 + a5 << std::endl;

	//문제 2: 이름과 전화번호 (static array 형식)
	char name[10];
	char number[15];
	std::cout << "이름을 입력해주세요. : " <<std::endl;
	std::cin >> name;
	std::cout << "전화번호를 입력하세요. : " << std::endl;
	std::cin >> number;
	std::cout << "이름: " << name << std::endl;
	std::cout << "전화번호: " << number << std::endl;

	// 문제 3: 구구단을 외자!
	int num = 1;
	std::cout << "원하는 숫자를 입력하시면, 구구단을 출력해드립니다!";
	std::cin >> num;
	std::cout << num << "단 구구단!" << std::endl;
	std::cout << 1 * num << std::endl;
	std::cout << 2 * num << std::endl;
	std::cout << 3 * num << std::endl;
	std::cout << 4 * num << std::endl;
	std::cout << 5 * num << std::endl;
	std::cout << 6 * num << std::endl;
	std::cout << 7 * num << std::endl;
	std::cout << 8 * num << std::endl;
	std::cout << 9 * num << std::endl;
	std::cout << "끝났어요! :) " << std::endl;

	// 문제 4: 급여 계산 프로그램
	double money = 0;
	double f_money = 1;
	while (money != -1) {
		std::cout << "판매 금액을 만원 단위로 입력 (-1 to end): ";
		std::cin >> money;
		f_money = 50 + money * 0.12;
		std::cout << "이번 달 급여: " << f_money << "만원" << std::endl;
	}
	std::cout << "프로그램을 종료합니다.";
}



