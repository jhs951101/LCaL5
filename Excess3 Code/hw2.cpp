#include "excess3Code.h"
#include <iostream>
#include <cmath>

using namespace std;

int main(){

	Excess3Code E;  // E: Excess3Code Ŭ����
	string str;  // str: �Է¹��� bcd ���� ������
	cout << "Input BCD code: ";
	cin >> str;  // BCD ���� �Է¹���

	if(str.length() != 4){  // �Է¹��� bcd�� 4�ڸ��� �ƴ� ��� error
		cout << "Error: more or less dights" << endl;
		return 1;
	}

	int sum = 0;  // sum: bcd�� 10������ ��ȯ�� ���� �����
	int dight;  // dight: ���� ���ڸ��� �����ϱ� ���� ����

	int k = 0;
	for(int i=3; i>=0; i--){  // bcd�� 10������ ��ȯ��
		dight = str.at(i) - 48;
		sum += ( dight * pow(2,k) );
		k++;
	}

	if(sum >= 10){  // 10������ ��ȯ�� ���� 10�� ���� ��� XXXX�� �����
		cout << "Excess 3 Code: xxxx" << endl;
		return 0;
	}

	E.setinput(str);
	E.divide();
	E.calculating();
	E.print();

	return 0;
}
