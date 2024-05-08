#include "CCircle.h"
#include<iostream>
#include<fstream>
using namespace std;

CCircle::CCircle()
{}

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	ID = 200 + (ID_Num++);
	Center = P1;
	OnCircle = P2;
	Radius = sqrt(pow((P1.x - P2.x), 2) + pow((P1.y - P2.y), 2));
}

void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCirc to draw a circle on the screen	
	pOut->DrawCirc(Center, OnCircle, FigGfxInfo, Selected);
}

void CCircle::Save(ofstream& OutFile)	//Save the figure parameters to the file
{
	if (OutFile.is_open())
	{
		OutFile << "Circle   " << ID << "   " << Center.x << "   " << Center.y << "   " << OnCircle.x
			<< "   " << OnCircle.y << "   " << getstring(FigGfxInfo.DrawClr) << "   ";
		if (FigGfxInfo.isFilled)
			OutFile << getstring(FigGfxInfo.FillClr) << endl;
		else
			OutFile << "NOT_FILLED" << endl;
	}
}


void CCircle::Load(ifstream& Infile)
{
	string c;
	Infile >> ID >> Center.x >> Center.y >> OnCircle.x >> OnCircle.y >> c;
	FigGfxInfo.DrawClr = getcolor(c);
	Infile >> c;
	if (c=="NOT_FILLED")
		FigGfxInfo.isFilled = false;

	else
	{
		FigGfxInfo.FillClr = getcolor(c);
		FigGfxInfo.isFilled = true;
	}

}
void CCircle::SetID(int ind)
{
	ID = ind;
}
void CCircle::PrintInfo(Output*pOut)
{
	string id = to_string(ID);
	string x = to_string(Center.x);
	string y = to_string(Center.y);
	string rad = to_string(Radius);
	

	string fillingColor;
	if (FigGfxInfo.isFilled)
	{
		fillingColor =getstring(FigGfxInfo.FillClr);
	}
	else
	{
		fillingColor = "NO_FILL";
	}
	pOut->PrintMessage("Circle / ID: " + id + " / Center: (" + x + ", " + y + " / Radius: " + rad + " / Drawing Color: " +getstring(FigGfxInfo.DrawClr) + " / Filling Color: " + fillingColor);
}



bool CCircle::PointInFig(int x, int y)  //Determine the position of the point
{
	if (abs(x-Center.x)<=Radius && abs(y- Center.y) <= Radius)
	{
		return true;
	}
	return false;
}