#include "graycode.h"

#include <iostream>

using namespace std;

int main(){

	GrayCode A;
	
	string str;
	cout << "Input binary code (4 dights) : ";
	cin >> str;

	A.settingInput(str);
	A.convertInt();
	A.calculating();
	A.print();

	return 0;
}