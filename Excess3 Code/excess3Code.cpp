#include "xor.h"
#include "or.h"
#include "and.h"
#include "not.h"
#include "defaultgate.h"
#include "excess3Code.h"
#include <iostream>

using namespace std;

void Excess3Code::setinput(string str){  // �Է¹��� bcd�� class ������ ������

	bcd = str;
}

void Excess3Code::divide(){  // string�� bcd�� �迭�� ����� ������
	
	int k = 0;
	for(int i=3; i>=0; i--){
		bcdarr[i] = bcd.at(k) - 48;
		k++;
	}
}

void Excess3Code::calculating(){  // �迭�� ��� bcd�� �����
	
	gate_NOT Not;
	gate_AND And;
	gate_OR Or;
	gate_XOR Xor;

	Not.setInput(bcdarr[0]);
	ex3arr[0] = Not.getOutput();  // Excess Code - [0]�ڸ�

	Xor.setInput(bcdarr[0], bcdarr[1]);
	Not.setInput( Xor.getOutput() );
	ex3arr[1] = Not.getOutput();  // Excess Code - [1]�ڸ�

	unsigned short value1;
	unsigned short value2;
	unsigned short value3;  // value1,2,3: gate�� ���� �ӽ÷� �����ϱ� ���� ���

	Not.setInput(bcdarr[2]);
	And.setInput( bcdarr[1], Not.getOutput() );
	value1 = And.getOutput();  // Excess Code[2] - and ����Ʈ 1

	And.setInput( bcdarr[0], Not.getOutput() );
	value2 = And.getOutput();  // Excess Code[2] - and ����Ʈ 2

	Not.setInput(bcdarr[0]);
	And.setInput( Not.getOutput(), bcdarr[2] );
	value3 = And.getOutput();

	Not.setInput(bcdarr[1]);
	And.setInput( value3, Not.getOutput() );
	value3 = And.getOutput();  // Excess Code[2] - and ����Ʈ 3

	Or.setInput(value1, value2);
	value1 = Or.getOutput();
	Or.setInput(value1, value3);
	ex3arr[2] = Or.getOutput();  // Excess Code - [2]�ڸ�

	And.setInput(bcdarr[1], bcdarr[2]);
	value1 = And.getOutput();  // Excess Code[3] - and ����Ʈ 1

	And.setInput(bcdarr[0], bcdarr[2]);
	value2 = And.getOutput();  // Excess Code[3] - and ����Ʈ 2

	Or.setInput(value1, value2);
	value3 = Or.getOutput();
	Or.setInput(value3, bcdarr[3]);
	ex3arr[3] = Or.getOutput();  // Excess Code - [3]�ڸ�

}

void Excess3Code::print(){  // ��ȯ�� excess-3 �ڵ带 �����

	cout << "Excess 3 Code: ";
	for(int i=3; i>=0; i--)
		cout << ex3arr[i];

	cout << endl;
}