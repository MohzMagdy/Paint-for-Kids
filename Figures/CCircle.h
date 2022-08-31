#ifndef CCirc_H
#define CCirc_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point centerPoint;
	Point edgePoint;
	double radius;
	Point start;
public:
	CCircle();
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool WithinMe(Point, Output* pOut);
	virtual double GetArea();
	virtual double GetPerimeter();
	virtual string PrintInfo();
	virtual CFigure* CopyInfo(CFigure*);
	virtual Point LocateStart();
	virtual void CalDiff(Point, Point, CFigure*);
	virtual void SetPoints(Point, Point, Point);
	virtual Point* GetPoints();


	virtual string SaveInfo();

};

#endif