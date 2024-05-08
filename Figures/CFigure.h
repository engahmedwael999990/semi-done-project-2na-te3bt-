#ifndef CFIGURE_H
#define CFIGURE_H
#include<iostream>
#include<fstream>
#include "..\defs.h"
#include "..\GUI\Output.h"
using namespace std;

//Base class for all figures
class CFigure
{
protected:

	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;  //Figure graphis info
	 static int ID_Num;//to increment ID of figures of the same type
	
	/// Add more parameters if needed.

public:
	CFigure();
	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	virtual void Save(ofstream& OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream& Infile) = 0;	//Load the figure parameters to the file
	color getcolor(string s);//convert string to color
	string getstring(color r);
	int GetId()const;
	void SetID(int ind);
	virtual bool PointInFig(int x, int y) = 0;
	virtual void PrintInfo(Output* pOut) = 0;
	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};


#endif