#include "HuffmanTree.h"

#ifndef MYMETHOD_H_INCLUDED
#define MYMETHOD_H_INCLUDED

void char_code();
void myStat(char ch,char* CharSet,int* FreqSet);//读入文本文件并统计频率不为0的字符集s，相应频率集w，及个数num
HuffmanTree *HuffmanBuild(char* CharSet,int* FreqSet,int num);//利用给定参数构建哈夫曼树
void HuffmanCode(HuffmanNode* ht1,char* Code,int length);//构建编码
void char_code();
void Myprinthelp();
void File_Code();
void File_Decode();

#endif // MYMETHOD_H_INCLUDED
