//测试数据abc  de g  f   //
#include<bits/stdc++.h>
#define MAXN 10000
using namespace std;
typedef struct Binode{
    char data;
    struct Binode* lchild, *rchild;
}Binode, *Bitree;
char a;         //输入的数据

void create(Bitree &T)       //1.建立二叉树
{
    a = getchar();
    if(a == ' ')
    {
        T = NULL;
    }
    else
    {
        T = new Binode;
        T->data = a;
        create(T->lchild);
        create(T->rchild);
    }
}
void intra(Bitree &T)     //2.中序遍历
{
    if(T == NULL)
        return;
    else
    {
        intra(T->lchild);
        printf("%c",T->data);
        intra(T->rchild);
    }
}
void pretra(Bitree &T)    //3.前序遍历
{
    if(T == NULL)
        return;
    else
    {
        printf("%c",T->data);
        pretra(T->lchild);
        pretra(T->rchild);
    }
}

void postra(Bitree &T)      //4.后序遍历
{
    if(T == NULL)
        return;
    else
    {
        postra(T->lchild);
        postra(T->rchild);
        printf("%c",T->data);
    }
}
int height(Bitree &T)        //5.计算二叉树的深度
{
    if(T == NULL)
        return 0;
    else
        return max(height(T->lchild),height(T->rchild))+1;
}
int nodecount(Bitree &T)    //6.计算二叉树的结点个数
{
    if(T == NULL)
        return 0;
    else
        return nodecount(T->lchild)+nodecount(T->rchild)+1;
}
int leafcount(Bitree &T)    //7.计算叶结点的个数
{
    if(T == NULL)
        return 0;
    if(T->lchild == NULL && T->rchild == NULL)
        return 1;
    else
        return leafcount(T->lchild) + leafcount(T->rchild);

}
int count1(Bitree &T)    //8.计算度为1的结点个数
{
    if(T == NULL)
        return 0;
    else if(T->lchild && T->rchild == NULL)
            return count1(T->lchild) + 1;
    else if(T->lchild == NULL && T->rchild)
            return count1(T->rchild) + 1;
    else
        return count1(T->lchild) + count1(T->rchild);
}

stack<char> path;           //用于存路径的栈
stack<char> temp;           //输出路径时的临时栈
void mypath(Bitree &T)      //9.输出二叉树中从每个叶子结点到根结点的路径
{
    if(T == NULL)
        return;
    path.push(T->data);
    if(T->lchild == NULL && T->rchild == NULL)
    {
        temp = path;
        while(!temp.empty())
        {
            printf("%c",temp.top());
            temp.pop();
        }
        printf("\n");
        return;
    }
    mypath(T->lchild);
    if(T->lchild)
        path.pop();
    mypath(T->rchild);
    if(T->rchild)
        path.pop();
}

Bitree tmp;              //用于交换子树的临时指针
void exchange(Bitree &T)       //10.交换二叉树每个结点的左孩子和右孩子
{
    if(T == NULL)
        return;
    else
    {
        exchange(T->lchild);
        exchange(T->rchild);
        tmp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = tmp;
    }
}
void dbltra(Bitree &T)           //11.双序遍历
{
    if(T == NULL)
        return;
    else
    {
        printf("%c",T->data);
        dbltra(T->lchild);
        printf("%c",T->data);
        dbltra(T->rchild);
    }
}
int main()
{
    Bitree T = NULL;
    printf("输入树的数值\n");
    create(T);

    printf("\n\n中序遍历\n");
    intra(T);

    printf("\n\n前序遍历\n");
    pretra(T);

    printf("\n\n后序遍历\n");
    postra(T);

    printf("\n\n树的深度 = %d ",height(T));

    printf("\n\n结点的个数 = %d",nodecount(T));

    printf("\n\n叶结点的个数 = %d",leafcount(T));

    printf("\n\n度为1的结点个数 = %d",count1(T));

    printf("\n\n每个叶子结点到根结点的路径:\n");
    mypath(T);

    printf("\n\n交换每个结点的左孩子和右孩子\n");
    printf("交换前中序遍历：");
    intra(T);
    printf("\n");
    exchange(T);
    printf("交换后中序遍历：");
    intra(T);

    printf("\n\n双序遍历为 ");
    dbltra(T);

    return 0;
}
