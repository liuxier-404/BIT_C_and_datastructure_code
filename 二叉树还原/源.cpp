#include<cstring>
#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
typedef struct tree {
	char data;
	struct tree* lchild;
	struct tree* rchild;
	struct tree* next;
}TREE;
TREE* head = NULL;
TREE* tail = NULL;
char lmr[50];
char lrm[50];
int visit[50];



TREE* Createtree(int a, int b, int n,int m) {
	int poition;
	char ch = lrm[m];
	int flag = 0;
	for (int i = a; i <= b; i++) {
		if (ch == lmr[i]) {
			flag = 1;
			poition = i;
			break;
		}
	}
	if (!flag)
		return NULL;
	TREE* root = (TREE*)malloc(sizeof(TREE));
	root->data = ch;
	if (a == b & poition == a) {
		root->lchild = NULL;
		root->rchild = NULL;
	}
	else if (poition == a) {
		root->lchild = NULL;
		root->rchild = Createtree(poition + 1, b,n, m - 1);
	}
	else if (poition == b) {
		root->rchild = NULL;
		root->lchild = Createtree(a, poition - 1,n, m - 1);
	}
	else {
		root->lchild = Createtree(a, poition - 1, n,n-a+poition  - 1);
		root->rchild = Createtree(poition + 1, b,n+poition-a, m - 1);
	}
	return root;
}
void Pop() {
	head->next = head->next->next;
	if (head->next == NULL)
		tail = head;
}

void Push(TREE* p) {
	tail->next = p;
	p->next = NULL;
	tail = tail->next;
}
int main() {
	scanf("%s", lmr);
	scanf("%s", lrm);
	int lenth = strlen(lmr);
	int l1, l2, m;
	l2 = lenth-1;
	l1 = m = 0;
	TREE* root = NULL;
	root = Createtree(l1, l2,l1,l2);
	 head = (TREE*)malloc(sizeof(TREE));
	head->next = NULL;
	tail = head;
	if (root)Push(root);
	TREE* ans;
	while (head->next != NULL) {
		ans = head->next;
		printf("%c", ans->data);
		Pop();
		if (ans->lchild != NULL)
			Push(ans->lchild);
		if (ans->rchild != NULL)
			Push(ans->rchild);
	}
	cout << endl;
	return 0;
}