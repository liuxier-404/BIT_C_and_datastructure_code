#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
struct gift
{
	int sort;
	int v;
	int nextSort;
	int lastSort;
}sGift[100000];
//由大到小排序  
int cmp(const void* a, const void* b)
{
	return  (*(struct gift*)b).v - (*(struct gift*)a).v;
}
int main()
{
	int k;
	int inNumber = 0;
	int i, j;
	int m = 1;
	int sorts[32];
	int giftNumber ;
	scanf("%d", &k);
	giftNumber = k;
	memset(sGift, 0, sizeof(sGift));
	memset(sorts, 0, sizeof(sorts));
	for (i = 0; i < k; i++)
	{
		scanf("%d", &sGift[i].v);
		sGift[i].sort = i + 1;
	}
	qsort(sGift, k, sizeof(struct gift), cmp);
	//开始塞礼物  
	for (i = 0; i < k; i++)
	{
		if (sGift[i].nextSort == 0 )
		{	
			for (j = m; j < k; j++)
			{
				if ( sGift[j].v * 2 <= sGift[i].v )
				{
					sGift[i].nextSort = j+1;
					sGift[j].lastSort = i+1;
					giftNumber--;
					m = j + 1;
					break;
				}
			}	
		}
		if (j== k-1||j==k)
			break;
	}
	printf("%d\n", giftNumber);
	//一个礼物中的所有礼物
	for (i = k - 1; i >= 0; i--)
	{
		if (sGift[i].nextSort == 0)
		{
			j = i;
			while (sGift[j].lastSort != 0)
			{
				inNumber++;
				sorts[inNumber - 1] = sGift[j].sort;
				j = sGift[j].lastSort - 1;
			}
			sorts[inNumber] = sGift[j].sort;
			printf("%d ", inNumber + 1);
			for (j = 0; j <= inNumber; j++)
			{
				printf("%d", sorts[j]);
				if (j != inNumber)
					printf(" ");
				else
					printf("\n");
			}
			inNumber = 0;
		}
		}
}