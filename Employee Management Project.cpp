//
//							Name 							Tashfeen  Latif
//							Roll No							17P - 6035(A)
//							Course							Data Structures
//		
//							Project							Employee Management System
//							Prof							M.Waqas


#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<windows.h>
using namespace std;


struct TreeNode{
	int EmpIdentity;
	TreeNode *right, *left;
	int height;
	
	string EmpName;
	string EmpFatherName;
	int EmpAge;
	string EmpPost;
	int EmpSalary;
	string EmpNo;
	string EmpAddress;
};

class BankEmployee{
	private:
		TreeNode *ptr;	
	public:
		int valu;
		TreeNode *temp;
		TreeNode *root;
		int val, sal, age;
		string cellno;
		bool flag;
		string name , fathname,  designation , adder;
	BankEmployee()
	{
		root = NULL;
		temp = NULL;
		ptr = NULL;
		flag = true;
	}
	~BankEmployee(){
		delete root , temp , ptr;
	}
	void face()
	{
		cout << "                                        W"; Sleep(200); cout << "E"; Sleep(200); cout << "L"; Sleep(200); cout << "C"; Sleep(200); cout << "O"; Sleep(200); cout << "M"; Sleep(200); cout << "E";
		Sleep(200); cout << " T"; Sleep(200); cout << "O "; Sleep(200);cout << "B"; Sleep(200);cout << "A"; Sleep(200);cout << "N"; Sleep(200);cout << "K " ; Sleep(200);cout << "E"; Sleep(200); cout << "M"; Sleep(200); cout << "P"; Sleep(200); cout << "L"; cout <<"O"; Sleep(200); cout<<"Y "; Sleep(200);cout<<"M";Sleep(200); cout<<"A";Sleep(200); cout<<"N"; Sleep(200); cout <<"A"; Sleep(200); cout << "G"; Sleep(200); cout << "E"; Sleep(200); cout << "M"; Sleep(200); cout << "E"; Sleep(200); cout << "N"; Sleep(200); cout << "T "; Sleep(200); cout << "S"; Sleep(200); cout << "Y"; cout << "S"; Sleep(200); cout << "T"; Sleep(200); cout << "E"; Sleep(200); cout << "M";
	}
	int Findmax(int num1, int num2)
	{
		if(num1 > num2)
		{
			return num1;
		}
		else
		{
			return num2;
		}
	}
	
	int height(TreeNode *temp)
	{
		if(temp == NULL)
		{
			return 0;
		}
		
		int lh = height(temp->left);
		int rh = height(temp->right);
		
		if(lh > rh)
		{
			return lh+1;
		}
		
		else
		{
			return rh+1;
		}
	}
	
	TreeNode *left_rotation(TreeNode *temp)
	{
		ptr = temp->right;
		temp->right = ptr->left;
		ptr->left = temp;
		
		temp->height = max(height(temp->left), height(ptr->right)) + 1;
		ptr->height = max(height(temp->left), height(ptr->right)) + 1;
		
		return ptr;
	}
	
	TreeNode *right_rotation(TreeNode *temp)
	{	
		ptr = temp->left;
		temp->left = ptr->right;
		ptr->right = temp;
		
		temp->height = max(height(temp->left), height(temp->right)) +1;
		ptr->height = max(height(ptr->left), height(ptr->right)) +1;
		
		return ptr;
	}
	
	TreeNode *right_left_rotation(TreeNode *temp)
	{	
		
		temp->right = right_rotation(temp->right);
		return left_rotation(temp);
	}
	
