#include "CFigure.h"
#include"ColorDlg.h"
CFigure::CFigure(){}
int CFigure::ID_Num = 0;
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	ID = ++ID_Num;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}


color CFigure::getcolor(string s) {
	if (s == "BLACK")
		return BLACK;
	else if (s == "BLUE")
		return BLUE;
	else if (s == "RED")
		return RED;
	else if (s == "WHITE")
		return WHITE;
	else if (s == "YELLOW")
		return YELLOW;
	else if (s == "GREEN")
		return GREEN;
	else if (s == "TURQUOISE")
		return TURQUOISE;
	else if (s == "MAGENTA")
		return MAGENTA;
	else if (s == "LIGHTGOLDENRODYELLOW")
		return LIGHTGOLDENRODYELLOW;
	

}
string CFigure::getstring(color r) {

	if (r == BLACK)
		return "BLACK";
	else if (r == BLUE)
		return "BLUE";
	else if (r == RED)
		return "RED";
	else if (r == WHITE)
		return "WHITE";
	else if (r == YELLOW)
		return "YELLOW";
	else if (r == GREEN)
		return "GREEN";
	else if (r == TURQUOISE)
		return "TURQUOISE";
	else if (r == MAGENTA)
		return "MAGENTA";
	else if (r == LIGHTGOLDENRODYELLOW)
		return "LIGHTGOLDENRODYELLOW";

}
int CFigure::GetId() const
{
	return ID;
}

void CFigure::SetID(int ind)
{
	ID_Num--;
	ID = ind;
}

