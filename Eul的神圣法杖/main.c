#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct loss
{
    long long t;        //time
    int d;          //伤害
}pp[5000];
int cmp(const void* a, const void* b)
{
    return (*(struct loss*)b).t>(*(struct loss*)a).t?1:-1;
}
int main()
{
    int n;      //发动攻击的总人数
    int q;      //k值不同取法的情况
    int qs[5001];
    int i,j;
    int icount;
    int left1,left2;
    int right1,right2;
    int max1,max2,max=0,max0=0;
    int alld=0; //总伤害
    memset(pp,0,sizeof(pp));
    scanf("%d%d",&n,&q);
    for(i=0;i<n;i++)
    {
        scanf("%lld%d",&pp[i].t,&pp[i].d);
        alld+=pp[i].d;
    }
    //现在输入k的取值情况
    for(i=0;i<q;i++)
    {
        scanf("%d",&qs[i]);
    }
    //降序排序
    qsort(pp,n,sizeof(pp[0]),cmp);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(pp[j].t==pp[i].t)
            {
                pp[i].d+=pp[j].d;
                pp[j].d=0;
            }
            else
            {
                i=j;
                break;
            }
        }
    }
    //简化合并后的数组
    for(i=0;i<n;i++)
    {
        if(pp[i].d==0)
        {
            for(j=i;j<n-1;j++)
            {
                pp[j].d=pp[j+1].d;
                pp[j].t=pp[j+1].t;
            }
            n--;
        }
    }
    pp[n].d=pp[n].t=0;
    //现在只有n个时刻可以攻击了
    //两边同时开始寻找最大的伤害
    for(icount=0;icount<q;icount++)
    {
        max=0;
        max0=0;
        max1=max2=0;
        for(left1=left2=0,right1=right2=n-1;right2>left1;left1++,right2--)
        {
            while(pp[left1].t-pp[left2].t<qs[icount]&&left2<n)
            {
                max1+=pp[left2].d;
                left2++;
            }
            while(pp[right1].t-pp[right2].t<qs[icount]&&right1>=0)
            {
                max2+=pp[right1].d;
                right1--;
            }
            max=max1>max2?max1:max2;
            if(max>max0)
                max0=max;
            max1-=pp[left1].d;
            max2-=pp[right2].d;
        }
        printf("%d\n",alld-max0);
    }
    return 0;
}
