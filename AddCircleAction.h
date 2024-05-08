#pragma once
#ifndef ADD_CIRCLE_ACTION_H
#define ADD_CIRCLE_ACTION_H

#include "Actions/Action.h"

//Add Circle Action class
class AddCircleAction : public Action
{
private:
	Point c1, c2; //circle Corners
	GfxInfo CircleGfxInfo;
public:
	AddCircleAction(ApplicationManager* pApp);//constructor

	//Reads Circle parameters
	virtual void ReadActionParameters();

	//Add Circle to the ApplicationManager
	virtual void Execute();

};

#endif