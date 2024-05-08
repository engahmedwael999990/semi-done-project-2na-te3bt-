
#pragma once
#ifndef BRING_FRONT_ACTION_H
#define BRING_FRONT_ACTION_H

#include"Actions/Action.h"
class BringFrontAction : public Action
{
private:
	int SelectedIndex;
public:
	BringFrontAction(ApplicationManager* pApp);
	virtual void Execute();
	virtual void ReadActionParameters();

};

#endif


