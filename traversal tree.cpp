void in_order(node *temp){
  			if( temp->left!=NULL )
    			in_order(temp->left);
  			cout<<temp->info<<"  ";
  			if(temp->right!=NULL)
		 		in_order(temp->right);
  					//return;
  			if(root==NULL){
				cout<<" Tree is empty.\n";
				return;
    		}
}
void post_order(node *temp){
  			if( temp->left!=NULL )
    			post_order(temp->left);
  			if(temp->right!=NULL)
		 		post_order(temp->right);
		 	cout<<temp->info<<"  ";
  			if(root==NULL){
				cout<<" Tree is empty.\n";
				return;
    		}
		}
void pre_order(node *temp){
	if(root == NULL){
		cout<<"Tree is empty "<<endl;
		//return;
	}
	cout<<temp->info<<" ";
	if(temp->left!=NULL){
		pre_order(temp->left);
		//return;
	}
	if(temp->right!=NULL){
		pre_order(temp->right);
		//return;
	}	
}
