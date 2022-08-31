#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	Point start;
public:
	CRectangle();
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool WithinMe(Point, Output* pOut);
	virtual string PrintInfo();
	virtual double GetArea();
	virtual double GetPerimeter();

	virtual string SaveInfo();
	virtual CFigure* CopyInfo(CFigure*);
	virtual Point LocateStart();
	virtual void CalDiff(Point, Point, CFigure*);
	virtual void SetPoints(Point, Point, Point);
	virtual Point* GetPoints();
};



#endif