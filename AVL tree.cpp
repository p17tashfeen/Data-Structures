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
	 				a(root);
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
				 	a(root);
					return;	
				}
			}
		}
		void a(node *temp){
				int bf = BF(temp);
			if(bf == -1 || 0 || 1){
				return;
			}
			if(bf == 2){
				if(number<temp->left->info){
					current = temp;
					temp = temp->left;
					temp->right = current;
					return;
				}
				else{
					current = temp;
					temp = temp->left;
					temp1 = temp->right;
					current->left = temp1;
					temp1->left = temp;
					temp1->right = current;
					temp = temp1;
					return;
				}
			}
			if(bf == -2){
				if(number>temp->right->info){
					current = temp;
					temp = temp->right;
					temp1 = temp->left;
					current->right = temp1;
					temp1->right = temp;
					temp1->left = current;
					temp = temp1;
					return;
				}
				else{
					current = temp;
					temp = temp->right;
					temp->left = current;
					 return;
				}
			}
		}

		void in_order(node *temp){
			//int hl = 0;
			//int hr = 0;
			
  			if(temp->left!=NULL ){
  				//hl = height(temp->left)+1;
    			in_order(temp->left);
    		}
    		cout<<temp->info<<endl;
  			if(temp->right!=NULL ){
  				//hr = height(temp->right)+1;
				in_order(temp->right);
		 	}
		 	//cout<<temp->info<<"->"<<"bf = "<<hl-hr<<endl;
		}
		int height(node *temp) {
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
        	else if (rh > lh) {
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
			//cout<<"->"<<" bfsd = "<<bf<<endl;
		}
};
int main(){
	BST b;
	for(int i=0;i<6;i++){
		cout<<"Enter number to insert in tree :"<<endl;
		cin>>b.number;
		b.AVL_inser(b.root);	
	}
	b.in_order(b.root);
	cout<<endl;
	//b.BF(b.root);
	//cout<<endl;
}





