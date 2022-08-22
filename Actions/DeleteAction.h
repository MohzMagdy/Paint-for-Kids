#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"

class DeleteAction : public Action
{
protected:
	Point v1;

public:

	DeleteAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};
