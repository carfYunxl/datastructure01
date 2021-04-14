#ifndef HFTREE_H
#define HFTREE_H
#include <iostream>
#include <string>
#include <QVector>
//typedef int ELEMTYPE;
using namespace std;
class hfTreeNode
{
public:
    //默认构造函数
    hfTreeNode(){
        lchild = nullptr;
        rchild = nullptr;
        parent = nullptr;
        hfcode = "";

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
        delete lchild;
        delete rchild;

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
    hfTreeNode *parent;
    string hfcode;
    char tag;
};
class hfTree
{
public:
    hfTree(){
        //root = nullptr;
    }
    ~hfTree(){
    }

    hfTreeNode *createHfTree(hfTreeNode *p,string str);
    void preOrderHfTree(hfTreeNode **p,string s);
    void getHfCode(hfTreeNode *p);

    void enCode();//显示哈夫曼编码
    void deCode(hfTreeNode *root,


                string str);//解码
private:
    //void hfTreeInitialize();
    //hfTreeNode *root;
    QVector<hfTreeNode *> finalHfTreeNode;
};

#endif // HFTREE_H
