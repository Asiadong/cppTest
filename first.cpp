#include<iostream>
#include<fstream>
#include<string>
using namespace std;
string filePath="/sdcard/mysrc/secretFile.cpp";
string filePath2="/sdcard/mysrc/myfile1.txt";
void read(){
	char temp;
	int cnt=0;
	ifstream input(filePath2);
	if(!input){
		cout<<"error";
		return;
		}//Of if
		while(!input.eof()){
			if((temp=input.get())!=EOF&&!input.fail()){
		//	temp++;
		cnt++;
        	cout<<(char)(temp-cnt*(cnt-2)%5);
        	}
		}
	}//Of read
	void create(){
		char temp;
		int cnt=0;
			ifstream input(filePath);
	if(!input){
		cout<<"error";
		return;
		}//Of if
		ofstream output(filePath2);
			while(!input.eof()){
			if((temp=input.get())!=EOF&&!input.fail()){
		//	temp++;
		cnt++;
        	output<<(char)(temp+cnt*(cnt-2)%5);
        	}
		}
		}//Of create
int main(int args,char *argv[]){
	create();
	read();
	return 0;
		}//Of main
