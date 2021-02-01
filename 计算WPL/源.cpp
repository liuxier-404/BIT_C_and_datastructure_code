#include <iostream>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <vector>
#include <cstring>


using namespace std;


priority_queue<int, vector<int>, greater<int>> q;


int main()
{
	int n;
	int data[1003];
	while (cin >> n) {
		while (!q.empty())	q.pop();
		for (int i = 0; i < n; i++) {
			cin >> data[i];
			q.push(data[i]);
		}
		int ans = 0;
		while (q.size() > 1) {
			int a = q.top(); 
			q.pop();
			int b = q.top(); 
			q.pop();
			q.push(a + b);
			ans += a + b;
		}
		cout << "WPL=" << ans << endl;
	}
	return 0;
}
