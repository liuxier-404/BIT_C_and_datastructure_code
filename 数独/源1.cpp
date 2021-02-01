#include<cstdio>
#include <algorithm>
#include <climits>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int ch_hang(int hang);
void back(int u, int v);
int iCount = 0;			//旋转的最小次数
int flag = 0;
int record[4][4];
char map[16][16];
char l[16];
char map0[16][16];	//用于恢复数独
//表示大方块的行和列
void rot(int hang, int lie) {
	int x = (hang - 1) * 4;
	int y = (lie - 1) * 4;
	char mid[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mid[i][j] = map[x + j][y + 3 - i];
		}
	}
	for (int i = x; i < x + 4; i++)
		for (int j = y; j < y + 4; j++) {
			map[i][j] = mid[i - x][j - y];
		}
}
//u表示大行行数，v表示该行的第几块方块
int dfs(int u, int v) {
	if (flag)
		return 0;
	if (v == 4) {
		for (int icount = 0; icount < 4; icount++) {
			for (int i = 0; i < icount; i++)
				rot(u, v);
			record[u - 1][v - 1] = icount;
			if (ch_hang((u - 1) * 4 )== 0) {
				flag = 1;
				return 0;
			}
			else
			{
				back(u, v);
				record[u - 1][v - 1] = 0;
			}
		}
	}
	else
	{
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < i; j++)
				rot(u, v);
			record[u - 1][v - 1] = i;
			dfs(u, v + 1);
			if (ch_hang(4 *( u - 1))) {
				back(u, v);
			}
			else
			{
				flag = 1;
				return 0;
			}
		}
	}
	return 0;
}
void back(int u, int v) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			map[(u - 1) * 4 + i][(v - 1) * 4 + j] = map0[(u - 1) * 4 + i][(v - 1) * 4 + j];
		}
	}
}
//不满足为1，满足为0；
int ch_hang(int hang) {
	int f = 0;
	char ch;
	for (int i = 0; i < 15; i++) {
		ch = map[hang][i];
		for (int j = i + 1; j < 16; j++) {
			if (map[hang][j] == ch) {
				f = 1;
				return f;
			}
		}
	}
	return f;
}
int ch_line() {
	int f = 1;
	char ch;
	for (int i = 0; i < 15; i++) {
		ch = l[i];
		for (int j = i + 1; j < 16; j++) {
			if (ch == l[j])
			{
				f = 0;
				return f;
			}
		}
	}
	return f;
}
int Min(int a, int b) {
	return (a > b) ? b : a;
}
int main() {
	int T;
	int i, j;
	//表示大方格旋转的次数
	cin >> T;
	while (T--) {
		iCount = 0;
		flag = 0;
		memset(record, 0, sizeof(record));
		for (int i = 0; i < 16; i++) {
			scanf("%s", &map[i]);
			for (int j = 0; j < 16; j++) {
				map0[i][j] = map[i][j];
			}
		}
		//此处i为大行行数
		for (int i = 1; i < 5; i++) {
			flag = 0;
			dfs(i, 1);
		}
		int a, b, c, d;
		for (a = 0; a < 2; a++)
		{
			for (b = 0; b < 2; b++)
			{
				for (c = 0; c < 2; c++)
				{
					for (d = 0; d < 2; d++)
					{
						for (int i = 0; i < 4; i++)
							l[i] = map[i][a * 3];
						for (int i = 4; i < 8; i++)
							l[i] = map[i][b * 3];
						for (int i = 8; i < 12; i++)
							l[i] = map[i][c * 3];
						for (int i = 12; i < 16; i++)
							l[i] = map[i][d * 3];
						if (ch_line())
							goto m;
						for (int k = 0; k <= 3; k++)
							record[3][k] = (record[3][k] + 2) % 4;
					}
					for (int k = 0; k <= 3; k++)
						record[2][k] = (record[2][k] + 2) % 4;
				}
				for (int k = 0; k <= 3; k++)
					record[1][k] = (record[1][k] + 2) % 4;
			}
			for (int k = 0; k <= 3; k++)
				record[0][k] = (record[0][k] + 2) % 4;
		}
	m:			int anther = 0;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				iCount += record[i][j];
				anther += (record[i][j] + 2) % 4;
			}
		int result = Min(iCount, anther);
		cout << result << endl;
		for (int i=0; i < 4; i++)
			for (int j=0; j < 4; j++) {
				if (result == iCount)
					for (int k=0; k < record[i][j]; k++)
						cout << i + 1 << " " << j + 1 << endl;
				else
					for (int k = 0; k < (record[i][j] + 2) % 4; k++)
						cout << i + 1 << " " << j + 1 << endl;
			}
	}
	return 0;
}