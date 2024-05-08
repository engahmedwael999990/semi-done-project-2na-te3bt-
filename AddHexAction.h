#pragma once
#ifndef ADD_HEXAGON_ACTION_H
#define ADD_HEXAGON_ACTION_H

#include "Actions/Action.h"

//Add hexagonal Action class
class AddHexAction : public Action
{
private:
	Point h; //hexagon center
	GfxInfo HexGfxInfo;
public:
	AddHexAction(ApplicationManager* pApp);//constructor

	//Reads hexagon parameters
	virtual void ReadActionParameters();

	//Add hexagon to the ApplicationManager
	virtual void Execute();

};

#endif
