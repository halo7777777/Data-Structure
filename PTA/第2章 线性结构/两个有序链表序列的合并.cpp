//����
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
    L1->Next = NULL;     //ע�����ʱL1��L2����ͷ��������
    L2->Next = NULL;
    return L;
}
