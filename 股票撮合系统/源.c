#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int sysid = 0;
int location[10000];//负数代表卖，正数代表加，0表示不存在
int Min(int a, int b) {
	return a < b ? a : b;
}
typedef struct node {
	int order;//系统编码
	float price;//股票价格
	int num;//股票数量
	struct node* next;
}stock;

typedef struct {
	stock* head; 
	stock* rear;
}queue;

//建立两个股票数组，数组元素是队列的头指针
queue sell[10000];//方括号内数字代表股票名字
queue buy[10000];
void Intsell(int name) {
	sell[name].head = (stock*)malloc(sizeof(stock));
	sell[name].rear = (stock*)malloc(sizeof(stock));
	sell[name].head->next = sell[name].rear;
	sell[name].rear->next = NULL;
	sell[name].head->price = -1;
}
void Intbuy(int name) {
	buy[name].head = (stock*)malloc(sizeof(stock));
	buy[name].rear = (stock*)malloc(sizeof(stock));
	buy[name].head->next = buy[name].rear;
	buy[name].head->price = -1;
	buy[name].rear->next = NULL;
}

//小数在前
void Pushsell(int name, float price, int number) {
	stock* q=(stock*)malloc(sizeof(stock));
	stock* q1 = q;
	stock* pre=(stock*)malloc(sizeof(stock));
	stock* pre1 = pre;
	pre->next = sell[name].head;
	q->next = sell[name].head->next;
	while (q->next != sell[name].rear) {
		if (q->next->price > price&&q->next->price>=0)
			break;
		q = q->next;
		pre = pre->next;
	}
	stock* p = (stock*)malloc(sizeof(stock));
	p->num = number;
	p->price = price;
	p->order = ++sysid;
	location[sysid] = -name;
	p->next = q->next;
	pre->next->next = p;
	free(q1);
	free(pre1);
}
//大数在前
void Pushbuy(int name, float price, int number) {
	stock* pre = (stock*)malloc(sizeof(stock));
	stock* pre1 = pre;
	stock* q = (stock*)malloc(sizeof(stock));
	stock* q1 = q;
	pre->next = buy[name].head;
	q->next = buy[name].head->next;
	while (q->next != buy[name].rear) {
		if (q->next->price < price && q->next->price>=0)
			break;
		q = q->next;
		pre = pre->next;
	}
	stock* p = (stock*)malloc(sizeof(stock));
	p->next = q->next;
	pre->next->next = p;
	p->num = number;
	p->price = price;
	p->order = ++sysid;
	location[sysid] = name;
	free(q1);
	free(pre1);
}
void Popsell(int name) {
	stock* p;
	location[sell[name].head->next->order] = 0;
	p = sell[name].head->next;
	sell[name].head -> next = sell[name].head->next->next;
	free(p);
}
void Popbuy(int name) {
	stock* p;
	location[buy[name].head->next->order] = 0;
	p = buy[name].head->next;
	buy[name].head->next = buy[name].head->next->next;
	free(p);
}
void C1() {
	int name, number;
	float price;
	char b_or_s;
	float pricesell, pricebuy;
	int flag = 0;
	scanf("%d %f %d %c", &name, &price, &number, &b_or_s);
	if (b_or_s == 'b'){
		if (buy[name].head == NULL) {
			Intbuy(name);
		}
		if (number == 0) {
			sysid++;
			if (sell[name].head != NULL) {
				if (sell[name].head->next->price <= price && sell[name].head->next != sell[name].rear) {
					float deal = (sell[name].head->next->price + price) / 2;
					printf("orderid: %04d\n", sysid);
					printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d", deal, number, sysid);
					printf("  sellorder:%04d\n", sell[name].head->next->order);
					flag = 1;
				}
			}
		}
		else
			Pushbuy(name, price, number);
	}
	else if(b_or_s=='s'){
		if (sell[name].head == NULL)
			Intsell(name);
		if (number == 0) {
			sysid++;
			printf("orderid: %04d\n", sysid);
			flag = 1;
		}
		else
			Pushsell(name,price,number);
	}
	if(flag==0)
	printf("orderid: %04d\n", sysid);
	 while(1){//这个股票既有买也有卖
		 if (sell[name].head == NULL || buy[name].head == NULL)
			 break;
		 if (sell[name].head->next!=sell[name].rear  && buy[name].head->next != buy[name].rear) {
			 pricesell = sell[name].head->next->price;
			 pricebuy = buy[name].head->next->price;
			 if (pricesell > pricebuy)
				 break;
			 else {
				 float deal = (sell[name].head->next->price + buy[name].head->next->price) / 2;
				 int quan = Min(sell[name].head->next->num, buy[name].head->next->num);
				 if (b_or_s == 's') {
				 printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d", deal, quan, sell[name].head->next->order);
				 printf("  buyorder:%04d\n", buy[name].head->next->order);
				 }
				 else {
					 printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d", deal, quan, buy[name].head->next->order);
					 printf("  sellorder:%04d\n", sell[name].head->next->order);
				 }
				 sell[name].head->next->num -= quan;
				 buy[name].head->next->num -= quan;
				 if (buy[name].head->next->num == 0)
					 Popbuy(name);
				 if (sell[name].head->next->num == 0)
					 Popsell(name);
			 }
		 }
		 else break;
	}//while(1)
}
void C2() {
	int name;
	stock* p;
	scanf("%d", &name);
	printf("buy orders:\n");
	if (buy[name].head != NULL) {
	p = buy[name].head;
	while (p->next != buy[name].rear) {
			printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: b\n", p->next->order, name, p->next->price, p->next->num);
		p = p->next;
	}
	}
	printf("sell orders:\n");
	if (sell[name].head != NULL) {
		p = sell[name].head;
		while (p->next != sell[name].rear) {
			printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: s\n", p->next->order, name, p->next->price, p->next->num);
			p = p->next;
		}
	}
}

void C3() {
	int id;
	int name;
	scanf("%d", &id);
	if (location[id]==0)
		printf("not found\n");
	else{
		name = location[id];
		stock* p = (stock*)malloc(sizeof(stock));
		stock* p1 = p;
		stock* pre = (stock*)malloc(sizeof(stock));
		stock* pre1 = pre;
		stock* p2;
		if (name > 0) {
			p->next = buy[name].head->next;
			pre->next = buy[name].head;
			while (1) {
				if (p->next->order == id)
					break;
				p = p->next;
				pre = pre->next;
			}
			p2 = p->next;
			printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: b\n", id, name, p->next->price, p->next->num);
			pre->next->next = p->next->next;
			location[id] = 0;
		}
		else {
			name = -name;
			p->next = sell[name].head->next;
			pre->next = sell[name].head;
			while (1) {
				if (p->next->order == id)
					break;
				pre = pre->next;
				p = p->next;
			}
		p2 = p->next;
		printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: s\n", id, name, p->next->price,p->next->num);
		pre->next->next = p->next->next;
		location[id] = 0;
		}
		free(p1); free(p2); free(pre1);
	}
}


int main() {
	int command;
	memset(location, 0, sizeof(location[0]));
	while (1) {
		scanf("%d", &command);
		switch (command) {
		case 0: return 0;
		case 1: {C1(); break; }
		case 2: {C2(); break;}
		case 3: {C3(); break; }
		}
	}
}