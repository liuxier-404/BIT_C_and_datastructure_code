#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N   65536
#define N1 128  //2^7次方的值
#define N2 192  //2^7+2^6的值
#define N3 224  //2^7+2^6+2^5的值
long Chi[N];
int main()
{
    unsigned char ch1,ch2,ch3;
    int num1,num2,num3;
    int n;
    int flag=0;
    register int i;
    memset(Chi,0,sizeof(Chi));


    while((scanf("%c",&ch1))!=EOF)
    {
        num1=ch1;
        if(num1<N3&&num1>=N2)
        {
            ch2=getchar();
            num2=ch2;
            n=((num1-N2)<<6)+num2-N1;
            Chi[n]++;
        }
        else if(num1<N1)
            continue;
        else
        {
            scanf("%c%c",&ch2,&ch3);
            num2=ch2;
            num3=ch3;
            n=((num1-N3)<<12)+((num2-N1)<<6)+(num3-N1);
            Chi[n]++;
        }
    }
        for(i=128;i<2048;i++)
        {
            if(Chi[i]>1)
                {
                    flag=1;
                    ch1=(i>>6)+N2;
                    ch2=i%64+128;
                    printf("%c%c ",ch1,ch2);
                    printf("0x%04x ",i);
                    printf("%ld\n",Chi[i]);
                }
        }
        for(i=2048;i<N;i++)
        {
            if(Chi[i]>1)
            {
                flag=1;
                ch1=(i>>12)+N3;
                ch2=(i>>6)%64+128;
                ch3=i%64+128;
                printf("%c%c%c 0x%04x %ld\n",ch1,ch2,ch3,i,Chi[i]);
            }
        }
        if(flag==0)
            printf("No repeat!\n");
    return 0;
}
