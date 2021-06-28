#include "xor.h"
#include "or.h"
#include "and.h"
#include "not.h"
#include "defaultgate.h"
#include "excess3Code.h"
#include <iostream>

using namespace std;

void Excess3Code::setinput(string str){  // 입력받은 bcd를 class 변수에 저장함

	bcd = str;
}

void Excess3Code::divide(){  // string형 bcd를 배열에 나누어서 저장함
	
	int k = 0;
	for(int i=3; i>=0; i--){
		bcdarr[i] = bcd.at(k) - 48;
		k++;
	}
}

void Excess3Code::calculating(){  // 배열에 담긴 bcd를 계산함
	
	gate_NOT Not;
	gate_AND And;
	gate_OR Or;
	gate_XOR Xor;

	Not.setInput(bcdarr[0]);
	ex3arr[0] = Not.getOutput();  // Excess Code - [0]자리

	Xor.setInput(bcdarr[0], bcdarr[1]);
	Not.setInput( Xor.getOutput() );
	ex3arr[1] = Not.getOutput();  // Excess Code - [1]자리

	unsigned short value1;
	unsigned short value2;
	unsigned short value3;  // value1,2,3: gate의 값을 임시로 저장하기 위해 사용

	Not.setInput(bcdarr[2]);
	And.setInput( bcdarr[1], Not.getOutput() );
	value1 = And.getOutput();  // Excess Code[2] - and 게이트 1

	And.setInput( bcdarr[0], Not.getOutput() );
	value2 = And.getOutput();  // Excess Code[2] - and 게이트 2

	Not.setInput(bcdarr[0]);
	And.setInput( Not.getOutput(), bcdarr[2] );
	value3 = And.getOutput();

	Not.setInput(bcdarr[1]);
	And.setInput( value3, Not.getOutput() );
	value3 = And.getOutput();  // Excess Code[2] - and 게이트 3

	Or.setInput(value1, value2);
	value1 = Or.getOutput();
	Or.setInput(value1, value3);
	ex3arr[2] = Or.getOutput();  // Excess Code - [2]자리

	And.setInput(bcdarr[1], bcdarr[2]);
	value1 = And.getOutput();  // Excess Code[3] - and 게이트 1

	And.setInput(bcdarr[0], bcdarr[2]);
	value2 = And.getOutput();  // Excess Code[3] - and 게이트 2

	Or.setInput(value1, value2);
	value3 = Or.getOutput();
	Or.setInput(value3, bcdarr[3]);
	ex3arr[3] = Or.getOutput();  // Excess Code - [3]자리

}

void Excess3Code::print(){  // 변환된 excess-3 코드를 출력함

	cout << "Excess 3 Code: ";
	for(int i=3; i>=0; i--)
		cout << ex3arr[i];

	cout << endl;
}