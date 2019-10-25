void Reverse()
{
    List L = Read();
    List pl, lc, q;
    pl = L->next;
    lc = L;
    lc->next = NULL;
    while(pl)
    {
        q = pl;                   //记住pl的指向
        pl = pl->next;           //要先改pl的指向，再插入
        q ->next = lc->next;     //插入：改变之前的pl的指向
        lc->next = q;
    }
    List c = lc->next;
    printf("Result:\n");
    while(c)
    {
        printf("%d ",c->data);
        c = c->next;
    }
    printf("\n----------------------------");
}
