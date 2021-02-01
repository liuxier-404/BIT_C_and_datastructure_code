#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
char map[1002][1002];
int visit[1002][1002];	//��¼(x,y)������Ƿ񱻷��ʹ�����������ʹ�������Ϊ1��
//�жϵ��Ƿ�Ϸ�
struct node {
	int x;
	int y;				//		�ڵ�λ��
	int step;
	int time;			//��ǰǰ����ʱ��
	node(int _x, int _y, int _step,int _time) :x(_x), y(_y), step(_step), time(_time) {}
};
int main()
{
	int m, n;		//	��ͼ���к���
	int k;			//����һ����ǰ���Ĳ���
	int i, j;
	int taltime = 0;
	int ans = -2;
	const int mx[] = { 0,0,-1,1 };
	const int my[] = { 1,-1,0,0 };	//��Ӧ���������������߷�

	//��ʼ��
	memset(map, 0, sizeof(map));
	memset(visit, 0, sizeof(visit));
	queue<node> q1;
	int x_in, y_in;
	int x_out, y_out;
	//��������
	cin >> m >> n >> k;
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
			cin >> map[i][j];
	cin >> x_in >> y_in;
	cin >> x_out >> y_out;
	if (x_in == x_out && y_in == y_out)
	{
		printf("0\n");
		return 0;
	}
	q1.push(node(x_in, y_in, 0, 0));
	visit[x_in][y_in] = 1;
	while (!q1.empty())
	{
		node tap = q1.front();
		q1.pop();
		if (tap.x == x_out && tap.y == y_out)
		{
			ans = tap.time;
			break;
		}
		for (i = 0; i < 4; i++)
		{
			int now_x = tap.x ;
			int now_y = tap.y ;
			for (j = 0; j < k; j++)
			{
				now_x += mx[i];
				now_y += my[i];
				if (now_x <= 0 || now_y <= 0 || now_x > m || now_y > n || map[now_x][now_y] == '#')
				{
					break;
				}
				if (visit[now_x][now_y] == 1)
				{
					continue;
				}
				if (now_x== x_out && now_y== y_out)
				{
					ans = tap.time + 1;
					goto m;
				}
				q1.push(node(now_x, now_y, k+1, tap.time + 1));
				visit[now_x][now_y] = 1;
			}
				
		}
	}
	if (q1.empty())
	{
		printf("-1\n");
		return 0;
	}
m:		printf("%d\n", ans);
	return 0;
}