#ifndef STACK_H
#define STACK_H
#include <iostream>
typedef char elemType;
class stack
{
public:
    enum{stackSize = 30};
    stack();
    ~stack();

    void initStack();
    void stackPush(elemType);
    int getStackSize();
    void printStack();
    bool stackEmpty();
    elemType getTop();
    elemType getBottom();
    void pop(elemType &e);

private:
    elemType *top;
    elemType *base;
    elemType st[stackSize];
};


#endif // STACK_H
