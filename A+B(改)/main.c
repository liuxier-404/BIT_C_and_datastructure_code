#include <stdio.h>
#include <stdlib.h>
#define N 500000
int main()
{
    char stra[N],strb[N];
    char str[N];
    int T;
    int flag=0;
    int count=0;
    int len;
    int max;
    int i,j=0,k;
    char ch;
    int lena,lenb;
	scanf("%d", &T);
	getchar();
	for (i = 0; i < T; i++)
    {
        j=0;
        count=0;
        flag=0;
        do {
		ch = getchar();
		if (ch != ' ')
			stra[j] = ch;
		else
			break;
		j++;
	} while (1);
	lena = j;
	stra[j] = '\0';
	j = 0;
	do {
		ch = getchar();
		if (ch != '\n')
			strb[j] = ch;
		else
			break;
		j++;
	} while (1);
	lenb = j;
	strb[j] = '\0';
	if(lena>lenb)
        max=lena;
    else
        max=lenb;
	for(j=lena-1,k=lenb-1;(j>=0&&k>=0);j--,k--,count++)
        {
            ch=stra[j]+strb[k];
            switch(ch)
            {
            case ('0'+'0'):
                {
                    if(flag)
                        str[count]='1';
                    else
                        str[count]='0';
                    flag=0;
                };break;
            case ('0'+'1'):
                {
                    if(flag)
                    {
                        str[count]='0';
                        flag=1;
                    }
                    else
                    {
                        str[count]='1';
                        flag=0;
                    }
                };break;
            case ('1'+'1'):
                {
                    if(flag)
                        str[count]='1';
                    else
                        str[count]='0';
                    flag=1;
                };break;
            default :break;
            }
        }
        if(k>=0)
            {
                while(k>=0)
                {
                    ch=strb[k]+flag;
                    if(ch>'1')
                    {
                        flag=1;
                        str[count]='0';
                    }
                    else
                    {
                        flag=0;
                        str[count]=ch;
                    }
                    count++;
                    k--;
                }
            }
            if(j>=0)
            {
                while(j>=0)
                {
                    ch=stra[j]+flag;
                    if(ch>'1')
                    {
                        flag=1;
                        str[count]='0';
                    }
                    else
                    {
                        flag=0;
                        str[count]=ch;
                    }
                    count++;
                    j--;
                }
            }
        if(flag)
        {str[count]='1';count++;};
        str[count]='\0';
        len=count;
        for(j=0;j<len+2-lena;j++)
            printf(" ");
        printf("%s\n",stra);
        printf("+");
        for(j=0;j<len+1-lenb;j++)
            printf(" ");
        printf("%s\n",strb);
        for(j=0;j<len+2;j++)
            printf("-");
        printf("\n");
        for(j=0;j<2;j++)
            printf(" ");
        for(j=len-1;j>=0;j--)
            printf("%c",str[j]);
        printf("\n");
    }
    return 0;
}
