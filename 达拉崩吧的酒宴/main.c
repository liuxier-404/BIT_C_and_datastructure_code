#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void Mounce(long long n)
{
	int i=1;
	long long number = 1;
	while (number < n)
	{
		number = pow(2, i);
		i++;
	}
	printf("%d\n", i - 1);
}
int main()
{
	long long n;
	int T;
	scanf("%d", &T);
	int iCount;
	for (iCount = 0; iCount < T; iCount++)
	{
		scanf("%lld", &n);
		Mounce(n);
	}
}
