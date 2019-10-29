#include<bits/stdc++.h>
#define MAXN 1000001
using namespace std;
typedef struct{
    char name[20];          //姓名
    char sex;                //性别
}Person;
Person s[MAXN];
int n;            //记录人数


typedef struct{
    Person q[MAXN];
    int qfront;
    int qrear;
}my_queue;
my_queue female, male;       //创建两个队列

#include"queue.h"


void readStream()        //c++文件流读入
{
    ifstream in;
    in.open("DancePartner.txt", ios::in);
    if(!in.is_open())
    {
        cout << "Open File Failed" << endl;
        return;
    }
    string strone;
    for(n = 0; getline(in, strone); n++)
    {
        stringstream ss;
        ss << strone;
        ss >> s[n].name >> s[n].sex;
    }
}
int main()
{
    female.qfront = -1;female.qrear = -1;
    male.qfront = -1;male.qrear = -1;
    string temp1, temp2;
    readStream();
    cout << "The dancing partners are:" << endl;
    for(int i = 0; i < n; i++)
    {
        if(s[i].sex == 'F')
        {
            q_push(female,s[i]);
        }
        else
        {
            q_push(male,s[i]);
        }
    }
    while(!q_empty(male) && !q_empty(female))
    {
        cout << q_front(female).name <<" "<< q_front(male).name << endl;
        q_pop(female);
        q_pop(male);
    }
    if(!q_empty(female))
    {
        cout << "The first man to get a partner is" << q_front(female).name << endl;
        q_pop(female);
    }
    if(!q_empty(male))
    {
        cout << "The first woman to get a partner is" << q_front(male).name << endl;
        q_pop(male);
    }
    return 0;
}
