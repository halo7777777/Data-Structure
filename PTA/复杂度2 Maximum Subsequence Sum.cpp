#include<cstdio>
#define MaxSize 100000
int main()
{
    int K = 0;
    int a[MaxSize] =  {0};
    int ThisSum = 0;
    int MaxSum = -1;            //避免负数和0的情况，无法改变First和Last
    int First, Last, l_First;
    int s_begin = 0;
    int s_minus = 1;     //判断全负数情况
    scanf("%d",&K);
    for(int i = 0; i < K; i++)
    {
        scanf("%d",&a[i]);
        if(a[i] >= 0)
            s_minus = 0;
        ThisSum += a[i];
        if(s_begin == 0)
        {
            s_begin = 1;
            First = a[i];
        }
        if(ThisSum > MaxSum)   //需要最小子列和，所以不能用>=号
        {
            MaxSum = ThisSum;
            Last = a[i];
            l_First = First;
        }
        if(ThisSum < 0)
        {
            ThisSum = 0;
            s_begin = 0;
        }
    }
    if(s_minus == 1)
    {
        l_First = a[0];
        Last = a[K-1];
        MaxSum = 0;
    }
    printf("%d %d %d",MaxSum,l_First,Last);
    return 0;
}
