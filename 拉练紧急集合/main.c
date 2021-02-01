#include <stdio.h>
#include <stdlib.h>
#define MIN -2e9-1
long long ab(long long a)
{
    return (a>0)?a:-a;
}
int main()
{
    long long m,n;
    long long x,y;
    long long tyr;
    long long d1,d2,d3,d4;
    int c;
    int a,b;
    int maxin=0;
    long long maxin0=-MIN;
    int i,j;
    int d;
    d1=d2=d3=d4=MIN;
    scanf("%lld%lld",&m,&n);
    scanf("%d",&c);
    for(i=0;i<c;i++)
    {
        scanf("%lld%lld",&x,&y);
        tyr=y-x;
        if(tyr>d1)
            d1=tyr;
        tyr=-x-y;
        if(tyr>d2)
            d2=tyr;
        tyr=x-y;
        if(tyr>d3)
            d3=tyr;
        tyr=x+y;
        if(tyr>d4)
            d4=tyr;
    }
    scanf("%d",&d);
    for(i=0;i<d;i++)
    {
        maxin=0;
        scanf("%d%d",&a,&b);
        tyr=ab(a-b+d1);
        maxin=(tyr>maxin)?tyr:maxin;
        tyr=ab(a+b+d2);
        maxin=(tyr>maxin)?tyr:maxin;
        tyr=ab(b-a+d3);
        maxin=(tyr>maxin)?tyr:maxin;
        tyr=ab(d4-a-b);
        maxin=(tyr>maxin)?tyr:maxin;
        maxin0=(maxin0>maxin)?maxin:maxin0;
    }
    printf("%lld\n",maxin0);
    return 0;
}
