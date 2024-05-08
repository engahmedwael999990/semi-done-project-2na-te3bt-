#include"SelectAction.h"
#include <iostream>

using namespace std;
SelectAction::SelectAction(ApplicationManager* pApp, bool _multiSelect)
	: Action(pApp), multiSelect(_multiSelect)
{

}

void SelectAction::ReadActionParameters()
{
	//We need a pointer to the input and output class as a reference
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	//select a point on the figure wanted
	pOut->PrintMessage("Select a figure ^_^ ");

	pIn->GetPointClicked(P.x, P.y);
	
}



void SelectAction::Execute()
{
	ReadActionParameters();
	int selectedcount = pManager->GetNumberOfSelectedFigures(selectedNum);
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	//check where this point :
	//and return selected figure or null 
	CFigure* fig = pManager->GetFigure(P.x, P.y);
	// no figure selected
	
	pManager->set_Clipboard(NULL);
	



	if (fig == NULL)
	{
		pOut->PrintMessage("No Figure Selected");
		pManager->UnSelectFigures();
		pManager->UpdateInterface();
	}
	else
	{
		if (fig->IsSelected())             //If the figure is already selected,unselect it
		{
			fig->SetSelected(false);
			pOut->ClearStatusBar();
			pManager->setselected(NULL);
			pManager->UpdateInterface();
		}
		
		
			// IF Multiple select Enabled
		else
		{
			if (!multiSelect)
			{
				pManager->UnSelectFigures();
			}
			fig->SetSelected(true);
			fig->PrintInfo(pOut);
			pManager->setselected(fig);
			pManager->UpdateInterface();
		
			
		}
		
	}
}



