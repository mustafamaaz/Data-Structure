#include<iostream>

using namespace std;

struct Node{
	
	Node* next;
	Node* prev;
	char info;
		
		
		Node(){
			next = NULL;
			prev = NULL;
		}
};

class DLL{
	public:
		Node* head;
		char number;
		Node* temp1;
		Node* temp2;
		int nextCount;
		int prevCount;
		int count;
		
		DLL(){
			head = NULL;
			temp1 = NULL;
			nextCount = 0;
			prevCount = 0;
			temp2 = NULL;
			count = 0;
		}
		
		void insert(Node* temp){
			
			if(head == NULL){
				head = new Node;
				head->info = number;
				head->next = NULL;
				head->prev = NULL;
				
				return;
			}
			
			temp = head;
			
			
			while(temp->next != NULL){
				temp = temp->next;
			}
			
			temp1 = new Node;
			
			temp1->next = temp->next;
			temp1->prev = temp;
			temp->next = temp1;
			temp1->info = number;
			
			return;
			
		}
		
		void takeToEnd(){
			if(temp2->next != NULL){
				temp2 = temp2->next;
				takeToEnd();
			}
		}
		
		void checkifitis(Node* start , Node* end){
			if(start != end && start->info == end->info){
				checkifitis(start->next , end->prev);
			}
			else{
				count++;
			}
		}
		
		void checkPalindrome(){
			temp1 = head;
			temp2 = head;
			
			takeToEnd();  // take temp2 to last node;
			
			checkifitis(temp1 , temp2);
			
			if(count == 0 || count == 1){
				cout<<"Palindrome";
			}
			else{
				cout<<"Not A Palindrome";
			}
		}
		
		void print(Node *temp){
			
			temp = head;
			
			if(head == NULL){
				cout<<"Nothing To Print"<<endl<<endl;
				return;
			}
			
			while(temp != NULL){
				cout<<temp->info<<"  ";
				
				temp = temp->next;
			
			}
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
			
			T.checkPalindrome();
			
		}
		else{
			cout<<"Wrong Option "<<endl<<endl;
		}
		
		cout<<endl<<endl;
	}
	while(1);
	
	
	
	
	return 0;
}