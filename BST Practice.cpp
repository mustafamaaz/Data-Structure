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
	
	
class BST{
	public:
	
		int countNodes;
		
		Node* root;
		Node* temp;
			
		int number;
		int mid;
		int check;
		int counter;
		int bolian;
		int bolian2;
			
		BST(){
			root = NULL;
			temp = NULL;
			countNodes = 0;
			mid = 0;
			counter = 0;
			check = 0;
			bolian = 1;
			bolian2 = 0;
		}
			
		void insertion(Node* head){
			if(head == root && root == NULL){
				root = new Node;
				root->info = number;
				
				return;
			}
				
			if(number < head->info && head->left != NULL){
				insertion(head->left);
			}
			else if(number > head->info && head->right != NULL){
				insertion(head->right);
			}
			else if(number == head->info){
				cout<<"Cannot Add A Duplicate"<<endl;
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
		
		Node* findSuccessor(Node* head){
			while(head->left != NULL){
				head = head->left;
			}
			
			return head;
		}
		
		Node* deletion(Node* head){
			if(head == root && root == NULL){
				cout<<"Nothing To Delete From The Tree"<<endl<<endl;
			}
			else if(number < head->info){
				head->left = deletion(head->left);
			}
			else if(number > head->info){
				head->right = deletion(head->right);
			}
			else{
				if(head->left == NULL && head->right == NULL){
					delete head;
					head = NULL;
				}
				else if(head->left == NULL){
					temp = head;
					head = head->right;
					delete temp;
				}
				else if(head->right == NULL){
					temp = head;
					head = head->left;
					delete temp;
				}
				else{
					
					temp = findSuccessor(head->right);
					
					head->info = temp->info;
					number = temp->info;
					head->right = deletion(head->right);
					
				}
			}
			
			return head;
		}
		
		void in_Order(Node *head){
			if(root == head && root == NULL){
				cout<<"Nothing To Triverse In The Tree"<<endl<<endl;
				return;
			}
			
			if(head->left != NULL){
				in_Order(head->left);
			}
		
			countNodes++;
			cout<<head->info<<" ";
			
			if(head->right != NULL){
				in_Order(head->right);
			}
		}
		
		void findMid(Node* head){
			if(head == root && root == NULL){
				cout<<"Nothing To Triverse"<<endl<<endl;
				return;
			}
			
			if(head->left != NULL){
				findMid(head->left);
			}
			
			if(mid == countNodes/2){
				
				cout<<"Mid Number Is : "<<head->info<<endl;
				
			}
			
			mid++;
			
			if(head->right != NULL){
				findMid(head->right);
			}
		
		}
		
		
		bool checkLeafLevel(Node *head){
			if(root == head && root == NULL){
				cout<<"Nothing To Triverse In The Tree"<<endl<<endl;
				return bolian2; 
			}
			
			if(head->left == NULL && head->right == NULL && bolian == 1){
				check = counter;
				bolian = 0;
			}
			
			if(head->left == NULL && head->right == NULL && bolian == 0){
				
				if(check != counter){	
					bolian2 = 1;
				}
				
			}

			if(head->left != NULL){
				counter++;
				checkLeafLevel(head->left);
			}
				
			cout<<head->info<<" ";
			
			if(head->right != NULL){
				counter++;
				checkLeafLevel(head->right);
			}
			
			counter--;
			return bolian2;
		}

};


int main(){
	BST T;
	
	int option;
	
	do{
		cout<<"1. Insert"<<endl;
		cout<<"2. Delete"<<endl;
		cout<<"3. Print In Order"<<endl;
		cout<<"4. Find Mid Number in Odd Number Of Nodes"<<endl;
		cout<<"5. Exit"<<endl;
		cout<<"6. Find Nodes If On The Same Level"<<endl<<endl;
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
			
		}
		else if(option == 4){
			T.countNodes = 0;
			T.mid = 0;
			
			T.in_Order(T.root);
			cout<<" Elements Are "<<T.countNodes<<" In The Tree"<<endl;
			T.findMid(T.root);
		}
		else if(option == 5){
			break;
		}
		else if(option == 6){
			T.counter = 0;
			T.check = 0;
			T.bolian = 1;
			T.bolian2 = 0;
			
			if(T.root == NULL){
				cout<<"There is Nothing In The Tree"<<endl<<endl;
			}
			else{
				
				
				if(T.checkLeafLevel(T.root)== 0){
					cout<<"They Are On The Same Level"<<endl;
				}
				else{
					cout<<"They Are Not On The Same Level"<<endl;
				}
				
			}
			
		}
		else{
			cout<<"Wrong Option"<<endl<<endl;
		}
		
		cout<<endl<<endl;
	}
	while(option != 5);
	
	
	
}


