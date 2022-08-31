#pragma once
#include "Action.h"
class ChangeBorderAction :
    public Action
{
private:

public:
    ChangeBorderAction(ApplicationManager* pApp);

    virtual void ReadActionParameters();

    virtual void Execute();

    virtual void Undo();

    virtual void Redo();
};

