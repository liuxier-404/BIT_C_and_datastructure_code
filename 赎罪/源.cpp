#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<stack>
#include<iostream>
#include<cstring>
using namespace std;
#define ESP 0.00001
float cnt[20];
int flag = 0;

void backtrack(int t) {
	if (t == 1) {
		for (int i = 0; i < 4; i++)
			if (fabs(cnt[i] - 24) < ESP)
				flag = 1;
		return;
	}
	for(int i=0;i<=3;i++)
		for (int j = 0; j <= 3; j++) {
			if (i != j && cnt[i] != 0 && cnt[j] != 0) {
				float a1 = cnt[i];
				float a2 = cnt[j];
				if (a2 > ESP) {
					cnt[i] = 1.0*cnt[i] / cnt[j];
					cnt[j] = 0;
					backtrack(t - 1);
					cnt[i] = a1;
					cnt[j] = a2;
				}
				if (a1 > ESP) {
					cnt[i] = 1.0 * cnt[j] / cnt[i];
					cnt[j] = 0;
					backtrack(t - 1);
					cnt[i] = a1;
					cnt[j] = a2;
				}
				cnt[i] = a1 - a2;
				cnt[j] = 0;
				backtrack(t - 1);
				cnt[i] = a1;
				cnt[j] = a2;
				cnt[i] = a1 + a2;
				cnt[j] = 0;
				backtrack(t - 1);
				cnt[i] = a1;
				cnt[j] = a2;
				cnt[i] = cnt[j] * cnt[i];
				cnt[j] = 0;
				backtrack(t - 1);
				cnt[i] = a1;
				cnt[j] = a2;
			}
		}
}
void solve() {
	flag = 0;
	backtrack(4);
	if (flag)
		printf("yes\n");
	else
		printf("no\n");
}

int main() {

	while (scanf("%f %f %f %f", &cnt[0], &cnt[1], &cnt[2], &cnt[3]) != EOF) {
		solve();
		memset(cnt, 0, sizeof(cnt));
	}
	return 0;
}