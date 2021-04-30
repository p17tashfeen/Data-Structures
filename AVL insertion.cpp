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
		int number,count;
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
     	
   			}
   			if(temp->info>number){
   				if(temp->left!=NULL){
					AVL_inser(temp->left);
			
				}
      			else{
	 				temp->left=new node;
	 				temp->left->info = number;
	 				temp->left->left=NULL;
	 				temp->left->right=NULL;
       				
				}
    
			}
			
			if(temp->info<number){
				if(temp->right!=NULL){
					AVL_inser(temp->right);
					
				   }
     			else{
	 				temp->right=new node;
	 				temp->right->info = number;
	 				temp->right->left=NULL;
	 				temp->right->right=NULL;
					
				}
			}
			
			int bf = BF(temp);
			cout<<temp->info<<"->bf = "<<bf<<endl;
			if(bf == -1 || 0 || 1){
				//return;
			}
			if(bf == 2){
				if(number<temp->left->info){     //insertion to the left subtree of the left child (single right rotation to fix case1.)
					if(temp->left->right == NULL){     
						current = temp;              
						temp = temp->left;          
						count = current->info;        
						current->info = temp->info; 
						temp->info = temp->left->info;
						current->right = new node;
						current->right->info = count;
						current->right->right = NULL;
						current->right->left = NULL;
						delete temp->left;
						temp->left = NULL; 
						return;
					}
					if(temp->left->right!=NULL){ 
						current = temp;
						temp = temp->left;
						current->left = temp->right;
						temp->right = current;
						root = temp;
						return;
					}
				}
				else{            //insertion to the left subtree of the right child (double  rotation to fix case2.)
					current = temp;
					temp = temp->left;
					temp1 = temp->right;
					current->left = temp1;
					temp->right = current;
					root = temp;
					return;
				}
			}
			if(bf == -2){
				if(number>temp->right->info){ //insertion to the right subtree of the right child (single left rotation to fix case4.)
					if(temp->right->left == NULL){ 
						current = temp;
						temp = temp->right;
						count = current->info;
						current->info = temp->info;
						temp->info = temp->right->info;
						current->left = new node;
						current->left->info = count;
						current->left->left = NULL;
						current->left->right = NULL;
						delete temp->right;
						temp->right = NULL; 
						return;
					}
					if(temp->right->left!=NULL){ 
						current = temp;
						temp = current->right;
						current->right = temp->left;
					    temp->left = current;
					    root = temp;
						return;
					}
				}
				else{          //insertion to the right subtree of the left child (double rotation case3.) 
					current = temp;
					temp = temp->right;
					temp1 = temp->left;
					current->right = temp1;
					temp1->right = temp;
					count = current->info;
					current->info = temp1->info;
					temp1->info = temp->info;
					delete temp;
					temp = NULL;
					temp1->right = NULL;
					current->left = new node;
					current->left->info = count;
					current->left->left = NULL;
					current->left->right = NULL;
					return;
				}
			}
		}	

		void in_order(node *temp){
  			if(temp->left!=NULL ){
    			in_order(temp->left);
    		}
    		cout<<temp->info<<endl;
    		cout << "Balance: " << BF(temp) << endl;
  			if(temp->right!=NULL ){
				in_order(temp->right);
		 	}
		}
		int height(node *temp){
        	int lh = 0;
        	int rh = 0;
        	int h = 0;
        	
        	if(temp->left != NULL){
            	lh++;
            	lh += height(temp->left);
        	}
        	if(temp->right != NULL){
            	rh++;
            	rh += height(temp->right);
        	}
        	if (lh > rh) {
            	h = lh;
        	}
        	else if (rh > lh){
            	h = rh;
        	}
        	else{
            	h = rh;
        	}
        	return h;
    	}
		int BF(node *temp){
			int hl = 0; 
			int hr = 0;
			if(temp->left!=NULL){
				hl = height(temp->left)+1;
			}
			if(temp->right!=NULL){
				hr = height(temp->right)+1;
			}
			int bf = hl-hr;
			return bf;
		}
};
int main(){
	BST b;
	for(int i=0;i<10;i++){
		cout<<"Enter number to insert in tree :"<<endl;
		cin>>b.number;
		b.AVL_inser(b.root);	
	}
	b.in_order(b.root);
	cout<<endl;
}
/*
if(temp->left->right != NULL){
						if(temp->right == NULL){
							current = temp;
							temp = temp->left;
							current->left = temp->right;
							temp->right = current;
							root = temp;
							return;
						}
					}*/
