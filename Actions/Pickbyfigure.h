#pragma once
#include "..\Figures\CFigure.h"

#include "Action.h"
class Pickbyfigure :
	public Action
{
	CFigure* Fig;
	Point P;
	int  no_figs, rand_fig_no, picked_fig_no, wrgSel, rigSel;
	int figs[4];
	void PrntScore(int);

public:
	Pickbyfigure(ApplicationManager*);
	~Pickbyfigure();
	void ReadActionParameters();
	void Execute();

	virtual void Undo();
	virtual void Redo();
};