#pragma once
#include"Actions/Action.h"
#include"ApplicationManager.h"
class SaveAction : public Action
{
	int Figc;
	string filename;
public:
	SaveAction(ApplicationManager* pApp);//constructor
	void Execute();
	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();

};