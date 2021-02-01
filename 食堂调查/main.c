#include <stdio.h>
#include <stdlib.h>
#define N 100005
int in[N];
int out[N];
int main()
{
	int sum = 0;
	int max = 0;
	int people;
	int i = 0;
	int del = 0;
	int j=0,k=0;
	int point=0;
	int mid;
	scanf("%d", &people);
	do
	{
		scanf("%d%d", &in[i], &out[i]);
		i++;
	} while (i < people);
	for (i = 0; i < people - 1; i++)
	{
		point = i;
		for (j = i + 1; j < people; j++)
		{
			if (in[point] > in[j])
				point = j;
		}
		if (i != point)
		{
			mid = in[i];
			in[i] = in[point];
			in[point] = mid;
		}
	}
	for (i = 0; i < people - 1; i++)
	{
		point = i;
		for (j = i + 1; j < people; j++)
		{
			if (out[point] > out[j])
				point = j;
		}
		if (i != point)
		{
			mid = out[i];
			out[i] = out[point];
			out[point] = mid;
		}
	}
	j=0;
	k = 0;
	for (i = in[0]; i <= out[people - 1]; i++)
	{
		sum -= del;
		del = 0;
		while (i >=in[j])
		{
			if (i == in[j])
				sum++;
			j++;
		}
		while (i >= out[j])
		{
			if (i == out[j])
				del--;
			k++;
		}
		if (max < sum)
			max = sum;
	}
	printf("%d\n", max);
	return 0;
}
