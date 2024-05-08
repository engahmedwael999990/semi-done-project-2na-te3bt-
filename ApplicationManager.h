#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include<fstream>
//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	int DORF = 0;
	CFigure* SelectedFig; //Pointer to the selected figure
	
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

	CFigure* Clipboard;  //Pointer to copied/cut figure

public:	
	bool multiSelect;
	ApplicationManager(); 
	~ApplicationManager();
	int selectedNum;
	int selectedIndex;
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void SendFigBack(int SelectedIndex);    //sends selected figure to back
	void BringFigFront(int SelectedIndex);  //brings selected figure to front
	void set_Clipboard(CFigure* c);
	CFigure* GetSelectedFigure();  //get one selected figure by checking isSelected flag
	void DeleteSelectedFigures();    //delete selected figures
	void RearrangingFigList();  
	void UnSelectFigures() const;     //remove null refrences from the FigList
	int GetNumberOfSelectedFigures(int selectedNum) const;
	
	int GetSelectedFigureIndex()const;
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	void SaveAll(ofstream& OutFile);//call save for all drawn figures
	void LoadAll();//clean figlist
	int getFig();//getter for FigCount
	void setFig(int x);//setter for FigCount
	string ConvertToString(color c);//convert color to string
	color ConvertToColor(string s);
	//convert string to color

	void setselected(CFigure*selected);
};

#endif