//annotation encoding: UTF-8
#include<bits/stdc++.h>
#define MAXSIZE 1000000
#define ERROR -1     //将错误信息定义为-1
using namespace std;
typedef struct{
    char no[8];
    char name[20];
    int price;
}Student;
//#include "SqlList.h"
#include "LinkList.h"
int main()
{
    List L = MakeEmpty();
    int n;
    printf("Input number:");           //输入
    scanf("%d",&n);
    printf("Input information:\n");
    input(L, n);
    printf("Output information:\n");    //显示
    output(L);
    printf("Input name: ");          //根据姓名查找
    char name[20];
    scanf("%s", name);
    name_Find(L, name);
    printf("Input position: ");      //根据指定位置查找
    int i;
    scanf("%d",&i);
    position_Find(L,i);
    printf("Input information of insert:\n");    //插入
    char X1[8];
    char X2[20];
    int X3;
    scanf("%s %s %d",X1,X2,&X3);
    printf("Input the position of insert: ");
    int in_position;
    scanf("%d",&in_position);
    Insert(L,X1,X2,X3,in_position);
    printf("Input the position of delete: ");     //删除
    int del_position;
    scanf("%d",&del_position);
    Delete(L, del_position);
    printf("Output the number of student: ");     //统计学生个数
    int number = count_student(L);
    printf("%d\n",number);
    return 0;
}
