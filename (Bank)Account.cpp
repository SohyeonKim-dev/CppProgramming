/*
파일 이름: (Bank) Account.cpp
작성자: 김소현
업데이트 정보: [2021, 08, 24] 파일 버전 0.1
*/

# define _CRT_SECURE_NO_WARNINGS
# include "(Bank)Account.h"
# include "(Bank)BankingCommonDecl.h" // 여기에 <iostream>, <cstring> 포함되어 있음

Account::Account(int ID, int money, char* name)
	: accID(ID), balance(money) {
	cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);
}

Account::Account(const Account& ref)
	: accID(ref.accID), balance(ref.balance) {
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
}

int Account::GetAccID() const { return accID; }

void Account::Deposit(int money) {
	balance += money;
}

int Account::Withdraw(int money) {
	if (balance < money) {
		return 0;
	}
		
	balance -= money;
	return money;
}

void Account::ShowAccInfo() const {
	cout << "계좌ID: " << accID << endl;
	cout << "이  름: " << cusName << endl;
	cout << "잔  액: " << balance << endl;
}

Account::~Account() {
	delete [] cusName;
}