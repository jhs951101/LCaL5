#include "defaultgate.h"

#pragma once

class gate_XOR : public defaultGate
{
public:
	void setInput(unsigned short x, unsigned short y);
	virtual void gateOperation();
};