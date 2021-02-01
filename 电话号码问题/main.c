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
int cmp(const void* p1,const void* p2)
{
    return strcmp((*(struct mask*)p1).re,(*(struct mask*)p2).re);
}
short change(char ch)
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
        return ch-'0';break;
    case 'A':
    case 'B':
    case 'C':
        return 2;break;
    case 'D':
    case 'E':
    case 'F':
        return 3;break;
    case 'G':
    case 'H':
    case 'I':
        return 4;break;
    case 'J':
    case 'K':
    case 'L':
        return 5;break;
    case 'M':
    case 'N':
    case 'O':
        return 6;break;
    case 'P':
    case 'R':
    case 'S':
        return 7;break;
    case 'T':
    case 'U':
    case 'V':
        return 8;break;
    case 'W':
    case 'X':
    case 'Y':
        return 9;break;
    case '-':return '-';break;
    default:return -1;break;
    }
}
void main()
{
    char a[250001];
    struct mask b[1501];
    char ch[21];
    int i,j;
    short flag=0;
    short p;      //判断首位数字是3还是6，3为0，6为1
    int number=0;
    int num;
    short m;
    short count=0;
    short bits;
    int sets;   //判断在哪一个数组下标；
    memset(a,0,sizeof(a)/sizeof(char));
    memset(b,0,sizeof(struct mask));
    printf("Error:\n");
    while(gets(ch)!=NULL)
    {
        number=0;
        i=0;j=6;
        while(ch[i]!='\0')
        {
            m=change(ch[i]);
            i++;
            if(m==-1)
               break;
            else if(m=='-')
                continue;
            else
            {
                number+=pew(10,j)*m;
                j--;
            }
        }
        if(m==-1||j>0)
        {
            flag=1;
            puts(ch);
            continue;
        }
        m=number/1000000;
        if(m==3)
            p=0;
        else if(m==6)
            p=1;
        else
        {
            flag=1;
            puts(ch);
            continue;
        }
        num=number;
        for(i=6;i>=0;i--)
        {
            ch[i]=num%10+'0';
            num/=10;
        }
        ch[7]='\0';
        number%=1000000;
        i=0;
        sets=number/8+125000*p;
        bits=number%8;
        if((a[sets]>>bits)%2)
        {
            for(i=0;i<count;i++)
            {
                if(strcmp(b[i].re,ch)==0)
                {
                    b[i].x++;
                    break;
                }
            }
            if(i==count)
            {
                count++;
                strcpy(b[count-1].re,ch);
                b[count-1].x++;
            }
        }
        else
        {
            a[sets]+=pew(2,bits);
        }
    }
    if(!flag)
        printf("Not found.\n");
    printf("\n");
    printf("Duplication:\n");
    if(count==0)
        printf("Not found.\n");
    else{
        qsort(b,count,sizeof(b[0]),cmp);
        for(i=0;i<count;i++)
        {
            for(j=0;j<7;j++)
            {
                if(j==3)
                    printf("-");
                printf("%c",b[i].re[j]);
            }
            printf(" %d\n",b[i].x+1);
        }
    }
}
