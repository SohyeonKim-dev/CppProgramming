# include <iostream>
using namespace std;

class �θ�class {
private :
	int basenumber;

public:
	�θ�class() : basenumber(100) {
		cout << "�θ� class ������ ȣ��" << endl;
	}
	�θ�class(int n) : basenumber(n) {
		cout << "�θ� class ������ ȣ��" << endl;
	}
	void ShowBaseData() {
		cout << basenumber << endl;
	}
};

class �ڽ�class : public �θ�class {
private:
	int derivenumber;
public:
	�ڽ�class() : derivenumber(10) {
		cout << "�ڽ� class ������ ȣ��" << endl;
	}
	�ڽ�class(int n) : derivenumber(n) {
		cout << "�ڽ� class ������ ȣ��" << endl;
	}
	�ڽ�class(int n1, int n2) : �θ�class(n1), derivenumber(n2) {
		cout << "�ڽ� class ������ ȣ��" << endl;
	}
	void ShowDeriveData() {
		ShowBaseData();
		cout << derivenumber << endl;
	}
};

int main() {
	cout << "--- ù��° ��� ---" << endl;
	�ڽ�class ù��°_�ڽ�;
	ù��°_�ڽ�.ShowDeriveData();
	cout << "-------------------" << endl;
	cout << "--- �ι�° ��� ---" << endl;
	�ڽ�class �ι�°_�ڽ�(12);
	�ι�°_�ڽ�.ShowDeriveData();
	cout << "-------------------" << endl;
	cout << "--- ����° ��� ---" << endl;
	�ڽ�class ����°_�ڽ�(25,27);
	����°_�ڽ�.ShowDeriveData();
	cout << "-------------------" << endl;
	return 0;
}
