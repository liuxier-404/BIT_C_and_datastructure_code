#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define INF 0x3f3f3f3f
#define N 500005	
int a[N];
long long dp[4][N];
long long Max(long long x, long long y)
{
	if (x > y)
		return x;
	else
		return y;
}
int main() {
	int n;		//ÃÃ×ÓÊýÁ¿
	long long sum = 0;
	long long m;
	int k;
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	memset(dp, 0, sizeof(dp));
	/*for (i = 0; i <= 3; i++)
		for (j = 0; j < N; j++)
			dp[i][j] = -INF;*/
	for (i = 1; i <= n; i++)
	{
		dp[1][i] = a[i];
		if (dp[1][i - 1] > 0)
			dp[1][i] += dp[1][i - 1];
	}
	dp[1][1] = a[1];
	dp[2][2] = (long long)a[1] + (long long)a[2];
	dp[3][3] = dp[2][2] + a[3];
	for (i = 2; i <= 3; i++)
	{
		m = -INF;
		for (k = 1; k < i; k++)
			m = Max(m, dp[i - 1][k]);
		for (j = i + 1; j <= n; j++)
		{
			if (m < dp[i - 1][j - 1])
				m = dp[i - 1][j - 1];
			dp[i][j] = Max((long long)dp[i][j - 1], (long long)m) + a[j];
		}
	}
	m = -INF;
	for (j = 3; j <= n; j++)
		if (m < dp[3][j])
			m = dp[3][j];
	printf("%lld\n", m);
}