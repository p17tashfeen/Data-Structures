#include <iostream>
using namespace std;

struct node{
	int info;
	node *next;
	node *bottom;
};

class bucketSort{
	private:
		int *array, *temp;
		node *newArray, *newArrayHead, *ptr, *ptr1, *ptr2;
		int size, fInt;
	public:
		bucketSort(){
			temp = NULL;
			cout << "Enter the size: ";
			cin >> size;
			ptr = ptr1 = ptr2 =newArrayHead= newArray = NULL;
			array = new int[size];
			
			
		}
		
		~bucketSort(){
			delete array, temp;
		}
		
		void checkFirstDigit(){
			int cLength;
			cLength = *temp;
			while(2){
				if(cLength == 0){
					break;
				}
				fInt =  cLength;
				cLength = cLength/10;
			}
		}
		
		
		
		void inputArray(){
			temp = array;
			for(int i = 1; i <= size; i++){
				cout << "Enter the value: ";
				cin >> *temp;
				temp++;
			}
			
			int j = 1;
			while(j <= 9){
				if(newArrayHead == NULL){
					newArray = new node;
					newArray->info = j;
					newArray->next = NULL;
					newArray->bottom = NULL;
					newArrayHead = newArray;
				}
				else{
					ptr = newArray;
					newArray = new node;
					newArray->info = j;
					newArray->next = NULL;
					ptr->bottom = newArray;
					newArray->bottom = NULL;
				}
				j++;
			}
		
			
		}
		
		void bucketSortSet(){
			temp = array;
			for(int i = 1; i<= size; i++){
				checkFirstDigit();
				newArray = newArrayHead;
				while(newArray->info != fInt){
					newArray = newArray->bottom;
				}
				ptr = newArray;
				while(ptr != NULL){
					if(ptr->info > *temp && ptr->next == NULL){
						ptr1 = new node;
						ptr1->info = *temp;
						ptr2->next = ptr1;
						ptr1->next = ptr;
						break;
					}
					if(ptr->info > *temp && ptr->next != NULL){
						ptr1 = new node;
						ptr1->info = *temp;
						ptr2->next = ptr1;
						ptr1->next = ptr;
						break;
					}
					if(ptr->next == NULL){
						ptr1 = new node;
						ptr1->info = *temp;
						ptr1->next = ptr->next;
						ptr->next = ptr1;
						break;
					}
					ptr2 = ptr;
					ptr = ptr->next;
				}	
				temp++;	
				
			}
		}
		
		void BucketOutput(){
			newArray = newArrayHead;
			while(newArray != NULL){
				cout << "["  <<newArray->info << "]: ";
				ptr = newArray->next;
				while(ptr != NULL){
					cout << ptr->info << " ";
					ptr = ptr->next;
				}
				cout << endl;
				newArray = newArray->bottom;
				
				
			}
		}
		void outputArray(){
			temp = array;
			cout << "print the value " << endl;
			for(int i = 1; i <= size; i++){
				cout << *temp << " ";
				temp++;
			}
			
		}
		
};




int main(){
	bucketSort b;
	b.inputArray();
	b.outputArray();
	cout << endl;
	b.bucketSortSet();
	b.BucketOutput();
}
