# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <cstring>
using namespace std;

class Person {
private:
	char* name;
	int age;

public:
	Person(char* myname, int myage) {
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}

	void ShowPersonInfo() const {
		cout << "My name is : " << name << endl;
		cout << "My age is : " << age << endl;
	}

	~Person() {
		delete[] name;										// ���� �Ҵ��� �̷���� ����� ���� �޸� ������ ���ָ� �ȴ�!
		cout << " Called Destructor!" << endl;
	}
};

int main() {
	Person man1 ("KimSoHyeon", 21);
	Person man2 ("Broccoli", 31);
	man1 = man2;

	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}

/*

[���� ���]
My name is : Broccoli
My age is : 31
My name is : Broccoli
My age is : 31
 Called Destructor!

[���� �ڵ�]
1. ���� ���� ����� ���� �Ҹ��ڰ� �ѹ��� ȣ��Ǵ� ����Ʈ ���� �������� �������� �߰��� �� �ִ�. 
	: �޸� ������ ���� ������ �ذ��ϱ� ����, ���� �����ڿ� ���������� ���� �����ڸ� ���� �����Ͽ� ������ �ذ��Ѵ�.

	�Ʒ��� ���� ���� �����ڸ� �����Ѵ�. (Shallow copy -> Deep copy)

	Person& operator= (const &Person ref) {
	delete [] name;									// ���⼭ �޸� ������ ���� �޸� leak�� �ذ��Ѵ�. 
	int len  = strlen(ref.name)+1 ;					// �Ʒ� ������ ����� ��� ������ �����ϰ� �̷������. 
	name = new char[len];							// new������ ���� �޸� ������ ���� �Ҵ��� �̷������. 
	strcpy (name, ref.name);
	age = ref.age; 
	return *this;									// ����ü ��ȯ 
	}

2. ���� ��Ȳ�� ��ü������ �м��غ��ڸ�, 
	: ���� �Ҵ�� �ϳ��� ���ڿ� 'name'�� ���Ͽ�, �� ���� ��ü�� �̸� ���ÿ� �����ϰ� �ȴ�. 
	1�������� man1�� ���� ������� ���ڿ��� ���� �޸� ������ �߻��Ѵ�. 
	���� man2 ��ü�� �켱 �Ҹ�Ǹ鼭, 2��° ���ڿ��� ���� �Ҹ��� �Բ� �߻��Ѵ�. 
	�������� �̷������ man1 ��ü�� ����� name�� �Ҹ� ��������,
	name�� ����Ű�� ���ڿ��� ���� man2��ü�� �Ҹ��ϴ� �������� �̹� �Ҹ���ѹ��ȴ�. 
	���� �̹� �Ҹ�� ���ڿ��� ��Ҹ��ϴ� ������ �߻��Ѵ�. (���� ���� ������ ������ �ִ� ���ڿ��� �޸𸮴��� �߻�)
	���� ������ ������ ���� �Ҵ��� �̷������ ���, ����Ʈ ���� �����ڴ� �ΰ��� ������ ���ϹǷ�,
	���� ���� ���� ���� �����ڸ� �����ؾ� �Ѵ�. 

	(1) ���� ���縦 �����ϵ��� �����Ѵ�. 

	- ���� ����: ��ü�� ������(�ּ�) ����
		: ���� ��ü�� ������ �޸� �ּҸ� ����
		�ش� �޸� �ּ��� ���� ����Ǹ� ���� ����ȴ�. 

	- ���� ����: ��ü�� ���� �� ����
		: ���θ� �����Ͽ� �� �ּҿ� ��� ������ ������ �������� �ʴ´�.
		������ ��ü�� ��ȭ��, copy ��ü�� ������ ��ġ�� �ʴ´�. (���� �������� ��ü�� �ൿ��)

	(2) �޸� ������ �߻����� �ʵ���, ���� ������ �ռ� �޸� ������ ������ ��ģ��. 
	-> ���� ����� ����, ���� ������ �Ͼ�� ���� �̸� ������ ���� �Ҵ�� �޸�(name)�� ���Ͽ�
	�޸� ���� (delete [] name;) �� �������� ���̴�! 

*/