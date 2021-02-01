#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100001
struct CrystalBall
{
	int isort;
	long long length;
	long long width;
	long long height;
};
long long Min(long long a,long long b,long long c)
{
    long long min;
    if(a<b)
        min=a;
    else
        min=b;
    if(min>c)
        min=c;
    return min;
}
struct CrystalBall Ball[N];
int cmp(const void* p1, const void* p2)
{
	struct CrystalBall* a = (struct CrystalBall*)p1;
	struct CrystalBall* b = (struct CrystalBall*)p2;
	if (a->height != b->height)
		return (b->height) - (a->height);
	else if (a->width != b->width)
		return (b->width) - (a->width);
	else
		return (b->length) - (a->length);
}
int main()
{
	int iCrystalBallNumber;
	long long llMaxMin = 0; //水晶球最大的最小一边长度
	long long lltyr = 0;	//每次计算两个求合并后最小边的长度
	int NowSort;			//记录当前满足条件的水晶球的序号
	int i;
	int a, b;				//配对的两个水晶球的序号
	short flag = 0;
    long long max;
	long long mid;
	long long* p1, * p2;
	memset(Ball, 0, sizeof(Ball[0]));
	scanf("%d", &iCrystalBallNumber);
	for (i = 0; i < iCrystalBallNumber; i++)
	{
		scanf("%lld%lld%lld", &Ball[i].length, &Ball[i].width, &Ball[i].height);
		Ball[i].isort = i + 1;
	if(Ball[i].height<Ball[i].width)
	{
		max = Ball[i].width;
		p1 = &Ball[i].width;
		p2 = &Ball[i].height;
		mid = *p2;
		*p2 = max;
		*p1 = mid;
	}
	if (Ball[i].height < Ball[i].length)
	{
		p1 = &Ball[i].height;
		p2 = &Ball[i].length;
		mid = *p1;
		*p1 = *p2;
		*p2 = mid;
	}
	if (Ball[i].width < Ball[i].length)
	{
		p1 = &Ball[i].length;
		p2 = &Ball[i].width;
		mid = *p2;
		*p2 = *p1;
		*p1 = mid;
	}
    if (llMaxMin < Ball[i].length)
    {
        llMaxMin = Ball[i].length;
        NowSort = Ball[i].isort;
    }
	}
	qsort(Ball, iCrystalBallNumber, sizeof(Ball[0]), cmp);
	for (i = 0; i < iCrystalBallNumber-1; i++)
	{
		if (Ball[i].height == Ball[i + 1].height && Ball[i].width == Ball[i + 1].width)
		{
			lltyr = Ball[i].length + Ball[i + 1].length;
			lltyr=Min(lltyr,Ball[i].height,Ball[i].width);
			if (lltyr > llMaxMin)
			{
				flag = 1;
				llMaxMin = lltyr;
				a = Ball[i].isort;
				b = Ball[i + 1].isort;
			}
		}
	}
	if (flag)
	{
		printf("2\n%d %d\n",a,b );
	}
	else
	{
		printf("1\n%d", NowSort);
	}
	return 0;
}