	TreeNode *left_right_rotation(TreeNode *temp)
	{	
		
		temp->left = left_rotation(temp->left);
		return right_rotation(temp);
	}
	TreeNode *Add_Employees_in_bank(TreeNode *temp, int number ,string name , string fathername, int age , string post , int salary ,string phone , string address)
	{
		// cout << "Come in Add_Employees_in_bank:"<<endl;
		if(temp == NULL)
		{
			temp = new TreeNode;
			temp->EmpIdentity = number;
			temp->left = NULL;
			temp->right = NULL;			
			temp->height = 0;

			temp->EmpName = name;

			temp->EmpFatherName = fathername;

			temp->EmpAge = age;
			
			temp->EmpPost = post;

			temp->EmpSalary = salary;
						
			temp->EmpAddress = address;
				
			temp->EmpNo = phone;
	
		}
	
		if(number < temp->EmpIdentity)
		{
			temp->left = Add_Employees_in_bank(temp->left, number,name ,fathername,age ,post , salary ,phone , address);
			
			if(height(temp->left) - height(temp->right) == 2)
			{
				if(number < temp->left->EmpIdentity)
				{
					temp = right_rotation(temp);
				}
				else
				{
					temp = left_right_rotation(temp);
				}
			}
		}
		if(number > temp->EmpIdentity)
		{
			temp->right = Add_Employees_in_bank(temp->right, number,name ,fathername,age ,post , salary ,phone , address);
			
			if(height(temp->right) - height(temp->left) == 2)
			{
				if(number > temp->right->EmpIdentity)
				{
					temp = left_rotation(temp);
				}
				else
				{
					temp = right_left_rotation(temp);
				}
			}
		}
		temp->height = max(height(temp->left), height(temp->right)) +1 ;
		return temp;
	}
	
	TreeNode *User_Based_Employ_Entry(TreeNode *temp,int number){
		if(temp == NULL)
	{	
		temp = new TreeNode;
		
		temp->EmpIdentity = val;
		
		temp->EmpName = name;
		
		temp->EmpFatherName = fathname;
		
		temp->EmpAge = age;
		
		temp->EmpPost =  designation;
		
		temp->EmpSalary = sal;
		
		temp->EmpNo = cellno;
		
		temp->EmpAddress = adder;
		
		temp->left = NULL;
		temp->right = NULL;			
		temp->height = 0;
		
		}
	
		if(number < temp->EmpIdentity)
		{
			temp->left = User_Based_Employ_Entry(temp->left,number);
			
			if(height(temp->left) - height(temp->right) == 2)
			{
				if(number < temp->left->EmpIdentity)
				{
					temp = right_rotation(temp);
				}
				else
				{
					temp = left_right_rotation(temp);
				}
			}
		}
		if(number > temp->EmpIdentity)
		{
			temp->right = User_Based_Employ_Entry(temp->right,number);
			
			if(height(temp->right) - height(temp->left) == 2)
			{
				if(number > temp->right->EmpIdentity)
				{
					temp = left_rotation(temp);
				}
				else
				{
					temp = right_left_rotation(temp);
				}
			}
		}
		temp->height = max(height(temp->left), height(temp->right)) +1 ;
		return temp;
	}
	
	///////////////////////////////////////////////////////////////////////////////////
	
	TreeNode *min(TreeNode *temp)
	{
		if(temp == NULL)
		{
			return 0;	
		}	
		if(temp->left == NULL)
		{
			return temp;
		}
		else
		{
			min(temp->left);
		}
		
	}	

	
	
	TreeNode *balance(TreeNode *temp)
	{
		if(temp == NULL)
		{
			cout<< "No Rotation is found "<<endl;
		}
		else if( height(temp->left)-height(temp->right) > 1)
		{
			if(height(temp->left->left) >= height(temp->left->right))
			{
				temp = right_rotation(temp);
			}
			else
			{
				temp = left_right_rotation(temp);
			}
		}
		else if( height(temp->right) - height(temp->left) > 1)
		{
			
			if(height(temp->right->right) >= height(temp->right->left))
			{
				temp = left_rotation(temp);
			}
			else
			{
				temp = right_left_rotation(temp);
			}
		}
		temp->height = max(height(temp->left), height(temp->right)) + 1;
		return temp;
	}

	TreeNode *Remove_Employees(TreeNode *temp, int number)
	{
		if(temp == NULL)
		{
			cout<<"The value is not found "<<endl;
		}
		else if(number < temp->EmpIdentity)
		{  
			temp->left = Remove_Employees(temp->left, number);
		}
		else if(number > temp->EmpIdentity)
		{
			temp->right = Remove_Employees(temp->right, number);
		}
		else if(temp->left && temp->right)
		{
			ptr = min(temp->right);
			temp->EmpIdentity = ptr->EmpIdentity;
			temp->right = Remove_Employees(temp->right, temp->EmpIdentity);
		}
		else
		{
			ptr = temp;
			if(temp->left == NULL)
			{ 
				temp = temp->right;
			}
			else if(temp->right == NULL)
			{
				temp = temp->left;
			}
			delete ptr;
		}
		if(temp != NULL)
		{
			temp = balance(temp);
		}

		return temp;
		
	}
		
