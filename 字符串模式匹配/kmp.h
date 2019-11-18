int next[100000] = {0};

//获取模式串的next数组
void getnext(char s[], int len)
{
    memset(next,0,sizeof(next));
    int j = -1;
    next[0] = -1;
    for(int i = 1; i < len; i++)
    {
        while(j != -1 && s[i] != s[j+1])
        {
            j = next[j];
        }
        if(s[i] == s[j+1])
        {
            j++;
        }
        next[i] = j;
    }
}

bool KMP(char text[], char pattern[])
{
    int n = strlen(text), m = strlen(pattern);
    char tmp[100000];
    strcpy(tmp,pattern);
    strcat(pattern,tmp);

    for(int k = 0; k < m; k++)   //匹配串的开头位置k
    {
        pattern += 1;          //匹配串从下一个开始
        getnext(pattern, 2*m-k);   //不同字符串next数组不同
        int j = -1;
        for(int i = 0; i < n; i++)
        {
            while(j != -1 && text[i] != pattern[j+1])
            {
                j = next[j];
            }
            if(text[i] == pattern[j+1])
            {
                j++;
            }
            if(j == m-1)
                return true;
        }
    }
    return false;
}
