#pragma once
#ifndef CCIRC_H
#define CCIRC_H
#include<fstream>
#include"Figures/CFigure.h"
class CCircle : public CFigure
{
private:
	Point Center;
	Point OnCircle;
	int Radius;
public:
	CCircle();
	CCircle(Point center, Point oncircle, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	void Save(ofstream& OutFile);	//Save the figure parameters to the file
	void Load(ifstream& Infile);
	virtual bool PointInFig(int x, int y);
	virtual void PrintInfo(Output* pOut);
	virtual void SetID(int ind);
};

#endif