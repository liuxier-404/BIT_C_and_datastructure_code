#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#define N 200010
int lake[N];
using namespace std;
int main()
{
	int wide;
	int i, j;
	int last;
	int flag = 1;	//0代表不能，1代表能
	int max;
	stack< int> a;
	while (scanf("%d",&wide)!=EOF)
	{
		max = 0;
		flag = 1;
		memset(lake, 0, sizeof(lake));
		for (i = 0; i < wide; i++)
		{
			scanf("%d",&lake[i]);
			if (max < lake[i])
				max = lake[i];
 			if (a.size() == 0)
				a.push(lake[i]);
			else  
			{
				if (a.top() == lake[i])
				{
					a.pop();
				}
				else  if (a.top() < lake[i])
				{
					flag = 0;
				}
				else
				{
					a.push(lake[i]);
				}
			}
		}
		if (a.size() > 1)
			flag = 0;
		else if (a.size() == 1 && a.top() != max)
			flag = 0;
			if (flag)
				cout << "YES\n" ;
			else if(flag==0)
				cout << "NO\n" ;
			while (!a.empty())
			{
				a.pop();
			}
	}
	return 0;
}