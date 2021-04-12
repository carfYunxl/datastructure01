/*1.双亲孩子表示法，构造一个树的类
**2.采用类模板的形式进行定义，树中存储的数据类型，在实例化时确定
**
*/
#ifndef TREE_H
#define TREE_H
#define MAX_TREE_SIZE 100
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
//树类
class tree
{
public:
    struct node
    {
        int child = 0;
        node *next;//指向下一个孩子的指针
    };//结点
    struct p_node
    {
        int p_node_data;                  //数据域
        int p_node_parent;               //指向父亲的下标
        node *first_child;                  //孩子链表头指针
    };
    tree();
    tree(int head);
    ~tree();

    //成员函数
    //1.增加一个孩子结点
    void addTreeNode(int index,int a);
    void getTreeNodeNum();
    void getTreeRootData();
    void printTree();
    void getParent(int a);
private:
    p_node nodes[MAX_TREE_SIZE];
    int root = 0; //根的位置
    int num = 1;  //结点数
};


#endif // TREE_H
