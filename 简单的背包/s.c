#include<stdio.h> 
#include<string.h> 
#define N 10000000 
int valum[20010];
int dp[2010][2010];
int main()

{
	int n;      //物品数 
	int v;          //背包体积基数 
	int i, j;
	scanf("%d%d", &n, &v);
	memset(dp, 0, sizeof(dp));
	for (i = 1; i <= n; i++)
		scanf("%d", &valum[i]);
	for (i = 1; i <= n; i++)
		dp[i][valum[i] % v] = 1;
	for (i = 1; i <= n; i++)
		for (j = 0; j < v; j++)
		{
			dp[i][j] += dp[i - 1][j] + dp[i - 1][(v - valum[i] % v + j) % v];
			dp[i][j] %= N;
		}
	printf("%d\n", dp[n][0]);
	return 0;
}