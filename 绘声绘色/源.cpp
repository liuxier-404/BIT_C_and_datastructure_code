#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;
stack<int>a;
queue<int>b;
priority_queue<int>c;			//´ó¶¥¶Ñ
priority_queue<int, vector<int>, greater<int> >d;	//Ð¡¶¥¶Ñ
void Push(int number)
{
	a.push(number);
	b.push(number);
	c.push(number);
	d.push(number);
}
void Clear()
{
	while (!a.empty())
	{
		a.pop();
	}
	while (!b.empty())
	{
		b.pop();
	}
	while (!c.empty())
	{
		c.pop();
	}
	while (!d.empty())
	{
		d.pop();
	}
}
int main()
{
	int times;
	int op;
	int result;
	int number;
	int flag[4];
	int i, j;
	while (scanf("%d", &times) != EOF)
	{
		result = 0;
		memset(flag, 0, sizeof(flag));
		for (i = 0; i < times; i++)
		{
			cin >> op;
			cin >> number;
			if (op == 1)
				Push(number);
			else if (op == 2)
			{
				if (number != a.top())
				{
					flag[0] = 1;
				}
				if (number != b.front())
				{
					flag[1] = 1;
				}
				if (number != c.top())
				{
					flag[2] = 1;
				}
				if (number != d.top())
				{
					flag[3] = 1;
				}
				a.pop();
				b.pop();
				c.pop();
				d.pop();
			}
		}
		for (i = 0; i < 4; i++)
		{
			if (flag[i]==0)
				result++;
		}
		switch (result)
		{
		case 2:
		case 3:
		case 4:
		{
			cout << "not sure" << endl;
		}break;
		case 0:cout << "pool zls" << endl; break;
		case 1:
		{
			if (flag[0] == 0)
				cout << "stack" << endl;
			else if (flag[1] == 0)
				cout << "queue" << endl;
			else if (flag[2] == 0)
				cout << "big priority queue" << endl;
			else if (flag[3] == 0)
				cout << "small priority queue" << endl;
		}break;
		}
		Clear();
	}
	return 0;
}
