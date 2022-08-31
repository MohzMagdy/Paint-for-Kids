#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_CLR,
	MODE_PEN,
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_PLAY,
	ITM_RECT,		//Recangle item in menu
	ITM_CIRC,		//Circle item in menu
	ITM_TRIA,      //Triangle item in menu
	ITM_LINE,
	ITM_SELECT,
	ITM_CLR,		//Color item
	ITM_FILL,
	ITM_BORDER,
	ITM_DELETE,
	ITM_COPY,
	ITM_CUT,
	ITM_PASTE,
	
	// ITM_Change_FClr,
	//TODO: Add more items names here

	

	ITM_SAVE,
	ITM_LOAD,

	ITM_UNDO,
	ITM_REDO,

	ITM_EXIT,		//Exit item
	
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum ColorMenuItem
{
	CLR_RED,
	CLR_GREEN,
	CLR_BLUE,
	CLR_NONE,

	DRAW_CLR_COUNT
};

enum PenMenuItem
{
	PEN_3PT,
	PEN_5PT,
	PEN_7PT,
	PEN_10PT,

	PEN_SIZE_COUNT
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	//TODO: Add more items names here
	PLY_DRAW,
	PLY_HIDE,
	PLY_COLOR,
	PLY_EXIT,


	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	GUI_MODE PrevInterfaceMode;
	
	int	width, height,	//Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	bool Style = false;
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif