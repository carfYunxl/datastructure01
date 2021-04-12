/*-------------------------------------------------------------------------------------------------------------
 * Normal tree operation!
 * 1.Class definition about the tree;
 * 2.Some useful functions!
 *-----------------------------------------------------------------------------------------------------------*/
#include "tree.h"
//孩子结点类默认构造函数
tree::tree()
{
   cout << " default constractor! " << endl;
   //创建根节点，且没有孩子结点
   nodes->first_child = nullptr;
   nodes->p_node_data = 10;
   nodes->p_node_parent = -1;
}
tree::tree(int head)
{
   cout << " new constractor! " << endl;
   //创建根节点，且没有孩子结点
   nodes->first_child  = nullptr;
   nodes->p_node_data = head;
   nodes->p_node_parent = -1;
}
tree::~tree()
{
    cout << " de_constractor! " << endl;
}
void tree::addTreeNode(int index,int a)
{
/*
*添加新节点，若在已知的根上创建子节点
*若把子结点作为根，继续添加子结点，则根加1，即表项加1
*/
    cout << "********************************************************" << endl;
    if((index >= 0) | (index <= root))
    {
        num++;
        //分配新结点空间
        node *newNode = new node;
        //结点初始化
        newNode -> child = num - 1;
        newNode->next = nullptr;
        cout << "111111   " << newNode << endl;

        //子结点连接到根结点
        node *p;
        p = nodes[index].first_child;
        cout << "0000000   " << p << endl;
        if(p == nullptr)
        {
            nodes[index].first_child = newNode;
        }
        else
        {
            //头插法
            newNode->next = p->next;
            p->next = newNode;
        }
        nodes[num - 1].p_node_data = a;
        nodes[num - 1].p_node_parent = index;
        nodes[num - 1].first_child = nullptr;
        root ++;
    }
    cout << "********************************************************" << endl;

}
void tree::getTreeNodeNum()
{
    cout << "Now tree node num = " << this->num << endl;
}
void tree::getTreeRootData()
{
    int e = nodes[root].p_node_data;
    cout << "Now tree root data = " << e << endl;
}
void tree::printTree()
{
    cout << "********************************************************" << endl;
    cout << "num = " << num << endl;
    for(int i = 0;i < num;++i)
    {
        cout << nodes[i].p_node_data << endl;
    }
    cout << "********************************************************" << endl;
}
void tree::getParent(int a)
{
    int index,k;
    for(int i = 0;i < num;++i)
    {
        if(nodes[i].p_node_data  == a)
        {
            index = i;
        }
    }
    k = nodes[index].p_node_parent;
    if(k == -1)
    {
       cout << "the"
               " node of " << a << " is root!" <<endl;
    }
    else {
        int data = nodes[k].p_node_data;
        cout << "the parent of " << a << " is:" << data << endl;
    }
}
