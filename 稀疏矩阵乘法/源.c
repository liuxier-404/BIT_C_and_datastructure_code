#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
	int x ;
	int y ;
	int data;
}NODE;
NODE m[101];
NODE n[101];
int re[101][101];

int main() {
	int row1, line1, row2, line2;
	int not_01, not_02;
	int x, y, data;
	memset(re, 0, sizeof(re));
	memset(m, 0, sizeof(m));
	memset(n, 0, sizeof(n));
	scanf("%d%d%d", &row1, &line1,&not_01);
	for (int i = 1; i <= not_01; i++) {
		scanf("%d%d%d", &x, &y, &data);
		m[i].data = data;
		m[i].x = x;
		m[i].y = y;
	}
	scanf("%d%d%d", &row2, &line2, &not_02);
	for (int i = 1; i <= not_02; i++) {
		scanf("%d%d%d", &n[i].x, &n[i].y, &n[i].data);
	}
	for(int i=1;i<=not_01;i++)
		for (int j = 1; j <= not_02; j++) {
			if (m[i].y == n[j].x) {
				int ans;
				ans = m[i].data * n[j].data;
				re[m[i].x][n[j].y] += ans;
			}
		}
	printf("%d\n%d\n", row1, line2);
	int all = 0;
	for(int i=1;i<=row1;i++)
		for (int j = 1; j <= line2; j++) {
			if (re[i][j] != 0)
				all++;
		}
	printf("%d\n", all);
	for (int i = 1; i <= row1; i++)
		for (int j= 1; j <= line2;j++) {
			if(re[i][j]!=0)
		printf("%d,%d,%d\n", i, j, re[i][j]);
	}
	return 0;
}