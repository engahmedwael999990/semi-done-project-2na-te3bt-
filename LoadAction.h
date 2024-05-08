#pragma once
#include"Actions/Action.h"
#include"ApplicationManager.h"
class LoadAction : public Action
{
	string filename;
public:
	LoadAction(ApplicationManager* pApp);//constructor
	void Execute();
	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();
};