#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
#define MAXN 101
char map[MAXN][MAXN];
char visit[MAXN][MAXN][51];
struct node {
	int x;
	int y;
	int steps;
	int time;
	node(int _x,int _y,int _steps, int _time):x(_x),y(_y),steps(_steps),time(_time){}
};
const int mx[] = { 0,0,1,-1 };
const int my[] = { 1,-1,0,0 };
int main()
{
	int T;
	int i, j;
	int n, m;
	int ans;
	int k;
	int x_in, y_in;
	int x_out, y_out;
	queue<node> q1;
	cin >> T;
	for (int icount = 0; icount < T; icount++)
	{
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		cin >> m >> n>>k;
		for(i=1;i<=m;i++)
			for (j = 1; j <= n; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 'S')
				{
					x_in = i;
					y_in = j;
				}
				if (map[i][j] == 'E')
				{
					x_out = i;
					y_out = j;
				}
			}
		q1.push(node(x_in, y_in, 0,0));
		visit[x_in][y_in][0] = 1;
		while (!q1.empty())
		{
			node tap = q1.front();
			q1.pop();
			if (tap.x == x_out && tap.y == y_out)
			{
					 ans = tap.steps;
					goto out;
			}
				for (j = 0; j < 4; j++)
				{
					int now_x = tap.x + mx[j];
					int now_y = tap.y + my[j];
					int now_time = (tap.time + 1)%k;
					if (now_x <= 0 || now_y <= 0 || now_x > m || now_y > n || map[now_x][now_y] == '#'||visit[now_x][now_y][now_time]==1)
						continue;
					if (map[now_x][now_y] == '*' && now_time != 0)
						continue;
					q1.push(node(now_x, now_y, tap.steps + 1, now_time));
					visit[now_x][now_y][now_time] = 1;
				}
		}



		if (q1.empty())
		{
			printf("-1\n");
		}
		else
			out:cout << ans << endl;
		while (!q1.empty())
		{
			q1.pop();
		}
	}
	return 0;
}