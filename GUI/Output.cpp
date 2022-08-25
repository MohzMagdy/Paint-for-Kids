#include "Output.h"
#include <cmath>

Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1300;
	UI.height = 700;
	UI.wx = 5;
	UI.wy =5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 80;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = WHITE;		//Messages color
	UI.BkGrndColor = LIGHTGREY;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = LIGHTSLATEGREY;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

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
	ClearToolBar();

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu,
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_PLAY] = "images\\MenuItems\\Menu_Play.jpg";
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\Menu_Circ.jpg";
	MenuItemImages[ITM_TRIA] = "images\\MenuItems\\Menu_Tria.jpg";
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\Menu_line.jpg";
	MenuItemImages[ITM_CLR] = "images\\MenuItems\\Menu_Color.png";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_Delete.jpg";
	MenuItemImages[ITM_FILL] = "images\\MenuItems\\Menu_Filling.jpg";
	MenuItemImages[ITM_BORDER] = "images\\MenuItems\\Menu_Border.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearToolBar() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}

void Output::CreateColorToolBar() const
{
	//Saving previous toolbar mode to return it after picking
	UI.PrevInterfaceMode = UI.InterfaceMode;
	UI.InterfaceMode = MODE_CLR;
	ClearToolBar();

	string MenuItemImages[DRAW_CLR_COUNT];
	MenuItemImages[CLR_RED] = "images\\ColorItems\\Color_Red.jpg";
	MenuItemImages[CLR_GREEN] = "images\\ColorItems\\Color_Green.jpg";
	MenuItemImages[CLR_BLUE] = "images\\ColorItems\\Color_Blue.jpg";
	MenuItemImages[CLR_NONE] = "images\\ColorItems\\Color_None.jpg";

	for (int i = 0; i < DRAW_CLR_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}

void Output::CreatePenToolBar() const
{
	//Saving previous toolbar mode to return it after picking
	UI.PrevInterfaceMode = UI.InterfaceMode;
	UI.InterfaceMode = MODE_PEN;
	ClearToolBar();

	string MenuItemImages[PEN_SIZE_COUNT];
	MenuItemImages[PEN_3PT] = "images\\PenItems\\Pen_3pt.jpg";
	MenuItemImages[PEN_5PT] = "images\\PenItems\\Pen_5pt.jpg";
	MenuItemImages[PEN_7PT] = "images\\PenItems\\Pen_7pt.jpg";
	MenuItemImages[PEN_10PT] = "images\\PenItems\\Pen_10pt.jpg";

	for (int i = 0; i < DRAW_CLR_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	ClearToolBar();

	//Play mode items
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[PLY_DRAW] = "images\\MenuItems\\Menu_Play.jpg";
	MenuItemImages[PLY_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drwawing color
{	return UI.DrawColor;	}

void Output::setCrntDrawColor(color DrawColor) //set current drawing color
{	UI.DrawColor = DrawColor;	}

//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

bool Output::getCrntStyle() const
{	return UI.Style;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

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

void Output::DrawCirc(Point center, Point edge, GfxInfo CircGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, CircGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (CircGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else
		style = FRAME;

	double radius = pow(pow(edge.x - center.x, 2) + pow(edge.y - center.y, 2), 0.5);

	pWind->DrawCircle(center.x, center.y, radius, style);
}

void Output::DrawTria(Point P1, Point P2, Point P3, GfxInfo TriaGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriaGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, TriaGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (TriaGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriaGfxInfo.FillClr);
	}
	else
		style = FRAME;

	//double radius = pow(pow(edge.x - center.x, 2) + pow(edge.y - center.y, 2), 0.5);

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}

void Output::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = LineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, LineGfxInfo.BorderWdth);	//Set Drawing color & width

	//drawstyle style;
	//if (LineGfxInfo.isFilled)
	//{
		//style = FILLED;
		//pWind->SetBrush(LineGfxInfo.FillClr);
	//}
	//else
		//style = FRAME;


	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y);
}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

