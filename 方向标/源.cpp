#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
#define MAXN 2005
using namespace std;
#define MODE 2147483647
int dp[MAXN][MAXN];
int Greater(int x, int y) {
	return (x > y) ? x : y;
}
int Smaller(int x, int y) {
	return(x < y) ? x : y;
}
int main() {
	int i, j;
	int n;
	int Head[MAXN];
	int tail;
	int left, right;
	cin >> n;
	memset(dp, 0, sizeof(dp));
	cin >> tail;
	cin >> Head[1];
	for (i = 2; i <= n; i++)
		cin >> Head[i];
	dp[1][tail] = 1;
	for(i=2;i<=n;i++)
		for (j = 1; j <= n + 1; j++) {
			if (dp[i - 1][j] != 0) {
				right = Greater(Head[i - 1], j);
				left = Smaller(Head[i - 1], j);
				if (Head[i] < right) {
					dp[i][right] = ((long long)dp[i - 1][j] + (long long)dp[i][right]) % MODE;
				}

			 if (Head[i] > left)
					dp[i][left] = ((long long)dp[i - 1][j] + (long long)dp[i][left]) % MODE;
			}
		}
	int ans = 0;
	for (i = 1; i <= n+1; i++)
		ans = ((long long)ans + (long long)dp[n][i]) % MODE;
	cout << ans << endl;
	return 0;
}