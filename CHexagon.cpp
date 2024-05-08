#include "CHexagon.h"
#include<fstream>
CHexagon::CHexagon(){}
CHexagon::CHexagon(Point P, int sl, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	ID = 300 + (ID_Num++);
	center = P;
	sidelength = sl;
	P3.x = center.x + sidelength;  P3.y = center.y;
	P4.x = center.x + 0.5 * sidelength; P4.y = center.y + (sidelength * (sqrt(3) / 2));
	P5.x = center.x - 0.5 * sidelength; P5.y = center.y + (sidelength * (sqrt(3) / 2));
	P6.x = center.x - sidelength;  P6.y = center.y;
	P2.x = center.x + 0.5 * sidelength; P2.y = center.y - (sidelength * (sqrt(3) / 2));
	P1.x = center.x - 0.5 * sidelength; P1.y = center.y - (sidelength * (sqrt(3) / 2));
}

void CHexagon::Draw(Output* pOut) const
{
	//call function Draw_Hex to draw a hexagon on the screen
	pOut->draw_Hex(center, FigGfxInfo, Selected, sidelength);
}

void CHexagon::Save(ofstream& OutFile)	//Save the figure parameters to the file
{
	if (OutFile.is_open())
	{
		OutFile << "Hexagon   " << ID << "   " << P1.x << "   " << P1.y << "   " << P2.x
			<< "   " << P2.y << "   " << P3.x << "   " << P3.y << "   " << P4.x << "   " << P4.y << "   " << P5.x
			<< "   " << P5.y << "   " << P6.x << "   " << P6.y << "   " << center.x << "   " << center.y << "   " << getstring(FigGfxInfo.DrawClr) << "   ";
		if (FigGfxInfo.isFilled)
			OutFile << getstring(FigGfxInfo.FillClr) << endl;
		else
			OutFile << "NOT_FILLED" << endl;
	}
}


void CHexagon::Load(ifstream& Infile)
{
	string c;
	Infile >> ID >> P1.x >> P1.y >> P2.x >> P2.y >> P3.x >> P3.y >> P4.x >> P4.y >> P5.x >> P5.y >> P6.x >> P6.y >> center.x >> center.y;
	Infile >> c;
	FigGfxInfo.DrawClr = getcolor(c);
	Infile >> c;
	sidelength = 110;
	if (c == "NOT_FILLED")
		FigGfxInfo.isFilled = false;
	else
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = getcolor(c);
	}
}
void CHexagon::PrintInfo(Output* pOut)
{
	string id = to_string(ID);
	string x = to_string(center.x);
	string y = to_string(center.y);
	string len = to_string(sidelength);

	string fillingColor;
	if (FigGfxInfo.isFilled)
	{
		fillingColor = getstring(FigGfxInfo.FillClr);
	}
	else
	{
		fillingColor = "NO_FILL";
	}
	pOut->PrintMessage("Hexagon / ID: " + id + " / Center: (" + x + ", " + y + ") / Length: " + len + " / Drawing Color:" + getstring(FigGfxInfo.DrawClr) + " / Filling Color: " + fillingColor);
}
void CHexagon::SetID(int ind)
{
	ID = ind;
}

bool  CHexagon::PointInFig(int x, int y) {
	bool checkforx = false; //check if point between x1 and x2
	bool checkfory = false; //check if point between y1 and y2
	if (x >= center.x - 110 && x <= center.x + 110)
		checkforx = true;
	if (y >= center.y - 110 && y <= center.y + 110)
		checkfory = true;
	if (checkforx && checkfory) //return true if and only if two condition satisfied
		return true;
	else
		return false;
}
