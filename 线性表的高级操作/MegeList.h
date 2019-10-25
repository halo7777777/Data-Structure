void MegeList()
{
    List La = Read();
    List Lb = Read();
    List pa, pb, L, pl, q;
    L = La;
    pa = La->next;
    pb = Lb->next;
    L->next = NULL;
    while(pa || pb)
    {
        if(!pa)
        {
            q = pb;
            pb = pb->next;
        }
        else if(!pb)
        {
            q = pa;
            pa = pa->next;
        }
        else if(pa->data < pb->data)
        {
            q = pa;
            pa = pa->next;
        }
        else
        {
            q = pb;
            pb = pb->next;
        }
        q->next = L->next;
        L->next = q;
    }
    delete Lb;

    pl = L->next;
    printf("Result:\n");
    while(pl)
    {
        printf("%d ",pl->data);
        pl = pl->next;
    }
    printf("\n----------------------------");
    delete La;

}

