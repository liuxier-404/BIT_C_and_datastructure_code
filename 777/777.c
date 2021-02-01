#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10005
#define MOD 100000000
#define RS 4000
struct INT {
	int a[MAX];
};
struct REU {
	int a[RS+5];
};
struct REU one;
//减法
struct REU Sub(struct REU x, struct REU y) {
	for (int i = RS; i >= 0; i--) {
		x.a[i] -= y.a[i];
	}
	for (int i = RS; i; i--) {
		if (x.a[i] < 0) {
			x.a[i] += MOD;
			x.a[i - 1]--;
		}
	}
	return x;
}
//加法
struct REU Add(struct REU x, int y) {
	x.a[RS] += y;
	for (int i = RS; i >= 0; i--) {
		if (x.a[i] < MOD)
			break;
		else {
			x.a[i - 1] += x.a[i] / MOD;
			x.a[i] %= MOD;
		}
	}
	return x;
}
//乘法
struct REU Mul(struct REU x, int y) {
	int t;
	for (t = 0; t <= RS; t++) {
		if (x.a[t] != 0)
			break;
	}
	for (int i = RS; i >= t; i--) {
		x.a[i] *= y;
	}
	t--;
	for (int i = RS; i >= t; i--) {
		if (x.a[i] >= MOD) {
			x.a[i - 1] += x.a[i] / MOD;
			x.a[i] %= MOD;
		}
	}
	return x;
}
//计算1-该数字的含7数字的数量
struct REU NUM(char* str) {
	struct REU re;
	memset(re.a, 0, sizeof(re.a));
	int flag = 0;
	int len;
	struct INT shuzi;
	struct REU number1;
	struct REU number2;
	memset(number1.a, 0, sizeof(number1.a));
	memset(number2.a, 0, sizeof(number2.a));
	if (strcmp(str, "7") == 0)
	{
		re.a[RS] = 1;
		return re;
	}
	len = strlen(str);
	for (int i = 0; i < len; i++) {
		shuzi.a[i] = str[i] - '0';
	}
	number1.a[RS] = shuzi.a[0];
	number2.a[RS] = shuzi.a[0];
	if (shuzi.a[0] == 7)
		flag = 1;
	if (shuzi.a[0] > 7)
		number2.a[RS]--;
	for (int i = 1; i < len; i++) {
		number1 = Mul(number1, 10);
		number1 = Add(number1, shuzi.a[i]);
		number2 = Mul(number2, 9);
		if (flag == 0) {
			number2 = Add(number2, shuzi.a[i]);
			if (shuzi.a[i] > 7) {
				number2 = Sub(number2, one);
			}
			if (shuzi.a[i] == 7)
				flag = 1;
		}
	}
	re = Sub(number1, number2);
	if (flag && len > 1)
		re = Add(re, 1);
	return re;
}
//输出函数
void Myprint(struct REU x) {
	int flag = 0;
	int i;
	for (i = 0; i <RS; i++) {
		if (x.a[i] != 0) {
			flag = 1;
			break;
		}
	}
	if (flag==0)
	{
		printf("%d\n",x.a[RS]);
		return;
	}
	printf("%d", x.a[i]);
	for (i++; i <= RS; i++)
	{
		printf("%08d", x.a[i]);
	}
	printf("\n");
}
int main() {
	int T;
	char lstr[MAX];
	char rstr[MAX];
	struct REU re;
	scanf("%d", &T);
	memset(one.a, 0, sizeof(one.a));
	one.a[RS] = 1;
	while (T--) {
		struct REU lre;
		struct REU rre;
		memset(lstr, 0, sizeof(lstr));
		memset(rstr, 0, sizeof(rstr));
		memset(re.a, 0, sizeof(re.a));
		scanf("%s%s", lstr, rstr);
		lre = NUM(lstr);
		rre = NUM(rstr);
		re = Sub(rre, lre);
		int flag = 0;
		for (int i = 0; lstr[i]; i++) {
			if (lstr[i] == '7') {
				flag = 1;
				break;
			}
		}
		if (flag)
			re=Add(re, 1);
		Myprint(re);
	}
	return 0;
}