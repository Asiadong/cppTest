#include "file.h"
#include<iostream>
#include<cstring>
using namespace std;
int main(int arv,char *arg[])
{
	cout << "My Encryption." << endl;
    if(arv==1||(arv==2&&!strcmp(arg[1],"-H"))){
    help();
    return 0;
    }//Of if
    if(!strcmp(arg[1],"-E")){
        if(arv!=4){
            cout<<"error!"<<endl;
            help();
            return 0;
        }//Of if
        create(arg[2],arg[3]);
        return 0;
    }//Of if
        if(!strcmp(arg[1],"-D")){
        if(arv!=4){
            cout<<"error!"<<endl;
            help();
            return 0;
        }//Of if
        decipher(arg[2],arg[3]);
        return 0;
    }//Of if
    if(!strcmp(arg[1],"-R")){
        if(arv!=3){
            cout<<"error!"<<endl;
            help();
            return 0;
        }//Of if
        read(arg[2]);
     return 0;
    }//Of if
    //cout << "My Encryption." << endl
    //cout<<arg[0];
    return 0;
}//Of main