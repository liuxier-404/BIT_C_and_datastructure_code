#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;
typedef struct node1 {
	int element;
	struct node1* next;
}NODE;
NODE* al[1000];
int visited[1000];
int order[1000];
queue<int> list;
int loop=0;
void Intnode(int a, int ele) {
	NODE* nw = (NODE*)malloc(sizeof(NODE));
	nw->next = al[a]->next;
	nw->element = ele;
	al[a] ->next= nw;
}
void Putnode(int i) {
	NODE* p = al[i];
	while (p->next != NULL) {
		if (p->next->next == NULL)
			printf(" %d", p->next->element);
		else
			printf(" %d", p->next->element);
		p = p->next;
	}
	printf("\n");
}
void bfs(int nw) {
	NODE* p = al[nw];
	//if (p == NULL)
		//return;
	while (p->next != NULL) {
		if (visited[order[p->next->element]] == 0) {
			visited[order[p->next->element]] = 1;
			list.push(order[p->next->element]);
		}
		p = p->next;
	}
}
int main() {
	char ch;
	int nodenumber = 0;
	memset(visited, 0, sizeof(visited));
	while (1) {
		ch = getchar();
		if (ch == '*') break;
		order[nodenumber] = ch - 'a';
		al[ch-'a'] = (NODE*)malloc(sizeof(NODE));
		al[ch - 'a']->next= NULL;
		nodenumber++;
		getchar();
	}
	while (1) {
		int a, b;
		scanf("%d,%d", &a, &b);
		if (a == -1 && b == -1)
			break;
		Intnode(order[a], b);
		Intnode(order[b], a);
	}
	printf("the ALGraph is\n");
	for (int i = 0; i < nodenumber; i++) {
		printf("%c", order[i]+ 'a');
		Putnode(order[i]);
	}
	printf("the Breadth-First-Seacrh list:");
	for (int i = 0; i < nodenumber; i++) {
		if (visited[order[i]] == 0) {
			if (list.empty()) {
				list.push(order[i]);
				visited[order[i]] = 1;
			}
			while (!list.empty()) {
			int n = list.front();
			list.pop();
			printf("%c", n + 'a');
			bfs(n);
			}
		}
	}
	printf("\n");
}