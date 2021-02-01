#include <stdio.h>
#include <stdlib.h>
#define N 3005
struct tree
{
    int day;        //果子第几天成熟
    int number;     //果树上桃子的数量
};
int main()
{
    int max;        //最大采摘数量
    struct tree array[N];
    int treenumber;//果树数量
    int i,j;
    int mid;
    int sum=0;
    int firstday=0;
    int secondday=0;
    int change1,change2;
    //输入果树数量和能采摘的最大数量
    scanf("%d%d",&treenumber,&max);
    //输入每棵果树的相关数据
    for(i=0;i<treenumber;i++)
    {
        scanf("%d%d",&array[i].day,&array[i].number);
    }
    //按照成熟天数升序排列树
    for(i=0;i<treenumber-1;i++)
    {
        mid=i;
        for(j=i+1;j<treenumber;j++)
        {
            if(array[mid].day>array[j].day)
                mid=j;
        }
        if(mid!=i)
            {
                change1=array[i].day;
                change2=array[i].number;
                array[i].day=array[mid].day;
                array[i].number=array[mid].number;
                array[mid].day=change1;
                array[mid].number=change2;
            }
    }
    for(i=1;i<=array[treenumber-1].day;i++)
    {
        j=0;
        if(i==1)
        {
            while((array[j].day==1)&&(j<treenumber))
            {
                firstday+=array[j].number;
                j++;
            }
            secondday=0;
        }
        else
            {
                j=0;
                while((array[j].day<=i)&&(j<treenumber))
                {
                    if(array[j].day==i)
                    {
                        firstday+=array[j].number;
                    }
                    j++;
                }
            }
        if((firstday+secondday)<=max)
        {
            sum+=(firstday+secondday);
            firstday=0;
            secondday=0;
        }
        else
        {
            if(secondday>=max)
            {
                sum+=max;
                secondday=firstday;
                firstday=0;
            }
            else
            {
                sum+=max;
                secondday=firstday+secondday-max;
                firstday=0;
            }
        }
    }
    if(secondday>=max)
        sum+=max;
    else
        sum+=secondday;
    printf("%d\n",sum);
    return 0;
}
