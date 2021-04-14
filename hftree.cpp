#include "hftree.h"
#include <QVector>
#include <iostream>
#include <string>

using namespace std;

hfTreeNode * hfTree::createHfTree(hfTreeNode *root,string str)
{
    //string str = "let me check out";
    //构造存储有256个树节点的数组，用来存储每一个字符以及该字符的权重（出现的次数）
    QVector<hfTreeNode *> hft;
    //hfTreeNode hf_array[256];
    for(int i = 0;i < 256;++i)
    {
        hfTreeNode *node = new hfTreeNode;

        node->weight = 0;
        node->lchild = nullptr;
        node->rchild = nullptr;
        node->parent = nullptr;
        hft.push_back(node);
    }

    //统计输入字符的种类，以及每种种类出现的次数，并将其存入树结点之中
    for(unsigned int j = 0;j < str.length();++j)//以此迭代每个输入的字符
    {
        for(int h = 0;h < 256;++h)//如果该字符等于某个ASCII码值，就将该ASCII下的树权重++，意味着该字符出现的次数+1
        {
            if(str[j] == h)
            {
                hft.at(h)->weight++;
                hft.at(h)->tag = (char)h;
                //hf_array[h].weight++;
            }
        }
    }
    QVector<hfTreeNode *> fhft;
    QVector<hfTreeNode *>::iterator it;
    int tmp = 0;

    //重新整理权重值不为0的结点，放在一个新的vector:fhft中，并对其进行排序
    for(it = hft.begin();it != hft.end();++it)
    {
        if((*it)->weight != 0)//如果权重值不等于0
        {
            tmp = (*it)->weight;//tmp获得第一个权重值
            if(fhft.size() == 0)//如果此时vector为空
            {
                fhft.push_back((*it));//直接加入vector
            }else//如果vector里目前元素数量不为0，寻找第一个比tmp小的结点
                 //如果找到，就将tmp插到该位置；找不到，说明tmp是最小的一个，直接插入末尾；
            {
                for(int i = 0;i<fhft.size();++i)
                {
                    if( fhft.at(i)->weight < tmp )
                    {
                        fhft.insert(i,(*it));
                        break;
                    }
                    if(i == fhft.size()-1)
                    {
                        fhft.push_back((*it));
                        break;
                    }
                }
            }
        }
    }
    //打印排序结果
    for(it = fhft.begin();it != fhft.end();++it)
    {
        //cout << (*it)->weight << " ";
        finalHfTreeNode.push_back((*it));
    }
    //生成哈夫曼树
    while(fhft.size() != 1)//只要vector中的元素还不为1，就可以继续生成树
    {
        int size = fhft.size();//获得vector的大小
        hfTreeNode *s = fhft.at(size - 1);
        hfTreeNode *t = fhft.at(size - 2);//取出vector顶部最小的两个元素，且s<t

        hfTreeNode *p = new hfTreeNode;//分配新的结点空间
        p->weight = s->weight + t->weight;//新的根节点，权重为两结点之和

        p->lchild = s;//左孩子是小的那个
        p->rchild = t;//右孩子大

        s->parent = p;
        t->parent = p;
        fhft.pop_back();
        fhft.pop_back();//弹出这两个用完的元素
        //fhft.push_back(p);
        //排序并将新结点压入vector
        //QVector<hfTreeNode *>::iterator it;
        if(fhft.size() == 0)//如果此时vector为空
        {
            fhft.push_back(p);//直接加入vector
        }else//如果vector里目前元素数量不为0，寻找第一个比tmp小的结点
             //如果找到，就将tmp插到该位置；找不到，说明tmp是最小的一个，直接插入末尾；
        {
            for(int i = 0;i<fhft.size();++i)
            {
                if( fhft.at(i)->weight < p->weight )
                {
                    fhft.insert(i,p);
                    break;
                }
                if(i == fhft.size()-1)
                {
                    fhft.push_back(p);
                    break;
                }
            }
        }

        //重复以上操作，直至vector剩余一个元素
//        for(it = fhft.begin();it != fhft.end();++it)
//        {
//            cout << (*it)->weight << " ";
//        }
//        cout << endl;
    }
/*整个算法执行的结果，最后剩余一个结点28，该结点也是根结点
2 1 1 1 1
2 1 1 2
2 1 3
2 4
6
*/
    //剩余的这个元素即为根，赋值给Huffman Tree的根
    root = fhft.at(0);
    //返回这个根结点
    return root;
}
void hfTree::preOrderHfTree(hfTreeNode **root,string s)
{
    if((*root))
    {
//        cout << "---------------------------------------------" << endl;
//        cout << "now = " <<(*root) << endl;
//        cout << "parent = " <<(*root)->parent << endl;
//        cout << "lchild = " <<(*root)->lchild << endl;
//        cout << "rchild = " <<(*root)->rchild << endl;
        //先序遍历二叉树
        if((*root)->parent == nullptr)
        {
            (*root)->hfcode = "";
//            cout << "weight = " << (*root)->weight << " ";
//            cout << "hfcode = " <<(*root)->hfcode << " " << endl;
        }
        else
        {
            //当前编码等于其父编码加上偏移值
//            cout << "parent hfcode = " <<(*root)->parent->hfcode << endl;
            (*root)->hfcode = ((*root)->parent->hfcode) + s;
//            cout << "......................" << endl;
//            cout << "(*root)->hfcode = " << (*root)->hfcode << endl;
//            cout << "(*root)->parent->hfcode = " << (*root)->parent->hfcode << endl;
//            cout << "......................" << endl;
            //输出权重值和编码值
//            cout << (*root)->weight << " ";
//            cout << (*root)->hfcode << " " << endl;
        }
        preOrderHfTree(&(*root)->lchild,"0");
        preOrderHfTree(&(*root)->rchild,"1");
    }
}
void hfTree::getHfCode(hfTreeNode *root)
{
    string s = "";
    preOrderHfTree(&root,s);
}
void hfTree::enCode()
{
//    cout << " weight tag hfcode" << endl;
    QVector<hfTreeNode *>::iterator it;
    for(it = finalHfTreeNode.begin();it != finalHfTreeNode.end();++it)
    {
//        cout << (*it)->weight << " ";
//        cout << (*it)->tag << " ";
//        cout << (*it)->hfcode << " " << endl;
    }
}//解码
void hfTree::deCode(hfTreeNode *root,string str)
{
    hfTreeNode *p;
    p = root;
    if(root)
    {
        for(unsigned int i = 0;i < str.size();++i)
        {
            if(str[i] == '0')
            {
               p = p->lchild;
               if(!p->lchild)
               {
                   cout << p->tag <<"";
                   p = root;
               }
            }
            if(str[i] == '1')
            {
                p = p->rchild;
                if(!p->rchild)
                {
                    cout << p->tag <<"";
                    p = root;
                }
            }
        }
    }
    cout << endl;
}
