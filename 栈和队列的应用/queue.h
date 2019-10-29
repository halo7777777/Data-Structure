bool q_empty(my_queue &a)
{
    if(a.qfront == a.qrear)
        return true;
    else
        return false;
}
void q_pop(my_queue &a)
{
    if(q_empty(a))
        printf("队列空\n");
    else
        a.qfront++;
}
void q_push(my_queue &a, Person x)
{
    a.q[++a.qrear] = x;
}
Person q_front(my_queue &a)
{
    Person x;
    if(q_empty(a))
        printf("队列空\n");
    else
        x = a.q[a.qfront+1];
    return x;
}
