#include "AddTriangleAction.h"
#include "CTriangle.h"

#include"ApplicationManager.h"

#include"GUI/Input.h"
#include"GUI/Output.h"

AddTriangleAction::AddTriangleAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddTriangleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");

	//Read 1st corner and store in point t1
	pIn->GetPointClicked(t1.x, t1.y);
	//condition to not allow to draw(click) outside the window
	while (t1.y < UI.StatusBarHeight || t1.y > UI.height - UI.StatusBarHeight)
	{
		pOut->PrintMessage("Choose a valid place");
		pIn->GetPointClicked(t1.x, t1.y);
	}
	pOut->PrintMessage("New Triangle: Click at second corner");

	//Read 2nd corner and store in point t2
	pIn->GetPointClicked(t2.x, t2.y);

	pOut->PrintMessage("New Triangle: Click at third corner");

	//Read 2nd corner and store in point P3
	pIn->GetPointClicked(t3.x, t3.y);

	TriangleGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriangleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriangleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddTriangleAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a triangle with the parameters read from the user
	CTriangle* T = new CTriangle(t1, t2, t3, TriangleGfxInfo);

	//Add the triangle to the list of figures
	pManager->AddFigure(T);
}