#include <iostream>
using namespace std;

struct node{
	int info;
	node *left, *right;
	int index;
};

class completeBinaryTree{
	private:
		node *ptr, *hCheck;
		int count, Height, totalNode, h, number, dex;
		bool flag;
	public:
		node *root;
		int value;
		completeBinaryTree(){
			root = ptr = hCheck = NULL;
			count = Height = totalNode = h = number = dex =  0;
		}
		
		~completeBinaryTree(){
			delete root, ptr, hCheck;
		}
		
		int power(int h){
			if(h == 0){
				return 1;
			}
			else{
				return 2 * power(h-1);
			}
		}
		
		void insertCompleteBinaryTree(node *temp){
			flag = false;
			if(root == NULL){
					temp = new node;
					temp->info = value;
					temp->index = ++dex;
					temp->left = NULL;
					temp->right = NULL;
					root = temp;
					count++;
					totalNode++;
					return;
			}
			if(count == totalNode){
				count = 0;
				totalNode = power(Height+1);
				Height++;
				cout << "Height: " << Height << endl;
				cout << "totalNode: " << totalNode << endl;
				while(temp->left != NULL){
					temp = temp->left;
				}
				ptr = new node;
				ptr->info = value;
				ptr->index = ++dex;
				ptr->left = NULL;
				ptr->right = NULL;
				temp->left = ptr;
				count++;
				return;
			}
			if(count != totalNode){
				insertionSearch(temp);
				cout << "ptr->info:: " << ptr->info << endl;
				if(ptr->left != NULL && ptr->right == NULL){
					cout << "right: " << endl;  
					temp = new node;
					temp->info = value;
					temp->index = ++dex;
					ptr->right = temp;
					temp->left = NULL;
					temp->right = NULL;
					count++;
					return;
				}
				if(ptr->left == NULL && ptr->right == NULL ){
					cout << "left: " << endl;  
					temp = new node;
					temp->info = value;
					temp->index = ++dex;
					ptr->left = temp;
					temp->left = NULL;
					temp->right = NULL;
					count++;
					return;
				}
			}
			
		}
		void insertionSearch(node *temp){
   			if(temp->left!=NULL && h < Height){
   				h++;
   				insertionSearch(temp->left);
				h--; 
			}
			if((temp->left==NULL && h == Height-1) || (temp->right==NULL && h == Height-1)){
				if(flag == false){
					ptr = temp;
					flag = true;
					return;
				} 
			}
			if(temp->right!=NULL){
   				h++;
   				insertionSearch(temp->right);
				h--;
			}
		}
		void deletionCompleteBinaryTree(node* temp){
			deletionSearch(temp);
			if(root->left == NULL){
				delete root;
				root = NULL;
				return;
			}
			while(temp->left != NULL){
				temp = temp->left;
			}
			hCheck = temp;
			if(ptr->right != NULL){
				temp = ptr->right;
				cout << temp->info << " is deleted" << endl;
				ptr->right = NULL;
				delete temp;
				temp = NULL;
				return;
			}
			temp = ptr->left;
			cout << temp->info << " is deleted" << endl;
			if(hCheck == temp){
				Height--;
			}
			ptr->left = NULL;
			delete temp;
			temp = NULL;
			return;
		}
		void deletionSearch(node* temp){
			if(temp->left!=NULL && h < Height){
   				h++;
   				deletionSearch(temp->left);
				h--; 
			}
			if(h == Height-1 && temp->left != NULL){
				ptr = temp;
			}
			if(temp->right!=NULL && h < Height){
   				h++;
   				deletionSearch(temp->right);
				h--;
			}
		}
		
		
		void printCompleteBinaryTree(node *temp){
   			if(temp == NULL){    		
			   cout<<" Tree is empty.\n";       
			   return;    
			}
   			if(temp->left != NULL){
   				printCompleteBinaryTree(temp->left);	
			}
   			cout <<"[" << temp->index << "]: " << temp->info << " ";
   			if(temp->right != NULL ){
   				printCompleteBinaryTree(temp->right);	
			}
	}		
};

int main(){
	completeBinaryTree CBT;
	CBT.printCompleteBinaryTree(CBT.root);
	for(int i = 0; i <  11; i++){
		cout << "enter the value: " << endl;
		cin >> CBT.value;
		CBT.insertCompleteBinaryTree(CBT.root);
		CBT.printCompleteBinaryTree(CBT.root);
		cout << endl;
	}
	for(int i = 0; i < 11; i++){
		CBT.deletionCompleteBinaryTree(CBT.root);
		CBT.printCompleteBinaryTree(CBT.root);
		cout << endl;
	}
}








