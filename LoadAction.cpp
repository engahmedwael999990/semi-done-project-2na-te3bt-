#include"LoadAction.h"
#include"ApplicationManager.h"
#include<fstream>
#include<string>
#include<iostream>
#include"Figures\CRectangle.h"
#include"CSquare.h"
#include"CCircle.h"
#include"CTriangle.h"
#include"CHexagon.h"
#include"ApplicationManager.h"
LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp)
{}
void LoadAction::ReadActionParameters()//get file name
{
	Output* pOut = pManager->GetOutput();//pointer to output
	Input* pIn = pManager->GetInput();//pointer to input
	pOut->PrintMessage("Please write a File name then press Enter: ");
	filename = pIn->GetSrting(pOut);//store input in filename
}
void LoadAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ifstream InFille;
	ReadActionParameters();//read file name
	pOut->ClearDrawArea();//clear screen
	InFille.open(filename + ".txt", ios::in);//read
	if (InFille.is_open())
	{
		string CLR, FillCLR, name; int count;
		CFigure* fig;
		string line;
		InFille >> CLR >> FillCLR;
		UI.DrawColor = pManager->ConvertToColor(CLR);
		UI.FillColor = pManager->ConvertToColor(FillCLR);
		pManager->LoadAll();
		InFille >> count;//number of figures
		//pManager->setFig(count);
		while (count)
		{
			InFille >> name;
			if (name == "Rectangle")
				fig = new CRectangle;
			else if (name == "Triangle")
				fig = new CTriangle;
			else if (name == "Hexagon")
				fig = new CHexagon;
			else if (name == "Square")
				fig = new CSquare;
			else if (name == "Circle")
				fig = new CCircle;

			fig->Load(InFille);
			fig->SetSelected(false);
			pManager->AddFigure(fig);//add to figlist
			count--;
		}
		pManager->UpdateInterface();
		pOut->ClearStatusBar();
		pOut->CreateStatusBar();
		pOut->PrintMessage("Graph Loaded succesfully");
	}
	else
		pOut->PrintMessage("Sorry wrong name :)...");
}