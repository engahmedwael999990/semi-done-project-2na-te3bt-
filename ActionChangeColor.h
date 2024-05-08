#pragma once
#include "Actions/Action.h"

#include "Figures/CFigure.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

class ActionChangeColor : public Action
{
private:
	color colour;
	int DrawOrFill;
	int  selectedNum;
	CFigure* fig;

public:
	ActionChangeColor(ApplicationManager* pApp, color c, int DrawOrFill, CFigure* figure);

	virtual void Execute();
	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();
};