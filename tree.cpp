#include<iostream>
using namespace std;

struct node{
	int info;
	node *right,*left;
};
class BST{
	private:
		int gh,lh,rh;
	public:
		int even;
		int number;
		node *root,*current;
		node *temp,*temp1;
		BST(){
			temp = root = temp1 = current = NULL;
			gh = 0;
			lh = rh = 0;
		}
		void AVL_inser(node *temp){
			if(root==NULL){
     			temp=new node;
     			temp->info = number;
    			temp->left=NULL;
     			temp->right=NULL;
     			root=temp;
     			return;
   			}
   			if(temp->info>number){
   				if(temp->left!=NULL){
					AVL_inser(temp->left);
		 			return;
      			}
      			else{
	 				temp->left=new node;
	 				temp->left->info = number;
	 				temp->left->left=NULL;
	 				temp->left->right=NULL;
	 				return;
       			}
    
			}
			if(temp->info<number){
				if(temp->right!=NULL){
					AVL_inser(temp->right);
		 			return;
       			}
     			else{
	 				temp->right=new node;
	 				temp->right->info = number;
	 				temp->right->left=NULL;
	 				temp->right->right=NULL;
					return;	
				}
			}
		}
		void in_order(node *temp){
			if(temp->left != NULL){
				in_order(temp->left);
			}
			cout<<temp->info;
			if(temp->right != NULL){
				in_order(temp->right);
			}
		}
};
int main(){
	BST b;
	for(int i=0;i<3;i++){
		cout<<"Enter number to insert in tree :"<<endl;
		cin>>b.number;
		b.AVL_inser(b.root);	
	}
	b.in_order(b.root);
	cout<<endl;
	//b.BF(b.root);
	//cout<<endl;
}





