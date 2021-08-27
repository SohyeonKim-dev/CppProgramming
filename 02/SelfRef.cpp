# include <iostream>
using namespace std;

class SelfRef {
private:
	int num;
public:
	SelfRef(int n) : num(n) {
		cout << "°´Ã¼°¡ »ý¼ºµÇ¾ú½À´Ï´Ù! :) " << endl;
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
