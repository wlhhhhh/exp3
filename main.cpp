#include <iostream>
#include "MyMethod.h"
#include "HuffmanTree.h"

using namespace std;

int main()
{
    int i;
    Myprinthelp();
    do{
        cin>>i;
        switch(i){
        case 1:
            char_code();break;
        case 2:
            File_Code();break;
        case 3:
            File_Decode();break;
        case 4:
            ;
        }

    }while(i!=4);


}
