//提高版，且用浮点数表示，除号/可以真确得出答案

#define MAXN 1000001
#include<cstring>
#include<iostream>
#include<cstdio>
#include"stack.h"
using namespace std;
char s[MAXN];       //存读入的表达式
node q[MAXN];int j = 0;   //存后缀表达式,j为个数
double snum[MAXN];     //存计算后缀表达式的过程的栈
int ntop = -1;

node stk[MAXN];    //定义结构体的栈
int top = -1;    //初始化栈顶指针

bool In(char c)
{
    switch(c)
    {
        case'+':return true;
        case'-':return true;
        case'*':return true;
        case'/':return true;
        case'(':return true;
        case')':return true;
        default:return false;
    }
}
char Precede(char t1, char t2)     //考虑先后顺序的运算符优先级判断
{
    char f;
    switch(t2)
    {
        case'+':
        case'-':if(t1 == '(')       //出栈时优先级最小
                   f = '<';
                else
                    f = '>';
                break;
        case'*':
        case'/':if(t1 == '+' || t1 == '-')
                    f = '<';
                else
                    f = '>';
                    break;
        case'(':f = '<';        //入栈时优先级最大
        case')':f = '<';
    }
    return f;
}
double Operate(double a, char theta, double b)   //除号可能无法除尽，用double存
{
    double c;
    switch(theta)
    {
        case'+':c = a+b;break;
        case'-':c = a-b;break;
        case'*':c = a*b;break;
        case'/':c = a/b;break;
    }
    return c;
}
void change()             //将中缀表达式转化为后缀表达式
{
    node temp;
    for(int i = 0; s[i] != '#'; i++)
    {
        if(!In(s[i]))
        {

            temp.flag = true;
            temp.num = s[i]-'0';
            for(;!In(s[++i]) ;)
            {
                temp.num = 10*temp.num + (s[i] - '0');
            }
            i--;
            q[j++] = temp;
        }
        else
        {
            temp.flag = false;
            temp.op = s[i];

            while(!stk_empty(top) && Precede(stk_top(stk,top).op,s[i]) == '>')
            {
                q[j++] = stk_top(stk,top);
                stk_pop(stk,top);
            }
            stk_push(stk,top,temp);
            if(stk_top(stk,top).op == ')')
            {
                while(stk_top(stk,top).op != '(')
                {
                    if(stk_top(stk,top).op != ')')        //不将')'输入后缀表达式
                        q[j++] = stk_top(stk,top);
                    stk_pop(stk,top);
                }
                stk_pop(stk,top);              //将'('pop出
            }
        }
    }
    while(!stk_empty(top))
    {
        q[j++] = stk_pop(stk,top);
        stk_pop(stk,top);
    }
}
double cal()           //计算后缀表达式
{
    for(int i = 0; i < j; i++)
    {
        if(q[i].flag)
            snum[++ntop] = q[i].num;
        else
        {
            snum[ntop-1] = Operate(snum[ntop-1],q[i].op,snum[ntop]);
            ntop--;
        }

    }
    return snum[ntop];
}
int main()
{
    memset(q,0,sizeof(q));
    memset(stk,0,sizeof(stk));
    memset(snum,0,sizeof(snum));
    printf("请输入算术表达式(过程中可以有浮点数)，并以#结束\n");
    for(int i = 0; scanf("%c",&s[i]) && s[i] != '#'; i++);
    change();
    printf("= %.2lf",cal());
}
