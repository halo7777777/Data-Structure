#include<bits/stdc++.h>
using namespace std;
#define MAXN 10001
int coe_1[MAXN] = {0};
int exp_1[MAXN] = {0};
int coe_2[MAXN] = {0};
int exp_2[MAXN] = {0};
int coe_prt[MAXN] = {0};
int exp_prt[MAXN] = {0};
int coe_sum[MAXN] = {0};
int exp_sum[MAXN] = {0};
int prt(int a, int b)
{
    return (a*b);
}
int sum(int a, int b)
{
    return a+b;
}
int main()
{
    int n, m;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d",&coe_1[i],&exp_1[i]);
    }
    scanf("%d",&m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d",&coe_2[i],&exp_2[i]);
    }
    int j = 0;
    for(j = 0; coe_1[j] && coe_2[j]; j++)
    {
        coe_prt[j] = prt(coe_1[j], coe_2[j]);
        exp_prt[j] = sum(exp_1[j], exp_2[j]);
    }
    for(; coe_1[j]; j++)
    {
        coe_prt[j] = coe_1[j];
        exp_prt[j] = exp_1[j];
    }
    for(; coe_2[j]; j++)
    {
        coe_prt[j] = coe_2[j];
        exp_prt[j] = exp_2[j];
    }
    int max_n = m > n? m : n;
    for(int i = 0; i < max_n; i++)
    {
        if(i == max_n)
            printf("%d %d\n", coe_prt[i], exp_prt[i]);
        else
            printf("%d %d ", coe_prt[i], exp_prt[i]);
    }
    return 0;
}
