#include "head.h"


int realSize;//文件的字节数

void decode(char* path)
{

    FILE* fp = fopen(path, "rb");
    //获取文件大小
    int fileSize = 0;
    fileSize = getFileSize(fp);
    printf("%d\n", fileSize);
    //开辟储存空间储存数据流
    unsigned __int8* a2 = (unsigned __int8*)malloc(fileSize);
    //装载数据
    fillData(a2, fp);
    fclose(fp);//记得关闭文件。
    char* out;
    out = (char*)decodeXOR(1LL,0,(__int64)a2, (__int64)fileSize);
    if (out == 0) {
       return;
    }
    FILE* fpout = fopen(path, "wb");
    output(out, fpout);
    fclose(fpout);
    printf("输出完毕");
}

void fillData(unsigned __int8* a2, FILE* fp) {
    int i = 0;
    rewind(fp);//记得重置文件头；
    while (!feof(fp))//判断文件是否已结束 
    {
        fread(&a2[i], sizeof(unsigned char), 1, fp);
        i++;

    }
    printf("循环次数%d\n", i);
}

void output(char* out, FILE* fpout) {
    int i = 0;
    for (; i < realSize; i++)
    {
        fwrite(&out[i], sizeof(char), 1, fpout);
    }
    printf("output字节数 %d\n", i);
}

int getFileSize(FILE* fp) {
    int fileSize = 0;
    if (fp == 0)
    {
        printf("fail to open the file1 !\n");
        return 0;
    }
    unsigned char c;
    while (!feof(fp))//判断文件是否已结束 
    {
        fread(&c, sizeof(unsigned char), 1, fp);
        fileSize++;
    }

    return --fileSize;
}


__int64 decodeXOR(__int64 a1, __int64 a2, __int64 a3, __int64 a4)//a3 字节数组 a4 数组长度
{
        unsigned __int8 v7; // w0
        unsigned int v8; // w20
        __int64 v9; // x12
        int v10; // w0
        unsigned __int8* v11; // x24
        __int64 v12; // x5
        int v13; // w14
        __int64 v14; // x22
        int v15; // w11
        int v16; // w7
        int v17; // w10
        int v18; // w9
        int v19; // w1
        int v20; // w6
        unsigned int v21; // w3
        int v22; // w1
        int v23; // w6
        int v24; // w1
        __int64 v25; // x22
        __int64 v26; // x26
        unsigned int v27; // w24
        __int64 v28; // x25
        unsigned int v29; // w2
        unsigned int v31; // w22
        unsigned int v33; // [xsp+64h] [xbp+64h] BYREF
        unsigned __int8 v34[16]; // [xsp+68h] [xbp+68h] BYREF
        void(__fastcall * v35)(unsigned __int8*, unsigned __int8*, __int64); // [xsp+78h] [xbp+78h]
        char v36[16]; // [xsp+88h] [xbp+88h] BYREF
        char zidian[] = "Copyright(C),2017,DragonPunchStorm Tech.Co.,Ltd.";

       

        v7 = memcmp((void*)a3, "@S#T$O%", 7);
        v8 = v7;
        if (v7)
            return 0;
        v9 = 7;
        v10 =0x30LL;
        v11 = (unsigned __int8*)(a3 + v9);//第8个字符
        v12 = (__int64)zidian;
        v13 = *(unsigned __int8*)(a3 + v9);//第8个字符的指针
        v14 = a4 - v9;
        v15 = v11[1];
        v16 = v15 + v13;
        v17 = v15 + v15 + v13;
        v18 = v15 + v13 + v17;
        v19 = v18 + v17 + v18;
        v20 = v17 + v18 + v19;
        if ((int)(v16 - 13 * ((unsigned int)((unsigned __int64)(1321528399LL * v16) >> 32) >> 2)) < 8)
            v21 = 8;
        else
            v21 = v16 - 13 * ((unsigned int)((unsigned __int64)(1321528399LL * v16) >> 32) >> 2);
        v36[0] = *(unsigned __int8*)(v12 + v13 - v13 / v10 * v10);
        v36[1] = *(unsigned __int8*)(v12 + v15 - v15 / v10 * v10);
        v36[2] = *(unsigned __int8*)(v12 + v16 - v16 / v10 * v10);
        v36[3] = *(unsigned __int8*)(v12 + v17 - v17 / v10 * v10);
        v36[4] = *(unsigned __int8*)(v12 + v18 - v18 / v10 * v10);
        v36[5] = *(unsigned __int8*)(v12 + v17 + v18 - (v17 + v18) / v10 * v10);
        v36[6] = *(unsigned __int8*)(v12 + v19 - v19 / v10 * v10);
        v36[7] = *(unsigned __int8*)(v12 + v20 - v20 / v10 * v10);
        if (v21 != 8)
        {
            v22 = v19 + v20;
            v36[8] = *(unsigned __int8*)(v12 + v22 - v22 / v10 * v10);
            if (v21 != 9)
            {
                v23 = v20 + v22;
                v36[9] = *(unsigned __int8*)(v12 + v23 - v23 / v10 * v10);
                if (v21 != 10)
                {
                    v24 = v22 + v23;
                    v36[10] = *(unsigned __int8*)(v12 + v24 - v24 / v10 * v10);
                    if (v21 == 12)
                        v36[11] = *(unsigned __int8*)(v12 + v23 + v24 - (v23 + v24) / v10 * v10);
                }
            }
        }
        if (false)//you a1
        {
            v25 = v14 - 2;
            v26 = (__int64)(v11 + 2);
            v27 = v25;
        }
        else
        {
            v26 = (__int64)(v11 + 6);
            v25 = v14 - 6;
            v27 = v11[5] | ((v11[4] | ((v11[3] | (v11[2] << 8)) << 8)) << 8);
        }
        if ((v25 & 0x8000000000000000LL) != 0)
            return 0;
        v33 = 0;
        v28 = xxtea_decrypt(v26, v27, (__int64)v36, v21, (_DWORD*)(&v33));
        
        
        v31 = v25 - v27;
        v28 = (__int64)realloc((void*)v28,v31+v33);
        memcpy((void*)(v28 + v33), (void*)(v26 + v27), v31);
        v29 = v31 + v33;
        v33 += v31;
        
        realSize = v33;
        return v28;



    }
