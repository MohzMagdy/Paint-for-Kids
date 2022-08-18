#ifndef ADDLINEACTION_H_INCLUDED
#define ADDLINEACTION_H_INCLUDED

#include "Action.h"

class AddLineAction : public Action
{
private:
	Point P1, P2;  //Line endpoints
	GfxInfo LineGfxInfo;
public:
	AddLineAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

};

#endif // ADDLINEACTION_H_INCLUDED
