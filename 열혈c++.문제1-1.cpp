// ���� 01-1 [c++ ����� ������ �����]

#include <iostream>
int main() {
	
	//���� 1: 5���� ������ ��
	int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0;
	std::cout << "1��° ���� �Է�: ";
	std::cin >> a1;
	std::cout << "2��° ���� �Է�: ";
	std::cin >> a2;
	std::cout << "3��° ���� �Է�: ";
	std::cin >> a3;
	std::cout << "4��° ���� �Է�: ";
	std::cin >> a4;
	std::cout << "5��° ���� �Է�: ";
	std::cin >> a5;
	std::cout << "�հ�: " << a1 + a2 + a3 + a4 + a5 << std::endl;

	//���� 2: �̸��� ��ȭ��ȣ (static array ����)
	char name[10];
	char number[15];
	std::cout << "�̸��� �Է����ּ���. : " <<std::endl;
	std::cin >> name;
	std::cout << "��ȭ��ȣ�� �Է��ϼ���. : " << std::endl;
	std::cin >> number;
	std::cout << "�̸�: " << name << std::endl;
	std::cout << "��ȭ��ȣ: " << number << std::endl;

	// ���� 3: �������� ����!
	int num = 1;
	std::cout << "���ϴ� ���ڸ� �Է��Ͻø�, �������� ����ص帳�ϴ�!";
	std::cin >> num;
	std::cout << num << "�� ������!" << std::endl;
	std::cout << 1 * num << std::endl;
	std::cout << 2 * num << std::endl;
	std::cout << 3 * num << std::endl;
	std::cout << 4 * num << std::endl;
	std::cout << 5 * num << std::endl;
	std::cout << 6 * num << std::endl;
	std::cout << 7 * num << std::endl;
	std::cout << 8 * num << std::endl;
	std::cout << 9 * num << std::endl;
	std::cout << "�������! :) " << std::endl;

	// ���� 4: �޿� ��� ���α׷�
	double money = 0;
	double f_money = 1;
	while (money != -1) {
		std::cout << "�Ǹ� �ݾ��� ���� ������ �Է� (-1 to end): ";
		std::cin >> money;
		f_money = 50 + money * 0.12;
		std::cout << "�̹� �� �޿�: " << f_money << "����" << std::endl;
	}
	std::cout << "���α׷��� �����մϴ�.";
}