__int64 xxtea_decrypt(__int64 a1, __int64 a2, __int64 a3, unsigned int a4, _DWORD* a5)
{
    unsigned int v5; // w19
    __int64 v8; // x24
    unsigned __int8* v9; // x23
    __int64 v10; // x19

    *a5 = 0;
    v5 = a2;
    if (a4 > 0xF)
        return sub_725D952854(a1, a2, (unsigned __int8*)a3, (unsigned int*)a5);
    v8 = a4;
    v9 = (unsigned __int8*)malloc(0x10u);
    memcpy((void*)v9, (const void*)a3, v8);
    memset(&v9[v8], 0LL, (unsigned int)(16 - v8));
    v10 = sub_725D952854(a1, v5, v9, (unsigned int*)a5);
    free(v9);
    return v10;
}
__int64 sub_725D952854(__int64 a1, __int64 a2, unsigned __int8* a3, unsigned int* a4)
{
    _DWORD* v6; // x21
    __int64 v7; // x22
    unsigned int v8; // w8
    int v9; // w2
    int v10; // w0
    unsigned int v11; // w4
    int v12; // w3
    int v13; // w1
    unsigned int v14; // w10
    __int64 i; // x1
    unsigned int v16; // w8
    unsigned int v17; // w9
    unsigned int v18; // w2
    unsigned int v19; // w5
    unsigned int v20; // w4
    int v21; // w2
    int v22; // w4
    unsigned int v23; // w23
    __int64 v24; // x0
    __int64 v25; // x24
    unsigned int v27; // [xsp+94h] [xbp+44h] BYREF

    v6 = (_DWORD*)sub_725D95253C(a1, a2, 0LL, &v27);
    v7 = (__int64)malloc(0x10u);
    *(__int64*)v7 = 0LL;
    *(__int64*)(v7 + 8) = 0LL;
    v8 = 0;
    v9 = a3[12] | *(_DWORD*)(v7 + 12) | (a3[13] << 8) | (a3[14] << 16);
    v10 = a3[15];
    v11 = v27;
    v12 = *a3 | (a3[1] << 8) | (a3[2] << 16) | (a3[3] << 24);
    v13 = a3[4] | (a3[5] << 8) | (a3[6] << 16) | (a3[7] << 24);
    *(_DWORD*)(v7 + 8) |= a3[8] | (a3[9] << 8) | (a3[10] << 16) | (a3[11] << 24);
    *(_DWORD*)(v7 + 4) = v13;
    *(_DWORD*)v7 = v12;
    v14 = v11 - 1;
    *(_DWORD*)(v7 + 12) = v9 | (v10 << 24);
    i = (unsigned int)*v6;
    if (v11 != 1)
    {
        v16 = -1640531527 * (0x34 / v11 + 6);
        if (v16)
        {
            do
            {
                v17 = v16 >> 2;
                v18 = v14;
                do
                {
                    v19 = v18 - 1;
                    LODWORD(i) = v6[v18]
                        - (((v6[v19] ^ *(_DWORD*)(v7 + 4LL * ((v18 ^ v17) & 3))) + (i ^ v16)) ^ ((((unsigned int)i >> 3) ^ (16 * v6[v19]))
                            + ((4 * i) ^ (v6[v19] >> 5))));
                    v6[v18--] = i;
                } while (v19);
                v20 = v6[v14];
                v21 = (i ^ v16) + (v20 ^ *(_DWORD*)(v7 + 4LL * (v17 & 3)));
                v16 += 1640531527;
                i = *v6 - ((((16 * v20) ^ ((unsigned int)i >> 3)) + ((v20 >> 5) ^ (4 * (_DWORD)i))) ^ v21);
                *v6 = i;
            } while (v16);
            v11 = v27;
            v8 = v27 - 1;
        }
        else
        {
            v8 = v11 - 1;
        }
    }
    v22 = 4 * v11;
    v23 = v6[v8];
    if (v23 < v22 - 7 || v23 > v22 - 4)
    {
        v25 = 0LL;
    }
    else
    {
        //v24 = ((__int64(__fastcall*)(__int64, __int64))unk_725D569A60)(v23 + 1, i);
        v24 = (__int64)malloc(v23 + 1);
        for (i = 0LL; v23 > (unsigned int)i; ++i)
            *(unsigned __int8*)(v24 + i) = v6[(unsigned int)i >> 2] >> (8 * (i & 3));
        *(unsigned __int8*)(v24 + v23) = 0;
        v25 = v24;
        *a4 = v23;
    }
  //  ((void(__fastcall*)(__DWORD*, __int64))unk_725D5698B0)(v6, i);
    free(v6);
    free((void*)v7);
    return v25;
}

