# include <iostream>
using namespace std;

class 부모class {
private :
	int basenumber;

public:
	부모class() : basenumber(100) {
		cout << "부모 class 생성자 호출" << endl;
	}
	부모class(int n) : basenumber(n) {
		cout << "부모 class 생성자 호출" << endl;
	}
	void ShowBaseData() {
		cout << basenumber << endl;
	}
};

class 자식class : public 부모class {
private:
	int derivenumber;
public:
	자식class() : derivenumber(10) {
		cout << "자식 class 생성자 호출" << endl;
	}
	자식class(int n) : derivenumber(n) {
		cout << "자식 class 생성자 호출" << endl;
	}
	자식class(int n1, int n2) : 부모class(n1), derivenumber(n2) {
		cout << "자식 class 생성자 호출" << endl;
	}
	void ShowDeriveData() {
		ShowBaseData();
		cout << derivenumber << endl;
	}
};

int main() {
	cout << "--- 첫번째 경우 ---" << endl;
	자식class 첫번째_자식;
	첫번째_자식.ShowDeriveData();
	cout << "-------------------" << endl;
	cout << "--- 두번째 경우 ---" << endl;
	자식class 두번째_자식(12);
	두번째_자식.ShowDeriveData();
	cout << "-------------------" << endl;
	cout << "--- 세번째 경우 ---" << endl;
	자식class 세번째_자식(25,27);
	세번째_자식.ShowDeriveData();
	cout << "-------------------" << endl;
	return 0;
}
