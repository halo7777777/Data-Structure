#include<stdio.h>
#define MAXN 100000
int MaxSubseqSum4(int A[], int N)
{
	int ThisSum, MaxSum;
	int i;
	ThisSum = MaxSum = 0;
	for(i = 0; i < N; i++)
	{
		ThisSum += A[i];
		if(ThisSum > MaxSum)
		MaxSum = ThisSum;
	 
		else if(ThisSum < 0)
		ThisSum = 0;
	}
	return MaxSum;
}
int main()
{
	int i = 0, k = 0;
	int a[MAXN] = {0};
	scanf("%d",&k);
	for(i = 0; i < k; i++)
	{
		scanf("%d",&a[i]);
	}
	printf("%d", MaxSubseqSum4(a, k ));
	return 0;
} 
