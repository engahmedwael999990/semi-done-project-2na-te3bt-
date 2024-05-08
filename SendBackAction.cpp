#include"SendBackAction.h"
#include "ApplicationManager.h"
#include "GUI/Output.h"

SendBackAction::SendBackAction(ApplicationManager* pApp) :Action(pApp)
{}
void SendBackAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if (SelectedIndex == -1)
		pOut->PrintMessage("please select a figure first");
	else
		pManager->SendFigBack(SelectedIndex);


}

void SendBackAction::ReadActionParameters()
{

	SelectedIndex = pManager->GetSelectedFigureIndex();
}
