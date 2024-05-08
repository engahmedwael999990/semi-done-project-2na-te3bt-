#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include"AddSquareAction.h"
#include"AddCircleAction.h"
#include"AddHexAction.h"
#include"AddTriangleAction.h"
#include"SaveAction.h"
#include"LoadAction.h"
#include"SelectAction.h"
#include"ActionChangeColor.h"
#include"ActionDelete.h"
#include"SendBackAction.h"
#include"BringFrontAction.h"
#include"Copy.h"
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
	//delete all old figures

}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	CFigure* figure = NULL;
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case EXIT:
			///create ExitAction here
			
			break;


		case TO_DELETE_FIGURE:
			pAct = new	ActionDelete(this, SelectedFig);
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;

		case TO_SELECT:
			pAct = new SelectAction(this, multiSelect);
			break;
		case TO_SAVE_GRAPH:
			pAct = new SaveAction(this);
			break;

		case TO_LOAD_GRAPH:
			pAct = new LoadAction(this);
			break;

		case DRAW_TRIANGLE:
			pAct = new AddTriangleAction(this);
			break;

		case DRAW_HEXAGON:
			pAct = new AddHexAction(this);
			break;

		case DRAW_CIRCLE:
			pAct = new AddCircleAction(this);
			break;

		case DRAW_SQUARE:
			pAct = new AddSquareAction(this);
			break;


		case TO_CHANGE_TO_YELLOW:

			pAct = new ActionChangeColor(this, YELLOW, DORF, figure);
			break;

		case TO_CHANGE_TO_BLUE:

			pAct = new ActionChangeColor(this, DEEPSKYBLUE, DORF, figure);
			break;

		case TO_CHANGE_TO_GREEN:

			pAct = new ActionChangeColor(this, LIGHTGREEN, DORF, figure);
			break;

		case TO_CHANGE_TO_ORANGE:

			pAct = new ActionChangeColor(this, ORANGE, DORF, figure);
			break;

		case TO_CHANGE_TO_RED:

			pAct = new ActionChangeColor(this, TOMATO, DORF, figure);
			break;
		case TO_CHANGE_TO_BLACK:

			pAct = new ActionChangeColor(this, BLACK, DORF, figure);
			break;

		case TO_CHANGE_BORDER_COLOR:
			DORF = 1;
			pOut->PrintMessage("Select drawing color, u cant select more than one figure");
			break;

		case TO_CHANGE_FILLING_COLOR:
			DORF = 2;
			pOut->PrintMessage("Select filling color, u cant select more than one figure");
			break;

		case TO_SEND_BACK:
			pAct = new SendBackAction(this);
			break;

		case TO_BRING_FRONT:
			pAct = new BringFrontAction(this);
			break;

		case TO_COPY:
			pAct = new Copy(this, figure);
			break;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
//unSelect Figures
void ApplicationManager::UnSelectFigures() const       //mull number of unselected figures
{
		for (int i = 0; i < FigCount; i++)
		{
			FigList[i]->SetSelected(false);
		}
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.
	// if the point in figure will return Pointer on Figure
	for (int i=0;i<FigCount;i++)
	{
		// point in Figure and Figure not hide
		if (FigList[i]->PointInFig(x, y))
		{
			FigList[i]->PrintInfo(pOut);
			return FigList[i];
		}
	}
	// if point not in any figure will return NULL
	return NULL;
}
void ApplicationManager::set_Clipboard(CFigure* c)
{
	Clipboard = c;
}


	CFigure* ApplicationManager::GetSelectedFigure()
{
	selectedNum = 0;

	for (int i = 0;i < FigCount;i++) {
		if (FigList[i]->IsSelected())
		{
			selectedIndex=i;
			selectedNum++;
		}
	}
	if (selectedNum == 0)
	{
		// if no figure is selected return null
		return NULL;
	}
	else
	{
		CFigure* SelectedFigure = FigList[selectedIndex];
		return  FigList[selectedIndex];
	}
}



