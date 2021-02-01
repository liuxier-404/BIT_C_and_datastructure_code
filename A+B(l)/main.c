#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100001
int Ten(char str[])
{
    int result=0;
    int lens;
    int i;
    lens=strlen(str);
    for(i=0;i<lens;i++)
    {
        result+=pow(2,lens-i-1);
    }
    return result;
}
void Change(int a)
{
    int b,k,i;
    int remainder[30];
    //定义了一个remainder数组，用来收集短除法除得的余数，栈倒序输出。
    k=0;
    while(a!=0){
        b=a/2;
        k++;
        remainder[k]=a-b*2;
        a=a/2;
    };
    for (i=k;i>=1;i--){
        printf("%d",remainder[i]);
    }
}
void Add()
{
    char stra[N];
    char strb[N];
    char add[N];
    int lena;
    int lenb;
    int a,b;
    int i=0;
    int j;
    int count;
    int flag;
    int max=0;
    char ch;
    do
    {
        ch=getchar();
        if(ch!=' ')
            stra[i]=ch;
        else
            break;
        i++;
    }while(1);
    stra[i+1]='\0';
    lena=i;
    i=0;
    do
    {
        ch=getchar();
        if(ch!='\n')
            strb[i]=ch;
        else
            break;
        i++;
    }while(1);
    strb[i+1]='\0';
    lenb=i;
    if(lena>=lenb)
        printf("   ");
    else
        for(i=0;i<lenb-lena;i++)
    {
        printf(" ");
    }
    printf("%s\n",stra);
    printf("+");
    if(lena>=lenb)
    for(i=0;i<lena-lenb+2;i++)
    {
        printf(" ");
    }
    printf("%s\n",strb);
    if(lena>lenb)
        max=lena;
    else
        max=lenb;
    for(i=0;i<max+3;i++)
        printf("-");
    printf("\n");
    a=Ten(stra);
    b=Ten(strb);
    printf("  ");
    Change(a+b);
    //转化为十进制计算结果

    /*for(i=lena-1,j=lenb-1,count=0;i>=0&&j>=0;i--,j--,count++)
    {
        flag=0;
        switch(stra[i]+strb[j])
        {
        case ('0'+'0'):
            {
                if(flag)
                    add[count]='1';
                else
                    add[count]='0';
                flag=0;
            };break;
        case ('0'+'1'):
            {
                if(flag)
                {
                    add[count]='0'
                    flag=1;
                }
                else
                {
                    add[count]='1';
                    flag=0;
                }
            };break;
        case ('1'+'1'):
            {
                if(flag)
                    add[count]='1';
                else
                    add[count]='0';
                flag=1;
            };break;
            default:break;
        }
    }*/

}
int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    int i;
    for(i=0;i<T;i++)
    {
            Add();
    }
    return 0;
}
