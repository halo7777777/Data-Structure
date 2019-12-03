#include<bits/stdc++.h>
#define MAXN 10000
using namespace std;

typedef struct Hnode{
    int weight;
    int parent, lch, rch;
}Hnode, *Htree;

char s[MAXN] = {0};        //存输入字符串的数组
int n[MAXN] = {0};        //统计字符信息的数组
int cnt = 0;              //统计哈夫曼树叶结点的个数
int nw[MAXN] = {0};            //用于存weight不为0的字母
void alphcount()               //1.字符信息统计
{
    int j = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        n[s[i]]++;
    }
    for(int i = 0; i < MAXN; i++)
    {
        if(n[i])
        {
            printf("%c : %d个\n",i,n[i]);
            nw[++j] = i;
            cnt++;
        }
    }
}
void select(Htree &HT, int n, int &s1, int &s2)
{
    int weight1, weight2;
    weight1 = weight2 = 10000;
    s1 = s2 = 0;
    for(int i = 1; i <= n; i++)
    {
        if(HT[i].parent == 0)
            if(weight1 > HT[i].weight)
            {
                s2 = s1;           //s2为其中第2小数
                weight2 = weight1;

                weight1 = HT[i].weight;
                s1 = i;         //s1为其中第1小数
            }
            else if(weight2 > HT[i].weight)
            {
                s2 = i;
                weight2 = HT[i].weight;
            }
    }
}

int q[MAXN];  //存各字母对应在Huffman树中的序号
void create(Htree &HT)         //2.建立哈夫曼树
{
    if(cnt <= 1)
        return;
    int m = 2*cnt - 1;
    HT = new Hnode[m+1];         //0号单元未用，HT[m]表示根节点
    for(int i = 1; i <= m; i++)
    {
        HT[i].lch = 0;
        HT[i].rch = 0;
        HT[i].parent = 0;
    }
    for(int i = 1; i <= cnt; i++)
    {
        HT[i].weight = n[nw[i]];
        q[nw[i]] = i;
    }
    for(int i = cnt+1; i <= m; i++)     //构造Huffman树
    {
        int s1, s2;
        select(HT,i-1,s1,s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lch = s1;
        HT[i].rch = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}

void CreatHuffmanCode(Htree &HT, char **&HC, int n)    //3.HuffmanCode
{//从叶子到根逆向求每个字符的HuffmanCode，存储在编码表HC中
    HC = new char *[n+1];        //分配n个字符编码的头指针矢量
    char *cd = new char[n];            //分配临时存放编码的动态数组空间
    cd[n-1] = '\0';
    for(int i = 1; i <= n; i++)
    {//逐个字符求HuffmanCode
        int start = n-1;
        int c = i;
        int f = HT[i].parent;
        while(f != 0)
        {//从叶子结点开始向上回溯，直到根结点
            start--;
            if(HT[f].lch == c)
                cd[start] = '0';
            else
                cd[start] = '1';
            c = f;
            f = HT[f].parent;
        }
        HC[i] = new char[n-start];         //为第i个字符编码分配空间
        strcpy(HC[i], &cd[start]);
    }
    delete cd;
}

void decode(Htree &HT,char *s)       //5.译码功能
{
    int k = 2*cnt-1;
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        if(s[i] == '0')
        {
            k = HT[k].lch;
        }
        else if(s[i] == '1')
        {
            k = HT[k].rch;
        }
        if(HT[k].lch == 0 && HT[k].rch == 0)
        {
            printf("%c",nw[k]);
            k = 2*cnt-1;
        }
    }
}

int main()
{
    freopen("SourceFile.txt","r",stdin);
    gets(s);
    alphcount();

    Htree HT = NULL;
    create(HT);
    printf("\nHuffman tree:\n");
    printf("\tweight\tparent\tlch\trch\n");
    for(int i = 1; i <= 2*cnt-1; i++)
    {
        printf("%c\t%-3d\t%-3d\t%-3d\t%-3d\n",nw[i],HT[i].weight,HT[i].parent,HT[i].lch,HT[i].rch);
    }

    char **HC = NULL;
    CreatHuffmanCode(HT, HC, cnt);
    printf("\nHuffman code:\n");
    for(int i = 1; i <= cnt; i++)
    {
        printf("%c   %s\n",nw[i],HC[i]);
    }

    char *result = new char[MAXN];
    char *temp = result;
    for(int i = 0; i < strlen(s); i++)
    {
        if(i == 0)
            strcpy(result,HC[q[s[i]]]);      //空字符串时须覆盖
        else
            strcat(result, HC[q[s[i]]]);
        result += strlen(HC[q[s[i]]]);
    }
    freopen("ResultFile.txt","w",stdout);    //输入到文件开启重定向
    printf("Huffman code:\n");
    cout << temp;

    freopen("CON","w",stdout);        //关闭重定向
    char *decode_s = new char[MAXN];
    decode_s = temp;
    printf("decode:\n");             //5.译码功能
    decode(HT,decode_s);

    return 0;
}
