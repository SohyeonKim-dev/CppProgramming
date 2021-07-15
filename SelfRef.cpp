# include <iostream>
using namespace std;

class SelfRef {
private:
	int num;
public:
	SelfRef(int n) : num(n) {
		cout << "객체가 생성되었습니다! :) " << endl;
	}

	SelfRef& Adder(int n) {
		num = num + n;
		return *this;
	}

	SelfRef& ShowTwoNumber() {
		cout << num << endl;
		return *this;
	}
};

int main() {
	SelfRef obj(3);
	SelfRef& ref = obj.Adder(2);

	obj.ShowTwoNumber();
	ref.ShowTwoNumber();

	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
	return 0;
}