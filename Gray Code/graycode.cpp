#include "graycode.h"
#include "xor.h"
#include "defaultgate.h"

#include <iostream>
#include <string>

using namespace std;

void GrayCode::settingInput(string str){

	binaryCode = str;
}

void GrayCode::convertInt(){

	for(int i=0; i<4; i++)
		BinaryArr[i] = binaryCode.at(i) - 48;

}

void GrayCode::calculating(){

	gate_XOR G;
	
	// Gray 코드로 변환
	GrayArr[0] = BinaryArr[0];

	for(int i=0; i<=2; i++){
		G.setInput(BinaryArr[i], BinaryArr[i+1]);
		GrayArr[i+1] = G.getOutput();
	}
	
	// Binary 코드로 해독
	BinaryArr[0] = GrayArr[0];

	for(int i=0; i<=2; i++){
		G.setInput(BinaryArr[i], GrayArr[i+1]);
		BinaryArr[i+1] = G.getOutput();
	}

}

void GrayCode::print(){

	cout << "Gray code: ";
	for(int i=0; i<4; i++)
		cout << GrayArr[i];

	cout << endl;

	cout << "Binary code: ";
	for(int i=0; i<4; i++)
		cout << BinaryArr[i];

}