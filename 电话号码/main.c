#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct mask
{
    char re[8];
    int x;
};
int pew(int a, int b)
{
    int i;
    int result=1;
    for(i=0;i<b;i++)
    {
        result*=a;
    }
    return result;
}
int change(char ch)
{
    switch(ch)
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return ch;break;
    case 'A':
    case 'B':
    case 'C':
        return '2';break;
    case 'D':
    case 'E':
    case 'F':
        return '3';break;
    case 'G':
    case 'H':
    case 'I':
        return '4';break;
    case 'J':
    case 'K':
    case 'L':
        return '5';break;
    case 'M':
    case 'N':
    case 'O':
        return '6';break;
    case 'P':
    case 'R':
    case 'S':
        return '7';break;
    case 'T':
    case 'U':
    case 'V':
        return '8';break;
    case 'W':
    case 'X':
    case 'Y':
        return '9';break;
    case '-':return '-';break;
    default:return -1;break;
    }
}
int check(char ch[])
{
    int len=strlen(ch);
    int i;
    int m;
    if(len!=7)
        return 1;       //1表示是错误的输入
    else if(ch[0]!='3'&&ch[0]!='6')
        return 1;
    for(i=1;i<len;i++)
    {
        if(ch[i]==-1)
            return 1;
    }
    return 0;
}
void main()
{
    char a[250000];
    struct mask b[1500];
    char ch[21];
    char ch0[21];
    int i,j;
    int flag=0;
    int p;      //判断首位数字是3还是6，3为0，6为1
    int number;
    int count=0;
    int bits;
    int sets;   //判断在哪一个数组下标；
    memset(a,0,sizeof(a)/sizeof(char));
    memset(b,0,sizeof(struct mask));
    printf("Error:\n");
    while(gets(ch)!=NULL)
    {
        strcpy(ch0,ch);
        i=0;
        while(ch[i]!='\0')
        {
            ch[i]=change(ch[i]);
        }
        i=0;
        while(ch[i]!='\0')
        {
            if(ch[i]=='-')
                for(j=i;ch[j]!='\0';j++)
            {
                if(j>0&&ch[j-1]=='\0')
                    break;
                ch[j]=ch[j+1];
            }
            i++;
        }
        if(check(ch))
        {
            puts(ch0);
            flag=1;
            continue;
        }
        number=0;
        i=0;
        if(ch[0]=='3')
            p=0;
        else p=1;
        for(i=1,j=5;i<9;i++,j--)
        {
            if(i!=3)
            {
                ch[i]=change(ch[i]);
                number+=pew(10,j)*(ch[i]-'0');
            }
        }
        sets=number/8+12500*p;
        bits=number%8;
        if((a[sets]>>bits)%2)
        {
            count++;
            strcpy(b[count-1].re,ch);
            b[count-1].x++;
        }
        else
        {
            a[sets]+=pew(2,bits);
        }
    }
    if(!flag)
        printf("Not found.\n");
    printf("Duplication:\n");
    if(count==0)
        printf("Not found.\n");
    else{
        for(i=0;i<count;i++)
        {
            for(j=0;j<7;j++)
            {
                if(j==3)
                    printf("-");
                printf("%c",b[i].re[j]);
            }
            printf(" %d\n",b[i].x);
        }
    }
    printf("\n");
}
