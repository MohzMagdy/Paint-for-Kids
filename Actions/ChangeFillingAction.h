#pragma once
#include "Action.h"
class ChangeFillingAction :
    public Action
{
private:

public:
    ChangeFillingAction(ApplicationManager* pApp);

    virtual void ReadActionParameters();

    virtual void Execute();
};

