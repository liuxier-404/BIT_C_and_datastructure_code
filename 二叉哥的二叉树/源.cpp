#include<cstring>
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
long long list[32];
int cal(int n) {
	if (n > 27)
		return  100000010;
	if (n < 0)
		return 0;
	return list[n];
}
int build(int n, int m) {
	if (n < m)
		return 0;
	if (n == m)
		return 1;
	if (n >= cal(m) - 1)
		return cal(m - 1);
	if (n > cal(m - 1))
		return cal(m-2) + build(n - cal(m - 1), m - 1);
	return build(n - 1,m - 1);
}
int main() {
	int N;
	cin >> N;
	list[0] = 1;
	for (int j = 1; j <= 32; j++) {
		list[j] = list[j - 1] * 2;
	}
	while (N--) {
		int m, n;//n个节点，第m层最多的个数
		scanf("%d%d", &n, &m);
		m++;
		if (m > 32)
			printf("%d\n", build(n - (m - 32), 32));
		else
			printf("%d\n", build(n, m));

	}
}