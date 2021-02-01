#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<list>
#include<cstdlib>
using namespace std;
#define N 14
int FindMaxFinger(int arr[], int len)//找最大位数
{
	int max = arr[0];
	for (int i = 1; i < len; ++i)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	int count = 0;
	while (max != 0)
	{
		max = max / 10;
		count++;
	}
	return count;
}

int FindFingerNumber(int num, int fin)//求（个、十、百……）位上的数
{
	return num / (int)pow(10.0, fin) % 10;
}

void Radix(int arr[], int len, int fin)
{
	int tmp[10][N] = {};
	int num_fin;
	int count[10] = {};
	memset(tmp, 0, sizeof(tmp));
	memset(count, 0, sizeof(count));
	for (int i = 0; i < len; ++i)//向‘桶’中放
	{
		num_fin = FindFingerNumber(arr[i], fin);
		tmp[num_fin][count[num_fin]] = arr[i];
		count[num_fin]++;
	}
	int index = 0;
	for (int i = 0; i < 10; ++i)//从‘桶’中取
	{
		for (int j = 0; j < count[i]; ++j)
		{
			arr[index++] = tmp[i][j];
		}
	}
}

void RadixSort(int arr[], int len)//基数排序
{
	int maxFinNum = FindMaxFinger(arr, len);
	for (int i = 0; i < maxFinNum; ++i)
	{
		Radix(arr, len, i);
	}
}

int main()
{
	int arr[N] = { 1,0,45, 5, 4, 12, 4, 156, 456, 465, 4, 12, 16, 6 };
	int len = N;
	RadixSort(arr, len);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}