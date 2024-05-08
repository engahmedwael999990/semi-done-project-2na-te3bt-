#ifndef CRECT_H
#define CRECT_H
#include<fstream>
#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1; //top left corner
	Point Corner2; //top right corner
	Point Corner3; //bottom right corner
	Point Corner4; //bottom left corner
public:
	CRectangle();
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	void Save(ofstream& OutFile);	//Save the figure parameters to the file
	void Load(ifstream& Infile);
	virtual bool PointInFig(int x, int y);
	virtual void PrintInfo(Output* pOut);
	virtual void SetID(int ind);
};

#endif