	///////////////////////////////////////////////////////////////////////////////////
	void in_order(TreeNode *temp)
	{
		if(temp->left != NULL)
		{
			in_order(temp->left);
		}
		cout << temp->EmpIdentity << "    ";
		if(temp->right != NULL)
		{
			in_order(temp->right);
		}
	}
	void View_Employ_List(TreeNode *temp)
	{	
		
		cout << temp->EmpIdentity <<"         "; 
		cout << temp->EmpName << "        ";
		cout << temp->EmpFatherName<<"	      "; 
		cout << temp->EmpAge<<"      ";
		cout << temp->EmpSalary<<"        ";
		cout << temp->EmpNo<<"      ";
		cout << temp->EmpAddress<<"       ";
		cout << temp->EmpPost<<"";
		cout << endl;
		
		if(temp->left != NULL)
		{
			View_Employ_List(temp->left);
		}
			if(temp->right != NULL)
		{
			View_Employ_List(temp->right);
		}
		
	}
	
	void post_order(TreeNode *temp)
	{
		
		if(temp->left != NULL)
		{
			View_Employ_List(temp->left);
		}
		if(temp->right != NULL)
		{
			View_Employ_List(temp->right);
		}
		cout << temp->EmpIdentity <<"   ";
	}
	void update_employee_address(TreeNode*temp,int key){
		
		
		if(temp->left != NULL)
		{
			update_employee_address(temp->left,key);
		}
		if(key == temp->EmpIdentity){
			flag = false;	
			
			cout << "Employ Imformation:"<<endl;
			cout << temp->EmpIdentity <<"   "; 
			cout << temp->EmpName << " ";
			cout << temp->EmpFatherName<< " ";
			cout << temp->EmpNo<< " ";
			cout << temp->EmpPost<< " ";
			cout << temp->EmpSalary<< " ";
			cout << temp->EmpAge<< " ";
			cout << temp->EmpAddress<< " ";
			cout << endl;
			
			cout << "Enter New Address of Employee"<<endl;
			cin >>temp->EmpAddress;
			cout << temp->EmpIdentity <<"   "; 
			cout << temp->EmpName << " ";
			cout << temp->EmpFatherName<< " ";
			cout << temp->EmpNo<< " ";
			cout << temp->EmpPost<< " ";
			cout << temp->EmpSalary<< " ";
			cout << temp->EmpAge<< " ";
			cout << temp->EmpAddress<< " ";
			cout << endl;
			cout << "Address is succesfully update:"<<endl;

			
		}
		if(temp->right != NULL)
		{
			update_employee_address(temp->right,key);
		
		}
	}
		void Update_Employee_Post(TreeNode*temp,int key){
		if(temp->left != NULL)
		{
			Update_Employee_Post(temp->left,key);
		}
		if(key == temp->EmpIdentity){
			flag = false;	
			
			cout << "Employ Imformation before Promotion:"<<endl;
			cout << temp->EmpIdentity <<"   "; 
			cout << temp->EmpName << " ";
			cout << temp->EmpFatherName<< " ";
			cout << temp->EmpNo<< " ";
			cout << temp->EmpPost<< " ";
			cout << temp->EmpSalary<< " ";
			cout << temp->EmpAge<< " ";
			cout << temp->EmpAddress<< " ";
			cout << endl;
			
			cout << "Enter New Post of Employee"<<endl;
			cin >>temp->EmpPost;
			
			cout << "Employ Imformation After Promotion:"<<endl;
			cout << temp->EmpIdentity <<"   "; 
			cout << temp->EmpName << " ";
			cout << temp->EmpFatherName<< " ";
			cout << temp->EmpNo<< " ";
			cout << temp->EmpPost<< " ";
			cout << temp->EmpSalary<< " ";
			cout << temp->EmpAge<< " ";
			cout << temp->EmpAddress<< " ";
			cout << endl;
			cout << "Post is succesfully update:"<<endl;
			cout << "Congratulations teri Promotion ho gayii     Balayyyy:"<<endl;
			cout << "Treat Khila bache :"<<endl;
			
		}
		if(temp->right != NULL)
		{
			Update_Employee_Post(temp->right,key);
		
		}
	}	
	void Update_Employee_Sallary(TreeNode*temp,int key){
		if(temp->left != NULL)
		{
			Update_Employee_Sallary(temp->left,key);
		}
		if(key == temp->EmpIdentity){
			flag = false;	
			
			cout << "Employ Sallary Imformation before Promotion:"<<endl;
			cout << temp->EmpIdentity <<"   "; 
			cout << temp->EmpName << " ";
			cout << temp->EmpFatherName<< " ";
			cout << temp->EmpNo<< " ";
			cout << temp->EmpPost<< " ";
			cout << temp->EmpSalary<< " ";
			cout << temp->EmpAge<< " ";
			cout << temp->EmpAddress<< " ";
			cout << endl;
			
			cout << "Enter New Sallary of Employee"<<endl;
			cin >>temp->EmpSalary;
			
			cout << "Employ Sallary Imformation After Promotion:"<<endl;
			cout << temp->EmpIdentity <<"   "; 
			cout << temp->EmpName << " ";
			cout << temp->EmpFatherName<< " ";
			cout << temp->EmpNo<< " ";
			cout << temp->EmpPost<< " ";
			cout << temp->EmpSalary<< " ";
			cout << temp->EmpAge<< " ";
			cout << temp->EmpAddress<< " ";
			cout << endl;
			cout << "Sallary is succesfully update:"<<endl;
			cout << "Congratulations teri Promotion ho gayii Balayyyy:"<<endl;
			cout << "Treat Khila bachay :"<<endl;
			
		}
		if(temp->right != NULL)
		{
			Update_Employee_Sallary(temp->right,key);
		
		}
	}
	void Find(TreeNode *temp,int find){			
			
			if(temp != NULL){
				Find(temp->left,find);
				if(temp->EmpIdentity == find){
				cout << "It is in bank:"<<endl;

				cout << temp->EmpIdentity <<"   "; 
				cout << temp->EmpName << " ";
				cout << temp->EmpFatherName<< " ";
				cout << temp->EmpNo<< " ";
				cout << temp->EmpPost<< " ";
				cout << temp->EmpSalary<< " ";
				cout << temp->EmpAge<< " ";
				cout << temp->EmpAddress<< " ";
				cout << endl;
			
				}
				Find(temp->right,find);
			}
			
	}
			
	
		
};

