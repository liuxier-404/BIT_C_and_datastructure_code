#include <stdio.h>  
#include <stdlib.h>  

typedef struct node
{
	int    coef, exp;//coef是系数，exp是次数
	struct node* next;
} NODE;

void multiplication(NODE*, NODE*, NODE*);
void input(NODE*);
void output(NODE*);

void input(NODE* head)
{
	int flag, sign, sum, x;
	char c;

	NODE* p = head;

	while ((c = getchar()) != '\n')
	{
		if (c == '<')
		{
			sum = 0;
			sign = 1;
			flag = 1;
		}
		else if (c == '-')
			sign = -1;
		else if (c >= '0' && c <= '9')
		{
			sum = sum * 10 + c - '0';
		}
		else if (c == ',')
		{
			if (flag == 1)
			{
				x = sign * sum;
				sum = 0;
				flag = 2;
				sign = 1;
			}
		}
		else if (c == '>')
		{
			p->next = (NODE*)malloc(sizeof(NODE));
			p->next->coef = x;
			p->next->exp = sign * sum;
			p = p->next;
			p->next = NULL;
			flag = 0;
		}
	}
}

void output(NODE* head)
{
	while (head->next != NULL)
	{
		head = head->next;
		printf("<%d,%d>,", head->coef, head->exp);
	}
	printf("\n");
}

int main()
{
	NODE* head1, * head2, * head3;

	head1 = (NODE*)malloc(sizeof(NODE));
	input(head1);

	head2 = (NODE*)malloc(sizeof(NODE));
	input(head2);

	head3 = (NODE*)malloc(sizeof(NODE));
	head3->next = NULL;
	multiplication(head1, head2, head3);
	output(head3);
	getchar();
	return 0;
}
void multiplication(NODE* X, NODE* Y, NODE* result) {
	NODE* x = X;
	NODE* y = Y;
	NODE* z = result;
	NODE* begain = result;
	NODE* begain1 = result;
	int ifone = 0;
	while (y->next != NULL) {
		y = y->next;
		int b = y->coef;
		if (b == 0)
			continue;
		x = X;
		ifone = 1;
		while (x->next != NULL) {
			x = x->next;
			int a = x->coef;
			if (a == 0)
				continue;
			if (result->next==NULL) {
				NODE* p = (NODE*)malloc(sizeof(NODE));
				if (ifone) {
					ifone = 0;
					begain = z;
					begain1 = begain;
				}
				z->next = p;
				p->coef = a * b;
				p->exp = y->exp + x->exp;	
				z = z->next;
				p->next = NULL;
			}
			else {
				int c = x->exp + y->exp;
				if (c > z->exp) {
					NODE* p = (NODE*)malloc(sizeof(NODE));
					p->next = NULL;
					if (ifone) {
						begain = z;
						begain1 = begain;
						ifone = 0;
					}
					z->next = p;
					p->exp = c;
					p->coef = x->coef * y->coef;
					z = z->next;
				}
				else {
					NODE* p ;
					if (ifone)
						p = begain;
					else
						p = begain1;
						while (c > p->next->exp) {
							p = p->next;
						}
						if (c == p->next->exp) {
															if (ifone) {
																ifone = 0;
																begain = p;
																begain1 = begain; 
																p->next->coef += a * b;
															}
															else	if (begain1->next != NULL) {
																	p->next->coef += a * b;
																	begain1 = begain1->next;
															}
															
															
														}
						else if (c < p->next->exp) {
							NODE* q = (NODE*)malloc(sizeof(NODE));
							q->exp = c;
							q->coef = a * b;
							q->next = p->next;
							if (ifone) {
								ifone = 0;
								begain = q;
								begain1 = begain;
								p->next = q;
							}
							else if (begain1->next != NULL) {
								p->next = q;
								begain1 = begain1->next;
							}
							
							
						}
				}
			}
		}
	}
	int flag1 = 1;
	z = result;
	x = result->next;
	while (z->next != NULL) {
		if (x->coef == 0) {
			z->next = x->next;
			NODE* tem = x;
			x = x->next;
			free(tem);
		}
		else
		{
			flag1 = 0;
			x = x->next;
		}
		z = z->next;
		
	}
	if (flag1) {
		NODE* new = (NODE*)malloc(sizeof(NODE));
		result->next = new;
		new->coef = 0;
		new->exp = 0;
		new->next = NULL;
	}
}