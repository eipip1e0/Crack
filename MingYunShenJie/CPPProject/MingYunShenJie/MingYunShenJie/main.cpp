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



typedef    unsigned char  byte;   //表示字符
typedef    unsigned int   uint32; //无符号32位整型

#define CUR_PATH_MAX  300

FILE* g_pfWrite = NULL;
byte pcFisrtName[50] = { '\0' };
void view(byte* pcTmp, uint32 u32TmpLen);


int main(int argc, char* argv[])
{
	byte pcFolderPath[CUR_PATH_MAX] = { '\0' };
	uint32 u32Circle = 0;
	uint32 u32FolderPathLen = 0;  //当前程序运行的文件夹路径偏移



	/* 遍历路径字符串，获取程序运行的路径(不包括程序名称) */
	if (argc < 1)
	{
		printf("argc参数错误!!!\n");
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
		else if (argv[0][u32Circle] == '\0')  //如果路径字符串到了终点
		{
			break;
		}
		u32Circle++;
	}
	memcpy(pcFolderPath, argv[0], u32FolderPathLen);



	/* 打开用于记录结果的文件 */
	g_pfWrite = fopen("E:\\result.txt", "w");
	if (g_pfWrite == NULL)
	{
		printf("打开文件result.txt失败\n");
		return 0;
	}



	view(pcFolderPath, u32FolderPathLen);

	fclose(g_pfWrite);
	printf("程序结束!!!\n");
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

	lHandle = (long)_findfirst((char*)pcPath, &stFileInfo);  //找到第一个文件
	if (lHandle == -1)
	{
		return;
	}

	pcPath[--u32Len] = '\0';
	pcPath[--u32Len] = '\0';
	pcPath[--u32Len] = '\0';
	do
	{
		/*  得到文件或文件夹的完整路径 */
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

		/* 根据文件信息结构体的性质判断文件还是文件夹，文件夹的话就需要进一步分析，递归调用 */
		if (stFileInfo.attrib & _A_SUBDIR) //是目录
		{
			if (stFileInfo.name[0] == '.' && stFileInfo.name[1] == '\0')  //当文件夹是“.”
			{
				continue;
			}
			if (stFileInfo.name[0] == '.' && stFileInfo.name[1] == '.' && stFileInfo.name[2] == '\0')  //当文件夹是“..”
			{
				continue;
			}
			pcPath[u32Len + cFileNameLen] = '\\';
			view(pcPath, u32Len + cFileNameLen + 1);
		}
		else  //是文件
		{
				decode((char*)pcPath);
				fprintf(g_pfWrite, "%s", pcPath);
				printf("%s\n", pcPath);

		}
	} while (_findnext(lHandle, &stFileInfo) == 0);
	_findclose(lHandle);

	return;
}