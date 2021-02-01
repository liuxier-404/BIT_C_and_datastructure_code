#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
char str[100];
int du[100];
int side[100][100];
int order[100];
int numberdu[100];
int app[100];//出现过的节点
void Print(int ,int);
int main() {
	int begin;
	memset(du, 0, sizeof(du));
	memset(side, 0, sizeof(side));
	memset(app, 0, sizeof(app));
	memset(numberdu, 0, sizeof(numberdu));
	int flag = 0;
	scanf("%s", str);
	int length = strlen(str);
	if (length == 2) {
		printf("Degree of tree: 0\nNumber of nodes of degree 0: 0\n");
		return 0;
	}
	for (int i = 0; i < length; i++) {
		if (str[i] != '(' && str[i] != ')' && str[i] != ',') {
			begin = i, flag = 1;
			order[str[i] - 'a'] = i;
			app[str[i] - 'a'] = 1;
		}
		else
			continue;
		for (int j = begin + 1; j < length; j++) {
			if (str[j] == '(')
				flag++;
			else if (str[j] == ')')
				flag--;
			else if (str[j] != ',' && flag == 2) {
				side[str[begin]-'a'][str[j]-'a'] = 1;
			}
			if (flag == 0)
				break;
		}
	}
	for (int i = 0; str[i] > 'z' || str[i] < 'a'; i++)
		begin = i;
	begin = str[begin + 1] - 'a';
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (side[i][j] != 0)
				du[i]++;
		}
	}
	for (int i = 0; i < 100; i++) {
		if(app[i])
		numberdu[du[i]]++;
	}
	int maxdu=0;
	for (int i = 0; i < 100; i++)
		if (numberdu[i] != 0)
			maxdu = i;
	Print(0,begin);
	printf("Degree of tree: %d\n", maxdu);
	for (int i = 0; i <= maxdu; i++)
		printf("Number of nodes of degree %d: %d\n", i, numberdu[i]);
}
void Print(int n,int node) {
	for (int i = 0; i < n * 4; i++)
		printf(" ");
	printf("%c\n", node + 'a');
	for (int j = 0; j < 100; j++) {
		if (side[node][j]) {
			Print(n + 1, j);
		}
	}
}