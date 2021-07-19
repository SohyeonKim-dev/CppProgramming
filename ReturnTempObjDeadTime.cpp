# include <iostream>
using namespace std;

class SoHyeon {
private:
	int num;
public:
	SoHyeon(int n) : num(n) {									// ������ 1. class�� �̸� ���� 2. return ����
		cout << "New Object: " << this << endl;					// this pointer -> �� ��ü�� �ּ�
	}

	SoHyeon(const SoHyeon & copy) : num(copy.num) {				// (default) ���� ������ 1. class�� �̸� ���� 2. return ����
		cout << "New Copy Object: " << this << endl;			// (3) �ַ� parameter const reference(&) ����Ѵ�. 
	}															// ���������� this �� ���� �� ��ü(����Ÿ��)�� �ּҸ� ��ȯ�ϰ� �ȴ�. 
														        
	~ SoHyeon () {												// �Ҹ��� 1. ~class�� 2. return, input parameter X 3. ������ ����
		cout << "Destroy Object: " << this << endl;
	}
};																// class ���Ǵ� ���⼭ ������. 

SoHyeon OutFunc(SoHyeon ob) {
	//cout << "Parm ADR: " << &ob << endl;
	cout << "I am out funcObj: " << &ob << endl;
	return ob;
}

/*
return type�� �����̴�.
input parameter�� Ÿ�Ե� �����̴�. 
class���ο� ������ �������� �����Ƿ�, ��� �Լ��� �ƴϴ�.
�ٸ� ���� Ÿ���� �Է°� ��ȯ�� ���´�. 
�ش� ������ ����� ����, &ob�� ���� �Է¹��� ��ü�� �ּҸ� ��ȯ�Ѵ�. 
���� �ش� ��ü�� return�ϸ� �Լ��� ����ȴ�. 

*/

int main() {
	SoHyeon obj(7);												// ���� Ÿ���� ��ü, obj�� �����ȴ�. (������� �ʱ�ȭ�� �̷����)
	OutFunc(obj);												// �Ʊ� �Լ� �ۿ��� �����ص�, ���� Ÿ���� in/output �Լ��̴�. 
																// OutFunc�� �� ����? ��� �Լ��� �ƴѵ� ���� �����ص� ������? 
																// �ӽ� ��ü�� �Ҹ꿡 ���� �����ϱ� ���� �����ϴ� �� ������,
																// �ڵ� �м� ��Ʈ���� �˾ƺ����� ����. 
																// �ռ� ������ ��ü obj�� OutFunc�� �־��ش�.

	cout << endl;												// ���� ���� ����ֱ� ^_^
	SoHyeon tempRef = OutFunc(obj);								// �̹����� OutFunc(obj:�ʱ�ȭ) ��ü�� ���� Ÿ���� tempRef�� �����Ѵ�.
	cout << "Return obj " << &tempRef << endl;					// ���� ������ tempRef�� �ּҸ� ����Ѵ�. 
	return 0;													// main �Լ��� ����ȴ�. 
}

/*

[1st ���� ���]
New Object: 00EFF8EC										
New Copy Object: 00EFF7D4									
Parm ADR: 00EFF7D4											 
New Copy Object: 00EFF808
Destroy Object: 00EFF7D4
Destroy Object: 00EFF808

New Copy Object: 00EFF7D4
Parm ADR: 00EFF7D4
New Copy Object: 00EFF8E0
Destroy Object: 00EFF7D4
Return obj 00EFF8E0
Destroy Object: 00EFF8E0
Destroy Object: 00EFF8EC

*/

