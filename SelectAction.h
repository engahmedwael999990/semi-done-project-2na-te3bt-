#pragma once
#include"Actions/Action.h"
#include "ApplicationManager.h"

using namespace std;

class SelectAction : public Action
{
	Point P;
	bool multiSelect;
	int selectedNum;
	int selectedIndex;

public:
	// make that constructor take x & y when creation
	SelectAction(ApplicationManager* pApp, bool);
	//  Select Figure 
	virtual void Execute();
	virtual void ReadActionParameters();
};