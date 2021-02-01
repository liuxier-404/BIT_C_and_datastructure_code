#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char words[1000+10][20+1];
int main()
{
    int n;
    int i,j;
    int all=0;
    int lenth=0;
    int flag=0;
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        gets(words[i]);
        lenth=strlen(words[i]);
        if(lenth<11)
            continue;
        j=0;
        flag=0;
        while(j<i)
        {
            if(strcmp(words[i],words[j])==0)
            {
                flag=1;
                break;
            }
            j++;
        }
        if(flag)
            continue;
        all++;
    }
    printf("%d\n",all);
    return 0;
}
