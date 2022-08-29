#ifndef CLINE_H_INCLUDED
#define CLINE_H_INCLUDED

#include "CFigure.h"

class CLine : public CFigure
{
private:
	
public:
	Point Point1;
	Point Point2;
	Point start;
	double length;
	CLine();
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool CLine::WithinMe(Point v, Output* pOut);
	virtual double GetArea();
	virtual double GetPerimeter();
	virtual string PrintInfo();
	virtual Point LocateStart();
	virtual Point* GetPoints();
	virtual CFigure* CopyInfo(CFigure*);
	virtual void CalDiff(Point, Point, CFigure*);
	virtual void SetPoints(Point, Point, Point);
};

#endif // CLINE_H_INCLUDED
