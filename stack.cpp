/*--------------------------------------------------------------------------------------------------------------
 * This is all about the stack！
 * It contains:
 * 1.Class definition of stack;
 * 2.All the meaningful API that you will use;
 *
 *
 * -----------------------------------------------------------------------------------------------------------*/
#include "stack.h"
using std::cout;
using std::endl;
stack::stack()
{
    cout << "s default constructor!" << endl;
}
stack::~stack()
{
    cout << "s default un_constructor!" << endl;
}
void stack::initStack()
{
    this->top = &st[0];
    this->base = &st[0];
}
void stack::stackPush(elemType e)
{
    if(this->getStackSize() == stackSize)//栈已满
    {
        this->base = new elemType[getStackSize() + 10];
        this->top = this->base + getStackSize();
    }
    *(top) = e;
    (top)++;
}
int stack::getStackSize()
{
    int j = 0;
    elemType *p;
    p = this->base;
    while(p!= this->top)
    {
        p ++;
        ++j;
    }
    return j;

}
void stack::printStack()
{
    elemType *p;
    p = this->top;
    while(p >= this->base)
    {
        cout << (*p)<< endl;
        p--;

    }
}
bool stack::stackEmpty()
{
    if(base == top)
        return true;
    else
        return false;
}
elemType stack::getTop()
{
    elemType *p = this->top;
    if(stackEmpty())
        return 0;
    return  *(--p);
}
elemType stack::getBottom()
{
    if(stackEmpty())
        return 0;
    return  *(this->base);
}
void stack::pop(elemType &e)
{
    if(!stackEmpty())
    {
        e = *(--top);
    }
}
