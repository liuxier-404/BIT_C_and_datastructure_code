#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<Windowsx.h>
#include<string.h>
#define buf_size 4096 
void copyFile(char* fsource, char* ftarget)
{
	WIN32_FIND_DATA lpfindfiledata;
	HANDLE hfind = FindFirstFile(fsource, &lpfindfiledata);
	//��Դ�ļ�
	HANDLE hsource = CreateFile(fsource, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	//����Ŀ���ļ�
	HANDLE htarget = CreateFile(ftarget, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	//Դ�ļ��Ĵ�С	
	if (SetFileTime(htarget, &lpfindfiledata.ftCreationTime, &lpfindfiledata.ftLastAccessTime, &lpfindfiledata.ftLastWriteTime) == 0) printf("�����ļ�ʱ������ʧ��\n");
	LONG size = lpfindfiledata.nFileSizeLow - lpfindfiledata.nFileSizeHigh;
	DWORD wordbit;
	//�½�����������������	
	int* BUFFER = new int[size];
	//Դ�ļ�������	
	ReadFile(hsource, BUFFER, size, &wordbit, NULL);
	//Ŀ���ļ�д����	
	WriteFile(htarget, BUFFER, size, &wordbit, NULL);
	//�رվ��
	CloseHandle(hfind);
	CloseHandle(hsource);
	CloseHandle(htarget);
}
//��ԴĿ¼��Ϣ���Ƶ�Ŀ��Ŀ¼��
void mycp(char* fsource, char* ftarget)
{
	WIN32_FIND_DATA lpfindfiledata;
	WIN32_FIND_DATA lpfindfiledatatarget;
	char source[buf_size];
	char target[buf_size];
	lstrcpy(source, fsource);
	lstrcpy(target, ftarget);
	lstrcat(source, "\\*.*");
	lstrcat(target, "\\*.*");
	//printf("%s\n", source);
	//printf("%s\n", target);
	HANDLE hfind = FindFirstFile(source, &lpfindfiledata);
	HANDLE htarget = FindFirstFile(target, &lpfindfiledatatarget);

	if (hfind != INVALID_HANDLE_VALUE && htarget != INVALID_HANDLE_VALUE)
	{
		while (FindNextFile(hfind, &lpfindfiledata) != 0)
		{
			memset(source, '0', sizeof(source));
			memset(target, '0', sizeof(target));
			lstrcpy(source, fsource);
			lstrcat(source, "\\");
			lstrcpy(target, ftarget);
			lstrcat(target, "\\");
			lstrcat(source, lpfindfiledata.cFileName);
			lstrcat(target, lpfindfiledata.cFileName);
			//printf("f1:%s\n", source);
			//printf("f2:%s\n", target);

			if ((lpfindfiledata.dwFileAttributes) == 16)//�ж��Ƿ�ΪĿ¼(��ΪĿ¼FILE_ATTRIBUTE_DIRECTORY��16)			
			{
				//�жϸ�Ŀ¼�Ƿ�ǰĿ¼��Ŀ¼��.��ʾ��ǰĿ¼��..��ʾ��Ŀ¼
				if ((strcmp(lpfindfiledata.cFileName, ".") != 0) && (strcmp(lpfindfiledata.cFileName, "..") != 0))
				{
					//����Ȳ��ǵ�ǰĿ¼Ҳ���Ǹ�Ŀ¼����ݹ����mycp()����
					CreateDirectory(target, NULL);//ΪĿ���ļ�����Ŀ¼					
					mycp(source, target);//������Ŀ¼����		
					HANDLE sou = CreateFile(source, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
					HANDLE tar = CreateFile(target, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
					FILETIME create, access, change;
					GetFileTime(sou, &create, &access, &change);
					SetFileTime(tar, &create, &access, &change);
				}
			}
			else //����Ǹ��ļ��͵���copyFile()����
				copyFile(source, target);//ֱ�ӵ����ļ����ƺ���				
		}
	}
	else
	{
		printf("����ָ���ļ�·�����ļ�ʧ��!\n");
	}
	//lstrcpy(source, fsource);
	//lstrcpy(target, ftarget);
	//lstrcat(source, "\\*.*");
	//lstrcat(target, "\\*.*");
	//HANDLE sou = CreateFile(source, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
	//HANDLE tar = CreateFile(target, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
	//FILETIME create, access, change;
	//GetFileTime(sou, &create, &access, &change);
	//SetFileTime(tar, &create, &access, &change);
}
int main(int argc, char* argv[])
{
	WIN32_FIND_DATA lpfindfiledata;
	if (argc != 3)
	{
		printf("��������!\n");
	}
	else
	{
		if (FindFirstFile(argv[1], &lpfindfiledata) == INVALID_HANDLE_VALUE)
		{
			printf("����Դ�ļ�·��ʧ��!\n");
			exit(0);
		}
		if (FindFirstFile(argv[2], &lpfindfiledata) == INVALID_HANDLE_VALUE)
		{
			CreateDirectory(argv[2], NULL);//ΪĿ���ļ�����Ŀ¼		
		}
		mycp(argv[1], argv[2]);
		printf("�������!\n");
	}
	return 0;
}