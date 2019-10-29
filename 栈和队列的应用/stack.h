struct node{
    double num;        //操作数，中间过程可能存在浮点数
    char op;           //操作符
    bool flag;         //true表示操作数，false表示操作符
};

bool stk_empty(int &top)
{
    if(top == -1)
        return true;
    else
        return false;
}
void stk_push(node *stk, int &top, node x)
{
    if(top == MAXN-1)
    {
        return;
    }
    else
    {
        stk[++top]= x;

    }
}

node stk_pop(node *stk, int &top)
{
    node x;
    if(!stk_empty(top))
        x = stk[top--];
    return x;
}
node stk_top(node *stk, int &top)
{
    node x;
    if(!stk_empty(top))
        x = stk[top];
    return x;
}
