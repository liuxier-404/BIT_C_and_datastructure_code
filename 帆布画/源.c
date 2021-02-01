#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
	return *(int*)b - *(int*)a;
}
// π”√≤Â»Î≈≈–Ú≥¢ ‘
void main()
{
	int T;
	int n;
	int icount;
	int i, j,k;
	long long daiding;
	int s[100000];
	long long all;
	scanf("%d", &T);
	for (icount = 0; icount < T; icount++)
	{
		memset(s, 0, sizeof(s));
		all = 0;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &s[i]);
		qsort(s,n,sizeof(s[0]),cmp);
		if (n == 1)
		{
			printf("0\n");
		}
		else
		{
			while (n != 1)
			{
			daiding = (long long)s[n - 1] + (long long)s[n - 2];
			all += daiding;
			s[n - 1] = s[n - 2] = 0;
			n--;
			if (n == 1)
			{
				break;
			}
			k = n - 2;
			while (daiding >= s[k])
			{
				k--;
				if (k == -1)
					break;
			}
				for (i = n - 1; i >k+1; i--)
						s[i] = s[i - 1];
				s[k+1] = daiding;
			}	
			printf("%lld\n", all);
			}
	}
}