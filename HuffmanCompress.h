#include<iostream>
#include<fstream>
#include<stdio.h>
#include"MyMethod.h"

using namespace std;

#ifndef HUFFMANCOMPRESS_H_INCLUDED
#define HUFFMANCOMPRESS_H_INCLUDED

struct BufferType
{
    char ch;
    int bits;
};

class HuffmanCompress
{
protected:
    BufferType buf;
    FILE *infp;
    FILE *outfp;
    HuffmanTree *pHuffmantree;

    void Write(int bit);
    void WriteToOutfp();
public:
    HuffmanCompress(){}
    ~HuffmanCompress(){}
    void Compress();
    void DeCompress();
    char *FindCode(HuffmanNode* t,char ch,char *Code,int length);
};

void HuffmanCompress::Write(int bit)
{
    buf.bits++;
    buf.ch = (buf.ch<<1)|bit;
    if(buf.bits==8)
    {
        fputc(buf.ch,outfp);
        buf.bits = 0;
        buf.ch = 0;
    }
}

void HuffmanCompress::WriteToOutfp()
{
    int len = buf.bits;
    if(len>0)
    {
        for(int i=0;i<8-len;i++)
            Write(0);
    }
}

char *HuffmanCompress::FindCode(HuffmanNode *t,char ch,char *Code,int length)
{
    if(t->isLeaf())
    {
        if(t->LeafSymbol()==ch)
        {
            return Code;
        }
    }
    if(t->left()!=NULL)
    {
        char temp[50];
        int len;
        strcpy(temp,Code);
        len=length;
        temp[len++]='0';
        temp[len]='\0';
        FindCode(t->left(),ch,temp,len);
    }
    if(t->right()!=NULL)
    {
        char temp[50];
        int len;
        strcpy(temp,Code);
        len=length;
        temp[len++]='1';
        temp[len]='\0';
        FindCode(t->right(),ch,temp,len);
    }
}

void HuffmanCompress::Compress()
{
    char infName[256];
    char outfName[256];
    cout<<"������Դ�ļ������ļ�С��4GB����";
    cin>>infName;
    if((infp = fopen(infName,"rb"))==NULL)
	{
		cout << "��Դ�ļ�ʧ��!!" << endl;
		return;
	}
    fgetc(infp);
    cout<<"������Ŀ���ļ���";
    cin>>outfName;
    if((outfp = fopen(outfName,"wb"))==NULL)
	{
		cout << "��Ŀ���ļ�ʧ��!!" << endl;
		return;
	}
    cout<<"���ڴ������Ժ�"<<endl;
    const int n = 256;
    char ch[n];
    int w[n];
    int i,size=0;
    char cha;

    for(i=0;i<n;i++)
    {
        ch[i] = (char)i;
        w[i] = 0;
    }
    rewind(infp);
    cha = fgetc(infp);
    while(!feof(infp))
    {
        w[(char)cha]++;
        size++;
        cha = fgetc(infp);
    }
    if (pHuffmantree != NULL)
		delete[] pHuffmantree;
    pHuffmantree = HuffmanBuild(ch,w,n);
    rewind(outfp);
    fwrite(&size,sizeof(int),1,outfp);
    for(i=0;i<n;i++)
    {
        fwrite(&w[i],sizeof(int),1,outfp);
    }

    buf.bits = 0;
    buf.ch = 0;
    rewind(infp);
    cha = fgetc(infp);
    while(!feof(infp))
    {
        char a[100];
        char Code[50]={'\0'};
        strcpy(a,FindCode(pHuffmantree->root(),cha,Code,0));
        for(i=0;i<strlen(a);i++)
        {
            if(a[i]=='0') Write(0);
            else Write(1);
        }
        cha = fgetc(infp);
    }
    WriteToOutfp();
    fclose(infp);
    fclose(outfp);
    cout<<"�������"<<endl;
}

void HuffmanCompress::DeCompress()
{
	char infName[256], outfName[256];
	cout << "������ѹ���ļ���: ";
	cin >> infName;
	if ((infp = fopen(infName, "rb")) == NULL)
	{
		cout << "��Դ�ļ�ʧ��!!" << endl;
		return;
	}
	cout << "������Ŀ���ļ���: ";
	cin >> outfName;
	if ((outfp = fopen(outfName, "wb")) == NULL)
	{
		cout << "��Ŀ���ļ�ʧ��!!" << endl;
		return;
	}
	const int n = 256;
	char ch[n];
	int w[n];
	int i, size;
	char cha;
	rewind(infp);
	fread(&size, sizeof(int), 1, infp);
	for (i = 0; i < n; i++)
	{
		ch[i] = (char)i;
		fread(&w[i], sizeof(int), 1, infp);
	}
	if (pHuffmantree != NULL)
		delete[] pHuffmantree;
	pHuffmantree =  HuffmanBuild(ch,w,n);
	int len = 0;
	char p[100000];
	int k = 0;
	cha = fgetc(infp);
	while (!feof(infp))
	{
		for(int i = 7; i >= 0; i--)
		{
			if ((cha >> i) & 1)
				p[k] = '1';
			else
				p[k] = '0';
			k++;
		}
		cha = fgetc(infp);
	}
	p[k] = '\0';
	while(true)
	{
		len++;

		if (len == size) break;
	}
	fclose(infp);
	fclose(outfp);
}
#endif // HUFFMANCOMPRESS_H_INCLUDED
