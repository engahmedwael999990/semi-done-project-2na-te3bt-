#include "AddCircleAction.h"
#include "CCircle.h"
#include"ApplicationManager.h"

#include"GUI/Input.h"
#include"GUI/Output.h"

AddCircleAction::AddCircleAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddCircleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at first corner");//message to get 1st point

	//Read 1st corner and store in point c1
	pIn->GetPointClicked(c1.x, c1.y);


	pOut->PrintMessage("New Circle: Click at second corner");//message to get 2nd point

	//Read 2nd corner and store in point c2
	pIn->GetPointClicked(c2.x, c2.y);

	CircleGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCircleAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a circle with the parameters read from the user
	CCircle* C = new CCircle(c1, c2, CircleGfxInfo);

	//Add the circle to the list of figures
	pManager->AddFigure(C);
}