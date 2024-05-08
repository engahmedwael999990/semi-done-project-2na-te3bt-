#include "CTriangle.h"
#include<fstream>
CTriangle::CTriangle(){}
CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	ID = 150 + (ID_Num++);
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTrig to draw a triangle on the screen	
	pOut->DrawTrig(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}

void CTriangle::Save(ofstream& OutFile)	//Save the figure parameters to the file
{
	if (OutFile.is_open())
	{
		OutFile << "Triangle   " << ID << "   " << Corner1.x << "   " << Corner1.y << "   " << Corner2.x
			<< "   " << Corner2.y << "   " << Corner3.x << "   " << Corner3.y << "   " << getstring(FigGfxInfo.DrawClr) << "   ";
		if (FigGfxInfo.isFilled)
			OutFile << getstring(FigGfxInfo.FillClr) << endl;
		else
			OutFile << "NOT_FILLED" << endl;
	}
}


void CTriangle::Load(ifstream& Infile)
{
	string c;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y;
	Infile >> c;
	FigGfxInfo.DrawClr = getcolor(c);
	Infile >> c;
	if (c == "NOT_FILLED")
		FigGfxInfo.isFilled = false;
	else
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = getcolor(c);
	}
}
void CTriangle::SetID(int ind)
{
	ID = ind;
}
void CTriangle::PrintInfo(Output* pOut)
{
	string id = to_string(ID);
	string x1 = to_string(Corner1.x);
	string y1 = to_string(Corner1.y);
	string x2 = to_string(Corner2.x);
	string y2 = to_string(Corner2.y);
	string x3 = to_string(Corner3.x);
	string y3 = to_string(Corner3.y);
	string clr = getstring(this->FigGfxInfo.DrawClr);
	if (FigGfxInfo.isFilled)
	{
		string clrF = getstring(this->FigGfxInfo.FillClr);
		pOut->PrintMessage("Triangle - ID:" + id + " Corner1: (" + x1 + ", " + y1 + ")" + " Corner2: (" + x2 + ", " + y2 + ")" + " Corner3: (" + x3 + ", " + y3 + ")" + " DrawColor: " + clr + " FillColor: " + clrF);
	}
	else
		pOut->PrintMessage("Triangle - ID:" + id + " Corner1: (" + x1 + ", " + y1 + ")" + " Corner2: (" + x2 + ", " + y2 + ")" + " Corner3: (" + x3 + ", " + y3 + ")" + " DrawColor: " + clr + " FillColor: NON-Filled");
}

float CTriangle:: area(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

bool CTriangle::PointInFig(int x, int y)              //Function to inform me if the point in the figure or not
{
	float A = area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	float A1 = area(x, y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	float A2 = area(Corner1.x, Corner1.y, x, y, Corner3.x, Corner3.y);
	float A3 = area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, x, y);
	if (A == A1 + A2 + A3)
	{
		return true;
	}
	return false;
}