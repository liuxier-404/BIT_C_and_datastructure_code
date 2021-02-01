#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX_RUNG_WAYS 105
int current_time;
int runways_number;
int off_cost_time;
int down_cost_time;
//飞机跑道
typedef struct runways{
	int free_time;
	int totaltime;
}Runways;
//飞机信息
typedef struct airplane {
	int airplane_ID;
	int start_wait_time;
	struct airplane* Next;
}Airplane;

Runways Airstrip[MAX_RUNG_WAYS];
Airplane* down_queue_head = NULL;
Airplane* down_queue_tail = NULL;
Airplane* off_queue_head = NULL;
Airplane* off_queue_tail = NULL;

//构造队列
Airplane* CreateQueue() {
	Airplane* p = (Airplane*)malloc(sizeof(Airplane));
	p->airplane_ID = p->start_wait_time = -1;
	p->Next = NULL;
	return p;
}

//进队函数
Airplane* PushQueue( int ID, int time) {
	Airplane* p = (Airplane*)malloc(sizeof(Airplane));
	p->Next = NULL;
	p->airplane_ID = ID;
	p->start_wait_time = time;
	return p;
}

//出队函数
Airplane PopQueue(Airplane* head,Airplane* tail) {
	Airplane* p;
	p = head->Next;
	head->Next = p->Next;
	if (head->Next == NULL) {
		if (tail == down_queue_tail) {
			down_queue_tail = down_queue_head;
		}
		else {
			off_queue_tail = off_queue_head;
		}
	}
	return *p;
}

//判断队列是否为空
int IsEmpty(Airplane* head) {
	if (head->Next == NULL)
		return 1;
	else
		return 0;
}



int main() {

	current_time = 0;
	int down_number, off_number;
	int if_end=0;
	int off_startnumber = 1, down_startnumber = 5001;
	int off_wait_time = 0, down_wait_time = 0;
	int if_airstrip_free = 1;
	int totaltime = 0;
	int total_down_number = 0, total_off_number = 0;
	Airplane a;
	scanf("%d%d%d", &runways_number, &down_cost_time, &off_cost_time);
	printf("Current Time: %4d\n", current_time++);
	for (int i = 1; i < runways_number+1; i++) {
		Airstrip[i].free_time = Airstrip[i].totaltime = 0;
	}
	//分别构建降落队列，起飞队列
	down_queue_head = CreateQueue();
	down_queue_tail = down_queue_head;
	off_queue_head = CreateQueue();
	off_queue_tail = off_queue_head;
	while (1) {
		if (!if_end) {
			scanf("%d%d", &down_number, &off_number);
			if (down_number < 0 && off_number < 0) {
				if_end = 1;
			}
		}
		for (int i = 0; i < down_number; i++) {
			down_queue_tail->Next=PushQueue(down_startnumber++, current_time);
			down_queue_tail = down_queue_tail->Next;
			total_down_number++;
		}
		for (int i = 0; i < off_number; i++) {
			off_queue_tail->Next=PushQueue(off_startnumber++, current_time);
			off_queue_tail = off_queue_tail->Next;
			total_off_number++;
		}
		for (int i = 1; i <= runways_number; i++) {
			if (Airstrip[i].free_time == 0) {
				if (!IsEmpty(down_queue_head)) {
					a = PopQueue(down_queue_head,down_queue_tail);
					Airstrip[i].free_time = down_cost_time;
					printf("airplane %04d is ready to land on runway %02d\n", a.airplane_ID, i);
					down_wait_time += current_time - a.start_wait_time;
					Airstrip[i].totaltime += down_cost_time;
				}
				else if (!IsEmpty(off_queue_head)) {
					a = PopQueue(off_queue_head,off_queue_tail);
					Airstrip[i].free_time = off_cost_time;
					printf("airplane %04d is ready to takeoff on runway %02d\n", a.airplane_ID, i);
					off_wait_time += current_time - a.start_wait_time;
					Airstrip[i].totaltime += off_cost_time;
				}
			}
		}
		if_airstrip_free = 1;
		printf("Current Time: %4d\n", current_time++);
		for (int i = 1; i <= runways_number; i++) {
			if (Airstrip[i].free_time != 0) {
				Airstrip[i].free_time--;
				if (!Airstrip[i].free_time) {
					printf("runway %02d is free\n", i);
				}
				else {
					if_airstrip_free = 0;
				}
			}
		}
		if (if_end && IsEmpty(off_queue_head) && IsEmpty(down_queue_head) && if_airstrip_free)
			break;
	}
	printf("simulation finished\n");
	printf("simulation time: %4d\n", --current_time);
	double land_average = (double)down_wait_time / total_down_number;
	printf("average waiting time of landing: %4.1f\n", land_average);
	double off_average = (double)off_wait_time / total_off_number;
	printf("average waiting time of takeoff: %4.1f\n", off_average);
	for (int i = 1; i <= runways_number; i++) {
		printf("runway %02d busy time: %4d\n", i, Airstrip[i].totaltime);
		totaltime += Airstrip[i].totaltime;
	}
	float pertime = ((float)totaltime) / runways_number* 100 / current_time;
	printf("runway average busy time percentage: %4.1f%%\n", pertime);
	return 0;
}