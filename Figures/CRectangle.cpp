#include "CRectangle.h"

CRectangle::CRectangle(){}
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	ID = 100 + (ID_Num++);
	Corner1 = P1;
	Corner3 = P2;
	Corner2.x = Corner3.x; Corner2.y = Corner1.y;
	Corner4.x = Corner1.x; Corner4.y = Corner3.y;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner3, FigGfxInfo, Selected);
}


void CRectangle::Save(ofstream& OutFile)	//Save the figure parameters to the file
{
	if (OutFile.is_open())
	{
		OutFile << "Rectangle   " << ID << "   " << Corner1.x << "   " << Corner1.y << "   " << Corner3.x
			<< "   " << Corner3.y << "   " << getstring(FigGfxInfo.DrawClr) << "   ";
		if (FigGfxInfo.isFilled)
			OutFile << getstring(FigGfxInfo.FillClr) << endl;
		else
			OutFile << "NOT_FILLED" << endl;
	}
}


void CRectangle::Load(ifstream& Infile)
{
	string c;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner3.x >> Corner3.y;
	Corner2.x = Corner3.x; Corner2.y = Corner1.y;
	Corner4.x = Corner1.x; Corner4.y = Corner3.y;
	Infile >> c;
	FigGfxInfo.DrawClr = getcolor(c);
	Infile >> c;
	if (c == "NOT_FILLED") {
		FigGfxInfo.isFilled = false;
	}
	else
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = getcolor(c);
	}
}
bool CRectangle::PointInFig(int x, int y)
{
	if ((x >= min(Corner1.x, Corner3.x) && x <= max(Corner1.x, Corner3.x) && y >= min(Corner1.y, Corner3.y) && y <= max(Corner1.y, Corner3.y)))
	{
		return true;
	}
	return false;
}

void CRectangle::PrintInfo(Output* pOut)
{
	string id = to_string(ID);
	string x1 = to_string(Corner1.x);
	string y1 = to_string(Corner1.y);
	string x2 = to_string(Corner2.x);
	string y2 = to_string(Corner2.y);
	string fillingcolor;
	if (FigGfxInfo.isFilled)
	{
		fillingcolor = getstring(FigGfxInfo.FillClr);
	}
	else
	{
		{
			fillingcolor = "No Fill";
		}
		pOut->PrintMessage("Rectangle / ID:" + id + " / Top Left Corner: " + x1 + ", " + y1 + ") / / " + " / bottom right Corner: (" + x2 + ", " + y2 + ") / / " + " Drawing Color: " + getstring(FigGfxInfo.DrawClr) + " / Filling Color: " + fillingcolor);
	}
}

void CRectangle::SetID(int ind)
{
	ID = ind;
}