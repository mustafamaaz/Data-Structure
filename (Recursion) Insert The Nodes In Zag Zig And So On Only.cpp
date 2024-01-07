#include<iostream>

using namespace std;

struct Node{
	
	int info;
	Node* left;
	Node* right;
	
	Node(){
		left = NULL;
		right = NULL;
	}
};

class BT{
	public:
		Node* root;
		int check;
		int number;
		
		BT(){
			root = NULL;
			check = 0;
		}
		
		void insert(Node *head){
			if(root == NULL){
				root = new Node;
				root->info = number;
				return;
			}
			if(head->left != NULL){
				insert(head->left);
			}
			else if(head->right != NULL){
				insert(head->right);
			}
			else{
				if(!check){
					cout<<"Inserted In Left"<<endl;
					head->left = new Node;
					head->left->info = number;
				}
				else{
					cout<<"Inserted In Right"<<endl;
					head->right = new Node;
					head->right->info = number;
				}
				check = !check;
			}
		}
		
		void printTree(Node* head){
			if(head == NULL){
				cout<<"Nothing To Print In The Tree"<<endl<<endl;
				return;
			}
			
			cout<<head->info<<"  ";
			
			if(head->left != NULL){
				printTree(head->left);
			}
			
			if(head->right != NULL){
				printTree(head->right);
			}
		}
};


int main(){
	
	BT T;
	int option;
	
	cout<<"Insert At Root Left First Press 0"<<endl;
	cout<<"Insert At Root Right  First Press 1"<<endl;
	cin>>T.check;
	
	
	do{
		cout<<"1. Enter A Number"<<endl;
		cout<<"2. Print"<<endl;
		cout<<"3. Exit"<<endl<<endl;
		cout<<"Enter Your Option : ";
		cin>>option;
		
		if(option == 1){
			
			cout<<"Enter The Number To Insert : ";
			cin>>T.number;
			
			
			T.insert(T.root);
		}
		else if(option == 2){
			cout<<"Printing Now : ";
			T.printTree(T.root);
			
			
		}
		else if(option == 3){
			break;
		}
		else{
			cout<<"Wrong Option "<<endl<<endl;
		}
		
		cout<<endl<<endl;
	}
	while(option != 3);
	
	
	
	
	
	return 0;
}