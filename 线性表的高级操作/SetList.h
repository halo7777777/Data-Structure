void SetList()
{
    List La = Read();
    List Lb = Read();
    List pa, pb, pl, p;
    pa = La->next;
    pb = Lb->next;
    pl = La;
    while(pa && pb)
    {
        if(pa->data > pb->data)
        {
            pb = pb->next;
        }
        else if(pa->data < pb->data)
        {
            pa = pa->next;
        }
        else if(pa->data == pb->data)           //相等
        {
            pl->next = pa;
            pl = pa;
            pa = pa->next;
            pb = pb->next;
        }
    }
    pl->next = NULL;
    delete Lb;
    p = La->next;                      //一定要在此时在给出输出的指针，否则指向了pa的第一个数据
    printf("交集为: ");
    while(p)                           //打印
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n----------------------------");
    delete La;
}
