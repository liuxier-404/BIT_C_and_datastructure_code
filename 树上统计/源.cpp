#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#define MAX 200010
using namespace std;
vector<int>V[1];
int Head[MAX];
int nxt[MAX*10];
int Size[MAX];
int deep[MAX];
int md[MAX * 10];
long long dp[MAX];
int n;
void dfs(int u, int v, int w ) {
	int i;
	deep[u] = w;
	Size[u] = 1;
	int mid;
	for (i = Head[u]; i >0; i = nxt[i]) {
		mid = md[i];
		if (mid != v) {
			dfs(mid, u, w + 1);
			Size[u] += Size[mid];
			dp[u] = (long long)dp[u] + dp[mid] + (long long)(n - Size[mid]) * Size[mid];
		}
	}
}
int bu=0;
int build(int u, int v) {
	int mid;
	mid = Head[u];
	Head[u] = bu;
	nxt[bu] =mid;
	md[bu] = v;
	return 1;
}
int main()
{
	int a, b;
	int i, j;
	int flag = 0;
	long long result = 0;
	long long x = 0, y = 0;
	memset(nxt, 0, sizeof(nxt));
	memset(Head, 0, sizeof(Head));
	memset(dp, 0, sizeof(dp));
	cin >> n;
	i = 1;
	while (i <= n - 1) {
			cin >> a >> b;
			bu++;
			build(a, b);
			bu++;
			build(b, a);
			++i;
	}
	memset(deep, 0, sizeof(deep));
	memset(Size, 0, sizeof(Size));
	dfs(1, -1, 0);
	i = 1;
	while (1)
	{
		flag = deep[i] % 2;
		switch (flag)
		{
		case 0:x++; break;
		case 1:y++; break;
		default:break;
		}
		i++;
		if (i > n)
			break;
	}
	result = dp[1];
	result += x * y;
	result /= 2;
	cout << result << endl;
	return 0;
}