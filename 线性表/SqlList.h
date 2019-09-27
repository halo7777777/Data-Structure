
//线性表

typedef int Position;
typedef struct LNode * PtrToLNode; //创建指向结构体的指针
struct LNode{
    Student Data[MAXSIZE];
    Position length;
};
typedef PtrToLNode List;
List MakeEmpty()           //初始化
{
    List L = (List)new struct LNode;
    L->length = -1;
    return L;
}
int input(List L, int n)        //1.输入信息
{
    for(int i = 0; i < n; i++)
    {
        if(scanf("%s %s %d",L->Data[i].no, L->Data[i].name, &(L->Data[i].price)) != 3)
        {
            printf("Input ERROR\n");
            return ERROR;
        }
        L->length = i;
    }
    return true;
}
int output(List L)           //2.显示所有相关信息
{
    for(int i = 0; i <= L->length; i++)
        printf("%s %s %d\n",L->Data[i].no, L->Data[i].name, L->Data[i].price);
    return true;
}
int name_Find(List L, char * X)  //3.根据名字查找
{
    Position i = 0;
    for( ; i <= L->length && strcmp(L->Data[i].name, X) != 0; i++);
    if(i > L->length)
    {
        printf("no find\n");
        return ERROR;
    }
    else
    {
        printf("no:%s price:%d\n",L->Data[i].no, L->Data[i].price);
        return true;
    }
}
int position_Find(List L, int i)    //4.根据指定位置查找
{
    i = i-1;
    if(i >= 0 && i <= L->length)
    {
        printf("%s %s %d\n",L->Data[i].no, L->Data[i].name, L->Data[i].price);
        return true;
    }
    else
    {
        printf("no find\n");
        return ERROR;
    }
}
int Insert(List L, char * X1, char * X2, int X3, int i )  //5.插入
{
    Position j;
    if(L->length == MAXSIZE - 1)
    {
        printf("List filled\n");
        return false;
    }
    if(i<1 || i > L->length+2)
    {
        printf("Position illegal\n");
        return false;
    }
    for(j = L->length; j >= i-1; j--)
        L->Data[j+1] = L->Data[j];
    strcpy(L ->Data[i-1].no,X1);
    strcpy(L ->Data[i-1].name,X2);
    L ->Data[i-1].price = X3;
    L->length++;
    printf("OK\n");
    return true;
}
int Delete(List L, int i)         //6.删除
{
    Position j;
    if(i<1 || i > L->length+1)
    {
        printf("Position %d no find\n", i);
        return false;
    }
    for(j = i; j <= L->length; j++)
        L->Data[j-1] = L->Data[j];
    L->length--;
    printf("OK\n");
    return true;
}
int count_student(List L)           //统计个数
{
    return (L->length+1);
}
