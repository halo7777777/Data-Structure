#include<bits/stdc++.h>
using namespace std;
#include"kmp.h"
#include"bf.h"
int main()
{
    int n;
    char pattern[100000];
    char text[100000];
    freopen("in.txt","r",stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {

        cin >> pattern >> text;
        cout << pattern << "\t  "<<text;

        if(bf(text,pattern))
        //if(KMP(text,pattern))
            printf("\tYES\n");
        else
            printf("\tNO\n");
    }
    return 0;
}
