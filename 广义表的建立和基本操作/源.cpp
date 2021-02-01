#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;
#define MAXN 10000
char str[MAXN];
int main() {
	int start = 0;
	int end=0;
	int ifbreak = 0;
	scanf("%s", str);
	end = strlen(str) - 1;
	printf("generic list: %s\n",str);
	int command;
	while (cin>>command) {
		if (command == 1) {//È¡±íÍ·
			printf("destroy tail\nfree list node\ngeneric list: ");
			int top = -1;
			for (int i = start; i < strlen(str); i++) {
				if (str[i] == '(') {
					top++;
					if (top == 0)
						start = i + 1;
					continue;
				}
				if (str[i] == ')') {
					top--;
					if (top == 0) {
						end = i;
						break;
					}
					continue;
				}
				if (str[i] == ',' && top == 0) {
					end = i - 1;
					break;
				}
			}
			for (int i = start; i <= end; i++)
				printf("%c", str[i]);
			printf("\n");
			if (start == end)
				return 0;
			if (end - start == 1 && str[start] == '(' && str[end] == ')')
				return 0;
		}
		else if (command == 2) {
			printf("free head node\nfree list node\ngeneric list: ");
			int tot = -1;
			int Isempty = 0;
			for (int i = start; i < strlen(str); i++) {
				if (i == end) {
					Isempty = 1;
					break;
				}
				else if (str[i] == ')')
					tot--;
				else if (str[i] == '(')
					tot++;
				else if (str[i] == ',' && tot == 0) {
					str[i] = '(';
					start = i;
					break;
				}
			}
			if (Isempty) {
				cout << "()" << endl;
					continue;
			}
			for (int i = start; i <= end; i++) {
				printf("%c", str[i]);
			}
			printf("\n");
			if (start == end)
				return 0;
			if (end - start == 1 && str[start] == '(' && str[end] == ')')
				return 0;
		}
	}
	return 0;
}