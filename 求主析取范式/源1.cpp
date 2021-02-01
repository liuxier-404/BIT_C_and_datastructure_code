#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
char input[1000];
bool yuan[30];
int explain[30];
int truetable[10000000];
int sum = 0;

int turnto(char ch) {
	switch (ch) {
	case '$':return -1;
	case '(':return 0;
	case '+':return 1;
	case '-':return 2;
	case '|':return 3;
	case '&':return 4;
	case '!':return 6;
	default:return 0;
	}
}

void process() {
	char yn[1000] = {'\0'};
	char ch[1000] = { '$' };
	int y = -1, c = 0;
	int lenth = strlen(input);
	for (int i = 0; i < lenth; i++) {
		if (input[i] >= 'a' && input[i] <= 'z')
			yn[++y] = input[i];
		else if (input[i] == '|' || input[i] == '&' || input[i] == '-' || input[i] == '+' || input[i] == '!') {
			while (turnto(input[i]) <= turnto(ch[c]))
				yn[++y] = ch[c--];
			ch[++c] = input[i];
		}
		else if (input[i] == '(')
			ch[++c] = '(';
		else if (input[i] == ')') {
			while (ch[c] != '(')
				yn[++y] = ch[c--];
			c--;

		}
	}
	while (c) yn[++y] = ch[c--];
	strcpy(input,yn);
}
void possiblity() {
	memset(yuan, 0, sizeof(yuan));
	int lenth = strlen(input);
	for (int i = 0; i < lenth; i++) {
		if (input[i] >= 'a' && input[i] < 'z')
			yuan[input[i] - 'a'] = true;
	}
	for (int i = 0; i < 26; i++) {
		if (yuan[i])
			sum++;
	}
	sum = (int)pow(2, sum);
}
int boti() {
	int result = 0;
	int quan = 1;
	for (int i = 25; i >=0; i--) {
		if (yuan[i]) {
			if (explain[i])
				result += quan;
			quan *= 2;
		}
	}
	return result;
}
int calc(int a, int b, int c) {
	switch (c) {
	case '&':return a * b;
	case '|':if (a + b==0) return 0; else return 1;
	case '-':if (a == 1 && b == 0) return 0; else return 1;
	case '+':return !((a + b) & 1);
	}
}
int deal() {
	int ch[1000];
	int c = -1;
	int lenth = strlen(input);
	for (int i = 0; i < lenth; i++) {
		if (input[i] >= 'a' && input[i] <= 'z') {
			ch[++c] = explain[input[i] - 'a'];
		}
		else if (input[i] == '!')
			ch[c] = (ch[c] + 1) & 1;
		else {
			int ans = calc(ch[c - 1], ch[c], input[i]);
				c--;
				ch[c] = ans;
		}
		
	}
	return ch[0];
}
void set() {
	int x = boti();
	int ans = deal();
	truetable[x] = ans;
}
void generate(char sr) {
	while (sr <= 'z' && yuan[sr - 'a'] == false) sr++;
	if (sr > 'z') {
		set();
		return;
	}
	explain[sr - 'a'] = 0;
	generate(sr+1);
	explain[sr - 'a'] = 1;
	generate(sr + 1);
}
void output() {
	int i = 0;
	while (i < sum && !truetable[i])
		i++;
	if (i >= sum) {
		printf("NO\n");
		
	}
	else {
		printf("YES\n");
		/*printf("m%d", i);
		for (i++; i < sum; i++)
			if (truetable[i])
				printf(" ¡Å m%d", i);
		printf(" ; ");*/
	}
	/*int j = 0;
	while (j < sum && truetable[j])
		j++;
	if (j >= sum) {
		printf("1\n");
	}
	else {
	printf("M%d", j);
	for (j++; j < sum; j++)
		if (!truetable[j]) 
			printf(" ¡Ä M%d", j);
	printf("\n");
	}*/

}


int main() {
	scanf("%s", input);
	process();
	possiblity();
	memset(truetable, 0, sizeof(truetable));
	memset(explain, 0, sizeof(explain));
	generate('a');
	output();
	return 0;
}