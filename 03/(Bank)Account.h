/*
* 파일 이름: (Bank)Account.h
* 작성자: 김소현
* 업데이트 정보: [2021, 08, 11] 파일 버전 0.1
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account {
private:
	int accID;
	int balance;
	char* cusName;

public:
	Account(int ID, int money, char* name);
	Account(const Account& ref);

	int GetAccID() const;
	virtual void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;

	~Account();
};


#endif // ! __ACCOUNT_H__
