#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node {
	char e;
	struct node* next;
}NODE;
NODE* head;
NODE* p;
//创建栈
void CreateStack() {
	head = (NODE*)malloc(sizeof(NODE));
	head->next = NULL;
	head->e = NULL;
}
void Push(char ch) {
	NODE* p = (NODE*)malloc(sizeof(NODE));
	p->e = ch;
	p->next = head->next;
	head->next = p;
}
void Pop() {
	p = head->next;
	head->next = p->next;
	free(p);
}
int IfLetter(char ch) {
	if (ch <= 'Z' && ch >= 'A')
		return 1;
	else if (ch <= 'z' && ch >= 'a')
		return 1;
	else
		return 0;
}
int main() {
	int N;
	scanf("%d", &N);
	getchar();
	while (N--) {
		char ch;
		CreateStack();
		while ((ch = getchar()) && ch != '#') {
			if (IfLetter(ch))
				printf("%c", ch);
			else if (ch == '(')
				Push(ch);
			else if (ch == ')') {
				while (head->next->e != '(') {
					putchar(head->next->e);
					Pop();
				}
				Pop();
			}
			else {
				if (head->next == NULL) {
					Push(ch);
				}
				else {
					char ch1;
					int value1, value2;//栈里是value1，后来的是value2
					while (1) {
						if (head->next == NULL) {
								Push(ch);
								break;
								}
						switch (ch) {
						case '+':
						case '-': {value2 = 1; break; }
						case '*':
						case '/': {value2 = 2; break; }
						case '^': {value2 = 4; break; }
						default:break;
						}
						ch1 = head->next->e;
						switch (ch1) {
						case '+':
						case '-': {value1 = 1; break; }
						case '*':
						case '/': {value1 = 2; break; }
						case '^': {value1 = 3; break; }
						case '(': {value1 = -1; break; }
						}
						if (value1 >= value2) {
							putchar(ch1);
							Pop();
							continue;
						}
						else {
							Push(ch);
							break;
						}
					}
				}
			}

		}
		while (head->next != NULL) {
			putchar(head->next->e);
			Pop();
		}
		putchar('\n');
		ch=getchar();
	}

}