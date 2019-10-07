#include<cstdio>
#define MaxSize 100000
int main()
{
    int K = 0;
    int a[MaxSize] =  {0};
    int ThisSum = 0;
    int MaxSum = 0;
    scanf("%d",&K);
    for(int i = 0; i < K; i++)
    {
        scanf("%d",&a[i]);
        ThisSum += a[i];
        if(ThisSum < 0)
            ThisSum = 0;
        if(ThisSum > MaxSum)
            MaxSum = ThisSum;
    }
    printf("%d",MaxSum);
    return 0;
}
