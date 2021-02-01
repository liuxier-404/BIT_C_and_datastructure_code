#include <stdio.h>
#include <stdlib.h>
#define N 100010
long long x[N];
long long y[N];
//由小到大排序
long long cmp(const void*a,const void*b)
{
    return *(long long*)a-*(long long*)b;
}
long long ab(long long a)
{
    return (a>0)?a:-a;
}
int main()
{
    int num;
    int i;
    int j;
    int k;
    int mid;
    long long steps=0;
    scanf("%lld",&num);
    for(i=0;i<num;i++)
    {
        scanf("%lld%lld",&x[i],&y[i]);
    }
    //对纵坐标进行排序
    qsort(y,num,sizeof(long long),cmp);
    //对横坐标进行排序
    qsort(x,num,sizeof(long long),cmp);
    //计算到同一y坐标的距离
    for(i=0,j=num-1;i<j;i++,j--)
    {
        steps+=y[j]-y[i];
    }
    for(i=0;i<num;i++)
    {
        x[i]-=i;
    }
    //对横坐标进行排序
    qsort(x,num,sizeof(long long),cmp);
    for(i=0,j=num-1;i<j;i++,j--)
    {
        steps+=x[j]-x[i];
    }
    printf("%lld\n",steps);
    return 0;
}
