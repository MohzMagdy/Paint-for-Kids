#include "CFigure.h"

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


