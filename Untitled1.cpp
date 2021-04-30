#include<iostream>
using namespace std;

struct node{
	int info;
	node *right,*left;
};
class CBT{
	private:
		bool flag;
	public:
		int swap;
		node *root,*temp,*ptr;
		int number,count;
	    int	 h,ph;
		CBT(){
			root = ptr = temp = NULL;
			h = ph = 0;
			flag = false;
		}
		void CBT_insertion(node *temp){
			flag = false;
			if(root == NULL){
				temp = new node;
				temp->info = number;
				temp->left = NULL;
				temp->right = NULL;
				root = temp;
				count++;
				return;
			}
			else if(count == pow(h)){
				while(temp->left!=NULL){
					temp = temp->left;
				}
				temp->left = new node;
				temp->left->info = number;
				temp->left->left = NULL;
				temp->left->right = NULL;
				count++;
				h++;
				return;
			}
			else if(count != pow(h)){
				set(temp);
				if(ptr->left!=NULL && ptr->right == NULL){
					cout << "right: " << endl;  
					temp = new node;
					temp->info = number;
					ptr->right = temp;
					temp->left = NULL;
					temp->right = NULL;
					minheap(root);
					count++;
					return;
				}
				if(ptr->left ==NULL && ptr->right == NULL){
					cout << "left: " << endl;  
					temp = new node;
					temp->info = number;
					ptr->left = temp;
					temp->left = NULL;
					temp->right = NULL;
					minheap(root);
					count++;
					return;
				}
			}

		}
		void set(node *temp){
			if(temp->left != NULL && ph<h){
				ph++;
				set(temp->left);
				ph--;
			}
			if(temp->right!=NULL && ph<h){
				ph++;
				set(temp->right);
				ph--;
			}
			if(temp->left == NULL && ph == h-1 || temp->right == NULL && ph == h-1){
				if(flag == false){
					ptr = temp;
					flag = true;
					return;
				}
			}
		}
		
		int pow(int h){
			int result = 2;
			int y = h+1;
			for(int i = 1;i<y;i++){
				result = result*2;
			}
			return result-1;
		}
		void in_order(node *temp){
  			if(temp->left!=NULL ){
    			in_order(temp->left);
    		}
    		cout<<temp->info<<endl;
  			if(temp->right!=NULL ){
				in_order(temp->right);
		 	}
		}
		void left_heap(node *temp){
			if(temp->left == NULL){
				return;
			}
			if(temp->info>temp->left->info){
				swap = temp->info;
				temp->info = temp->left->info;
				temp->left->info = swap;
				return;
			}
			else{
				return;
			}
		}
		void right_heap(node *temp){
			if(temp->right == NULL){
				return;
			}
			if(temp->info>temp->right->info){
				swap = temp->info;
				temp->info = temp->right->info;
				temp->right->info = swap;
				return;
			}
			else{
				return;
			}
		}
		void minheap(node *temp){
			if(temp->left!=NULL){
				left_heap(temp);
				right_heap(temp);
				minheap(temp->left);	
			}
			if(temp->right != NULL ){
				left_heap(temp);
				right_heap(temp);
				minheap(temp->right);
			}
		}
};
int main(){
	CBT b;
	for(int i=0;i<6;i++){
		cout<<"Enter number to insert in tree :"<<endl;
		cin>>b.number;
		b.CBT_insertion(b.root);
	}
	b.in_order(b.root);
	cout<<endl;
}

