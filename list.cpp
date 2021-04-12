/*------------------------------------------------------------------------------------------------------------------------
 * 单向链表的定义与实现
 * 1.类的定义
 * 2.类方法
 * 3.相关算法思想
 * ---------------------------------------------------------------------------------------------------------------------*/
#include "list.h"

Node& Node::operator=(const Node&n)
{
    data = n.data;
    next = n.next;
    return *this;
}
List::List()//构造函数分配一个空指针
{
    cout << "welcome!" << endl;
    cout << "use default construtor!" << endl;
    head = new Node(0,nullptr);
    head->next = nullptr;
    if(head == nullptr)
    {
        cout << "allocated Failure" << endl;
    }
}
List::~List()
{
    delete head;
    cout << "use default un_construtor!" << endl;
    cout << "bye!" << endl;
}
List& List::operator=(const List&l)
{
    head = l.head;
    return *this;
}
void List::listPush(double d)
{
    //新节点
    Node *node = new Node(d,nullptr);
    node->next = this->head->next;//new Node
    this->head->next = node;
}
void List::printList()
{
    Node *p;
    p = this->head->next;
    if(p == nullptr)
    {
        cout << "the singal link is empty!" << endl;
    }
    cout << "***********************************************" << endl;
    for(int i = 0;i < getLinkLenth();++i)
    {
        if(p != nullptr)
        {
            cout << p->data << "->" ;
            p = p->next;
        }
    }
    cout << endl<< "***********************************************" << endl;
}
void List::listPushback(double d)
{
    //新节点
    Node *node = new Node(d,nullptr);

    Node *p;//巡回指针
    p = this->head;
    while(p->next != nullptr)
    {
        p = p->next;
    }//p到了链表的尾部
    node->next = p->next;
    p->next = node;
}
void List::deleteNode(const int i)
{
    //删除链表中的第 i 个结点
    Node *p = this->head;//巡回指针
    int j = 1;
    while(p && j < i)
    {
        p = p->next;
        ++j;
    }
    if((!p) || (j > i))
        return;
    if(p->next->next == nullptr)
    {
        p->next = nullptr;
    }else if(p->next->next != nullptr)
    {
        p->next = p->next->next;
    }
}
int List::getElem(const int i)
{
    Node *p ;
    p = this->head->next;//巡回指针
    int j = 1;
    while(p && j < i)
    {
        p = p->next;
        ++j;
    }
    return p->data;
}
void List::listInsert(const int i,double e)
{
    Node *node = new Node(e,nullptr);
    Node* p = this->head;//巡回指针
    int j = 0;
    while( p && j< i - 1)
    {
        p = p->next;
        ++j;
    }
    node->next = p->next;
    p->next = node;

}
void List::mergeList(List &la,List &lb)
{
    /*1.定义两个巡回指针p和q，分别指向链表la和lb的头指针，并不断向后取值
     *2.判断数据大小，小的加入lc，并不断循环
     *3.最后将剩余的一次性压入lc
    */
    Node *p,*q;
    p = la.head->next;
    q = lb.head->next;
    while(p && q)
    {
        if(p->data < q->data)
        {
            this->listPushback(p->data);
            p = p->next;
        }
        else{
            this->listPushback(q->data);
            q = q->next;
        }
    }
    while(p)
    {
        this->listPushback(p->data);
        p = p->next;
    }
    while(q)
    {
        this->listPushback(q->data);
        q = q->next;
    }
}
int List::getLinkLenth()
{
    Node *p;//巡回指针
    p = this->head;
    int j = 0;
    while( p->next != nullptr)
    {
        p = p->next;
        ++j;
    }
    return j;
}
