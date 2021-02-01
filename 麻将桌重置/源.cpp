#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
int width, lenth;
double x_c, y_c, r;
double x1, ya, x3, y3;
double x2, y2, x4, y4;
//ÔÚÔ²ÄÚ·µ»Ø1
double Abs(double a) {
	if (a < 0)
		return -a;
	else
		return a;
}
double Max(double a, double b) {
	return (a > b) ? a : b;
}
double Small(double a, double b) {
	return (a > b) ? b : a;
}
int Nei(double x_1, double y_1, double x_2, double y_2,double x_3,double y_3) {
	double a = x_1 - x_2;
	double b = y_1 - y_2;
	double c = x_1 - x_3;
	double d = y_1 - y_3;
	double s;
	s = a * c + b * d;
	if (s < 0)
		return 0;
	else
		return 1;
}
int Cir(double x,double y) {
	long long d;
	d = (x - x_c) * (x - x_c) + (y - y_c) * (y - y_c);
	double s;
	s = r * r;
	if (s >= d)
		return 1;
	else
		return 0;
}
int Blk(double x, double y) {

	if (Nei(x1, ya, x2, y2, x, y) == 0)
		return 0;
	if (Nei(x2, y2, x3, y3, x, y) == 0)
		return 0;
	if (Nei(x3, y3, x4, y4, x, y) == 0)
		return 0;
	if (Nei(x4, y4, x1, ya, x, y) == 0)
		return 0;
	return 1;
}
int main() {
	cin >> lenth >> width;
	cin >> x_c >> y_c >> r;
	cin >> x1 >> ya >>x3 >> y3;
	x2 = (x1 - ya + x3 + y3) / 2;
	y2 = (x1 + ya - x3 + y3) / 2;
	x4 = (x1 + ya + x3 - y3) / 2;
	y4 = (-x1 + ya + x3 + y3) / 2;
	for (int i = 0; i < lenth; i++) {
		for (int j = 0; j < width; j++) {
			if (Cir(i, j) || Blk(i, j))
				printf("/");
			else
				printf("\\");
		}
		printf("\n");
	}
	return 0;
}