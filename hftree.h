#ifndef HFTREE_H
#define HFTREE_H
#include <iostream>
//typedef int ELEMTYPE;
using std::cout;
using std::endl;
class hfTreeNode
{
public:
    //默认构造函数
    hfTreeNode(){
        lchild = nullptr;
        rchild = nullptr;
    }
    //拷贝构造函数
    hfTreeNode(const hfTreeNode& t)
    {
        this->weight = t.weight;

        this->lchild = new hfTreeNode;
        this->lchild = t.lchild;

        this->rchild = new hfTreeNode;
        this->rchild = t.rchild;
    }
    //默认析构函数
    ~hfTreeNode(){
        //delete lchild;
        //delete rchild;

    }
    bool operator<(hfTreeNode& h){
        if(this->weight < h.weight)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator>(hfTreeNode& h){
        if(this->weight > h.weight)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator==(hfTreeNode& h){
        if(this->weight == h.weight)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator!=(hfTreeNode& h){
        if(this->weight != h.weight)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //拷贝赋值运算符
    hfTreeNode& operator=(hfTreeNode& t)
    {
        this->weight = t.weight;
        this->lchild = t.lchild;
        this->rchild = t.rchild;
        return *this;
    }

    int weight;//数据域,存储权重
    hfTreeNode *lchild;//左孩子指针域
    hfTreeNode *rchild;//右孩子指针域
};
class hfTree
{
public:
    hfTree(){

    }
    ~hfTree(){

    }

    hfTreeNode *createHfTree();


private:
    //void hfTreeInitialize();
};

#endif // HFTREE_H
