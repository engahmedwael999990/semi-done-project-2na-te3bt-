#include "CSquare.h"
#include<fstream>
CSquare::CSquare(){}
CSquare::CSquare(Point P1, int sl, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	ID = 250 + (ID_Num++);
	center = P1;
	sidelength = sl;
	Corner1.x = center.x - (sidelength / 2); Corner1.y = center.y - (sidelength / 2);
	Corner2.x = center.x + (sidelength / 2); Corner2.y = center.y - (sidelength / 2);
	Corner3.x = center.x - (sidelength / 2); Corner3.y = center.y + (sidelength / 2);
	Corner4.x = center.x + (sidelength / 2); Corner4.y = center.y + (sidelength / 2);
}

void CSquare::Draw(Output* pOut) const
{
	//call function DrawSqr to draw a square on the screen
	pOut->DrawSqr(center, sidelength, FigGfxInfo, Selected);
}

void CSquare::Save(ofstream& OutFile)	//Save the figure parameters to the file
{
	if (OutFile.is_open())
	{
		OutFile << "Square   " << ID << "   " << Corner1.x << "   " << Corner1.y << "   " << Corner2.x
			<< "   " << Corner2.y << "   " << Corner3.x << "   " << Corner3.y << "   " << Corner4.x << "   " << Corner4.y
			<< "   " << getstring(FigGfxInfo.DrawClr) << "   ";
		if (FigGfxInfo.isFilled)
			OutFile << getstring(FigGfxInfo.FillClr) << endl;
		else
			OutFile << "NOT_FILLED" << endl;
	}
}


void CSquare::Load(ifstream& Infile)
{
	string c;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y >> Corner4.x >> Corner4.y;
	Infile >> c;
	//Add center for square

	sidelength = Corner2.x - Corner1.x;
	center.x = Corner1.x + (sidelength / 2);
	center.y = Corner1.y + (sidelength / 2);

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
void CSquare::SetID(int ind)
{
	ID = ind;
}
void CSquare::PrintInfo(Output* pOut) {
	string s = "Figure ID: " + to_string(ID) + ". Figure Type: Square. " + "Starting Point: (" + to_string(center.x - 100) +
		", " + to_string(center.y - 100) + "). Ending Point: (" + to_string(center.x + 100) + ", " + to_string(center.y + 100) +
		"). Side Length: 200." + "\0";
	pOut->PrintMessage(s);

}

bool CSquare::PointInFig(int x, int y)
{
	if ((x >= Corner1.x && x <= Corner1.x + sidelength) && (y >= Corner1.y && y <= Corner1.y + sidelength))
	{
		return true;
	}
	return false;
}