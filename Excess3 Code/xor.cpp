#include "xor.h"

void gate_XOR::gateOperation(void)
{
	if(inputX != inputY)
		result = 1;
	else
		result = 0;
}

void gate_XOR::setInput(unsigned short x, unsigned short y)
{
	inputX = x;
	inputY = y;

	gateOperation();
}