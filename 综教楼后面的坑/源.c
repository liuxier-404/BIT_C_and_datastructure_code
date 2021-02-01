#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXHI 1000005
typedef struct pit {
	int hi;
	long long wi;
	int order;
	struct pit* pre;
	struct pit* next;
}mypit;
long long pit_time[100005];
int main() {
	int n;
	int  heigth;
	long long width;
	mypit *nowpit, *prepit, *left, *right;
	mypit* delate;
	mypit* deepest;
	left = (mypit*)malloc(sizeof(mypit));
	left->hi = MAXHI;
	left->wi = 0;
	left->pre = NULL;
	left->order = -1;
	left->next = NULL;
	prepit = left;
	deepest = left;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld%d", &width, &heigth);
		nowpit = (mypit*)malloc(sizeof(mypit));
		nowpit->hi = heigth;
		nowpit->wi = width;
		nowpit->order = i;
		nowpit->pre = prepit;
		nowpit->next = NULL;
		prepit->next = nowpit;
		prepit = nowpit;
		if (deepest->hi > heigth) {
			deepest = nowpit;
		}
	}
	long long time=0;
	right = (mypit*)malloc(sizeof(mypit));
	right->hi = MAXHI;
	right->wi = 0;
	right->pre = nowpit;
	nowpit->next = right;
	right->next = NULL;
	right->order = -1;
	while (deepest->next->hi != deepest->pre->hi) {
		pit_time[deepest->order] = time + deepest->wi;
		if (deepest->pre->hi < deepest->next->hi) {
			time += (deepest->pre->hi - deepest->hi) * deepest->wi;
			deepest->pre->wi += deepest->wi;
			deepest->next->pre = deepest->pre;
			deepest->pre->next = deepest->next;
			delate = deepest;
			deepest = deepest->pre;
			free(delate);
		}
		else
		{
			time += (deepest->next->hi - deepest->hi) * deepest->wi;
			deepest->next->wi += deepest->wi;
			deepest->pre->next = deepest->next;
			deepest->next->pre = deepest->pre;
			delate = deepest;
			deepest = deepest->next;
			free(delate);
		}
		if (deepest->hi<deepest->pre->hi && deepest->next->hi>deepest->hi) {
			continue;
		}
		else if (deepest->pre->hi > deepest->next->hi) {
			while (deepest->hi > deepest->next->hi) {
				deepest = deepest->next;
			}
		}
		else if (deepest->pre->hi < deepest->next->hi) {
			while (deepest->hi > deepest->pre->hi) {
				deepest = deepest->pre;
			}
		}
	}
	pit_time[deepest->order] = time + deepest->wi;
	for (int i = 0; i < n; i++) {
		printf("%lld\n", pit_time[i]);
	}
}