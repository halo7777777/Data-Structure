#include<bits/stdc++.h>
using namespace std;
typedef struct Lnode* PtrtoNode;
struct Lnode{
    int data;
    PtrtoNode next;
};
typedef PtrtoNode List;

List Read()               //创建并读入带头结点的链表
{
    List L = (List)new struct Lnode;
    List Ll = L->next;
    List pre = L;
    printf("Input the number: ");
    int n;
    scanf("%d",&n);
    printf("Input the array:\n");
    for(int i = 0; i < n; i++)
    {
        Ll = (List)new struct Lnode;
        while(scanf("%d",&(Ll->data)) != 1)
        {
            printf("Input ERROR");
            return 0;
        }
        pre->next = Ll;
        pre = Ll;
    }
    if(Ll != NULL)
        Ll->next = NULL;
    return L;
}
#include"MegeList.h"
#include"SetList.h"
#include"Max.h"
#include"Reverse.h"
int main()
{
    printf("有序链表合并（两个非递减序列）\n\n");
    MegeList();
    printf("\n\n链表取交集（元素递增）\n\n");
    SetList();
    printf("\n\n求最大结点\n\n");
    Max();
    printf("\n\n逆转链表\n\n");
    Reverse();
    return 0;
}


