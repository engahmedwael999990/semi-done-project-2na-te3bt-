#pragma once
#ifndef ADD_SQUARE_ACTION_H
#define ADD_SQUARE_ACTION_H

#include "Actions/Action.h"

//Add square Action class
class AddSquareAction : public Action
{
private:
	Point s; //square Corners
	GfxInfo SQGfxInfo;
public:
	//constructor
	AddSquareAction(ApplicationManager* pApp);

	//Reads square parameters
	virtual void ReadActionParameters();

	//Add square to the ApplicationManager
	virtual void Execute();

};

#endif