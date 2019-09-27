
//链表

typedef struct LNode* PtrToLNode;
struct LNode{
    Student Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;        //表示结点的地址
typedef PtrToLNode List;
List MakeEmpty()                   //申请带有头指针
{
    List L = (List)new struct LNode;
    L->Next = NULL;
    return L;
}
int input(List L, int n)            //1.循环申请结点空间并输入数据
{  //尾插法申请的链表带有头结点
    Position tmp, pre;
    pre = L;
    for(int i = 0; i < n; i++)
    {
        tmp = (Position)new struct LNode;
        while(scanf("%s %s %d",tmp->Data.no,tmp->Data.name,&(tmp->Data.price)) != 3)
        {
            printf("Input ERROR\n");
            return ERROR;
        }
        pre->Next = tmp;
        pre = tmp;
    }
    if(tmp != NULL)
        tmp->Next = NULL;
    return true;
}
int output(List L)                 //2.输出数据
{
    Position tmp = L->Next;
    for(;tmp != NULL;)
    {
        printf("%s %s %d\n",tmp->Data.no, tmp->Data.name, tmp->Data.price);
        tmp = tmp->Next;
    }
    return true;
}
int name_Find(List L, char* X)      //3.按照姓名查找
{
    Position tmp = L->Next;
    while(tmp && strcmp(tmp->Data.name, X))
        tmp = tmp->Next;
    if(tmp)
    {
        printf("no: %s  price: %d\n",tmp->Data.no, tmp->Data.price);
        return true;
    }
    else
    {
        printf("no find\n");
        return false;
    }
}
int position_Find(List L, int i)     //4.按照位置查找
{
    Position tmp = L->Next;
    int cnt = 1;
    while(tmp && cnt < i)
    {
        tmp = tmp->Next;
        cnt++;
    }
    if((cnt == i) && tmp)
    {
        printf("%s %s %d\n",tmp->Data.no, tmp->Data.name, tmp->Data.price);
        return true;
    }
    else
    {
        printf("no find\n");
        return ERROR;
    }
}
int Insert(List L, char* X1, char* X2, int X3, int i)   //插入，有头结点
{
    Position tmp, pre;
    int cnt = 0;
    pre = L->Next;
    while(pre && cnt < i- 1)
    {
        pre = pre->Next;
        cnt++;
    }
    if(pre == NULL || cnt != i-1)
    {
        printf("ERROR\n");
        return false;
    }
    else
    {
        tmp = (Position)new struct LNode;
        strcpy(tmp->Data.no, X1);
        strcpy(tmp->Data.name, X2);
        tmp->Data.price = X3;
        tmp->Next = pre-> Next;
        pre->Next = tmp;
        return true;
    }
}
int Delete(List L, int i)       //删除,有头结点
{
    Position tmp, pre;
    int cnt = 0;
    pre = L->Next;
    while(pre && cnt < i - 1)
    {
        pre = pre->Next;
        cnt++;
    }
    if(pre == NULL || cnt != i-1 || pre->Next == NULL)
    {
        printf("ERROR\n");
        return false;
    }
    else
    {
        tmp = pre->Next;
        pre->Next = tmp->Next;
        free(tmp);
        return true;
    }
}
int count_student(List L)      //统计个数
{
    Position tmp = L->Next;
    int cnt = 0;
    while(tmp)
    {
        tmp = tmp->Next;
        cnt++;
    }
    return cnt;
}
