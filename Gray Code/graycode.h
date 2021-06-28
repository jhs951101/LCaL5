#pragma once

#include <string>

using namespace std;

class GrayCode
{
private:
	string binaryCode;
	int BinaryArr[4];
	int GrayArr[4];

public:
	void settingInput(string str);
	void convertInt();
	void calculating();
	void print();
};