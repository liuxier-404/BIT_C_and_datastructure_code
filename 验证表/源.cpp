#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<list>
#include<string>
using namespace std;
int main() {
	int number1, number2;
	int flag = 0;
	list<string> list1;
	list<string> list2;
	string str;
	cin >> number1;
	getchar();
	for (int i = 0; i < number1; i++) {
		getline(cin, str);
		list1.push_back(str);
	}
	cin >> number2;
	if (number2 == 0) {
		cout << "the LIST2 is NULL." << endl;
		return 0;
	}
	getchar();
	for (int i = 0; i < number2; i++) {
		getline(cin, str);
		list2.push_back(str);
	}
	list<string>::iterator iter1 = list1.begin();
	list<string>::iterator iter2 = list2.begin();
	int flag1 = 0;
	while (iter2 != list2.end()) {
		flag = 0;
		str = *iter2;
		iter1 = list1.begin();
		for (; iter1 != list1.end(); iter1++) {
			if (str == *iter1) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			flag1 = 1;
			cout << str << " is not in LIST1." << endl;
		}
		iter2++;
	}
	if (flag1 == 0) {
		cout << "the records of LIST2 are all in the LIST1." << endl;
	}
	list1.clear();
	list2.clear();
	return 0;
}