#include "HuffmanNode.h"
#include <iostream>

using namespace std;

#ifndef HUFFTREE_H_INCLUDED
#define HUFFTREE_H_INCLUDED

class HuffmanTree{
private:
    HuffmanNode *myroot;
    int nodecount;
    void clearhelp(HuffmanNode *subroot){
        if(subroot==NULL){
            return ;
        }
        clearhelp(subroot->left());
        clearhelp(subroot->right());
        delete subroot;
    }
    void printhelp(HuffmanNode *subroot,int level) const{
        FreqPair *s1;
        if(subroot==NULL) return;

        if(subroot->isLeaf()){
            for(int i=0;i<level;i++){
                cout<<"*";
            }
            cout<<"Leaf: ";
            s1=((LeafNode *)subroot)->val();
            cout<<s1->val()<<" "<<s1->weight()<<endl;
        }
        else{
            printhelp((IntlNode *)subroot->left(),level+1);//打印左树
            for(int i=0;i<level;i++){
                cout<<"*";
            }
            cout<<"Internal: ";
            cout<<((IntlNode *)subroot)->weight()<<endl;//打印根
            printhelp((IntlNode *)subroot->right(),level+1);//打印右树
        }

    }

public:
    HuffmanTree(char val,int freq){
        myroot = new LeafNode(val,freq);
    }
    HuffmanTree(HuffmanTree *l,HuffmanTree *r){//l,r分别为左右子节点
        myroot = new IntlNode(l->root(),r->root());
    }
    ~HuffmanTree(){
        clearhelp(myroot);
    }
    void myclear(){
        clearhelp(myroot);
        myroot=NULL;
        nodecount=0;
    }
    HuffmanNode* root(){
        return myroot;
    }
    int weight(){
        return myroot->weight();
    }
    void myprint() const{
        if(myroot==NULL){
            cout<<"this tree is empty"<<endl;
        }
        else{
            printhelp(myroot,0);
        }
    }

};

#endif // HUFFTREE_H_INCLUDED
