#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10000
typedef struct node{
	int x;
	int y;
	int data;
}NODE;

int main(){
	int row, line, n, x, y, data;
	scanf("%d %d %d", &row, &line, &n);
	NODE m[MAX];
	NODE t[MAX];
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &x, &y, &data);
		m[i].x = x;
		m[i].y = y;
		m[i].data = data;
	}
	int num[MAX];
	int cpot[MAX];
	memset(num, 0, sizeof(num));
	for (int i = 1; i <= n; i++) {
		num[m[i].y] += 1;
	}
	cpot[1] = 1;
	for (int i = 2; i <= line; i++) {
		cpot[i] = cpot[i - 1] + num[i - 1];
	}
	printf("num:");
	for (int i = 1; i <= line; i++) {
		printf("%d,", num[i]);
	}
	printf("\n");
	printf("cpot:");
	for (int i = 1; i <= line; i++) {
		printf("%d,", cpot[i]);
	}
	printf("\n");
	int q = 0;
	for (int i = 1; i <= n; i++) {
		q = m[i].y;
		t[cpot[q]].x = m[i].y;
		t[cpot[q]].y = m[i].x;
		t[cpot[q]].data = m[i].data;
		++cpot[q];
	}
	for (int i = 1; i <= n; i++) {
		printf("%d,%d,%d\n", t[i].x, t[i].y, t[i].data);
	}

	return 0;
}