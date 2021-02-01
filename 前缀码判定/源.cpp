#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define END 1
#define NOTEND 0
#define LEFT '0'
#define RIGHT '1'
char str[100000];
typedef struct node {
	int flag;
	struct node* lchild;
	struct node* rchild;
}NODE;
NODE* root;
NODE* p;
int flag = 0;
void Creatnode(int lenth, int loop) {
	if (str[loop] == LEFT) {	
		if (p->lchild == NULL) {
			NODE* nw = (NODE*)malloc(sizeof(NODE));
				p->lchild = nw;
				nw->lchild = nw->rchild = NULL;
				p = nw;
				if (loop + 1 == lenth) {
					p->flag = END;
				}
				else {
					p->flag = NOTEND;
					Creatnode(lenth, loop + 1);
				}
	}
		else if (p->lchild != NULL) {
			p = p->lchild;
			if (loop + 1 == lenth) {
				if (p->flag == END)
					flag = 1;
				p->flag = END;
			}
				
			else {
				Creatnode(lenth, loop + 1);
			}
		}
	}
	else if (str[loop] == RIGHT) {
		if (p->rchild == NULL) {
			NODE* nw = (NODE*)malloc(sizeof(NODE));
			p->rchild = nw;
			nw->lchild = nw->rchild = NULL;
			p = nw;
			if (loop + 1 == lenth) {
				p->flag = END;
			}
			else {
				p->flag = NOTEND;
				Creatnode(lenth, loop + 1);
			}
		}
		else if (p->rchild != NULL) {
			p = p->rchild;
			if (loop + 1 == lenth) {
				if (p->flag == END)
					flag = 1;
				p->flag = END;
			}

			else {
				Creatnode(lenth, loop + 1);
			}
		}
	}
	return;
}
void visit(NODE*nw) {
	if (nw->flag == NOTEND) {
		if (nw->lchild != NULL)
			visit(nw->lchild);
		if (nw->rchild != NULL)
			visit(nw->rchild);
	}
	if (flag == 1) {
		return;
	}
	if (nw->flag == END && (nw->lchild != NULL || nw->rchild != NULL)) {
		flag = 1;
		return;
	}
	return;
}
int main() {
	root = (NODE*)malloc(sizeof(NODE));
	root->flag = NOTEND;
	root->lchild = NULL;
	root->rchild = NULL;
	int N;
	scanf("%d", &N);
	while (N--) {
		p = root;
		scanf("%s", str);
		int lenth = strlen(str);
		if (lenth == 0) {
			printf("\n");
			return 0;
		}
		Creatnode(lenth, 0);
		visit(root);
		if (flag) {
			printf("%s\n", str);
			break;
		}
	}
		if (flag == 0) {
			printf("YES\n");
		}
}