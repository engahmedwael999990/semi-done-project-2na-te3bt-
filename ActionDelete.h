#pragma once

#include "Actions/Action.h"
#include "Figures/CFigure.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"


class ActionDelete :
	public Action
{
	CFigure* deleted;
public:

	ActionDelete(ApplicationManager* pApp, CFigure*);
	virtual void ReadActionParameters();
	virtual void Execute();

	~ActionDelete();

};
