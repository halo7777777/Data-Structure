void Max()
{
    List L = Read();
    List pl;
    pl = L->next;
    int maxn = 0, i = 0, maxi = 0;
    while(pl)
    {
        i++;
        if(pl->data > maxn)
        {
            maxn = pl->data;
            maxi = i;
        }
        pl = pl->next;
    }
    delete L;
    printf("第%d个结点为最大值： %d\n----------------------------",maxi,maxn);
}
