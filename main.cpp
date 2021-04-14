#include <QCoreApplication>
#include "list.h"
#include "stack.h"
#include "mat.h"
#include <iostream>
#include <windows.h>
#include "tree.h"
#include "bithrtree.h"
#include "hftree.h"
#include <QVector>
#include <algorithm>
#include <ctime>

void testFunc_1();
void testFunc_2();
void testFunc_3();
void testFunc_4();
void convert_10_to_();
bool checkKuoHao();
void MazePath();
void Mtest();
void sin_Integration(double t);
void controlPlatform();
void treeTest();
void testBiThrTree()
{
    biThrTree s;
    biThrNode *p = nullptr;
    biThrNode *T = nullptr;
    s.createThrTree(&p);
    s.inOrderThrTree(&T,p);
}

void testHfTree()
{
    string str = "this is my first time to learn huffman tree,"
                 "i think it is very interisting!";
    string str1 = "11000010001010000010010111000010011";

    cout << "the Huffman code you enter is : "<< endl << str1 << endl;
    hfTree s;
    hfTreeNode *root = nullptr;
    //创建哈夫曼树
    root = s.createHfTree(root,str);
    //创建哈夫曼编码
    s.getHfCode(root);
    //编码显示
    s.enCode();
    //解码
    cout << "what you want to say is :" << endl;
    s.deCode(root,str1);
    cout << endl;
}
void testt()
{
    //testHfTree();
    hfTreeNode node1,node2,node3;
    //调用拷贝构造函数
    node1.lchild = &node2;
    node1.rchild = &node3;

    hfTreeNode node4(node1);
}
using std::cin;
using std::cout;
using std::endl;

const static int num = 16;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc,argv);
    clock_t start_time,end_time;//计时开始
    start_time = clock();

    testHfTree();

    end_time = clock();//计时结束
    //输出运行时间
    cout << "function run time = " << 1000*(double)(end_time - start_time) /  CLOCKS_PER_SEC << "ms" << endl;
    cout << "system run time = " << 1000 * (double)clock() / CLOCKS_PER_SEC << "ms" << endl;
    return a.exec();
}

