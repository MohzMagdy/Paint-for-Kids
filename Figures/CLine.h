#ifndef CLINE_H_INCLUDED
#define CLINE_H_INCLUDED

#include "CFigure.h"

class CLine : public CFigure
{
private:
	Point Point1;
	Point Point2;
	double length;
public:
	CLine();
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool CLine::WithinMe(Point v, Output* pOut);
	virtual double GetArea();
	virtual double GetPerimeter();
	virtual string PrintInfo();

	virtual string SaveInfo();
	virtual CFigure* CopyInfo(CFigure*);
};

#endif // CLINE_H_INCLUDED
