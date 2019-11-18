bool bf(char text[], char pattern[])
{
    int n = strlen(text), m = strlen(pattern);
    char tmp[100000];
    strcpy(tmp,pattern);
    strcat(pattern,tmp);
    for(int k = 0; k < m; k++)
    {
        pattern += 1;
        int i,j;
        for(i = 0; i < n; i++)
        {
            int tmp = i;
            for(j = 0; j < m; j++)
            {
                if(text[tmp] != pattern[j])
                    break;
                tmp++;
            }
            if(j >= m)
                return true;
        }
    }
    return false;
}
