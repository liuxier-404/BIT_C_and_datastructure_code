#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<list>
#include<string>
using namespace std;
const string BEGIN("[Text]");
const string END("[/Text]");
list<string> text;
char strorder[200];
int flag = 0;
int cmp(const void* a, const void* b) {
	return (*(int*)a < *(int*)b) ? -1 : 1;
}
//����ı�����
void Output() {
	list<string>::iterator iter = text.begin();
	for (; iter != text.end(); iter++) {
		cout << *iter << endl;
	}
}
//�в��뺯��				i%d/��
void Insert() {
	int line0;
	string change;
	scanf("%d", &line0);
	while (getchar() != '/') { ; }
	getline(cin, change);
	for (int i = 0; i < change.size(); i++) {
		if (change[i] == '/' && i != 0 && change[i - 1] == '\\') {
			change.erase(i - 1,1);
			i--;
		}
	}
	if (line0 > text.size()) {
		text.insert(text.end(), change);
	}
	else {
		list<string>::iterator iter = text.begin();
		for (int i = 1; i < line0; iter++, i++);
		text.insert(iter, change);
	}
}
//�ı��滻����		c ���滻��/�滻��
void Replace() {
	string original;
	string now;	
	char ch;
	getchar();
	//=��һ���ַ����Ķ�ȡ
	while (1) {
		ch = getchar();
		if (ch == '/') {
			if (original[original.size() - 1] == '\\')
				original.erase(original.size() - 1);
			else
				break;
		}
		original.push_back(ch);
	}
	while (1) {
		ch = getchar();
		if (ch == '\n')
			break;
		if (ch == '/') {
			if (now[now.size() - 1] == '\\')
				now.erase(now.size() - 1);
		}
		now.push_back(ch);
	}
	//��ʼ�滻����
	int lenth1 = original.size();
	int lenth2 = now.size();
	list<string>::iterator iter = text.begin();
	int pos;
	for (; iter != text.end(); iter++) {
		pos = 0;
		while (pos < (*iter).size()) {
			pos = (*iter).find(original,pos);
			if (pos == -1)
				break;
			else {
				(*iter).replace(pos, lenth1, now);
				pos += lenth2;
			}
		}
	}
}
//��ɾ��							 d   #
void Delete() {
	int line0;
	scanf("%d", &line0);
	if (line0 > text.size())
		return;
	list<string>::iterator iter = text.begin();
	for (int i = 1; i < line0; iter++, i++);
	text.erase(iter);
}
//�кϲ�							f %d1/%d2/%d3...
void Merge() {
	int line = text.size();
	int de[2000];
	int line_now;
	char ch;
	int line_first;
	memset(de, 0, sizeof(de));
list<string>::iterator iter0 = text.begin();
	while (1) {
		scanf("%d", &line_first);
		getchar();
		if (line_first <= line)
			break;
	}
	for (int i = 1; i < line_first; iter0++, i++);
	list<string>::iterator iter1 = text.begin();
	int number = 0;
	while (1) {
		cin >> line_now;
		ch = getchar();
		if (line_now > line) {
			if (ch == '\n')
				break;
			else
			continue;
		}
		de[number] = line_now;
		number++;
		iter1 = text.begin();
		for (int i = 1; i < line_now; i++, iter1++);
		(*iter0).append((*iter1));
		if (ch == '\n') {
			break;
		}
	}
	qsort(de, number, sizeof(de[0]), cmp);
	iter1 = text.begin();
	for (int i = 0,j=1; de[i] > 0;i++ ) {
		iter1 = text.begin();
		for (j=1; j < de[i]-i; j++, iter1++);
		text.erase(iter1);
	}		
}
//���Ҵ�							q #%d/��
void Query() {
	if (flag == 0)
		Output();
		flag = 1;
		int line;
		string que;
		char ch;
		ch = getchar();
		while (ch != '#') { 
			ch = getchar();
		}
		scanf("%d", &line);
		if (line > text.size())
		{
			cout << "No" << endl;
			return;
		}
		getchar();
		while (1) {
			ch = getchar();
			if (ch == '\n')
				break;
			if (ch == '/') {
				if (que[que.size()- 1] == '\\')
					que.erase(que.size() - 1);
			}
			que.push_back(ch);
		}
		int flags = 1;
		list<string>::iterator iter = text.begin();
		for (int i=1; iter != text.end(); iter++,i++) {
			if (i==line) {
				if( (*iter).find(que, 0) == -1)
				flags = 0;
				break;
			}
		}
		if (flags)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
}
int main() {	
	string str1;
	char command;
	//�����ı�����
	while (1) {
		getline(cin, str1);
		if (str1.compare(BEGIN) == 0) {
			continue;
		}
		if (str1.compare(END) == 0) {
			break;
		}
		text.push_back(str1);
	}
	//������������	
	while (1) {
		command = getchar();
		if (command == EOF)
			break;
		memset(strorder, 0, sizeof(strorder));
		switch (command) {
		case 'i':Insert();break;
		case 'c':Replace(); break;
		case 'd':Delete();  break;
		case 'f':Merge(); break;
		case 'q': Query();  break;
		default:break;
		}
	}
	if (flag == 0) {
		Output();
	}
	return 0;
}