/*
[2nd ���� ���: �ڵ� ������]

New Object: 00B8F8B0											// SoHyeon obj(7) -> ���ο� ��ü�� ����(������ ȣ��)
New Copy Object: 00B8F798										// OutFunc�� obj�� ���޵Ǵ� �������� ��������� ȣ��ȴ�. (ob ����)
I am out funcObj: 00B8F798										// OutFunc�� ��ü�� �����. �Ű����� ob�� �ּ� ��ȯ
New Copy Object: 00B8F7CC										// OutFunc�� �Ű����� ob�� return�ϸ鼭 ��������� 2nd ȣ��
Destroy Object: 00B8F798										// �Ű����� ob�� ��� (obj�� ������ �ƴ�! ��� main�̶� ���� ����)
Destroy Object: 00B8F7CC										// (����X) �ӽð�ü�� ������ �� �� ��. 
																// ���� �ش� ���� ���� ����� �Բ� �����

New Copy Object: 00B8F798										// �Ű����� ob���� -> ���������� obj�� ���޵Ǵ� �������� ��������� ȣ��
I am out funcObj: 00B8F798										// OutFunc ��ü ����, �Ű����� ob�� �ּ� ���
New Copy Object: 00B8F8A4										// OutFunc�� return�� ���� �ӽð�ü ����
Destroy Object: 00B8F798										// �Ű����� ob�� ��� (OutFunc �Լ��� ����(return)�� �Բ�)
Return obj 00B8F8A4												// tempRef�� �ּҰ� �ӽð�ü�� �ּҿ� �����ϴ�. 
Destroy Object: 00B8F8A4										// main �Լ��� ����� �Բ� �ӽð�ü(tempRef) �Ҹ�
Destroy Object: 00B8F8B0										// �ռ� �����ߴ� obj �Ҹ�
*/

/*

[���� �ڵ� �м�]

* ���� �������� ���� 
* 1. �� ��ü�� ���� ��ü�� ����(�ʱ�ȭ)
* 2. �Լ��� �Ű������� ����
* 3. �Լ��� return (�̶� ������ ��ȯ�� X)

* �ӽ� ��ü�� Ư��
* 1. �ӽ� ��ü�� ���� ������ �Ѿ�� �ٷ� �Ҹ�
* 2. But �����ڷ� ���Ͽ� �����Ǵ� �ӽ� ��ü�� �ٷ� �Ҹ���� �ʴ´�. 
* 
* tempRef��� ���ο� ��ü�� �����Ͽ�, ��ȯ�Ǵ� ��ü�� ������ �����Ѵ�. (/)
* ��ȯ�Ǵ� �ӽ� ��ü�� tempRef��� �̸��� �Ҵ��Ѵ�. (O) ������;;
* ���� �ڵ带 ���� �ӽ� ��ü�� �Ҹ� Ÿ�̹��� Ȯ���غ���. 
* 
* + OutFunc�� ���� �������� ����? 
* ���ο� ����Ÿ���� ��ü�� �ٷ�ٴ� ������ �� �Լ��� ����غ��δ�. 
* 
* ���� �����ڴ� new ������ �����Ͽ�, ���� ������ parameter�� �־��ָ�, new ������ ��� ������ �ʱ�ȭ�ȴ�. 
* �ܼ��� �����ڿʹ� ���̰� �ִ�. 
* 
* OutFunc�� ���� ������ �Է� parameter�� �ް�, ���� Ÿ���� ��ȯ�ϴ� �Լ��̴�. 
* �̶� �� �Լ��� class�ۿ��� ����/���ǵǹǷ� ��� �Լ��� �ƴϴ�.
* �� �Լ��� ���� Ÿ���� ob�� �Ű������� �޴´�.
* �Լ��� ��ü���� "I am out funcObj: " ��� ������ �Ű����� ob�� �ּҸ� ����Ѵ�.
* ����, �ش� �Լ��� return ob�� ���� �ӽ� ��ü�� �����ϰ� ����ȴ�. �̶� �Ű����� ob�� �Ҹ�ȴ�.
* ������ �ӽ� ��ü�� �����ڿ� ���� �����ǰų�, Ȥ�� �ռ� �ڵ�� ���� �̸��� ���� �Ǹ� �Ҹ����� �ʰ� ��Ƴ��� �� �ִ�. 
* 
* ���� �����ڴ� ���ο� ���� Ÿ���� ��ü�� ������ ���� Ÿ�Կ� ���� ������ ��, ȣ��ȴ�.
* �̿� �޸�, OutFunc �Լ��� main�Լ����� Ư�� �Է� parameter�� �Բ� ȣ��� ��, 
* �� �Ű������� ���� �ʱ�ȭ �� �ӽ� ��ü�� ������Ų��. (return�Ѵ�.)
* �̶� �� �ӽ� ��ü�� ���� ���δ� �Լ� ��ü�θ� �����Ǵ� ���� �ƴϴ�.
* ������ ��ȯ���� �Լ��� ����� ���, ��Ƴ��´�. ������ �Լ� ��������, �̸��� �Ҵ�޴� ��쵵 �����.
* ������ �׷��� ���� ���, �� �Լ��� return�� ���� ������ �ӽð�ü�� �Լ� ����� �Բ� ��� �Ҹ�ȴ�. 
* 
*/