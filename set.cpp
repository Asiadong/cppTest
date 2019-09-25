#include<iostream>
#define MAX_SIZE 100
using namespace std;
typedef struct Node{
	int data;
	struct Node *next;
	} Node;
	
class Linklist{
	Node *head;
	Node *tail;
	int length;
	public:
	Linklist(){
		head=tail=NULL;
		length=0;
		}//
	void _add(int a){
		length++;
		if(!head){
			head=tail=new Node;
			tail->data=a;
			tail->next=NULL;
			return;
			}//Of if
		tail->next=new Node;	
		tail=tail->next;
		tail->data=a;
		tail->next=NULL;
		}//Of add
		void add(int a){
			Node *temp=head;
			if(!head){
				_add(a);
				return;
				}//Of if
			if(temp->data==a)return;
			if(temp->data>a){
				head=new Node;
				head->data=a;
				head->next=temp;
				length++;
				return;
				}//Of if
				while(1){
					if(temp->data==a){
								return;
								} 
					if(!temp->next){
						tail=new Node;
						tail->data=a;
						length++;
						temp->next=tail;
						return;
						}//Of if
						if(temp->next->data>a){
							Node *p=new Node;
							p->data=a;
							p->next=temp->next;
							temp->next=p;
							length++;
							return;
							}//Of if
						temp=temp->next;
					}//Of while
			}//Of view
			void print(){
				Node *temp=head;
				if(!head){
					cout<<"NULL SET"<<endl;
					return;
					}//Of if
				while(temp){
					if(temp!=head)
					cout<<',';
					cout<<temp->data;
					temp=temp->next;
					} //Of while
					cout<<endl<<length;
				}//Of print
	//int length;
};//Of hashSet
int main(){
	int i;
	int array[]= {2,1000,2,3,4,7,8,3,6,3,67,77,8,9,6,8,5,8};
	Linklist mySet;
	mySet.print();
	for(i=0;i<18;i++){
		mySet.add(array[i]);
		}//Of for
		mySet.print();
	return 0;
	}//Of main