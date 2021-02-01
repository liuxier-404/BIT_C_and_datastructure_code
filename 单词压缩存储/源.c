#include <stdio.h>  
#include <stdlib.h>  

typedef struct sdata
{
	char  data;
	struct sdata* next;
} SNODE;

void setlink(SNODE*, char*), outlink(SNODE*);
int listlen(SNODE*);
SNODE* ziplist(SNODE*, SNODE*);
SNODE* findlist(SNODE*, SNODE*);

int main()
{
	SNODE* head1, * head2, * head;
	char str1[100], str2[100];

	gets(str1);
	gets(str2);

	head1 = (SNODE*)malloc(sizeof(SNODE));
	head2 = (SNODE*)malloc(sizeof(SNODE));
	head = (SNODE*)malloc(sizeof(SNODE));
	head->next = head1->next = head2->next = NULL;

	setlink(head1, str1);
	setlink(head2, str2);

	head->next = ziplist(head1, head2);

	head->next = findlist(head1, head2);
	outlink(head);
	return 0;
}

void setlink(SNODE* head, char* str)
{
	SNODE* p;

	while (*str != '\0')
	{
		p = (SNODE*)malloc(sizeof(SNODE));
		p->data = *str;
		p->next = NULL;
		str++;
		head->next = p;
		head = p;
	}
	return;
}

void outlink(SNODE* head)
{
	while (head->next != NULL)
	{
		printf("%c", head->next->data);
		head = head->next;
	}
	printf("\n");
	return;
}

int listlen(SNODE* head)
{
	int len = 0;
	while (head->next != NULL)
	{
		len++;
		head = head->next;
	}
	return len;
}

SNODE* findlist(SNODE* head1, SNODE* head2)
{
	int m, n;
	SNODE* p1 = head1, * p2 = head2;

	m = listlen(head1);
	n = listlen(head2);
	while (m > n)
	{
		p1 = p1->next;
		m--;
	}
	while (m < n)
	{
		p2 = p2->next;
		n--;
	}

	while (p1->next != NULL && p1->next != p2->next)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1->next;
}
SNODE* ziplist(SNODE* head1, SNODE* head2) {
	SNODE* p1, * p2;
	p1 = head1, p2 = head2;
	int lenth1,lenth2;
	lenth1 = listlen(head1);
	lenth2 = listlen(head2);
	if (lenth1 < lenth2) {
		while (lenth1 < lenth2) {
			p2 = p2->next;
			lenth2--;
		}
	}
	else if (lenth2 < lenth1) {
		while (lenth2 < lenth1) {
			p1 = p1->next;
			lenth1--;
		}
	}
	int flag = 0;
	SNODE* q1, * q2;//怀疑共同后缀起点
	q1 = p1, q2 = p2;
	while (p1->next->next != NULL) {
		if (p1->next->data != p2->next->data) {
			q1 = p1->next;
			q2 = p2->next;
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	if (p1->next->data != p2->next->data) {
		return NULL;
	}
	else
	{
		SNODE* fr = q2->next;
		SNODE* fr1 = fr;
		q2->next = q1->next;
		while (fr->next != NULL) {
			fr1 = fr1->next;
			free(fr);
			fr = fr1;
		}
		return q1->next;
	}
}
/*
SNODE* ziplist(SNODE* head1, SNODE* head2) {
	SNODE* p1 = head1, * p2 = head2;
	int len1 = listlen(head1), len2 = listlen(head2);
	while (len1 > len2)
	{
		p1 = p1->next;
		len1--;
	}
	while (len1 < len2)
	{
		p2 = p2->next;
		len2--;
	}
	SNODE* t1 = p1, * t2 = p2;
	while (p1->next->next != NULL)
	{
		if (p1->next->data != p2->next->data)
		{
			t1 = p1->next;
			t2 = p2->next;
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	if (p1->next->data != p2->next->data)
		return NULL;
	else
	{
		t2->next = t1->next;
		return t2->next;
	}
}*/