#include <iostream>
using namespace std;


struct node
{
	int info;
	node *next;
	node *behind;
};

struct main_list 
{
	char info;
	main_list *down;
	node *right;
	int index;
};

class graph{
	private:
		main_list *temp;
		int count;
		char value;
		main_list *extra_temp;
		int storing_index;
	public:	
		main_list *root;
		graph(){
			temp = NULL;
			count = 0;
			value = 0;
			root = NULL;
			storing_index = 0;
		}
		int insertion(main_list *temp){
			cout << "Enter the value for the Node " << endl;
			cin >> value;
			if (root == NULL)
			{
				root = new main_list;
				root ->info = value;
				count ++;
				root->down	= NULL;
				root->right = NULL;
				root->index = count;
				// cout << "Index is " << root ->index << endl;
				temp = root;
			}
			else
			{
				while(temp->down != NULL)
				{
					temp = temp->down;
				}
				temp->down = new main_list();
				temp->down->info = value;
				count++;
				temp = temp->down;
				temp->down = NULL;
				temp->right = NULL;
				temp->index = count;
			}
		}

		int linking_with_Node(main_list *temp){
			temp = root;
			if (temp == NULL)
			{
				cout << "Graph does not Exit" << endl;
				return 0;
			}
			if (temp->down == NULL)
			{
				cout << "Sorry there is one node Exist so you can't able to link with another node"<< endl;
				cout << "Else if want to link with its self so press 1: " << endl;
				cout << "If you want to exit press any key" << endl;
				int pressing;
				cin >> pressing;
				if (pressing == 1)
				{
					temp->right = new node;
					node *link_root = temp->right;
					link_root ->info = temp->index;
					link_root ->behind = NULL;
					link_root->next = NULL;
					return 0;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				cout << "Hello World"<<endl;
				if(temp ->down != NULL)
				{
					char first_link;
					cout << "Enter first value for Link" << endl;
					cin >> first_link;
					searching(first_link);
				}
				if (extra_temp->right == NULL)
				{
					extra_temp ->right = new node;
					temp = extra_temp;
					node *list_temp = extra_temp ->right;
					extra_temp->info = storing_index;
				}
				else{
					node *list_temp = extra_temp ->right;
					while(list_temp ->next != NULL)
					{
						if(extra_temp ->index == storing_index)
						{
							node *behinding = list_temp;

							if (behinding->behind == NULL)
							{
								behinding->behind = new node;
								behinding->behind->info = storing_index;
							}
							else
							{
								while(behinding ->behind != NULL){
									behinding = behinding->behind;
								}

								behinding->behind= new node;
								behinding->behind->info = storing_index;
								behinding->behind->behind = NULL;
								return 0;
							}

						}
					}
				}

			}


		}

		int searching (char value )
		{
			int flag = 0;
			extra_temp = root;
			while(extra_temp->down != NULL)
			{
				if (extra_temp ->info == value)
				{
					cout << "Value found" << endl;
					flag = 1;
					break;
				}
				extra_temp = extra_temp->down;
			}
			if(flag == 1)
			{
				char val;
				cout << "Enter second value with first linking " << endl;
				cin >> val;
				main_list *extra_temp1 = root;
				while(extra_temp1 ->down != NULL)
				{
					if (extra_temp1 ->info == val)
					{
						cout<<"hi"<<endl;
						cout << "2nd value is found " << endl;
						storing_index = extra_temp1->index;
						break;
					}
					extra_temp1 = extra_temp1 ->down;
				}
				flag = 0;
				return 1;
				}
			else
			{
				flag  = 0;
				cout << "NO value is Found" << endl;
				return 0;

			}
		}
};

int main (){
	graph G1;
	for(int i = 0 ;i < 5; i++){
		G1.insertion(G1.root);
	}
	for (int i = 0; i < 5; ++i)
	{
		char vale;
		cin >> vale;
		G1.searching(vale);
	}

	

}
