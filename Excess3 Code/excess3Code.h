#pragma once
#include<string>

using namespace std;

class Excess3Code
{
private:
	string bcd;
	unsigned short bcdarr[4];
	unsigned short ex3arr[4];

public:
	void setinput(string str);
	void divide();
	void calculating();
	void print();
};