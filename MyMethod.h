#include "HuffmanTree.h"

#ifndef MYMETHOD_H_INCLUDED
#define MYMETHOD_H_INCLUDED

void char_code();
void myStat(char ch,char* CharSet,int* FreqSet);//�����ı��ļ���ͳ��Ƶ�ʲ�Ϊ0���ַ���s����ӦƵ�ʼ�w��������num
HuffmanTree *HuffmanBuild(char* CharSet,int* FreqSet,int num);//���ø�������������������
void HuffmanCode(HuffmanNode* ht1,char* Code,int length);//��������
void char_code();
void Myprinthelp();
void File_Code();
void File_Decode();

#endif // MYMETHOD_H_INCLUDED
