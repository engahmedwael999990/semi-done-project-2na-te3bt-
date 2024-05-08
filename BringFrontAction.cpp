#include"BringFrontAction.h"
#include"ApplicationManager.h"
#include"GUI/Output.h"

BringFrontAction::BringFrontAction(ApplicationManager* pApp) :Action(pApp)
{}
void BringFrontAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if (SelectedIndex == -1)
		pOut->PrintMessage("please select a figure first");
	else
		pManager->BringFigFront(SelectedIndex);


}

void BringFrontAction::ReadActionParameters()
{


	SelectedIndex = pManager->GetSelectedFigureIndex();
}