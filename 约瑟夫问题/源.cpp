#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
struct member {
	int order;
	struct member* next;
};
int main() {
	int n, k, m;
	scanf("%d,%d,%d", &n, &k, &m);
	if (k > n) {
		cout << "k should not bigger than n." << endl;
		return 0;
	}
	if (k < 1 || n < 1 || m < 1) {
		cout << "n,m,k must bigger than 0." << endl;
		return 
	}
	struct member* head=NULL;
	struct member* p=NULL;
	struct member* q=NULL;
	for (int i = 1; i <= n; i++) {
		q = (struct member*)malloc(sizeof(member));
		if (i == 1)
			head = q;
		if (i != 1)
			p->next = q;
		q->order = i;
		p = q;
	}
	p->next = head;//此时p在最后一个
	q = head;
	while (k != q->order) {
		q = q->next;
		p = p->next;
	}
	//p在q前面
	int num = 0;
	while (q->next != q) {
				for (int i = 1; i < m; i++)
						{
							p = p->next;
							q = q->next;
						}
				cout << q->order;
				num++;
				if (num == 10) {
					cout << endl;
					num = 0;
				}
				else
					cout << " ";
				p->next = q->next;
				free(q);
				q = p->next;
	}
	cout << q->order << endl;
	free(q);
	getchar();
	getchar();
	return 0;
}