#include<stdio.h>
#include<string.h>
#define N 200001
int lake[N];
int main()
{
	int wide;
	int i, j;
	int a[N];
	int number;
	int flag;
	while (scanf("%d", &wide) != EOF)
	{
		flag = 0;
		number = 0;
		for (i = 0; i < wide; i++)
		{
			scanf("%d", &lake[i]);
			lake[i] %= 2;
				if (number == 0 || lake[i] != a[number-1])
				{
					a[number] = lake[i];
					number++;
				}
				else
				{
					number--;
				}
		}
		if (number > 1)
		{
			printf("NO\n");
		}
		else
			printf("YES\n");
	}
}