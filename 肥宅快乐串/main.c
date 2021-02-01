#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *p="fattyhappy";
    char *pa=p;
    char cp;
    char ch[1000+10];
    int dif[10];
    int difnum;
    int i,j;
    int len;
    int icount;
    int flag;
    int change;
    int T;
    scanf("%d",&T);
    getchar();
    for(icount=0;icount<T;icount++)
    {
        flag=0;
        change=0;
        difnum=0;
        scanf("%s",ch);
        len = strlen(ch);
        for(i=0;i<len;i++)
        {
//第一种情况，开头的f还在
            if(ch[i]=='f'&&i<=len-10)
            {
                flag=0;
                for(j=i+1;j<i+10;j++)
                {
                    pa++;
                    if(ch[j]==*(pa))
                        ;
                    else
                        {
                            dif[flag]=j;
                            flag++;
                        }
                    if(flag>2)
                        break;
                }
                pa=p;
//完整的fattyhappy
                if(flag==0)
                {
                    change=1;
                    printf("3 4\n");
                    break;
                }
//少了两个字符的肥宅
                else if(flag==2)
                {
                    cp=ch[dif[0]];
                    ch[dif[0]]=ch[dif[1]];
                    ch[dif[1]]=cp;
                    for(j=i;j<i+10;j++,pa++)
                        if(ch[j]!=*pa)
                        {
                            change=0;
                            cp=ch[dif[0]];
                            ch[dif[0]]=ch[dif[1]];
                            ch[dif[1]]=cp;
                            break;
                        }
                    if(j==i+10)
                    {
                        change=1;
                        printf("%d %d\n",dif[0],dif[1]);
                    }
                    pa=p;
                }
//不快乐的肥宅
                else if(flag>2)
                {
                    change=0;
                }
//只有一个字符不同
                else if(flag==1)
                {
                    cp=ch[dif[0]];
                    for(j=0;j<len;j++)
                    {
                        if(ch[j]==cp&&(j<i||j>i+9))
                        {
                            change=1;
                            printf("%d %d\n",j,dif[0]);
                            break;
                        }
                    }
                    if(j==len)
                        change=0;
                }

            }
        if(change==1)
            break;
//第一个字符串不是f的情况
        //第二个字符是a
        if(ch[i]=='a'&&i>0&&ch[i-1]!='f'&&i<=len-9)
        {
            dif[0]=i-1;
            flag=1;
            pa++;
            for(j=i;j<i+9;j++)
            {
                if(ch[j]!=*(pa))
                    {
                        dif[flag]=j;
                        flag++;
                    }
                if(flag>2)
                    break;
                pa++;
            }
            pa=p;
            if(flag==1)
            {
                dif[0]=i-1;
                for(j=0;j<len;j++)
                if(ch[j]==ch[dif[0]]&&(j<i-1||j>i+8))
                {
                    dif[1]=j;
                    change=1;
                    printf("%d %d\n",dif[0],dif[1]);
                    break;
                }
                if(j==len)
                {
                    change=0;
                }
            }
            else if(flag==2)
            {
                printf("%d %d\n",dif[0],dif[1]);
            }
        }
        //第一二个字符都不相同
        if(ch[i]=='t'&&i>1&&ch[i-1]=='f'&&ch[i-2]=='a'&&j<len-9)
        {
            cp=ch[i-1];
            ch[i-1]=ch[i-2];
            ch[i-2]=cp;
            for(j=i-2;j<i+8;j++)
            {
                if(ch[j]!=*pa)
                {
                    change=0;
                    break;
                }
                pa++;
            }
            if(j==i+8)
            {
                change=1;
                printf("%d %d\n",i-2,i-1);
            }
        }
        }
        if(change==0)
            printf("-1\n");

    }
    return 0;
}
