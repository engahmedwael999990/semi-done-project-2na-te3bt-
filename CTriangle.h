#ifndef CTRIG_H
#define CRIG_H
#include<fstream>
#include"Figures/CFigure.h"
using namespace std;

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle();
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	void Save(ofstream& OutFile);	//Save the figure parameters to the file
	void Load(ifstream& Infile);
	virtual bool PointInFig(int x, int y);
	virtual void PrintInfo(Output* pOut);
	virtual void SetID(int ind);
	float area(int x1, int y1, int x2, int y2, int x3, int y3);
};

#endif