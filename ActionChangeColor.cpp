#include "ActionChangeColor.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include"Figures/CFigure.h"
#include"vector"
ActionChangeColor::ActionChangeColor(ApplicationManager* pApp, color c, int drawORfill, CFigure* figure) : Action(pApp), colour(c), DrawOrFill(drawORfill), fig(figure)
{

}
void ActionChangeColor::ReadActionParameters()
{
	// Get a Pointer to the Output Interfaces
	Output* pOut = pManager->GetOutput();

	// Print a Message To The User To Set a Color To Change The Figure Color
	pOut->PrintMessage("Please Select a Color To change The Figure ");
	
	
}

void ActionChangeColor::Execute()
{

	ReadActionParameters();
	int selectedcount = pManager->GetNumberOfSelectedFigures(selectedNum);
	Output* pOut = pManager->GetOutput();

	Input* pIn = pManager->GetInput();

	// Check If The Mode if Change Drawing Color

	CFigure* fig = pManager->GetSelectedFigure();
	
	
		if (selectedcount == 1)
		{
			if (DrawOrFill == 1) {
				if (fig == NULL)
				{
					UI.DrawColor = colour;
					pManager->UpdateInterface();fig->ChngDrawClr(colour);
				}
				else
					fig->ChngDrawClr(colour);
			}

			// Check If The Mode if Change Filling Color


			if (DrawOrFill == 2) {
				if (fig != NULL)
					fig->ChngFillClr(colour);
				else
					UI.FillColor = colour;
				pManager->UpdateInterface();
			}
		}
		else
			pOut->PrintMessage("Please select only one figure if u want to change color");
}




