#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 100001
int TenToTwo(int a)
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
    printf("\n");
    return 0;
}
int Change(char str[])
{
    int result=0;
    int len;
    int i;
    len=strlen(str);
    for(i=0;i<len;i++)
    {
        result+=pow(2,len-i-1);
    }
    return result;
}
void Add()
{
    char stra[N];
    char strb[N];
    char ch;
    int a,b;
    int i;
    int lena,lenb;
    do
    {
        ch=getchar();
        if(ch!=' ')
            stra[i]=ch;
        else
            break;
        i++;
    }while(1);
    lena=i;
    stra[i]='\0';
    i=0;
    do{
        ch=getchar();
        if(ch!='\n')
            strb[i]=ch;
        else
            break;
        i++;
    }while(1);
    lenb=i;
    strb[i]='\0';
    //输出格式
    if(lena>=lenb)
    {
        printf("   ");
        printf("%s\n",stra);
        printf("+");
        for(i=0;i<2+lena-lenb;i++)
            printf(" ");
        printf("%s\n",strb);
        for(i=0;i<lena+3;i++)
            printf("-");
        printf("\n");
    }
    else
    {
        for(i=0;i<3+lenb-lena;i++)
            printf(" ");
        printf("%s\n",stra);
        printf("+  %s\n",strb);
        for(i=0;i<lenb+3;i++)
            printf("-");
        printf("\n");
    }
    a=Change(stra);
    b=Change(strb);
    TenToTwo(a+b);
}
int main()
{
    int T;
    int i;
    scanf("%d",&T);
    getchar();
    for(i=0;i<T;i++)
        Add();
    return 0;
}
