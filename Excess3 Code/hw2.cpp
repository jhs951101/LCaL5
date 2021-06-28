#include "excess3Code.h"
#include <iostream>
#include <cmath>

using namespace std;

int main(){

	Excess3Code E;  // E: Excess3Code 클래스
	string str;  // str: 입력받은 bcd 값을 저장함
	cout << "Input BCD code: ";
	cin >> str;  // BCD 값을 입력받음

	if(str.length() != 4){  // 입력받은 bcd가 4자리가 아닐 경우 error
		cout << "Error: more or less dights" << endl;
		return 1;
	}

	int sum = 0;  // sum: bcd를 10진수로 변환한 값이 저장됨
	int dight;  // dight: 숫자 한자리씩 저장하기 위한 변수

	int k = 0;
	for(int i=3; i>=0; i--){  // bcd를 10진수로 변환함
		dight = str.at(i) - 48;
		sum += ( dight * pow(2,k) );
		k++;
	}

	if(sum >= 10){  // 10진수로 변환된 값이 10을 넘을 경우 XXXX를 출력함
		cout << "Excess 3 Code: xxxx" << endl;
		return 0;
	}

	E.setinput(str);
	E.divide();
	E.calculating();
	E.print();

	return 0;
}
