#include <stdio.h>
#include <stdlib.h>
#define N 3005
struct tree
{
    int day;        //���ӵڼ������
    int number;     //���������ӵ�����
};
int main()
{
    int max;        //����ժ����
    struct tree array[N];
    int treenumber;//��������
    int i,j;
    int mid;
    int sum=0;
    int firstday=0;
    int secondday=0;
    int change1,change2;
    //��������������ܲ�ժ���������
    scanf("%d%d",&treenumber,&max);
    //����ÿ�ù������������
    for(i=0;i<treenumber;i++)
    {
        scanf("%d%d",&array[i].day,&array[i].number);
    }
    //���ճ�����������������
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
