#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_SQUARE: return DRAW_SQUARE;
			case ITM_TRIANGLE: return DRAW_TRIANGLE;
			case ITM_HEXAGON: return DRAW_HEXAGON;
			case ITM_CIRCLE: return DRAW_CIRCLE;
			case SELECT: return TO_SELECT;
			case CHANGE_BORDER_COLOR: return TO_CHANGE_BORDER_COLOR;
			case CHANGE_FILLING_COLOR: return TO_CHANGE_FILLING_COLOR;
			case BLACK_COLOR: return TO_CHANGE_TO_BLACK;
			case YELLOW_COLOR: return TO_CHANGE_TO_YELLOW;
			case ORANGE_COLOR: return TO_CHANGE_TO_ORANGE;
			case RED_COLOR:return TO_CHANGE_TO_RED;
			case GREEN_COLOR: return TO_CHANGE_TO_GREEN;
			case BLUE_COLOR: return TO_CHANGE_TO_BLUE;
			case DELETE_FIGURE: return TO_DELETE_FIGURE;
			case CLEAR_ALL: return TO_CLEAR_ALL;
			case COPY: return TO_COPY;
			case CUT: return TO_CUT;
			case PASTE: return TO_PASTE;
			case SEND_BACK: return TO_SEND_BACK;
			case BRING_FRONT: return TO_BRING_FRONT;
			case SAVE_GRAPH: return TO_SAVE_GRAPH;
			case LOAD_GRAPH: return TO_LOAD_GRAPH;
			case SWITCH_PLAY_MODE: return TO_PLAY;
			case ITM_EXIT: return EXIT;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		if (UI.InterfaceMode == MODE_PLAY)
		{
			//[1] If user clicks on the Toolbar
			if (y >= 0 && y < UI.ToolBarHeight)
			{
				//Check whick Menu item was clicked
				//==> This assumes that menu items are lined up horizontally <==
				int ClickedItemOrder = (x / UI.MenuItemWidth);
				//Divide x coord of the point clicked by the menu item width (int division)
				//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

				switch (ClickedItemOrder)
				{
				case FIGURE_TYPE: return TO_CHOOSE_FIGURE_TYPE;
				case FIGURE_FILL_COLOR: return TO_CHOOSE_FILL_COLOR;
				case FIGURE_T_FILL_C: return TO_CHOOSE_FIGURE_TYPE_FILL_COLOR;
				case RESTART: return TO_RESTART;
				case SWITICH_DRAW_MODE: return TO_DRAW;
					//TODO: Add more items names here
				default: return EMPTY;	//A click on empty place in desgin toolbar
				}
			}

			//[2] User clicks on the drawing area
			if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
			{
				return PLAYING_AREA;
			}

			//[3] User clicks on the status bar
			return STATUS;
		}
	}

}
/////////////////////////////////

Input::~Input()
{
}
