#include<stdio.h>
#include<math.h>
#include<string.h>
#define N 100001
char* Change(int a)
{
	int  b, k, i;
	char* p;
	int flag;
	char remainder[30];
	p = remainder;
	//定义了一个remainder数组，用来收集短除法除得的余数，栈倒序输出。
	k = 0;
	while (a != 0) {
		b = a / 2;
		k++;
		flag= a - b * 2;
		if(flag)
            remainder[k]='1';
        else
            remainder[k]='0';
		a = a / 2;
	};
	remainder[k+1]='\0';
	return p;
}
int Ten(char str[])
{
	int len;
	int i;
	int result = 0;
	len=strlen(str);
	for (i = 0; i < len; i++)
	{
		result += str[i]*pow(2, len - i - 1);
	}
	return result;
}
void Add()
{
	char stra[N];
	char strb[N];
	char* p;
	int a, b;
	int max;
	int i=0;
	int lenp;
	char ch;
	int lena,lenb;
	do {
		ch = getchar();
		if (ch != ' ')
			stra[i] = ch;
		else
			break;
		i++;
	} while (1);
	lena = i;
	stra[i] = '\0';
	i = 0;
	do {
		ch = getchar();
		if (ch != '\n')
			strb[i] = ch;
		else
			break;
		i++;
	} while (1);
	lenb = i;
	strb[i] = '\0';
	if (lena >= lenb)
	{
		printf("   %s\n", stra);
		printf("+");
		for (i = 0; i < lena - lenb + 2; i++)
			printf(" ");
		printf("%s\n", strb);
		for (i = 0; i < lena + 3; i++)
			printf("-");
		printf("\n");
	}
	else
	{
		for (i = 0; i < lenb - lena + 3; i++)
			printf(" ");
		printf("%s\n", stra);
		printf("+  %s\n",strb);
		for (i = 0; i < lenb+3; i++)
			printf("-");
		printf("\n");
	}
	if (lena > lenb)
		max = lena;
	else
		max = lenb;
	a = Ten(stra);
	b = Ten(strb);
	p = Change(a + b);
	lenp = strlen(p);
	for (i = 0; i < (max + 3 - lenp); i++)
		printf(" ");
	printf("%s\n", p);
}
int main()
{
	int T;
	int i;
	scanf("%d", &T);
	getchar();
	for (i = 0; i < T; i++)
	{
		Add();
	}
	return 0;
}
