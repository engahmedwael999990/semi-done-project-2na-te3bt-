#pragma once
#ifndef CHEX_H
#define CHEX_H
#include<fstream>
#include<iostream>
#include"Figures/CFigure.h"
using namespace std;

class CHexagon : public CFigure
{
private:
	Point center;
	                /********************************************************************
					//corners are arranged clock-wise starting from the top left corner// 
				   *********************************************************************/
	Point P1;
	Point P2;  
	Point P3; 
	Point P4;
	Point P5;
	Point P6;
	int sidelength;
public:
	CHexagon();
	CHexagon(Point, int, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	void Save(ofstream& OutFile);	//Save the figure parameters to the file
	void Load(ifstream& Infile);
	virtual bool PointInFig(int x, int y);
	virtual void PrintInfo(Output* pOut);
	virtual void SetID(int ind);

};

#endif