void ApplicationManager::RearrangingFigList()         //removing null refrences from FigList
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == NULL)
		{
			//shifting all upcoming figures to remove the null referenece
			for (int j = i; j < FigCount - 1; j++)
			{
				FigList[j] = FigList[j + 1];
			}
		}
	}
}

void ApplicationManager::DeleteSelectedFigures()           //delete all selected figures
{
	int deletedNum = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			delete FigList[i];
			FigList[i] = NULL;
			deletedNum++;
			
		}
	}

	FigCount -= deletedNum;
}

void ApplicationManager::SendFigBack(int SelectedIndex)
{
	CFigure* SelectedFigure = FigList[SelectedIndex];//saving the selected figure in a separate pointer
	for (int i = SelectedIndex; i > 0; i--)//looping on figlist to increase the index of all preceding figures by one
		FigList[i] = FigList[i - 1];//this leaves the first place in the array empty for the selected figure
	//note that FigCount does not change
	FigList[0] = SelectedFigure;
}

void ApplicationManager::BringFigFront(int SelectedIndex)
{
	CFigure* SelectedFigure = FigList[SelectedIndex];//saving the selected figure in a separate pointer
	for (int i = SelectedIndex; i < FigCount; i++)//looping on figlist to dectrasee the index of all following figures by one
		FigList[i] = FigList[i + 1];//this leaves the last place in the array empty for the selected figure
	//note that FigCount does not change
	FigList[FigCount - 1] = SelectedFigure;
}

int ApplicationManager::GetSelectedFigureIndex() const
{
	for (int i = 0; i < FigCount; i++)//searching for a selected figure
		if (FigList[i]->IsSelected())
			return i;
	return -1;//a flag indicating that no figures are selected
}
int ApplicationManager::GetNumberOfSelectedFigures(int selectedNum) const
{
	selectedNum = 0;
	for (int i = FigCount - 1; i >= 0; i--) {
		if (FigList[i]->IsSelected())
		{
			selectedNum++;
		}
	}
	return selectedNum;
}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }

void ApplicationManager::setFig(int x)
{
	FigCount = x;
}

void ApplicationManager::SaveAll(ofstream& OutFile) //call save function for each figure
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Save(OutFile);
}


int ApplicationManager::getFig() //getter for count of figure(to not out<< in ApplicationManager)
{
	return FigCount;
}


string ApplicationManager::ConvertToString(color c) {

	if (c == BLACK)
		return "BLACK";
	else if (c == BLUE)
		return "BLUE";
	else if (c == RED)
		return "RED";
	else if (c == WHITE)
		return "WHITE";
	else if (c == YELLOW)
		return "YELLOW";
	else if (c == GREEN)
		return "GREEN";
	else if (c == TURQUOISE)
		return "TURQUOISE";
	else if (c == MAGENTA)
		return "MAGENTA";
	else if (c == LIGHTGOLDENRODYELLOW)
		return "LIGHTGOLDENRODYELLOW";
	return "BLACK";
}


color ApplicationManager::ConvertToColor(string s) {
	if (s == "BLACK")
		return BLACK;
	else if (s == "BLUE")
		return BLUE;
	else if (s == "RED")
		return RED;
	else if (s == "WHITE")
		return WHITE;
	else if (s == "YELLOW")
		return YELLOW;
	else if (s == "GREEN")
		return GREEN;
	else if (s == "TURQUOISE")
		return TURQUOISE;
	else if (s == "MAGENTA")
		return MAGENTA;
	else if (s == "LIGHTGOLDENRODYELLOW")
		return LIGHTGOLDENRODYELLOW;
	return BLACK;
}

void ApplicationManager::setselected(CFigure* selected)
{
	SelectedFig = selected;
}


void ApplicationManager::LoadAll()
{
	for (int i = 0; i < FigCount; i++)
		FigList[i] = NULL;
	FigCount = 0;
}


////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
