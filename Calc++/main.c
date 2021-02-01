#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 100000+10
#define W 1000000
#define JIN 6
long long result[200000+50];
int Sub(int m1[],int m2[],int len1,int len2)
{
    int *big;
    int *small;
    int bigger;
    int i;
    int count;
    int flag=-1;    //判断正负
    /*判断两个数据的大小*/
    if(len1>len2)
    {
        flag=1;
        bigger=len1;
        big=m1+len1;
        small=m2+len2;
    }
    else if(len1==len2)
    {
        i=0;
        bigger=len1;
           while(i<=len1)
           {
               if(m1[i]!=m2[i])
               {
                   flag=2;
                   break;
               }
               i++;
           }
           if(flag==2)
           {
               if(m1[i]>m2[i])
               {
                    big=m1+len1;
                    small=m2+len2;
                    flag=1;
               }
               else
               {
                   big=m2+len2;
                   small=m1+len1;
                   flag=-1;
               }
           }
           else
           {
               printf("0\n");
               return 0;
           }

    }
    else if(len1<len2)
    {
        bigger=len2;
        flag=-1;
        big=m2+len2;
        small=m1+len1;
    }
    /*计算两个数据的差,直到某一个数被运算完*/
    i=0;
    do
    {
        result[i]=*(big-i)-*(small-i);
        if(result[i]<0)
        {
            result[i]+=10;
            *(big-i-1)-=1;
        }
        i++;
    }while(i<=len1&&i<=len2);
    while(i<=bigger)
    {
        result[i]=*(big-i);
        if(result[i]<0)
        {
            result[i]+=10;
            *(big-i-1)-=1;
        }
        i++;
    }
    if(result[bigger]==0)
        bigger--;
    if(flag<0)
    {
        printf("-");
    }
    for(i=bigger;i>0;i--)
        if(result[i])
        break;
    bigger=i;
    for(i=bigger;i>0;i--)
    {
        printf("%lld",result[i]);
    }
    printf("\n");
    return 0;
}
//压位运算乘法，压6位
int Mul(int m1[],int m2[],int len1,int len2)
{
    int i,j;
    int count;
    int mid;
    int ten;
    long long number;
    //改变数组顺序
    for(i=0,j=len1-1;i<j;i++,j--)
    {
        mid=m1[i];
        m1[i]=m1[j];
        m1[j]=mid;
    }
    for(i=0,j=len2-1;i<j;i++,j--)
    {
        mid=m2[i];
        m2[i]=m2[j];
        m2[j]=mid;
    }
    //压位
    count=(len1-1)/JIN+1;
    for(i=0;i<count;i++)
    {
        ten=1;
        for(j=0;j<JIN;j++)
        {
            if(j==0)
                m1[i]=m1[i*JIN];
            else
            m1[i]+=m1[i*JIN+j]*(long long)ten;
            ten*=10;
        }
    }
    len1=count;//真实长度
    count=(len2-1)/JIN+1;
    for(i=0;i<count;i++)
    {
        ten=1;
        for(j=0;j<JIN;j++)
        {
            if(j==0)
                m2[i]=m2[i*JIN];
            else
            m2[i]+=m2[i*JIN+j]*(long long)ten;
            ten*=10;
        }
    }
    len2=count;//真实长度
    for(i=0;i<len1;i++)
        for(j=0;j<len2;j++)
    {
        result[i+j]+=(long long)m1[i]*(long long)m2[j];
    }
    mid=0;
    for(i=0;i<len1+len2;i++)
    {

        number=result[i]+mid;
        result[i]=number%W;
        mid=number/W;
    }
    //计算真实长度
    for(j=i;j>0;j--)
    {
        if(result[j]!=0)
           break;
    }
    len1=j+1;
    printf("%lld",result[len1-1]);
    for(i=len1-2;i>=0;i--)
    printf("%06lld",result[i]);
    printf("\n");
    return 0;
}
int main()
{
    int m1[N];
    int m2[N];
    int len1;
    int len2;
    char opt;
    char ch;
    int loop;
    int i,j;
    int flag=0;
    //读取数字和运算符
    while((scanf("%c",&ch))!=EOF)
    {
        memset(result,0,sizeof(result));
        memset(m1,0,sizeof(m1));
        memset(m2,0,sizeof(m2));
        len1=1;
        m1[0]=ch-'0';
        do
        {
            ch=getchar();
            if(ch!=' ')
               {
                   m1[len1]=ch-'0';
                   len1++;
               }
        }while(ch!=' ');
        opt=getchar();
        getchar();
        len2=0;
        do
        {
            ch=getchar();
            if(ch!='\n')
            {
                m2[len2]=ch-'0';
                len2++;
            }
        }while(ch!='\n');
        switch(opt)
        {
            //加法运算
        case '+':
            {
                flag=0;
                for(i=len1-1,j=len2-1,loop=0;i>=0&&j>=0;i--,j--,loop++)
                {
                    result[loop]=m1[i]+m2[j]+flag;
                    if(result[loop]>9)
                    {
                        flag=result[loop]/10;
                        result[loop]=result[loop]%10;
                    }
                    else
                        flag=0;
                }
                if(i>=0)
                    {
                        while(i>=0)
                        {
                            result[loop]=flag+m1[i];
                            if(result[loop]>9)
                            {
                                flag=result[loop]/10;
                                result[loop]=result[loop]%10;
                            }
                            else
                                flag=0;
                            loop++;
                            i--;
                        }
                    }
                if(j>=0)
                {
                    while(j>=0)
                    {
                        result[loop]=flag+m2[j];
                        if(result[loop]>9)
                        {
                            flag=result[loop]/10;
                            result[loop]=result[loop]%10;
                        }
                        else
                            flag=0;
                        loop++;
                        j--;
                    }
                }
                if(flag!=0)
                {
                    result[loop]=flag;
                }
                else
                    loop--;
                for(i=loop;i>=0;i--)
                    printf("%lld",result[i]);
                printf("\n");
            };break;
        case '-':
            Sub(m1,m2,len1,len2);break;
        case '*':
            Mul(m1,m2,len1,len2);break;
            default:break;
        }
    }
    return 0;
}
