#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <malloc.h>
#include<string.h>
//#include <windows.h>

//IDA�궨��
#define _BYTE  unsigned char
#define _WORD  unsigned short
#define _DWORD unsigned int 
#define _QWORD unsigned long long
#define LOBYTE(x)   (*((_BYTE*)&(x)))   // low byte
#define LOWORD(x)   (*((_WORD*)&(x)))   // low word
#define LODWORD(x)  (*((_DWORD*)&(x)))  // low dword
#define HIBYTE(x)   (*((_BYTE*)&(x)+1))
#define HIWORD(x)   (*((_WORD*)&(x)+1))
#define HIDWORD(x)  (*((_DWORD*)&(x)+1))

int getFileSize(FILE* fp);//��ȡ�ļ���С
void fillData(unsigned __int8* a2, FILE* fp);//�ļ����룬���ٿռ佫�ļ���ȡ��unsigned char* ָ���������
int char2uint(unsigned __int8* a2, int a3);//ida����ĺ�����һ
char* decodeXOR(const unsigned __int8* a3, int a4);//ida����ĺ������
__int64 decodeXOR(__int64 a1, __int64 a2, __int64 a3, __int64 a4);
void output(char* out, FILE* fpout); //�ļ����
void decode(char* path);//decode���������������к���
__int64 xxtea_decrypt(__int64 a1, __int64 a2, __int64 a3, unsigned int a4, _DWORD* a5);
unsigned __int8* sub_7C1FFC(int a1, int a2, unsigned __int8* a3, unsigned int* a4);
void* sub_7C1D0C(int a1, unsigned int a2, int a3, unsigned int* a4);
__int64 sub_725D952854(__int64 a1, __int64 a2, unsigned __int8* a3, unsigned int* a4);
__int64 __fastcall sub_725D95253C(__int64 a1, unsigned int a2, int a3, unsigned int* a4);
//main�������ҵ�ǰĿ¼�����ļ�����decode���н���#pragma once
