#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#define COMPUTER 0
#define PLAYER 1

using namespace std;
/////////////*全局变量*/////////////
char str[100];
int order[30];//每个节点出现顺序的编号
int side[30][30];//邻接矩阵
int maxheight[30];//该节点所有路径中最长的一调长度，也就是该节点的高度
int nodes[26];//出现过的节点；
int height[30][25];//节点所有可能的长度
/////////////*全局变量*/////////////
int turntoint(char ch) {
	return ch - 'a';
}
int max(int a, int b) {
	return a > b ? a : b;
}
int Height(int x) {
	if (maxheight[x] == 1) {
		height[x][0] = 1;
		return 1;
	}
	else {
		int loop = 0;
		for (int i = 0; i < 26; i++) {
			if (side[x][i]) {
				maxheight[x] = max(maxheight[x],Height(i)+1 );
			}
		}
		for (int i = 0; i < 26; i++) {
			if (side[x][i]) {
				int j = 0;
				while (height[i][j] != 0) {
					height[x][loop] = 1 + height[i][j];
					j++; loop++;
				}
			}
		}
	}
	return maxheight[x];
}
void leaves() {
	for (int i = 0; i < 26; i++) {
		if (nodes[i]) {
			int flag = 0;
			for (int j = 0; j < 26; j++) {
				if (side[i][j] != 0) {
					flag = 1; break;
				}
			}
			if (flag == 0) {
				maxheight[i] = 1;
			}
		}
	}
}
void ComputerFirst(int );
int Computer(int);
void PlayerFirst(int);
int Player(int);
int main() {
	int y_n;
	scanf("%s", str);
	memset(side, 0, sizeof(side));
	memset(maxheight, 0, sizeof(maxheight));
	memset(nodes, 0, sizeof(nodes));
	memset(order, 0, sizeof(order));
	int length = strlen(str);
	int flag = 0;
	int begin = 0;
	for (int i = 0; i < length; i++) {
		if (str[i] != '(' && str[i] != ')' && str[i] != ',') {
			begin = i, flag = 1;
			nodes[turntoint(str[i])] = 1;
			order[str[i] - 'a'] = i;
			printf("%c\n", str[i]);
		}
		else
			continue;
		for (int j = begin+1; j < length; j++) {
			if (str[j] == '(')
				flag++;
			else if (str[j] == ')')
				flag--;
			else if (str[j]!=',' && flag == 2) {
				side[turntoint(str[begin])][turntoint(str[j])] = 1;
			}
			if (flag == 0)
				break;
		}
	}
	leaves();
	for (int i = 0; str[i] > 'z' || str[i] < 'a'; i++) {
		begin = i;
	}
	Height(str[begin + 1]-'a');
	do {
		printf("Who play first(0: computer; 1: player )?\n");
		int command;
		scanf("%d", &command);
		switch (command) {
		case COMPUTER: {ComputerFirst(str[begin+1]-'a'); break; }
		case PLAYER: {PlayerFirst(str[begin+1]-'a'); break; }
		default:break;
		}
		printf("Continue(y/n)?\n");
		y_n = getchar();
		while (y_n == '\n') {
			y_n = getchar();
		}
	} while (y_n == 'y');
	return 0;
}
void ComputerFirst(int beign) {
	int node = beign;
	while (1) {
		node=Computer(node);
		if (maxheight[node] == 1) {
			printf("Sorry, you lost.\n");
			break;
		}
		char ch;
		int putnode;
		while (1) {
		printf("player:\n");
		ch = getchar();
		while (ch == '\n')
			ch = getchar();
		putnode = ch - 'a';
		if (side[node][putnode] == 1)
			break;
		printf("illegal move.\n");
		}
		node = putnode;
		if (maxheight[node] == 1) {
			printf("Congratulate, you win.\n");
			break;
		}
	}
}
void PlayerFirst(int begin) {
	int node = begin;
	while (1) {
		char ch;
		int putnode;
		while (1) {
			printf("player:\n");
			ch = getchar();
			while (ch == '\n')
				ch = getchar();
			putnode = ch - 'a';
			if (side[node][putnode] == 1)
				break;
			printf("illegal move.\n");
		}
		node = putnode;
		if (maxheight[node] == 1) {
			printf("Congratulate, you win.\n");
			break;
		}
		node = Computer(node);
		if (maxheight[node] == 1) {
			printf("Sorry, you lost.\n");
			break;
		}
	}
}
int Computer(int nownode) {
	int node=29;
	int node0=29;
	int samenuber = 0;
	int zuigao = 0;
	maxheight[node] = 10000;
	for (int i = 0; i < 26; i++) {
		if (side[nownode][i]) {
			int j = 0;
			int flag = 0;
			if (maxheight[i] >= zuigao) {
				if (maxheight[i] == zuigao && order[i] < order[node0]) {
					node0 = i;
				}
				else {
					zuigao = maxheight[i];
					node0 = i;
				}
			}
			while (height[i][j] != 0) {
				if (height[i][j] % 2 == 0)
				{
					flag = 1;
					break;
				}
				j++;
			}
			if (flag == 0 && maxheight[i] <= maxheight[node]) {
				if (maxheight[i] == maxheight[node]) {
					if (order[i] < order[node])
						node = i;
				}
				else node = i;
			}
		}
	}
	if (node == 29) {
		printf("computer: %c\n", node0 + 'a');
		return node0;
	}
	else {
		printf("computer: %c\n", node + 'a');
		return node;
	}
}