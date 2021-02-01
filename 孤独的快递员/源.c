#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int set;
int N;//环中站个数
int S;//货车最大容量
int Q;//B能放置货物的最大数量
//货车是栈结构
typedef struct truck {
	int terminus;//该货物的终点站
	struct truck* pre;
	struct truck* next;
}mytruck;
int cargo_number_in_truck = 0;//当前货车里的货物数量
mytruck* truck_head;
mytruck* truck_tail;

//入栈函数
void PushTruck(int a) {
	mytruck* new;
	new = (mytruck*)malloc(sizeof(mytruck));
	new->terminus = a;
	truck_tail->next = new;
	new->pre = truck_tail;
	truck_tail = new;
	truck_tail->next = NULL;
	cargo_number_in_truck++;
}

//出栈函数
int PopTruck() {
	int terminus;
	mytruck* f;
	f = truck_tail;
	terminus=truck_tail->terminus;
	truck_tail->pre->next = NULL;
	truck_tail = truck_tail->pre;
	cargo_number_in_truck--;
	free(f);
	return terminus;
}
//判断货车是否为空函数
int IsTruckEmpty() {
	if (cargo_number_in_truck==0)
		return 1;
	else
		return 0;
}

//B货台结构：队列
typedef struct platform {
	int cargo_contry;
	struct platform* next;
}myplatform;
//中心货物平台结构
typedef struct circul {
	int cargonumber;
	myplatform* head;
	myplatform* tail;
}mycircul;

mycircul center[105];
//初始化每个B平台队列
void CreatePlatform(int  contry) {
	center[contry].head = (myplatform*)malloc(sizeof(myplatform));
	center[contry].head->cargo_contry = -1;
	center[contry].head->next = NULL;
	center[contry].tail = center[contry].head;
	center[contry].cargonumber = 0;
}
//在某个国家的B平台队列上放包裹
void PushPlatform(int contry, int terminus) {
	myplatform* new = (myplatform*)malloc(sizeof(myplatform));
	center[contry].tail->next = new;
	new->cargo_contry = terminus;
	new->next = NULL;
	center[contry].tail = center[contry].tail->next;
	center[contry].cargonumber++;
}

//在某个国家的B平台上取东西
int PopPlatform(int contry) {
	int out;
	myplatform* f;
	f = center[contry].head;
	out = center[contry].head->next->cargo_contry;
	center[contry].head = center[contry].head->next;
	center[contry].cargonumber--;
	free(f);
	f = NULL;
	return out;
}
//判断某个国家的平台上是否还有货物
int IsPlatformEmpty(int contry) {
	if (center[contry].cargonumber==0)
		return 1;
	else
		return 0;
}
//判断是否货物中心所有的B平台已经为空
int IsCenterEmpty() {
	for (int i = 1; i <= N; i++) {
		if (IsPlatformEmpty(i))
			continue;
		else
			return 0;
	}
	return 1;
}
int main() {
	int totaltime;
	scanf("%d", &set);
	int loop=0;
	while (loop < set) {
		loop++;
		scanf("%d%d%d", &N, &S, &Q);
		//创建货车栈,现在是空车
		truck_head = (mytruck*)malloc(sizeof(mytruck));
		truck_head->next = NULL;
		truck_head->pre = NULL;
		truck_head->terminus = -1;
		truck_tail = truck_head;
		cargo_number_in_truck = 0; 
		totaltime = 0;
		int num;
		for (int i = 1; i <= N;i++) {
			scanf("%d", &num);
			//初始化中心的货物平台
			CreatePlatform(i);
			for (int j = 0; j < num; j++) {
				int cty;
				scanf("%d",&cty);
				PushPlatform(i, cty);
			}
		}

		for (int i = 1; i <= N;) {
			//卸货
			while ( cargo_number_in_truck>0) {
				totaltime++;
				int mid;
				mid = PopTruck();
				if (mid == i) {
					continue;
				}
				else {
					if (center[i].cargonumber >= Q) {
							PushTruck(mid);
							totaltime--;
							break;
					}
					else	
					PushPlatform(i, mid);
				}
			}
			//装货
			while (center[i].cargonumber > 0 && cargo_number_in_truck < S) {
				totaltime++;
				int mid;
				mid = PopPlatform(i);
				PushTruck(mid);
			}
			//判断是否全部货物已经分配完
			if (IsCenterEmpty() && IsTruckEmpty())
				break;
			if (i == N)
				i = 1;
			else
				i++;
			totaltime += 2;
		}
		free(truck_head);
		truck_head = NULL;
		for (int i = 1; i <= N; i++) {
			free(center[i].head);
			center[i].head = NULL;
		}
		printf("%d\n", totaltime);
	}
}