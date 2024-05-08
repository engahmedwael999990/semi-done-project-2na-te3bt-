#pragma once
#ifndef SEND_BACK_ACTION_H
#define SEND_BACK_ACTION_H

#include"Actions/Action.h"
class SendBackAction : public Action
{
private:
	int SelectedIndex;
public:
	SendBackAction(ApplicationManager* pApp);
	virtual void Execute();
	virtual void ReadActionParameters();

};

#endif