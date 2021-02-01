#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct node1 {
	int num;
	struct node1* next;
}NODE1;//s1数字栈
NODE1* s1head;
typedef struct node2 {
	char ch;
	struct node2* next;
}NODE2;//s2运算符栈
NODE2* s2head;
void Creates1() {
	s1head = (NODE1 * )malloc(sizeof(NODE1));
	s1head->next = NULL;
	s1head->num = 0;
}
void Creates2() {
	s2head = (NODE2*)malloc(sizeof(NODE2));
	s2head->next = NULL;
s2head->ch = NULL;
}
void Pushs1(int n) {
	NODE1* new = (NODE1*)malloc(sizeof(NODE1));
	new->num = n;
	new->next = s1head->next;
	s1head->next = new;
}
void Pushs2(char c) {
	NODE2* new = (NODE2*)malloc(sizeof(NODE2));
	new->ch = c;
	new->next = s2head->next;
	s2head->next = new;
}
void Pops1() {
	NODE1* p;
	p = s1head->next;
	s1head->next = p->next;
	free(p);
}
void Pops2() {
	NODE2* p;
	p = s2head->next;
	s2head->next = p->next;
	free(p);
}
int Ifs1empty() {
	if (s1head->next == NULL)
		return 1;
	else
		return 0;
}
int Ifs2empty() {
	if (s2head->next == NULL)
		return 1;
	else
		return 0;
}
int Sizeofs1() {
	NODE1* p;
	p = s1head->next;
	int res = 0;
	while (p != NULL) {
		res++;
		p = p->next;
	}
	return res;
}
int Sizeofs2() {
	int res = 0;
	NODE2* p = s2head->next;
	while (p != NULL) {
		p = p->next;
		res++;
	}
	return res;
}
void Clears1() {
	NODE1* p = s1head->next;
	while (s1head->next != NULL) {
		s1head->next = p->next;
		free(p);
		p = s1head->next;
	}
}
void Clears2() {
	NODE2* p = s2head->next;
	while (s2head->next != NULL) {
		s2head->next = p->next;
		free(p);
		p = s2head->next;
	}
}
int main() {
	int N;
	char input[1000];
	scanf("%d\n", &N);
	Creates1();
	Creates2();
	while (N--) {
		char ch;
		int ifnegative = 0;
		int iferro = 0;
		int ifdivide = 0;
		int lenth, loop;
		for (loop = 0;; loop++) {
			ch = getchar();
			if (ch == '\n')
				break;
			input[loop] = ch;
		}
		lenth = loop;
		for (int i = 0; i < lenth; i++) {
			if (input[i] == '(') {
				if (i < lenth - 1 && ((input[i + 1] < '0') || (input[i + 1] > '9')) && (input[i + 1] != '('))
				{
					if (input[i + 1] == '-') {
						if (i < lenth - 2 && ((input[i + 2] <= '9') && (input[i + 2] >= '0')))
							continue;
					}
					iferro = 1; goto last;
				}
			}
			else if (input[i] == ')') {
				if (i > 0 && ((input[i - 1] < '0') || (input[i - 1] > '9')) && input[i - 1] != ')') {
					iferro = 1; goto last;
				}
			}
		}
		for (int i = 0; i < lenth; i++) {
			if (input[i] <= '9' && input[i] >= '0') {//转化字符串为数字
				long long sum = 0;
				if (i > 0 && input[i - 1] == '-') {
					if ((i > 1 && (input[i - 2] > '9' || input[i - 2] < '0')) || i == 1)
						ifnegative = 1;
				}
				while (i < lenth && input[i] <= '9' && input[i] >= '0') {
					sum = sum * 10 + input[i] - '0';
					i++;
				}
				i--;
				if (ifnegative) {
					sum = -sum;
					ifnegative = 0;
				}

				Pushs1(sum);
			}//转化字符串为数字
			else if (input[i] == '-' && (i == 0 || input[i - 1] < '0' || input[i - 1]>'9') && (i < lenth - 1 && input[i + 1] <= '9' && input[i + 1] >= '0')&&input[i-1]!=')')
				continue;
			else if (Ifs2empty())
				Pushs2(input[i]);
			else if (s2head->next->ch == '(' && input[i] != ')')
				Pushs2(input[i]);
			else if (input[i] == ')') {
				if (Ifs1empty() || Ifs2empty()) {
					iferro = 1;
					goto last;
				}
				while (s2head->next->ch != '(') {
					long long tem;
					tem = s1head->next->num;
					Pops1();
					if (Ifs1empty() || Ifs2empty()) {
						iferro = 1;
						goto last;
					}

					switch (s2head->next->ch) {
					case '+': {tem = tem + s1head->next->num; Pops1(); Pushs1(tem); break; }
					case '-': {tem = s1head->next->num - tem; Pops1(); Pushs1(tem); break; }
					case '*': {tem *= s1head->next->num; Pops1(); Pushs1(tem); break; }
					case '/': {
						if (tem == 0) {
							ifdivide = 1;
							goto last;
						}
						else {
							tem = s1head->next->num / tem; Pops1(); Pushs1(tem); break;
						}
					}
					case '^': {
						if (s1head->next->num < 0) { iferro = 1; goto last; }
						tem = pow(tem, s1head->next->num); Pops1(); Pushs1(tem); break;
					}
					default: {iferro = 1; goto last; }
					}
					Pops2();
					if (Ifs2empty()) {
						iferro = 1;
						goto last;
					}
				}
				Pops2();
			}
			else {
				int num1, num2;//num1是第一个取出来，num2是第二个取出来的数
				char ch1;
				int value1, value2;//value1 是栈内，value2是栈外
				while (1) {
					if (Ifs2empty()) {
						Pushs2(input[i]);
						break;
					}
					ch1 = s2head->next->ch;
					switch (ch1) {
					case '+':
					case '-': {value1 = 2; break; }
					case '*':
					case '%':
					case '/': {value1 = 4; break; }
					case '^': {value1 = 5; break; }
					case '(': {value1 = 0; break; }
					}
					switch (input[i]) {
					case '+':
					case '-': {value2 = 1; break; }
					case '*': {value2 = 3; break; }
					case '/': {value2 = 3; break; }
					case '%': {value2 = 3; break; }
					case '^': {value2 = 6; break; }
					case '(': {value2 = 7; break; }
					}
					if (value1 <= value2) {
						Pushs2(input[i]);
						break;
					}
					else if (value1 > value2) {
						if (Ifs1empty()) {
							iferro = 1;
							goto last;
						}
						num2 = s1head->next->num;
						Pops1();
						if (Ifs1empty()) {
							iferro = 1;
							goto last;
						}
						num1 = s1head->next->num;
						Pops1();
						switch (ch1) {
						case '+': {num1 += num2; Pushs1(num1); break; }
						case '-': {num1 = num1 - num2; Pushs1(num1); break; }
						case '*': {num1 *= num2; Pushs1(num1); break; }
						case '/': {
							if (num2 == 0) {
								ifdivide = 1;
								goto last;
							}
							num1 = num1 / num2; Pushs1(num1); break;
						}
						case '%': {num1 = num1 % num2; Pushs1(num1); break; }
						case '^': {
							if (num2 < 0) { iferro = 1; goto last; }
							num1 = pow(num1, num2); Pushs1(num1); break;
						}
						}
						Pops2();
					}//value1>=value2
				}
			}//用于计算和判断
		}//计算过程循环

		//计算剩余栈内的数据
		if (Sizeofs1() - Sizeofs2() != 1) {
			iferro = 1;
			goto last;
		}
		while (1) {
			int num1, num2;
			char ch1;
			num1 = s1head->next->num;
			Pops1();
			if (Ifs1empty()) {
				Pushs1(num1);
				break;
			}
			num2 = s1head->next->num;
			Pops1();
			ch1 = s2head->next->ch;
			Pops2();
			switch (ch1) {
			case '+': {Pushs1(num1 + num2); break; }
			case '-': {num1 = num2 - num1; Pushs1(num1); break; }
			case '*': {num1 *= num2; Pushs1(num1); break; }
			case '^': {
				if (num1 < 0) { iferro = 1; goto last; }
				num1 = pow(num2, num1); Pushs1(num1); break;
			}
			case '%': {num1 = num2 % num1; Pushs1(num1); break; }
			case '/': {if (num1 == 0)
			{
				ifdivide = 1;
				goto last;
			}
					num1 = num2 / num1; Pushs1(num1); break;
			}
			}
		}

	last: if (iferro)
		printf("error.\n");
	else if (ifdivide)
		printf("Divide 0.\n");
	else {
		printf("%d\n", s1head->next->num);
		Pops1();
	}
	Clears1();
	Clears2();


	}//最大循环
}