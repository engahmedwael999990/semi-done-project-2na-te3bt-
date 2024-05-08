#include"Copy.h"



Copy::Copy(ApplicationManager* pManager, CFigure* figure) :Action(pManager), fig(figure)
{

}

void Copy::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Please Select a figure to copy");
	


}







void Copy::Execute() {
	int selectedcount = pManager->GetNumberOfSelectedFigures(selectedNum);
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	
	CFigure* fig = pManager->GetSelectedFigure();
	if (selectedcount == 1)
	{
		if (fig != NULL) {
			pManager->set_Clipboard(fig);
			pOut->PrintMessage("Figure is copied");
		}

		else if (fig == NULL) {
			pOut->PrintMessage("No selected figure to copy");

		}
	}
	else
	{
		pOut->PrintMessage("Please select one figure if u want to copy");
	}
}
Copy::~Copy() {}
