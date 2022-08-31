#include "CFigure.h"
#include <string>

CFigure::CFigure()
{

}

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

int CFigure::SelectCounter = 0;

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr, bool style)
{	
	FigGfxInfo.isFilled = style;
	FigGfxInfo.FillClr = Fclr; 
}

void CFigure::ChngBorderWidth(int width)
{
	FigGfxInfo.BorderWdth = width;
}

double CFigure::Cal_Length(Point p1, Point p2)
{
	return pow((pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2)), 0.5);
}

int CFigure::GetSelectCounter()
{
	return SelectCounter;
}

void CFigure::UpdateSelectCounter()
{
	SelectCounter -= 1;
}

Point CFigure::Closer(Point p1, Point p2)
{
	Point start;
	if (p1.x < p2.x)
		start.x = p1.x;
	else
		start.x = p2.x;

	if (p1.y < p2.y)
		start.y = p1.y;
	else
		start.y = p2.y;

	return start;
}

GfxInfo CFigure::Get_Gfx()
{
	return FigGfxInfo;
}

void CFigure::ClearSelectCounter()
{
	SelectCounter = 0;
}

string CFigure::PointToString(Point p)
{
	return "(" + to_string(p.x) + "," + to_string(p.y) + ")";
}

Point CFigure::StringToPoint(string str)
{
	string num;
	int coord[2];
	for (int i = 1; i < size(str) - 1; i++)
	{
		if (str[i] == ',')
		{
			coord[0] = stoi(num);
			num = "";
		}
		else
		{
			num += str[i];
		}
	}
	coord[1] = stoi(num);

	Point point;
	point.x = coord[0];
	point.y = coord[1];

	return point;
}

string CFigure::ColorToString(color c)
{
	if (CompareColors(c, MyRed))
		return "RED";
	if (CompareColors(c, MyGreen))
		return "GREEN";
	if (CompareColors(c, MyBlue))
		return "BLUE";
	if (CompareColors(c, LIGHTGREY))
		return "LIGHTGREY";
	if (CompareColors(c, MyRed))
		return "MyRed";
	if (CompareColors(c, MyGreen))
		return "MyGreen";
	if (CompareColors(c, MyBlue))
		return "MyBlue";
}

color CFigure::StringToColor(string st)
{
	if (st == "RED")
		return MyRed;
	if (st == "GREEN")
		return MyGreen;
	if (st == "BLUE")
		return MyBlue;
	if (st == "LIGHTGREY")
		return LIGHTGREY;
	if (st == "MyRed")
		return MyRed;
	if (st == "MyGreen")
		return MyGreen;
	if (st == "MyBlue")
		return MyBlue;
}

bool CFigure::CompareColors(color c1, color c2)
{
	return c1.ucBlue == c2.ucBlue && c1.ucGreen == c2.ucGreen && c1.ucRed == c2.ucRed;
}

