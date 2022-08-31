#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if(Key == 8 )	//BackSpace is pressed
			Label.resize(Label.size() -1 );
		else
			Label+= Key;
		pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	switch (UI.InterfaceMode)
	{
	case MODE_DRAW: //GUI in the DRAW mode
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
			case ITM_PLAY: return TO_PLAY;
			case ITM_RECT: return DRAW_RECT;
			case ITM_CIRC: return DRAW_CIRC;
			case ITM_TRIA: return DRAW_TRIA;
			case ITM_LINE: return DRAW_LINE;
			case ITM_SELECT: return SELECT;
			case ITM_DELETE: return DEL;
			case ITM_FILL: return CHNG_FILL_CLR;
			case ITM_CLR: return CHNG_DRAW_CLR;
			case ITM_BORDER: return CHNG_PEN_SIZE;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_COPY: return COPY;
			case ITM_PASTE: return PASTE;
			case ITM_CUT: return CUT;
			case ITM_UNDO: return UNDO;
			case ITM_REDO: return REDO;
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
		break;

	case MODE_PLAY: //GUI is in PLAY mode
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth);

			switch (ClickedItemOrder)
			{
			case PLY_DRAW: return TO_DRAW;
			case PLY_EXIT: return EXIT;

			default: return EMPTY;
			}
		}
		break;

	case MODE_CLR: //GUI is in COLOR switch mode
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case CLR_RED: return SET_CLR_RED;
			case CLR_GREEN: return SET_CLR_GREEN;
			case CLR_BLUE: return SET_CLR_BLUE;
			case CLR_NONE: return SET_CLR_NONE;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		break;

	case MODE_PEN: //GUI is in PEN switch mode
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case PEN_3PT: return SET_PEN_3PT;
			case PEN_5PT: return SET_PEN_5PT;
			case PEN_7PT: return SET_PEN_7PT;
			case PEN_10PT: return SET_PEN_10PT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		break;
	}

}
/////////////////////////////////

Input::~Input()
{
}
