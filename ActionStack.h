#pragma once

#include "DEFS.h";

template<typename Element>
class ActionStack
{
private:
	static const int size = 100;
	Element stack[size];
	int index = 0;

public:
	ActionStack();
	void push(Element);
	Element pop();
	void clear();
	bool isFull();
	bool isEmpty();
};

template<typename Element>
ActionStack<Element>::ActionStack()
{
	clear();
}

template<typename Element>
void ActionStack<Element>::push(Element act)
{
	if (isFull())
	{
		for (int i = 0; i < size - 1; i++)
			stack[i] = stack[i + 1];
		stack[size - 1] = act;
	}
	else
	{
		stack[index++] = act;
	}
}

template<typename Element>
Element ActionStack<Element>::pop()
{
	if (isEmpty())
		return stack[0];
	else
		return stack[--index];
}

template<typename Element>
void ActionStack<Element>::clear()
{
	index = 0;
}

template<typename Element>
bool ActionStack<Element>::isFull()
{
	if (index == size)
		return true;
	else
		return false;
}

template<typename Element>
bool ActionStack<Element>::isEmpty()
{
	if (index == 0)
		return true;
	else
		return false;
}