__int64 __fastcall sub_725D95253C(__int64 a1, unsigned int a2, int a3, unsigned int* a4)
{
    unsigned int v6; // w22
    __int64 v7; // x19
    __int64 v8; // x2
    __int64 i; // x0
    unsigned int v10; // w2
    int v11; // w1
    char v12; // w3

    v6 = ((a2 & 3) != 0) + (a2 >> 2);
    if (a3)
    {
        v7 = (__int64)malloc(4LL * ((v6 + 1) & 0x3FFFFFFF));
        v8 = 4LL * (v6 & 0x3FFFFFFF);
        *(_DWORD*)(v7 + 4LL * v6) = a2;
        *a4 = v6 + 1;
    }
    else
    {
        v7 = (__int64)malloc(4LL * (v6 & 0x3FFFFFFF));
        v8 = 4LL * (v6 & 0x3FFFFFFF);
        *a4 = v6;
    }
   memset((void*)v7, 0LL, v8);
    for (i = 0LL; a2 > (unsigned int)i; *(_DWORD*)(v7 + 4LL * v10) |= v11 << v12)
    {
        v10 = (unsigned int)i >> 2;
        v11 = *(unsigned __int8*)(a1 + i);
        v12 = 8 * (i++ & 3);
    }
    return v7;
}