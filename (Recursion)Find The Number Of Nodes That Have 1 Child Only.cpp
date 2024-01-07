#include<iostream>
#include<string.h>

using namespace std;

struct Node{
	int info;
	Node *left;
	Node *right;
	
	Node(){
		left = NULL;
		right = NULL;
	}
};

class tree{
	public:
		
		int singleChildNodes;	
		Node *root;
		Node *temp;
		Node *temp1;
		int number;
		
	tree(){
		singleChildNodes = 0;
		root = NULL;
		temp = NULL;
		temp1 = NULL;
	}	
	
	void insertion(Node *head){
		if(head == NULL && head == root){
			root = new Node;
			root->info = number;
		}
		else{
			if(number < head->info && head->left != NULL){
				insertion(head->left);
			}
			else if(number > head->info && head->right != NULL){
				insertion(head->right);
			}
			else{
				if(number < head->info){
					head->left = new Node;
					head->left->info = number;
				}
				else{
					head->right = new Node;
					head->right->info = number;
				}
			}
		}
	}
	
	Node* returnSuccessor(Node* head){
		while(head->left != NULL){
			head = head->left;
		}
		
		return head;
	}
	
	Node* deletion(Node *head){
		if(head == NULL){
			return head;
		}
		else if(number < head->info){
			head->left = deletion(head->left);
		}
		else if(number > head->info){
			head->right = deletion(head->right);
		}
		else{
			if(head->right == NULL && head->left == NULL){
				delete head;
				head = NULL;
			}
			else if(head->left == NULL){
				temp = head;
				head = head->right;
				delete temp;
				temp = NULL;
			}
			else if(head->right == NULL){
				temp = head;
				head = head->left;
				delete temp;
				temp = NULL;
			}
			else{
				temp = returnSuccessor(head->right);
				head->info = temp->info;
				number = temp->info;
				head->right = deletion(head->right);
			}
		}
		return head;
		
	}
	
	void check1ChildNodes(Node *head){
		if(head == root && head == NULL){
			cout<<"Nothing In the Tree"<<endl;
			return;
		}
		else{
			
			
			if(!(head->right == NULL && head->left == NULL || head->right != NULL && head->left != NULL)){
				singleChildNodes++;	
			}
			
			
			if(head->left != NULL){
				check1ChildNodes(head->left);
			}
			
			if(head->right != NULL){
				check1ChildNodes(head->right);
			}
		}
		
	}
	
	void in_Order(Node *head){
		if(head == NULL && head == root){
			cout<<"Nothing To Print"<<endl<<endl;
		}
		else{
			if(head->left != NULL){
				in_Order(head->left);
			}
			
			cout<<head->info<<" ";
			
			if(head->right != NULL){
				in_Order(head->right);
			}
		}
	}
	
};

int main(){
	tree T;
	int option;
	
	do{
		cout<<"1. Insert Into The Tree"<<endl;
		cout<<"2. Delete From The Tree"<<endl;
		cout<<"3. In Order triversal"<<endl;
		cout<<"4. Check Number Of Nodes With 1 Child"<<endl;
		cout<<"5. Exit"<<endl<<endl;
		cout<<"Enter Your Option : ";
		cin>>option;
		
		if(option == 1){
			cout<<"Enter The Number To Insert : ";
			cin>>T.number;
			T.insertion(T.root);
		}
		else if(option == 2){
			cout<<"Enter The Number To Delete : ";
			cin>>T.number;
			T.root = T.deletion(T.root);
		}
		else if(option == 3){
			T.in_Order(T.root);
			cout<<endl<<endl;
		}
		else if(option == 4){
			T.singleChildNodes = 0;
			T.check1ChildNodes(T.root);
			cout<<"There Are "<<T.singleChildNodes<<" Nodes With Single Child In The Tree"<<endl<<endl;
		}
		else if(option == 5){
			break;
		}
		else{
			cout<<"Wrong Option"<<endl<<endl;
		}
	}
	while(option != 5);
}