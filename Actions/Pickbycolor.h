#pragma once
#include "..\Figures\CFigure.h"
#include "Action.h"

class Pickbycolor :
	public Action
{
	CFigure* Fig;
	int  no_colors, rand_fig_no, picked_color_no, wrgSel, rigSel;
	int clrs[7];
	Point P;
	color AssignColor(CFigure*);
	void PrntScore(int);
public:
	Pickbycolor(ApplicationManager*);
	~Pickbycolor();
	void ReadActionParameters();
	void Execute();

	virtual void Undo();
	virtual void Redo();
};
