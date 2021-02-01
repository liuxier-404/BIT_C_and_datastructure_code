#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
#define MAXN 100000
char str[MAXN];//第几层；该层的的第几个元素
char visit[MAXN];	
int allnodes;//完全二叉树总节点
int nodes;//输入的总节点（包含了空元素）
int deep;//总层数
int loop;//记录总共输入的个数
int lft;
int num = 0;
int side = 1;
void swap(char& a, char& b) {
	char tem;
	tem = b;
	b = a;
	a = tem;
}
void Printleft() {
	int i;
	while (loop <= allnodes) {
		if (visit[loop] == 0) {
			visit[loop] = 1;
			lft--;
			if (str[loop] == '#' || str[loop] == '\0')
				;
			else {
				if(side!=1)
				for ( i = 0; i < 4 * (side - 1); i++)
					printf(" ");
				printf("%c\n", str[loop]);
			}
		}
		loop *= 2;
		side++;
	}
}
void MLR() {
	while (loop <= allnodes) {
		if (visit[loop] == 0) {
			visit[loop] = 1;
			lft--;
			if (str[loop] == '#' || str[loop] == '\0')
				;
			else {
				printf("%c", str[loop]);
			}
		}
		loop *= 2;
	}
}
void LMR() {
	while (loop * 2 <= allnodes) {
		loop *= 2;
	}
	if (visit[loop] == 0) {
		visit[loop] = 1;
		lft--;
		if (str[loop] != '#' && str[loop] != '\0') {
			printf("%c", str[loop]);
		}
	}
}
int main() {
	deep = 1;
	//输入部分
	char ch;
	loop = 0;
	memset(str, '\0', sizeof(str));
	int Iftwice = 0;
	while (1) {
		ch = getchar();
		if (ch == '\n')
			break;
		loop++;
		num++;
		if (num > side) {
			side*=2;
			deep++;
			num = 1;
		}
		str[loop]= ch;
	}

	cout << "BiTree" << endl;
	allnodes = (int)pow(2, deep) - 1;
	nodes = loop;
	//输出凹式
twice:
	memset(visit, 0, sizeof(visit));
	loop = 0;
	side = 1;
	 lft = allnodes;
		while (lft>0) {
			if(loop % 2 == 0) {
				loop++;
				Printleft();
			}
			else {
				loop /= 2; side--;
			}		
		}
//输出先序序列
		memset(visit, 0, sizeof(visit));
		lft = allnodes;
		loop = 0;
		cout << "pre_sequence  : " ;
		while (lft > 0) {
			if (loop % 2 == 0) {
				loop++;
				MLR();
			}
			else {
				loop /= 2;
			}
		}
		printf("\n");
		//输出中序序列
		memset(visit, 0, sizeof(visit));
		lft = allnodes;
		loop = 1;
		cout << "in_sequence   : ";
		LMR();
		while (lft > 0) {
			if (visit[loop]) {
				loop /= 2;
			}
			else {
				visit[loop] = 1;
				lft--;
				if (str[loop] == '#' || str[loop] == '\0')
					;
				else {
					printf("%c", str[loop]);
				}
				loop = loop*2 + 1;
				LMR();
			}
		}
		printf("\n");
//输出后序序列
		memset(visit, 0, sizeof(visit));
		lft = allnodes;
		loop = 1;
		cout <<"post_sequence : ";
		LMR();
		while (lft > 0) {
			loop /= 2;
			if (visit[loop * 2 + 1] == 1) {
				if (str[loop] == '#' || str[loop] == '\0')
					;
				else
				printf("%c", str[loop]);
				lft--;
				visit[loop] = 1;
			}
			else {
				loop = loop * 2 + 1;
				LMR();
			}
		}
		printf("\n");
		if (Iftwice==1)
			return 0;
//输出叶子节点个数
		int number = 0;
		for (int i = 1; i <= allnodes; i++) {
			if (str[i] == '\0' || str[i] == '#')
				continue;
				if ((str[i * 2] == '\0' || str[i * 2 ] == '#') && (str[2 * i+1] == '\0' || str[2 * i + 1] == '#'))
					number++;
		}
		printf("Number of leaf: %d\n", number);
//交换左右子树
		int flag = 1;
		int i, j;
		while (flag <= allnodes / 2 + 1) {
			for (i = flag, j = flag * 2 - 1; i < j; i++, j--) {
				swap(str[i], str[j]);
			}
			flag *= 2;
		}
		Iftwice = 1;
		printf("BiTree swapped\n");
		goto twice;
}