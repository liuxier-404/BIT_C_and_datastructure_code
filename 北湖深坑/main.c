#include <stdio.h>
#include<stdlib.h>
int main()
{
    int T;
    register int i;
    int j;
    int max;
    int left;
    int right;
    long long water;
    int p;
    int p1;
    int p2;
    int wide;
    int icount;
  int high[100000];
  scanf("%d", &T);
   for (icount = 0; icount <= T-1; icount++)
  {
      max=0;
      water=0;
      scanf("%d", &wide);
        for (i = 0; i <= wide-1; i++)
      {
          scanf("%d", &high[i]);
     }
    for(j=0;j<wide;j++)
    {
        if(max<high[j])
        {
            p=j;
            max=high[j];
        }
    }
        p2=p;
        p1=0;
        do
        {
            left=-1;
            for(i=0;i<p;i++)
            {
                if(left<high[i])
                {
                    left=high[i];
                    p1=i;
                }
            }
            for(i=p1;i<p;i++)
                {
                    water+=left-high[i];
                }
            p=p1;
        }while(p>1);
        p1=wide-1;
        do
        {
            right=-1;
            for(i=p2+1;i<wide;i++)
            {
                if(right<=high[i])
                {
                    right=high[i];
                    p1=i;
                }
            }
                for(i=p2+1;i<p1;i++)
                {
                    water+=right-high[i];
                }
            p2=p1;
        }while(p2<wide-2);
        printf("%lld\n",water);
    }
    return 0;
}

