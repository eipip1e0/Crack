#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include "head.h"
#include<time.h>
#include<dos.h>
#include<conio.h>
#include <stdlib.h>
#include <windows.h>
#include <direct.h>
#include <io.h>
#include <string.h>



typedef    unsigned char  byte;   //��ʾ�ַ�
typedef    unsigned int   uint32; //�޷���32λ����

#define CUR_PATH_MAX  300

FILE* g_pfWrite = NULL;
byte pcFisrtName[50] = { '\0' };
void view(byte* pcTmp, uint32 u32TmpLen);


int main(int argc, char* argv[])
{
	byte pcFolderPath[CUR_PATH_MAX] = { '\0' };
	uint32 u32Circle = 0;
	uint32 u32FolderPathLen = 0;  //��ǰ�������е��ļ���·��ƫ��



	/* ����·���ַ�������ȡ�������е�·��(��������������) */
	if (argc < 1)
	{
		printf("argc��������!!!\n");
		system("pause");
		return 0;
	}
	u32Circle = 0;
	while (1)
	{
		if (argv[0][u32Circle] == '\\' || argv[0][u32Circle] == '/')
		{
			u32FolderPathLen = u32Circle;
			u32FolderPathLen++;
		}
		else if (argv[0][u32Circle] == '\0')  //���·���ַ��������յ�
		{
			break;
		}
		u32Circle++;
	}
	memcpy(pcFolderPath, argv[0], u32FolderPathLen);



	/* �����ڼ�¼������ļ� */
	g_pfWrite = fopen("E:\\result.txt", "w");
	if (g_pfWrite == NULL)
	{
		printf("���ļ�result.txtʧ��\n");
		return 0;
	}



	view(pcFolderPath, u32FolderPathLen);

	fclose(g_pfWrite);
	printf("�������!!!\n");
	getchar();

	return 0;
}


void view(byte* pcTmp, uint32 u32TmpLen)
{
	struct _finddata_t stFileInfo;
	long lHandle = 0;
	byte pcPath[CUR_PATH_MAX] = { '\0' };
	uint32 u32Len = 0;
	byte cFileNameLen = 0;


	memcpy(pcPath, pcTmp, u32TmpLen);
	u32Len = u32TmpLen;

	pcPath[u32Len++] = '*';
	pcPath[u32Len++] = '.';
	pcPath[u32Len++] = '*';

	lHandle = (long)_findfirst((char*)pcPath, &stFileInfo);  //�ҵ���һ���ļ�
	if (lHandle == -1)
	{
		return;
	}

	pcPath[--u32Len] = '\0';
	pcPath[--u32Len] = '\0';
	pcPath[--u32Len] = '\0';
	do
	{
		/*  �õ��ļ����ļ��е�����·�� */
		cFileNameLen = 0;
		while (1)
		{
			if (stFileInfo.name[cFileNameLen] == '\0')
			{
				break;
			}
			cFileNameLen++;
		}
		memcpy(pcPath + u32Len, stFileInfo.name, cFileNameLen);
		pcPath[u32Len + cFileNameLen] = '\0';

		/* �����ļ���Ϣ�ṹ��������ж��ļ������ļ��У��ļ��еĻ�����Ҫ��һ���������ݹ���� */
		if (stFileInfo.attrib & _A_SUBDIR) //��Ŀ¼
		{
			if (stFileInfo.name[0] == '.' && stFileInfo.name[1] == '\0')  //���ļ����ǡ�.��
			{
				continue;
			}
			if (stFileInfo.name[0] == '.' && stFileInfo.name[1] == '.' && stFileInfo.name[2] == '\0')  //���ļ����ǡ�..��
			{
				continue;
			}
			pcPath[u32Len + cFileNameLen] = '\\';
			view(pcPath, u32Len + cFileNameLen + 1);
		}
		else  //���ļ�
		{
				decode((char*)pcPath);
				fprintf(g_pfWrite, "%s", pcPath);
				printf("%s\n", pcPath);

		}
	} while (_findnext(lHandle, &stFileInfo) == 0);
	_findclose(lHandle);

	return;
}