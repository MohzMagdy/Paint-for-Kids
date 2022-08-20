#ifndef CLINE_H_INCLUDED
#define CLINE_H_INCLUDED

#include "CFigure.h"

class CLine : public CFigure
{
private:
	Point Point1;
	Point Point2;
public:
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool CLine::WithinMe(Point v)
};

#endif // CLINE_H_INCLUDED
