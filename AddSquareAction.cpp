#include "AddSquareAction.h"
#include "CSquare.h"

#include"ApplicationManager.h"

#include"GUI/Input.h"
#include"GUI/Output.h"

AddSquareAction::AddSquareAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddSquareAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at center");

	//Read 1st corner and store in point s
	pIn->GetPointClicked(s.x, s.y);

	SQGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SQGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SQGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddSquareAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CSquare* S = new CSquare(s,110, SQGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(S);
}