#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#define N 1000000+10
long long s[N];
void Insert(long long a,int b)
{
    long long mid;
    int i;
    s[b]=a;
    for(i=b;i>1;i/=2)
    {
        if(s[i/2]>s[i])
        {
            mid=s[i/2];
            s[i/2]=s[i];
            s[i]=mid;
        }
    }
}
void build(int j,int number)
{
    int loop;
    long long mid;
    mid=s[j];
    loop=2*j;
    while(loop<=number)
    {
        if(loop<number&&s[loop+1]<s[loop])
        {
            loop++;
        }
        if(s[loop]>=mid)
            break;
        s[j]=s[loop];
        j=loop;
        loop*=2;
    }
    s[j]=mid;
}
void main()
{
    int i,j,k;
    int T;
    int icount;
    int number;
    long long mid;
    long long all=0;
    scanf("%d",&T);
    for(icount=0;icount<T;icount++)
    {
        all=0;
        memset(s,0,sizeof(s));
        scanf("%d",&number);
        for(i=1;i<=number;i++)
            scanf("%d",&s[i]);
            if(number==0)
            {
                printf("0\n");
                continue;
            }
        for(j=number/2;j>0;j--)
            build(j,number);
        for(i=number;i>1;i--)
        {
            mid=s[1];
            s[1]=s[i];
            build(1,i-1);
            mid+=s[1];
            s[1]=s[i-1];
            build(1,i-2);
            Insert(mid,i-1);
            all+=mid;
        }
        printf("%lld\n",all);
    }
}
