#include "HuffmanTree.h"
#include "MyMethod.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>
#include "HuffmanCompress.h"

using namespace std;

void char_code(){
    HuffmanTree *myroot;
    char ch;
    int num=0;
    char Code[50]={'\0'};
    char CharSet[256]={0};
    int FreqSet[256];
    for(int k=0;k<256;k++)
    {
        FreqSet[k] = 0;
    }
    ifstream fp("C:\\Users\\10179\\Desktop\\HuffmanCode\\f1.txt");

    if(!fp){
        cout<<"open error!"<<endl;
        return ;
    }

    while((ch=fp.get())!=EOF){
        if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')){
            if(ch>='A'&&ch<='Z'){
                ch= ch+32;
            }
            myStat(ch,CharSet,FreqSet);
        }
    }
    for(int i=0;i<26;i++){
        if(FreqSet[i]!=0){
            num++;
        }
    }

    myroot = HuffmanBuild(CharSet,FreqSet,num);

    myroot->myprint();

    cout<<endl<<endl;

    HuffmanCode(myroot->root(),Code,0);

}

void File_Code(){
    HuffmanCompress A;
    A.Compress();
}

void File_Decode(){
    HuffmanCompress A;
    A.DeCompress();
}

void myStat(char ch,char *CharSet,int *FreqSet){//s字符集,w频率集,n频率不为0的字符个数
    int n;
    n = (int) (ch-'a');
    CharSet[n]=ch;
    FreqSet[n]++;
}


HuffmanTree *HuffmanBuild(char *CharSet,int *FreqSet,int num){

    HuffmanTree *ttree[256],*temp;
    int j=0;

    for(int i=0;i<256;i++){
        if(FreqSet[i]!=0){
            ttree[j++]= new HuffmanTree(CharSet[i],FreqSet[i]);
        }
    }

    while(num!=1){

        int s1=0,s2=0;
        for(int i=0;i<num;i++){
            if(ttree[i]->weight()<ttree[s1]->weight()){
                s1=i;
            }
        }

        if(s1==s2){
            s2++;
        }

        for(int i=0;i<num;i++){
            if(i==s1){
                continue;
            }

            if(ttree[i]->weight()<ttree[s2]->weight()){
                s2=i;
            }
        }

        temp = new HuffmanTree(ttree[s1],ttree[s2]);
        ttree[s1] = temp;



        for(int i=s2;i<num;i++){
            ttree[i] = ttree[i+1] ;
        }

        num--;

    }

    return ttree[0] ;
}


void HuffmanCode(HuffmanNode *ht1,char *Code,int length){
    if(ht1==NULL){
        return ;
    }

    if(ht1->isLeaf()){
        cout<<ht1->LeafSymbol()<<"  "<<ht1->weight()<<"  "<<Code<<endl;
        return ;
    }
    if(ht1->left()!=NULL){
        char temp[50];
        int len;
        strcpy(temp,Code);
        len=length;
        temp[len++]='0';
        temp[len]='\0';
        HuffmanCode(ht1->left(),temp,len);
    }
    if(ht1->right()!=NULL){
        char temp[50];
        int len;
        strcpy(temp,Code);
        len=length;
        temp[len++]='1';
        temp[len]='\0';
        HuffmanCode(ht1->right(),temp,len);
    }
}

void Myprinthelp(){
    cout<<endl;
    for(int i=0;i<60;i++){
        cout<<"*";
    }
    cout<<endl;
    for(int i=0;i<12;i++){
        cout<<" ";
    }
    cout<<"欢迎使用huffman编码器V1.0  : ) ";
    cout<<endl;
    for(int i=0;i<60;i++){
        cout<<"*";
    }
    cout<<endl<<endl;
    cout<<"操作命令说明："<<endl;
    cout.flags(ios::right);
    cout<<setw(61)<<"统计输入文件字符频度并对字符集编码并输出至文件（基本要求）：1"<<endl;
    cout<<setw(61)<<"对整个文件编码并保存编码后结果（中级要求）：2"<<endl;
    cout<<setw(61)<<"文件解码（高级要求）：3"<<endl;
    cout<<setw(61)<<"退出：4"<<endl;
    cout<<endl<<endl<<"$$";

}


