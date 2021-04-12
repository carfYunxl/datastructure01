#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

class Node
{
public:
    Node();
    Node(double dat,Node *nt = nullptr):data(dat),next(nt){}
    Node(double dat):data(dat){  }
    Node& operator=(const Node&n);
    double data;
    Node *next;
};

class List
{
public:
    //初始化链表
    List();
    //List(Node *he = nullptr):head(he){  }
    ~List();
    //
    List& operator=(const List&he);
    //获取当前链表长度
    Node* getHead(){return head;}

    //头插法创建List
    void listPush(double);

    //尾插法创建List
    void listPushback(double);
    //打印当前链表
    void printList();
    //删除链表中某个位置的节点
    void deleteNode(const int i);
    //取出某个结点的数据
    int getElem(const int);
    //在位置i插入一个结点
    void listInsert(const int i,double e);
    //合并两个链表
    void mergeList(List &la,List &lb);
    //获取当前链表的长度
    int getLinkLenth();
private:
    Node *head;
};


#endif // LIST_H
