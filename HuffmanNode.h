#include <iostream>
#include <string.h>
#include <stdio.h>

#ifndef HUFFMANNODE_H_INCLUDED
#define HUFFMANNODE_H_INCLUDED

class FreqPair{
private:
    char symbol;
    int freq;
public:
    FreqPair(char s,int f){
        symbol = s;
        freq = f;
    }
    int weight(){
        return freq;
    }
    char val(){
        return symbol;
    }
};

class HuffmanNode{
public:
    virtual int weight()=0;
    virtual bool isLeaf()=0;
    virtual HuffmanNode *left()=0;
    virtual HuffmanNode *right()=0;
    virtual char LeafSymbol()=0;
};

class LeafNode:public HuffmanNode{
private:
    FreqPair *it;
public:
    LeafNode(char val,int freq){
        it = new FreqPair(val,freq);
    }
    int weight(){
        it->weight();
    }
    bool isLeaf(){
        return true;
    }
    HuffmanNode *left(){
        return NULL;
    }
    HuffmanNode *right(){
        return NULL;
    }
    FreqPair *val(){
        return it;
    }
    char LeafSymbol(){
        return it->val();
    }
};

class IntlNode:public HuffmanNode{
private:
    HuffmanNode *lc;
    HuffmanNode *rc;
    int wgt;
public:
    IntlNode(HuffmanNode *l,HuffmanNode *r){
        wgt = l->weight() + r->weight();
        lc = l;
        rc = r;
    }
    int weight(){
        return wgt;
    }
    bool isLeaf(){
        return false;
    }
    HuffmanNode *left(){
        return lc;
    }
    void setLeft(HuffmanNode *l){
        lc = (HuffmanNode *) l;
    }
    HuffmanNode *right(){
        return rc;
    }
    void setRight(HuffmanNode *r){
        rc = (HuffmanNode *) r;
    }
    char LeafSymbol(){
        return '\0';
    }

};

#endif // HUFFMANNODE_H_INCLUDED
