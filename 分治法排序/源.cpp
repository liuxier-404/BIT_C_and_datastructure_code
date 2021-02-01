#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int arr[100];
int arr1[100];
int Swap(int& a, int& b) {
	int m = a;
	a = b, b = m;
	return 0;
}
//p代表当前数组的起点，n代表当前数组内的元素，实现升序排序
int Fsort(int* p, int start1, int end1, int end2) {
	int start2 = end1 + 1;
	if (end1 - start1 == 0)
		{
			if (end2 - start2 == 0)
			{
				if (p[start1] > p[start2])
					Swap(p[start1], p[start2]);
			}
			else if (end2 - start2 == 1)
			{
				Fsort(arr, start2, start2, end2);
			}
		}

}
int main() {
	int iNumber;
	memset(arr, 0, sizeof(arr));
	int i = 0;
	cout << "请输入需要排序数字的数量（小于一百个）" << endl;
	cin >> iNumber;
	while (iNumber--) {
		cin >> arr[i];
		i++;
	}
	
	return 0;
}