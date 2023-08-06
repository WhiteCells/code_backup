#include "md5.h"
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    const char* data = "12345678";
    char R[] = { '1', '2', '3', '4' };
    char md5[_MD5_MAX + 1];
    char md5_2[_MD5_MAX + 1];
    memset(md5, 0, sizeof(md5));
    int length = sizeof(data) / sizeof(data[0]);
    Md5((BYTE*)data, length, (BYTE*)md5, _MD5_MAX);
    printf("md5:%s\n", md5);
    memset(md5_2, 0, sizeof(md5_2));
    for(int i = 0;i < _MD5_MAX;i++) {
        md5[i] = md5[i] ^ (R[i % 4]);
    }
    Md5((BYTE*)md5, _MD5_MAX, (BYTE*)md5_2, _MD5_MAX);
    printf("md5_2:%s\n", md5_2);
    return 0;
}