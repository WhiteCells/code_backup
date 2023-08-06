#ifndef __MD5_H_
#define __MD5_H_
#define _MD5_MAX        32

#include <windows.h>

/* Data structure for MD5 (Message Digest) computation */
typedef struct {
    DWORD i[2];                   /* number of _bits_ handled mod 2^64 */
    DWORD buf[4];                                    /* scratch buffer */
    BYTE in[64];                              /* input buffer */
    BYTE digest[16];     /* actual digest after MD5Final call */
} _MD5_CTX;

/**
 *        计算指定字符串的md5值
 *@data            待MD5的数据
 *@datalen        待md5数据的长度
 *@md5Value        OUT MD计算结果
 *@md5ValueMax    md5Value缓冲区大小(
                                     如果小于16字节，则返回失败；
                                     如果小区32字节则返回16字节的编码；
                                     如果大于等于32字节，则返回32字节的bcd编码)
 *@return        成功返回md5Value的使用字节数
 *                失败返回 -1
 *@notes        一般情况下，MD5的结果为16或32字节，32字节为16字节的bcd编码。
 */
int Md5(BYTE* data, int datalen, BYTE* md5Value, int md5ValueMax);
#define _md5  Md5

/**
 *        计算指定文件的md5值
 *@pcFilePath        待计算MD5的文件路径
 *@md5Value        OUT MD计算结果
 *@md5ValueMax    md5Value缓冲区大小(
                                如果小于16字节，则返回失败；
                                如果小区32字节则返回16字节的编码；
                                如果大于等于32字节，则返回32字节的bcd编码)
 *@return        成功返回md5Value的使用字节数
 *                失败返回 -1
 *@notes        一般情况下，MD5的结果为16或32字节，32字节为16字节的bcd编码。
 */
int CalcFileMd5(char* pcFilePath, BYTE* md5Value, int md5ValueMax);

/**
 *      Md5初始化
 *@mdContext        md5上下文
 *@return           无
 */
void Md5Init(_MD5_CTX* mdContext);

/**
 *          执行MD计算
 *@mdContext        MD5上下文，Md5Init初始化过。
 *@inBuf            待MD5计算的内容
 *@inLen            内容长度
 */
void Md5Update(_MD5_CTX* mdContext, BYTE* inBuf, DWORD inLen);

/**
 *      完成MD计算
 */
void Md5Final(_MD5_CTX* mdContext);

/**
 *        随机数Md5加密
 *@plaintext        加密前的明文
 *@plaintextLen     明文长度
 *@randtext         随机内容
 *@randtextLen      随机内容长度
 *@encryption       存放密文的空间
 *@encryptionMax    密文空间最大容量
 *@return           成功返回加密后的内容长度
 *                  失败返回 -1
 */
int RandMd5(char* plaintext, int plaintextLen,
            char* randtext, int randtextLen,
            char* encryption, int encryptionMax);

#endif // md5.h