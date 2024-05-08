#pragma once

#include"Actions/Action.h"
#include "Figures/CFigure.h"

#include "ApplicationManager.h"

class Copy : public Action
{
private:
	int selectedIndex, selectedNum;
	CFigure* fig;


public:
	Copy(ApplicationManager* pManager, CFigure* figure);
	virtual void ReadActionParameters();
	virtual void Execute();
	~Copy();
};

