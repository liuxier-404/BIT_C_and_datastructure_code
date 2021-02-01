#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int set;
int N;//����վ����
int S;//�����������
int Q;//B�ܷ��û�����������
//������ջ�ṹ
typedef struct truck {
	int terminus;//�û�����յ�վ
	struct truck* pre;
	struct truck* next;
}mytruck;
int cargo_number_in_truck = 0;//��ǰ������Ļ�������
mytruck* truck_head;
mytruck* truck_tail;

//��ջ����
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

//��ջ����
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
//�жϻ����Ƿ�Ϊ�պ���
int IsTruckEmpty() {
	if (cargo_number_in_truck==0)
		return 1;
	else
		return 0;
}

//B��̨�ṹ������
typedef struct platform {
	int cargo_contry;
	struct platform* next;
}myplatform;
//���Ļ���ƽ̨�ṹ
typedef struct circul {
	int cargonumber;
	myplatform* head;
	myplatform* tail;
}mycircul;

mycircul center[105];
//��ʼ��ÿ��Bƽ̨����
void CreatePlatform(int  contry) {
	center[contry].head = (myplatform*)malloc(sizeof(myplatform));
	center[contry].head->cargo_contry = -1;
	center[contry].head->next = NULL;
	center[contry].tail = center[contry].head;
	center[contry].cargonumber = 0;
}
//��ĳ�����ҵ�Bƽ̨�����ϷŰ���
void PushPlatform(int contry, int terminus) {
	myplatform* new = (myplatform*)malloc(sizeof(myplatform));
	center[contry].tail->next = new;
	new->cargo_contry = terminus;
	new->next = NULL;
	center[contry].tail = center[contry].tail->next;
	center[contry].cargonumber++;
}

//��ĳ�����ҵ�Bƽ̨��ȡ����
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
//�ж�ĳ�����ҵ�ƽ̨���Ƿ��л���
int IsPlatformEmpty(int contry) {
	if (center[contry].cargonumber==0)
		return 1;
	else
		return 0;
}
//�ж��Ƿ�����������е�Bƽ̨�Ѿ�Ϊ��
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
		//��������ջ,�����ǿճ�
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
			//��ʼ�����ĵĻ���ƽ̨
			CreatePlatform(i);
			for (int j = 0; j < num; j++) {
				int cty;
				scanf("%d",&cty);
				PushPlatform(i, cty);
			}
		}

		for (int i = 1; i <= N;) {
			//ж��
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
			//װ��
			while (center[i].cargonumber > 0 && cargo_number_in_truck < S) {
				totaltime++;
				int mid;
				mid = PopPlatform(i);
				PushTruck(mid);
			}
			//�ж��Ƿ�ȫ�������Ѿ�������
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