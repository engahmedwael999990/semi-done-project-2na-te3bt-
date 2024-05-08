#include "Output.h"
#include <cmath>

Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.LineUnderTBWidth = 4;
	UI.MenuItemWidth = 49;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = BLACK;		//Messages color
	UI.BkGrndColor = WHITESMOKE;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = RED;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project - Spring 2024");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_SQUARE] = "images\\MenuItems\\Menu_Square.jpg";
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\Menu_Triangle.jpg";
	MenuItemImages[ITM_HEXAGON] = "images\\MenuItems\\Menu_Hexagon.jpg";
	MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\Menu_Circle.jpg";
	MenuItemImages[SELECT] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[CHANGE_BORDER_COLOR] = "images\\MenuItems\\Menu_Change_Color_Border.jpg";
	MenuItemImages[CHANGE_FILLING_COLOR] = "images\\MenuItems\\Menu_Change_Filling_Color.jpg";
	MenuItemImages[BLACK_COLOR] = "images\\MenuItems\\Menu_Black_Color.jpg";
	MenuItemImages[YELLOW_COLOR] = "images\\MenuItems\\Menu_Yellow_Color.jpg";
	MenuItemImages[ORANGE_COLOR] = "images\\MenuItems\\Menu_Orange_Color.jpg";
	MenuItemImages[RED_COLOR] = "images\\MenuItems\\Menu_Red_Color.jpg";
	MenuItemImages[GREEN_COLOR] = "images\\MenuItems\\Menu_Green_Color.jpg";
	MenuItemImages[BLUE_COLOR] = "images\\MenuItems\\Menu_Blue_Color.jpg";
	MenuItemImages[DELETE_FIGURE] = "images\\MenuItems\\Menu_Delete_Figure.jpg";
	MenuItemImages[CLEAR_ALL] = "images\\MenuItems\\Menu_Clear_All.jpg";
	MenuItemImages[COPY] = "images\\MenuItems\\Menu_Copy.jpg";
	MenuItemImages[CUT] = "images\\MenuItems\\Menu_Cut.jpg";
	MenuItemImages[PASTE] = "images\\MenuItems\\Menu_Paste.jpg";
	MenuItemImages[SEND_BACK] = "images\\MenuItems\\Menu_Send_Back.jpg";
	MenuItemImages[BRING_FRONT] = "images\\MenuItems\\Menu_Bring_Front.jpg";
	MenuItemImages[SAVE_GRAPH] = "images\\MenuItems\\Menu_Save_Graph.jpg";
	MenuItemImages[LOAD_GRAPH] = "images\\MenuItems\\Menu_Load_Graph.jpg";
	MenuItemImages[SWITCH_PLAY_MODE] = "images\\MenuItems\\Menu_Switch_Play_Mode.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, UI.LineUnderTBWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
	UI.InterfaceMode = MODE_PLAY;

	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[FIGURE_TYPE] = "images\\MenuItems\\Menu_Choose_Figure.jpg";
	MenuItemImages[FIGURE_FILL_COLOR] = "images\\MenuItems\\Menu_Choose_Figure_Color.jpg";
	MenuItemImages[FIGURE_T_FILL_C] = "images\\MenuItems\\Menu_Choose_Figure_Choose_Color.jpg";
	MenuItemImages[RESTART] = "images\\MenuItems\\Menu_Restart.jpg";
	MenuItemImages[SWITICH_DRAW_MODE] = "images\\MenuItems\\Menu_Draw_Mode.jpg";





	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);


	pWind->SetPen(RED, UI.LineUnderTBWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight + UI.LineUnderTBWidth, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////



void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawTrig(Point P1, Point P2, Point P3, GfxInfo TrigGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TrigGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TrigGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TrigGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawCirc(Point P1, Point P2, GfxInfo CircGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (CircGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int radius;
	radius = sqrt(pow((P1.x - P2.x), 2) + pow((P1.y - P2.y), 2));

	pWind->DrawCircle(P1.x, P1.y, radius, style);

}

//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawSqr(Point P1, int side, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	Point P2, P3;
	P2.x = P1.x - (side / 2);
	P2.y = P1.y - (side / 2);
	P3.x = P1.x + (side / 2);
	P3.y = P1.y + (side / 2);
	pWind->DrawRectangle(P2.x, P2.y, P3.x, P3.y, style);

}
////////////////////////////////////////////////////////////////////////////////////
void Output::draw_Hex(Point H, GfxInfo HexInfo, bool selected, int length_Hex) const
{
	int x[6]; int y[6];
	x[0] = H.x + length_Hex;  y[0] = H.y;
	x[1] = H.x + 0.5 * length_Hex; y[1] = H.y + (length_Hex * (sqrt(3) / 2));
	x[2] = H.x - 0.5 * length_Hex; y[2] = H.y + (length_Hex * (sqrt(3) / 2));
	x[3] = H.x - length_Hex;  y[3] = H.y;
	x[5] = H.x + 0.5 * length_Hex; y[5] = H.y - (length_Hex * (sqrt(3) / 2));
	x[4] = H.x - 0.5 * length_Hex; y[4] = H.y - (length_Hex * (sqrt(3) / 2));
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = HexInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (HexInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexInfo.FillClr);
	}
	else
		style = FRAME;
	int* X = x;
	int* Y = y;
	pWind->DrawPolygon(X, Y, 6, style);
}


Output::~Output()
{
	delete pWind;
}

