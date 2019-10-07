//函数
List Merge(List L1, List L2)
{
    List a = L1->Next;
    List b = L2->Next;
    List L = (List)malloc(sizeof(struct Node));
    List tmp = L;
    for( ; a && b ; )
    {
        if(a->Data >= b->Data)
        {
            tmp->Next = b;
            b = b->Next;
        }
        else
        {
            tmp->Next = a;
            a = a->Next;
        }
        tmp = tmp->Next;
    }
    if(a) tmp->Next = a;
    if(b) tmp->Next = b;
    L1->Next = NULL;     //注意输出时L1和L2是有头结点的链表
    L2->Next = NULL;
    return L;
}
