#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T;
    char *p="fattyhappy";
    char *pa;
    int i,j;
    int len;
    char cp[10];
    int icount;
    int flag;
    int change;
    int dif[10];
    char ch[1000+10];
    int max,min;
    scanf("%d",&T);
    getchar();
    for(icount=0;icount<T;icount++)
    {
        scanf("%s",ch);
        len=strlen(ch);
        change=0;
        for(i=0;i<len-9;i++)
        {
            pa=p;
            flag=0;
            for(j=i;j<i+10;j++)
            {
                if(ch[j]!=*pa)
                {
                    flag++;
                    dif[flag-1]=j;
                    cp[flag-1]=*pa;

                }
                pa++;
                if(flag>2)
                    {change=0;break;}
            }
            pa=p;
            if(flag==0)
                {printf("%d %d\n",i+3,i+4);change=1;}
            else if(flag==1)
            {
                for(j=0;j<len;j++)
                {
                    if(ch[j]==cp[0]&&(j<i||j>i+9))
                    {
                        if(j<dif[0])
                        {
                            max=dif[0];
                            min=j;
                        }
                        else
                        {
                            max=j;
                            min=dif[0];
                        }
                        printf("%d %d\n",min+1,max+1);
                        change=1;
                        break;
                    }
                }
                if(j==len)
                    change=0;
            }
            else if(flag==2)
            {
                if(ch[dif[1]]==cp[0]&&ch[dif[0]]==cp[1])
                {printf("%d %d\n",dif[0]+1,dif[1]+1);
                change=1;
                break;
                }
                else
                    change=0;
            }
            if(change==1)
                break;
        }
        if(change==0)
                printf("-1\n");
    }
    return 0;
}
