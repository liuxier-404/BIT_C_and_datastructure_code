#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#define MOD   998244353
using namespace std;
int n, k;
struct mt {
	long long a[100][100];
};
	mt res;
mt Mul(mt x, mt y) {
	for(int i=0;i<k;i++)
		for (int j = 0; j < k; j++) {
			res.a[i][j] = 0;
		for (int m = 0; m < k; m++) 
				res.a[i][j] = (res.a[i][j] + (x.a[i][m] * y.a[m][j]) ) % MOD;
		}
	
	return res;
}
mt mat;
int Max(int a, int b) {
	return (a > b) ? a : b;
}
int Min(int a, int b) {
	return (a < b) ? a : b;
}
long long way[2][110];
long long f[100];
int main() {

	int T;
	long long all = 0;
	mt resb;	
	memset(resb.a, 0, sizeof(resb.a));
	cin >>T;
	while (T--) {
		all = 0;
		int max, min;
		cin >> n >> k;
		for (int i = 0; i < k; i++)
			resb.a[i][i] = 1;
		if (n<=1000) {
			memset(way, 0, sizeof(way));
			for (int i = 1; i <= k; i++) {
				way[0][i] = 1;
				//从1到n的循环
				for (int loop = 2; loop <= n; loop++) {
					max = i + n + 1 - loop;
					max = Min(max, i + loop - 1);
					if (max > k)
						max = k;
					min = i - n - 1 + loop;
					min = Max(min, i - loop + 1);
					if (min < 1)
						min = 1;
					for (int j = min; j <= max; j++) {
						way[1][j] = way[0][j - 1] + way[0][j] + way[0][j + 1];
						way[1][j] %= MOD;
					}
					for (int j = min; j <= max; j++) {
						way[0][j] = way[1][j];
					}
				}
				max = i + 1;
				if (max > k) max = k;
				min = i - 1;
				if (min < 1) min = 1;
				for (int j = min; j <= max; j++)
				{
					all += way[0][j];
					all %= MOD;
				}
				memset(way, 0, sizeof(way));
			}
			printf("%lld\n", all);
		}
		else {	
			mt resa = resb;
			memset(f, 0, sizeof(f));		
			memset(mat.a, 0, sizeof(mat.a));
			//a矩阵初始化
				for (int i = 0; i < k; i++) {
					mat.a[i][i] = 1;
					if (i > 0)
						mat.a[i][i - 1] = 1;
					if (i < k - 1)
						mat.a[i][i + 1] = 1;
				}
				n--;
				while (n) {
					if (n & 1)
						resa = Mul(resa, mat);
					mat = Mul(mat, mat);
					n >>= 1;
				}
				for (int j = 0; j < k; j++)
				{
					all = (all + resa.a[j][j]) % MOD;
					if (j > 0)
						all = (all + resa.a[j][j - 1]) % MOD;
					if (j < k - 1)
						all = (all + resa.a[j][j + 1]) % MOD;
			}
			printf("%lld\n", all);
		}
	}
	return 0;
}