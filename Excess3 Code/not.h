#include "or.h"

#pragma once

class gate_NOT : public gate_OR
{
public:
	gate_NOT(void);
	~gate_NOT(void);

	void setInput(unsigned short x);
	virtual void gateOperation();

};