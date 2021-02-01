#include <stdio.h>
#include<stdlib.h>
#include<math.h>
//要求：给出能够到达平衡态的步数
int main() {
	int heapnumber;
	int heap[1000];
	int heap1[1000];
	int steps;
	int type;
	int sum;
	int max = 0;
	int wei;
	int number;
	while (1) {
		scanf("%d", &heapnumber);
		if (!heapnumber)
			break;
		type = 0;
		max = 0;
		wei = 0;
		steps = 0;
		number = heapnumber;
		for (int i = 0; i < heapnumber; i++)
			scanf("%d", &heap[i]), heap1[i] = heap[i];
		while (number) {
			sum = 0;
			for (int i = 0; i < heapnumber; i++) {
					if (heap[i]) {
					sum += heap[i] % 2;
					heap[i] /= 2;
					if (heap[i] == 0)
						number--;
					}
				}
			if (sum % 2 == 1) {
				type = 1;
				max = wei;
				}
				wei++;
				}
		if (type == 0) {
			printf("0\n");
			continue;
	}
		int n = (int)pow(2, max);
		for (int i = 0; i < heapnumber; i++) {
			if ((heap1[i] /n)%2== 1)
				steps++;
		}
		printf("%d\n", steps);
	}
	return 0;
}