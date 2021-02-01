#include <stdio.h>  
#include <stdlib.h>  

typedef struct node
{
	int         data;
	int yu;
	struct node* next;
} NODE;

void output(NODE*);
void change(int, int, NODE*);

void output(NODE* head)
{
	int k = 0;

	printf("0.");
	while (head->next != NULL && k < 50)
	{
		printf("%d", head->next->data);
		head = head->next;
		k++;
	}
	printf("\n");
}

int main()
{
	int n, m;
	NODE* head;

	scanf("%d%d", &n, &m);
	head = (NODE*)malloc(sizeof(NODE));
	head->next = NULL;
	head->data = -1;
	change(n, m, head);
	output(head);
	return 0;
}
void change(int n, int m, NODE* head) {
	int shang, yushu;
	int flag = 0;
	NODE* p=NULL;
	NODE* loop=NULL;
	NODE* q = NULL;
	while (1) {
		n *= 10;
	shang = n / m;
	yushu = n % m;
	flag = 0;
	if (head->next == NULL) {
		p = (NODE*)malloc(sizeof(NODE));
		p->data = shang;
		p->yu = yushu;
		p->next = NULL;
		head->next = p;
	}
	else {
			loop = head->next;
			while (loop->next != NULL) {
				if (loop->data == shang&&loop->yu==yushu) {
					flag = 1;
					break;
				}
				loop = loop->next;
			}
			if (flag) {
				p->next = loop;
				break;
			}
			q = p;
			p = (NODE *) malloc(sizeof(NODE));
			q->next = p;
			p->data = shang;
			p->yu = yushu;
			p->next = NULL;
			}
	if (yushu == 0)
				break;
			n = yushu;
	}
	
}