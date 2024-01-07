#include<iostream>

using namespace std;

struct Node{
	
	Node* next;
	Node* prev;
	int info;
		
		
		Node(){
			next = NULL;
			prev = NULL;
		}
};

class DLL{
	public:
		Node* head;
		int number;
		Node* temp1;
		int nextCount;
		int prevCount;
		
		DLL(){
			head = NULL;
			temp1 = NULL;
			nextCount = 0;
			prevCount = 0;
		}
		
		void insert(Node* temp){
			
			if(head == NULL){
				head = new Node;
				head->info = number;
				head->next = head;
				head->prev = head;
				
				return;
			}
			
			temp = head;
			
			do{
				temp = temp->next;
			}
			while(temp->next != head);
			
			temp1 = new Node;
			
			head->prev = temp1;
			temp1->next = temp->next;
			temp1->prev = temp;
			temp->next = temp1;
			temp1->info = number;
			
			return;
			
		}
		
		void checkFront(Node* temp){
			if(temp->info != number){
				nextCount++;
				checkFront(temp->next);
			}
		}
		
		void checkPrev(Node* temp){
			if(temp->info != number){
				prevCount++;
				checkPrev(temp->prev);
			}
		}
		
		void print(Node *temp){
			
			temp = head;
			
			if(head == NULL){
				cout<<"Nothing To Print"<<endl<<endl;
				return;
			}
			
			do{
				cout<<temp->info<<"  ";
				
				temp = temp->next;
			
			}
			while(temp != head);
		}
};

int main(){
	
	DLL T;
	int option;
	
	do{
		cout<<"1. Insert"<<endl;
		cout<<"2. Print"<<endl;
		cout<<"3. Find Distance"<<endl<<endl;
		
		cout<<"Enter Your Option : ";
		cin>>option;
		
		if(option == 1){
			cout<<"Enter THe Number To Insert : ";
			cin>>T.number;
			T.insert(T.head);
		}
		else if(option == 2){
			T.print(T.head);
		}
		else if(option == 3){
			
			T.nextCount = 0;
			T.prevCount = 0;
			
			cout<<"Enter The Number That You Want To Check Its Distance : ";
			cin>>T.number;
			
			T.checkFront(T.head);
			T.checkPrev(T.head);
			
			if(T.nextCount == 0 && T.prevCount == 0){
				cout<<"Number Is Present In The Head"<<endl;
			}
			else if(T.nextCount > T.prevCount){
				cout<<"It Is Closer By Going Through Previous Pointer"<<endl<<endl;
			}
			else if(T.nextCount < T.prevCount){
				cout<<"It is Closer By Going Through Next Pointer"<<endl<<endl;
			}
			else if(T.nextCount == T.prevCount){
				cout<<"It Is In The Same Distance"<<endl;
			}
		}
		else{
			cout<<"Wrong Option "<<endl<<endl;
		}
		
		cout<<endl<<endl;
	}
	while(1);
	
	
	
	
	return 0;
}