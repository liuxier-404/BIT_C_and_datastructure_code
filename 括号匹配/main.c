#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100010

int main()
{
	int T;
	int icount;//���еĺϷ��ַ���������
	int i, j;
	int len;
	int right;
	int left;
	int branumber[N][2];
	char ch[N];
	int sum = 0;
	scanf("%d", &T);
	//¼�����ţ����Ұ����ŵ�Ч����
	memset(branumber, 0, sizeof(branumber));
	for (j= 0; j < T;  j++)
	{
		right = 0;
		left = 0;
		scanf("%s", ch);
		len = strlen(ch);
		for (i = 0; i < len; i++)
		{
			if (ch[i] == '(')
				left++;
			if (ch[i] == ')')
			{
				if (left)
				{
					left--;
				}
				else
				{
					right++;
				}
			}
		}
		if (right != 0 && left != 0)
		{
			;
		}
		else if (right != 0)
		{
			branumber[right][1]++;
		}
		else if (left != 0)
		{
			branumber[left][0]++;
		}
		else if (left == 0 && right == 0)
		{
			sum++;
		}
	}
	sum /= 2;
	//���û��������Ե��ַ���
	for (i = 1; i < N; i++)
	{
		if (branumber[i][0] > branumber[i][1])
			sum += branumber[i][1];
		else
			sum += branumber[i][0];
	}
	printf("%d\n", sum);
	return 0;
}
