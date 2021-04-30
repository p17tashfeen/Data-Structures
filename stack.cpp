#include<iostream>
using namespace std;

struct node{
	int info;
	node *next;
	node *rare;
	node *top;
};
class data{
	node *rare;
	node *front,*temp,*current;
public:
	data(){
		rare = front = temp = current = NULL;
	}
	void En_queu(){
		if(front == NULL){
			front = new node;
			cout<<"Enter value :"<<endl;
			cin>>front->info;
			front->next = NULL;
			rare = front;
		    
		}

		else{
			temp = new node;
			cout<<"Enter value 2:"<<endl;
			cin>>temp->info;
			temp->next = NULL;
			rare->next = temp;
			rare = temp;
		}
	}

	void del_qeue(){
		temp = front;
		front = front->next;
		delete temp;
		temp = NULL;
	};
	void print(){
		temp = front;
		while(temp!=NULL){
			cout<<temp->info<<endl;
			temp = temp->next;
		}

		}

};
void main(){
	data d;
	for(int i=0;i<4;i++){
		d.En_queu();
	}
	d.print();
	d.del_qeue();
	d.print();

}
