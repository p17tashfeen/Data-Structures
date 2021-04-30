#include<iostream>
using namespace std;

struct node{
	int info;
	node *next;
};

class ring{
	node *head,*current,*temp;
	public:
		
	ring(){
		head = current = NULL;
	}
	void insert(){
		if(head == NULL){
			head = new node;
			cout<<"Enter info for first node"<<endl;
			cin>>head->info;
			head ->next = head;
		}
		else if(head->next == head){
			current = new node;
			cout<<"Enter info for second node"<<endl;
			cin>>current->info;
			current->next = head;
			head->next = current;	
		}
		else{
			temp = new node;
			cout<<"Enter info for remaning nodes"<<endl;
			cin>>temp->info;
			temp->next = current;
			head->next = temp;
			current = temp;
		}
	}
	void insert_last(){
		if(head == NULL){
			head = new node;
			cout<<"Enter info for first node"<<endl;
			cin>>head->info;
			head -> next = head;
		}
		else if(head->next == head){
			current = new node;
			cout<<"Enter info for second node"<<endl;
			cin>>current->info;
			current ->next = head;
			head->next = current;
		}
		else{
			temp = new node;
			cout<<"Enter info for remaning nodes"<<endl;
			cin>>temp->info;
			temp->next = head;
			current->next = temp;
			current = temp;
		}
	}
	
	void insert_mid(){
		int key;
		cout<<"Enter key"<<endl;
		cin>>key;
		if(head->info == key){
			temp = head;
			temp = new node;
			cout<<"Enter info"<<endl;
			cin>>temp->info;
			temp->next = head->next;
			head->next = temp;
		}
		else{
			current = head->next;
			while(current!=head){
				if(current->info == key){
					temp = new node;
					cout<<"Enter info"<<endl;
					cin>>temp->info;
					temp->next = current->next;
					current->next = temp;
				}
				current = current->next;
			}
		}
		
	}
	void delete(){
		int key;
		cout<<"Enter value of node to delet"<<endl;
		cin>>key;
		if(head->info == key){
			temp = head;
			head = head->next;
			delete temp;
		}
		else {
			temp = head->next;
			while(temp!=head){
				if(temp->next->info == key){
					current = temp->next;
					temp = current->next;
					delete current;
					current = NULL;
				}
				temp = temp->next;
			}
		}
		
	}
	
	void print_for_first(){
		cout<<".............RING LIST................"<<endl;
		while(temp != head){
			cout<<temp->info;
			temp = temp->next;	 
		}
		cout<<temp->info;
	}
	void print_for_last(){
		cout<<".............RING LIST................"<<endl;
		temp = head;
		cout<<temp->info; //for print first node info;
		temp = head->next;
		while(temp != head){
			cout<<temp->info;
			temp = temp->next;	 
		}
	}
	
	
	
};

int main(){
	ring r;
	for(int i = 0;i<4;i++){
		r.insert();
	}
	r.print_for_first();
	for(int i = 0;i<4;i++){
		r.insert_last();
	}
	r.print_for_last();
	
}
