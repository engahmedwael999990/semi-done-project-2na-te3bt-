#include"SaveAction.h"
#include"ApplicationManager.h"
#include"Figures/CFigure.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
SaveAction::SaveAction(ApplicationManager* pApp) :Action(pApp)
{
	filename = "text";
}
//constructor

//Reads parameters required for action to execute (code depends on action type)
void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please write a File name then press Enter: ");
	filename = pIn->GetSrting(pOut);

}
void SaveAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	ofstream OutFile;
	OutFile.open(filename + ".txt", ios::out);
	if (OutFile.is_open())
	{
		OutFile << pManager->ConvertToString(UI.DrawColor) << "      " << pManager->ConvertToString(UI.FillColor)
			<< endl << pManager->getFig() << endl;
		pManager->SaveAll(OutFile);
		OutFile.close();
		pOut->PrintMessage("Graph saved succesfully");
	}
}