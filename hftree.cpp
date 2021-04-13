#include "hftree.h"
#include <QVector>
#include <iostream>
#include <string>

using namespace std;

hfTreeNode * hfTree::createHfTree()
{
    string str = "let me check out the hftree!";
    //构造存储有256个树节点的数组，用来存储每一个字符以及该字符的权重（出现的次数）
    QVector<hfTreeNode *> hft;
    //hfTreeNode hf_array[256];
    for(int i = 0;i < 256;++i)
    {
        hfTreeNode *node = new hfTreeNode;

        node->weight = 0;
        node->lchild = nullptr;
        node->rchild = nullptr;

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
            }else if(fhft.size() == 1)//vector里目前只有一个，只需要比较一次
            {
                if(fhft.at(0)->weight < tmp)
                {
                    fhft.insert(0,(*it));
                }
                else
                {
                    fhft.push_back((*it));
                }
            }
            else{//如果

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
        cout << (*it)->weight << " ";
    }

    //生成哈夫曼树
    while(fhft.size() != 1)
    {
        int size = fhft.size();
        hfTreeNode *s = fhft.at(size - 1);
        hfTreeNode *t = fhft.at(size - 2);

        hfTreeNode *p = new hfTreeNode;
        p->weight = s->weight + t->weight;
        if(s->weight < t->weight)
        {
           p->lchild = s;
           p->rchild = t;
        }
        else
        {
            p->lchild = t;
            p->rchild = s;
        }
        fhft.pop_back();
        fhft.pop_back();
    }
    hfTreeNode *root = fhft.at(0);
    return root;
}
