#include<iostream>
#include<fstream>
#include<string>
#define uchar unsigned char
using namespace std;
//string filePath="/sdcard/mysrc/secretFile.cpp";
//string filePath2="/sdcard/mysrc/myfile1.txt";
//Of read the fil
uchar fileStart[24]={2,153,5,200,235,199,200,201,133,3,3,3,200,201,202,3,3,3,133,2,6,192,6,233};
int len=24;
void read(string filePath){
    uchar temp;
    int cnt=0;
    int count=0;
    bool sum=true;
    ifstream input(filePath.c_str());
    if(!input){
        cout<<"error";
        return;
    }//Of if
    while(!input.eof()&&count<len){
       if((temp=input.get())!=EOF&&!input.fail()){
           if(temp!=fileStart[count]){
               cout<<"error type."<<endl;
               return;
           }//Of if
       }//Of if
       count++;
    }//Of while
    while(!input.eof()){
        int tempValue=0;
         if(cnt>2377)
       cnt=0;
       sum=!sum; if((temp=input.get())!=EOF&&!input.fail()){
            //	temp++;
            cnt++;
              if(sum)
            tempValue=temp-cnt*(cnt+7)%23;
            else
            tempValue=temp-cnt*(cnt+11)%7;
            if(tempValue<0){
                tempValue=256+tempValue;
            }//Of if
            cout<<(char)tempValue;
        }//Of if
    }//Of while
    input.close();
}//Of read
void decipher(string filePath,string filePath2){
	uchar temp;
    int cnt=0;
    int count=0;
    bool sum=true;
    ifstream input(filePath.c_str());
    
    if(!input){
        cout<<"error";
        return;
    }//Of if
    while(!input.eof()&&count<len){
       if((temp=input.get())!=EOF&&!input.fail()){
           if(temp!=fileStart[count]){
               cout<<"error type."<<endl;
               return;
           }//Of if
       }//Of if
       count++;
    }//Of while
    ofstream output(filePath2.c_str());
    while(!input.eof()){
        int tempValue=0;
        if(cnt>2377)
       cnt=0;
       sum=!sum; if((temp=input.get())!=EOF&&!input.fail()){
            //	temp++;
            cnt++;
                if(sum)
            tempValue=temp-cnt*(cnt+7)%23;
            else
            tempValue=temp-cnt*(cnt+11)%7;
            //tempValue=temp-cnt*(cnt-2)%5;
            if(tempValue<0){
                tempValue=256+tempValue;
            }//Of if
            output<<(char)tempValue;
        }//Of if
    }//Of while
    input.close();
    output.close();
}//Of decipher
/**
 * @brief create
 * @param filePath
 * @param filePath2
 */
void create(string filePath,string filePath2){
    char temp;
    int cnt=0;
    bool sum=true;
    ifstream input(filePath.c_str());
    cout<<"inputting..."<<endl;
    if(!input){
        cout<<"error";
        return;
    }//Of if
    ofstream output(filePath2.c_str());
    cout<<"outputting"<<endl;
    for(int i=0;i<len;i++){
        output<<fileStart[i];
    }//Of for
    while(!input.eof()){
        int tempValue=0;
        if(cnt>2377)
       cnt=0;
       sum=!sum; if((temp=input.get())!=EOF&&!input.fail()){
            //	temp++;
            cnt++;
            if(sum)
            tempValue=temp+cnt*(cnt+7)%23;
            else
            tempValue=temp+cnt*(cnt+11)%7;
            
            if(tempValue>255){
                tempValue=tempValue-256;
            } //Of if
            output<<(char)tempValue;
        }//Of if
    }//Of while
    input.close();
    output.close();
}//Of create
/**
 *help option or without any paramenter
 * @brief help
 */
void help(){
    cout<<"USAGE :encry [option] <arguments>"<<endl;
    cout<<"[option]:"<<endl;
    cout<<"-H\thelp"<<endl;
    cout<<"-E filename1 filename2\t encrypt file1 into file2"<<endl;
    cout<<"-R filename\t read the encrypted file"<<endl;
    cout<<"-D filename1 filename2\t decipher file1 into file2"<<endl;
}//Of help

/*
int main(int args,char *argv[]){
    create();
    read();
    return 0;
        }//Of main
*/