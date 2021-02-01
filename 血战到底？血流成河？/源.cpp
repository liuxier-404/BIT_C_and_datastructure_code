#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int pai[405];
int pai1[405];
int re[405];
int n;
int m;
void Back() {
	for (int j = 1; j <= n+2; j++) {
		pai1[j] = pai[j];
	}
}
//检查是否能胡的函数，能胡返回1
int Check() {
	int flag = 1;
	for (int icount = 1; icount <= n; icount++) {
		if (pai1[icount] >= 2) {
			pai1[icount] -= 2;
		}
		else
			continue;
		flag = 1;
		for (int i = 1; i <= n+2; i++) {
			if (pai1[i] < 0) {
				flag = 0;
				break;
			}
			pai1[i] %= 3;
			pai1[i + 1] -= pai1[i];
			pai1[i + 2] -= pai1[i];
			pai1[i] = 0;
		}
		if (flag ) {
			return 1;
		}
		Back();
		}
	return 0;
}
int main() {
	int all = 0;
	memset(pai, 0, sizeof(pai));
	memset(pai1, 0, sizeof(pai1));
	memset(re, 0, sizeof(re));
	cin >> n >> m;
	int number = 3 * m + 1;
	int a;
	for (int i = 0; i < number; i++) {
		cin >> a;
		pai[a]++;
		pai1[a]++;
	}
	for (int i = 1; i <= n; i++) {
		pai[i]++;
		pai1[i]++;
		if (Check()) {
			all++;
			re[all - 1] = i;
		}
		pai[i]--;
		Back();
	}
	if (all == 0)
		cout << "NO" << endl;
	else {
		for (int i = 0; i < all; i++)
		{
			if (i != all - 1)
				printf("%d ", re[i]);
			else
				printf("%d\n", re[i]);
		}
	}
}