void testFunc_1()
{
    List l;
    cout << "please choose what you want to do:" << endl;
    cout << "1\tcreate a new List;" << endl;
    cout << "2\tDelete List node;" << endl;
    cout << "3\tInsert List node;" << endl;
    cout << "4\tget the list length;" << endl;
    cout << "5\tprint the list;" << endl;
    cout << "please enter the value of your choise:" << endl;
    cout << "-------------------------------------------------" << endl;

    int num;
    while(cin >> num)
    {
        switch(num)
        {
            case 1:
            {
                List l;
                int number;
                cout << "please enter the value of num:" << endl;
                cout << "Enter 10 back to the menu!" << endl;
                cout << "-------------------------------------------------" << endl;
                while(cin >> number)
                {
                    if(number == 10)
                    {
                        cout << "stop enter now!" << endl;
                        cout << "the single chain is created !" << endl;
                        cout << "enter the print choise number can print the chain !" << endl;
                        cout << endl;
                        cout << "5\tprint the list;" << endl;
                        cout << "-------------------------------------------------" << endl;
                        break;
                    }
                    //l.listPush(l,ch);
                    l.listPushback(number);
                    cout << "please enter the value of num:" << endl;
                    cout << "-------------------------------------------------" << endl;
                }
                break;
            }
            case 2:
            {
                int number;
                cout << "Please enter the index of the node you want to deleted:" << endl;
                cout << "Enter 10 back to the menu!" << endl;
                cout << "-------------------------------------------------" << endl;
                while(cin >> number)
                {
                    if(number == 10)
                    {
                        cout << "Please try other method:" << endl;
                        cout << "please choose what you want to do:" << endl;
                        cout << "1\tcreate a new List;" << endl;
                        cout << "2\tDelete List node;" << endl;
                        cout << "3\tList Insert node;" << endl;
                        cout << "4\tget the list length;" << endl;
                        cout << "5\tprint the list;" << endl;
                        cout << "please enter the value of your choise:" << endl;
                        cout << "-------------------------------------------------" << endl;
                        break;
                    }
                    if(number > l.getLinkLenth())
                    {
                        cout << "Index " << number << " out of range!"<<endl;
                        cout << "-------------------------------------------------" << endl;
                    }else{
                        cout << "Index of number" << number <<"is deleted! "<< endl;
                        cout << "-------------------------------------------------" << endl;
                        l.deleteNode(number);
                    }
                }
                break;
            }
            case 3:
            {
                cout << "Please enter the node location you want to insert: " << endl;
                cout << "Enter 10 back to the menu!" << endl;
                cout << "-------------------------------------------------" << endl;
                int number;
                while(cin >> number)
                {
                    if(number == 10)
                    {
                        cout << "Exit now!Please try other method:" << endl;
                        cout << "please choose what you want to do:" << endl;
                        cout << "1\tcreate a new List;" << endl;
                        cout << "2\tDelete List node;" << endl;
                        cout << "3\tList Insert node;" << endl;
                        cout << "4\tget the list length;" << endl;
                        cout << "5\tprint the list;" << endl;
                        cout << "please enter the value of your choise:" << endl;
                        cout << "-------------------------------------------------" << endl;
                        break;
                    }
                    if(number > l.getLinkLenth() || number < 0)
                    {
                        cout << "Index out of range!" << endl;
                        cout << "Input again!" << endl;

                    }else{
                        l.listInsert(number,double(number));
                        cout << "Insert success!" << endl;
                        cout << "Enter 10 back to the menu!" << endl;
                        cout << "-------------------------------------------------" << endl;
                        break;
                    }
                }
                break;
            }
            case 4:
            {
                cout << "-------------------------------------------------" << endl;
                cout << "the link length = " << l.getLinkLenth() << endl;
                cout << "-------------------------------------------------" << endl;
                cout << "1\tcreate a new List;" << endl;
                cout << "2\tDelete List node;" << endl;
                cout << "3\tList Insert node;" << endl;
                cout << "4\tget the list length;" << endl;
                cout << "5\tprint the list;" << endl;
                cout << "please enter the value of your choise:" << endl;
                cout << "-------------------------------------------------" << endl;
                break;
            }
            case 5:
            {
                cout << "the chain you created is:" << endl;
                cout << "-------------------------------------------------" << endl;
                l.printList();
                cout << endl;
                cout << "Please try other method:" << endl;
                cout << "please choose what you want to do:" << endl;
                cout << "1\tcreate a new List;" << endl;
                cout << "2\tDelete List node;" << endl;
                cout << "3\tList Insert node;" << endl;
                cout << "4\tget the list length;" << endl;
                cout << "5\tprint the list;" << endl;
                cout << "please enter the value of your choise:" << endl;
               cout << "-------------------------------------------------" << endl;
                break;
            }

            default:
            {
                cout << "enter a wrong number!" << endl;
                cout << "enter again!" << endl;
                cout <<  endl;
                cout << "1\tcreate a new List;" << endl;
                cout << "2\tDelete List node;" << endl;
                cout << "3\tList Insert node;" << endl;
                cout << "4\tget the list length;" << endl;
                cout << "5\tprint the list;" << endl;
                cout << "please enter the value of your choise:" << endl;
                cout << "-------------------------------------------------" << endl;
            }
        }
    }
}
void testFunc_2()//创建对象数组
{
    List lv[5];
    for(int i =0;i < 5;++i)
    {
        lv[i].listPushback(10);
        lv[i].listPushback(20);

        lv[i].listPushback(30);
        lv[i].listPushback(40);
        lv[i].listPushback(50);
        lv[i].listPushback(60);
        lv[i].printList();
    }


}
void testFunc_3()
{
    List la,lb;
    la.listPushback(12);
    la.listPushback(22);
    la.listPushback(32);
    la.listPushback(42);
    la.listPushback(52);
    la.listPushback(62);
    la.listPushback(72);

    lb.listPushback(15);
    lb.listPushback(25);
    lb.listPushback(35);
    lb.listPushback(45);
    lb.listPushback(55);
    lb.listPushback(65);
    lb.listPushback(75);

    la.printList();

    lb.printList();

    List lc;
    lc.mergeList(la,lb);
    lc.printList();

    cout <<la.getLinkLenth()<<"\t"<<lb.getLinkLenth()<<lc.getLinkLenth()<<endl;
}
void testFunc_4()
{
    stack s;
    s.initStack();
    s.stackPush(20);
    s.stackPush(30);
    s.stackPush(50);
    s.stackPush(70);
    s.printStack();
    cout <<s.getStackSize()<< endl;
    if(!s.stackEmpty())
    {
        cout << " Not empty stack!" << endl;
        cout << " Top" << s.getTop() << endl;
        cout << " Base" << s.getBottom() << endl;
    }
    elemType e;
    s.pop(e);
    s.printStack();
    cout << " e:" << e << endl;
}
void convert_10_to_()
{
    stack s;
    s.initStack();
    elemType a;
    int A;
    cout << "please enter the ten_x number:" << endl;
    while(cin >> A)
    {
        if(A == 0)
        {
            cout << "End!" << endl;
            break;
        }
        while(A)
        {
           s.stackPush(A % num);
           A = A / num;
        }
        cout << "the following eight_x num =  " ;
        while(!s.stackEmpty())
        {
            s.pop(a);
            cout << a ;
        }
        cout << endl ;
    }

}
bool checkKuoHao()
{
    char ch;
    stack s;
    s.initStack();
    while(cin >> ch)
    {
        char tmp = s.getTop();
        char c;
        if((ch == '(') || (ch == '[') || (ch == '{'))
        {
            s.stackPush(ch);
        }
        if((tmp == '(' && ch == ')') || ((tmp == '[' && ch == ']')) || (tmp == '{' && ch == '}'))
        {
            s.pop(c);
            cout << c << ch << endl;
            if(s.stackEmpty())
            {
                return true;
            }
        }
        cout << "bad input!" << endl;
        return false;

    }
    return 0;
}
void MazePath()
{
    //创建地图
    int array[10][10];
    for(int i = 0;i < 10;++i)
    {
        for(int j = 0;j < 10;++j)
        {
            array[i][j] = qrand() % 2;
            if(array[i][j] == 0)
            {
              cout << " ";
            }else{
              cout << "*";
            }
            if(j == 9)
            cout << endl;
        }
    }
    //
}
void Mtest()
{
    //六种置换矩阵
    Mat p1(1,0,0,
           0,1,0,
           0,0,1);//单位阵，不做行变换
    Mat p2(0,1,0,
           1,0,0,
           0,0,1);//互换1，2行
    Mat p3(0,0,1,
           0,1,0,
           1,0,0);//互换1，3行
    Mat p4(1,0,0,
           0,0,1,
           0,1,0);//互换2，3行
    Mat p5(0,0,1,
           1,0,0,

           0,1,0);//1，2，3行全换
    Mat p6(0,1,0,
           0,0,1,
           1,0,0);//1，2，3行全换
    //Mat m(1,2,3,4,2,2);
    Mat n(1,3,5,6,2,2);
    Mat q(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,4,4);
    q.M_print();
    n.M_print();
}
void sin_Integration(double t)
{
    const int n = 500000;
    double dx = t / n;
    double sum = 0;
    for(int i = 0;i < n;++i)
    {
        sum =  sum + dx * cos(i*dx);

    }
    if(sum < 0.0001)
        sum = 0;
    cout << "sinx Integration = " << sum << endl;
}
void controlPlatform()
{
    system("color 0E");
    //黑底白字，不加BACKGROUND_INTENSITY默认黑底，指定黑底颜色必须加BACKGROUND_INTENSITY
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << "hello" << endl;
    //黑底红字
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
    cout << "world" << endl;
    //黑底绿字
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    cout << "good" << endl;
    //黑底蓝字
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    cout << "day" << endl;
    //灰底黑字
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY | BACKGROUND_INTENSITY);
    cout << "study everyday" << endl;
    //白底黑字
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
    cout << "work hard" << endl;
    //白底红字
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED);
    cout << "step forward" << endl;
    //蓝底绿字
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | BACKGROUND_BLUE | FOREGROUND_GREEN);
    cout << "Yes" << endl;
    //MessageBoxA(NULL,"wonderful","new box!",MB_OK);
    //HDC
    sin_Integration(M_PI);
    //Sleep(2000);
    //system("cls");
}
void treeTest()
{
    tree t(20);
    tree s;
    t.addTreeNode(0,30);
    t.addTreeNode(0,40);
    t.addTreeNode(0,50);
    t.addTreeNode(1,60);
    t.addTreeNode(2,70);
    t.addTreeNode(2,80);
    t.addTreeNode(5,90);
    t.printTree();

    t.getParent(20);
    t.getParent(30);
    t.getParent(40);
    t.getParent(50);
    t.getParent(60);
    t.getParent(70);
    t.getParent(80);
    t.getParent(90);

    s = t;
    s.printTree();
    s.findChildren(40);
}
