#pragma once
#ifndef ADD_TRIANGLE_ACTION_H
#define ADD_TRIANGLE_ACTION_H
#include "Actions/Action.h"

//Add triangle Action class
class AddTriangleAction : public Action
{
private:
	Point t1, t2, t3; //triangle Corners
	GfxInfo TriangleGfxInfo;
public:
	//contstructor
	AddTriangleAction(ApplicationManager* pApp);

	//Reads triangle parameters
	virtual void ReadActionParameters();

	//Add triangle to the ApplicationManager
	virtual void Execute();

};
#endif