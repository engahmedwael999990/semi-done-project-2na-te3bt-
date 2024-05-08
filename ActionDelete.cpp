#include "ActionDelete.h"
ActionDelete::ActionDelete(ApplicationManager* pApp, CFigure* fig) :Action(pApp), deleted(fig)
{}

void  ActionDelete::ReadActionParameters()
{}

void ActionDelete::Execute() {
	ReadActionParameters();
	//We need a pointer to the input and output class as a reference

	Output* pOut = pManager->GetOutput();
	//check if there were any selected figures to delete
	
	if (pManager->getFig()==0)
	{
		pOut->PrintMessage("No selected figure(s) to delete!");
	}
	else
	{
		//deleting selected figures
		pManager->DeleteSelectedFigures();
		//clearing the draw area and redraw the figList
		pOut->ClearDrawArea();
		pManager->UpdateInterface();
		//confirmation message
		pOut->PrintMessage("figure(s) deleted!");

	}
}

ActionDelete::~ActionDelete()
{
}