int main(){
	/*cout <<"***************************************************************************************************************"<<endl;
	cout <<"***************************************************************************************************************"<<endl;
	cout <<"***************************************************************************************************************"<<endl;
//	cout << "***********************************"<<endl;
	cout <<"***************************************************************************************************************"<<endl;
	cout << endl;
	cout <<"                                   |-> Welcome To Employ Management System <-|"<<endl;
	cout << endl;
	cout <<"***************************************************************************************************************"<<endl;
//	cout <<"                                                                             ********************************"<<endl;
	
	cout <<"***************************************************************************************************************"<<endl;
	cout <<"***************************************************************************************************************"<<endl;
	cout <<"***************************************************************************************************************"<<endl;
	
	*/
	
	BankEmployee BankEmp;
	BankEmp.face();
	int value[7];
	string name[7];
	string fname[7];
	int age[7];
	string post[7];
	int salary[7];
	string phone[7]; 
	string add[7];
	
	ifstream infile;
	infile.open("project.txt");
	if(infile.is_open()){
		for(int i = 0 ; i < 7; i++){
			infile >> value[i] >> name[i] >> fname[i] >> age[i]  >> salary[i] >> phone[i]  >> add[i] >> post[i] ;
	}
		cout << endl;
		
	}
	else{
		cout << "File is not open:"<<endl;
	}
	
	int selection;
	char more;
	do{
		cout << endl;
		cout << endl;
		cout << "****Enter 1-> for Add an Employ In Bank****  "<<endl;
		cout << "****Enter 2-> for See Employ****"<<endl;
		cout << "****Enter 3-> for User Input Employ:"<<endl;
		cout << "****Enter 4-> for deletion****"<<endl;
		cout << "****Enter 5-> for Update Address of Employee****"<<endl;
		cout << "****Enter 6-> for Update Post of Employee****"<<endl;
		cout << "****Enter 7-> for Update Sallary of Employee****"<<endl;
		cout << "****Enter 8-> for Search An Employee Either It is in  Bank or NOT****"<<endl;
		
		cout << endl;
		cout << "Enter your choice:"<<endl;
		cin >> selection;
		switch(selection){
			case 1:{
				for(int i = 0; i < 7; i++){
				int id = value[i];
				string naam = name[i];
				string fathname = fname[i];
				int agee = age[i];
				string pst = post[i];
				int sal = salary[i];
				string cellno = phone[i];
				string address = add[i];
				BankEmp.root = BankEmp.Add_Employees_in_bank(BankEmp.root , id , naam , fathname , agee , pst , sal , cellno ,address);	
				}
				break;
			}
			case 2:{
				cout << "EmployId"<< "   |";
				cout << " Name "<<" | ";
				cout << " FatherName "<< " |  ";
				cout << " Age "<<"   |  " ;
				cout << " Sallary "<<"  |  ";
				cout << "Phone No "<< "  | ";
				cout << "Address"<<"    |   ";
				cout << " Post "<<"    ";
				
				cout << endl;
				cout << "**********************************************************************************************"<<endl;
				BankEmp.View_Employ_List(BankEmp.root);
				break;
			}
			case 3:{
				
				cout << "Given Input From User:"<<endl;
				
				cout << "Enter Employ ENTRY NO:"<<endl;
				cin >>BankEmp.val;   	
		
				cout << "Enter Employ Name:"<<endl;
				cin >> BankEmp.name;

				cout << "Enter Employ Father Name:"<<endl;
				cin >>BankEmp.fathname;
	
				cout << "Enter Employ Age:"<<endl;	
				cin >>BankEmp.age;
			
				cout << "Enter Employ Post:"<<endl;
				cin >>BankEmp.designation;

				cout << "Enter Employ Salary:"<<endl;
				cin >> BankEmp.sal;
			
				cout << "Enter Employ Number:"<<endl;	
				cin >>BankEmp.cellno;
			
				cout << "Enter Employ Address:"<<endl;
				cin >>BankEmp.adder;

				BankEmp.User_Based_Employ_Entry(BankEmp.root,BankEmp.val);
				break;
			}
			case 4:{
				
				cout << "Before Employ is removing from Records:"<< endl;
				int Employ;
				cout << "Enter Employ Whose you want to remove from records:"<<endl;
				cin >> Employ;
				BankEmp.Remove_Employees(BankEmp.root,Employ);
				cout << "Employ is leaving company now he delete from records:"<<endl;
				break;
			}
			case 5:{
				cout << "Enter Value whose address do you want to change"<<endl;
				cin >> BankEmp.valu;
				BankEmp.update_employee_address(BankEmp.root,BankEmp.valu);
				if(BankEmp.flag == true){
					cout << "Employee is not found so we cant change his address"<<endl;
				
				}
				break;
			}
			case 6:{
				cout << "Enter Value Whose Post do you want to change"<<endl;
				cin >> BankEmp.valu;
				BankEmp.Update_Employee_Post(BankEmp.root,BankEmp.valu);
				if(BankEmp.flag == true){
					cout << "Employee is not found so we cant change his Post"<<endl;
				
				}
				break;
			}
			case 7:{
				cout << "Enter Value Whose Sallary do you want to change"<<endl;
				cin >> BankEmp.valu;
				BankEmp.Update_Employee_Sallary(BankEmp.root,BankEmp.valu);
				if(BankEmp.flag == true){
					cout << "Employee is not found so we cant change his Sallary"<<endl;
				
				}
				break;
			}
			case 8:{
				cout << "Enter Value for searching either it is in tree or not:"<<endl;
				cin >> BankEmp.valu;
				BankEmp.Find(BankEmp.root,BankEmp.valu);
				
			
				break;
			}
			default:
				cout << "It is Wrong Choice!"<<endl;
				
			}
		cout << endl << "to select more items (y/n)";
    	cin >> more;
		}while( more != 'n');
		return 0;
}


