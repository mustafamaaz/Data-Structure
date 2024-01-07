#include<iostream>
using namespace std;
class Node {
	public:
		string val;
		Node *next;
	
};
class Stack {
	public:
		Node *top , *temp;

		Stack() {
			top = NULL;

		}
		~Stack() {

		}

		bool isEmpty() {
			if(top==NULL) {
				return true;
				cout<<"Stack is empty"<<endl;
			} else {
				return false;
			}
		}

		void push(string val) {

			if(top == NULL){
				top = new Node;
				top->next = NULL;
				top->val = val;
			} else{
				temp = new Node;
				temp->next = top;
				temp->val = val;
				top = temp;
				temp = NULL;
			}

		}

		int pop() {

			if(top != NULL){
				cout<<"\n"<<top->val;
				top= top->next;
				return 0 ;
			} else {
                  cout<<"\nstack is empty";
				  return 1;
			}
			

		}

};

class Queue {
		string *front;
		string *rear;
		int size;
		string *arr;
		
	public:
	
		Queue(int size) {
			front=NULL;
			rear= NULL;
			this->size=size;
			arr=new string[size];
		}
		bool isEmpty() {
			return (front == NULL && rear == NULL) ? true : false;

		}
		bool isFull() {
		
      
        return  ( rear - front ) + 1 == size ? true : false;

		}

		void enqueue(string val) {

		if (isFull())
        {
            cout << "Queue is full. Cannot enqueue element.\n";
            return;
        }
        else if (isEmpty())
        {
            front = rear = arr;
            cout<<"empty que \n";
        }
        else
        {
            rear++;
        }

        *rear = val;
        // cout << val << " enqueued to the queue.\n";

		}

		void dequeue() {

		if (isEmpty())
        {
            cout << "Queue is empty. there is not place to visit.\n";
            return;
        }
        else if (front == rear)  
        {
            cout<<"currently at :"<<*front<<"   \n";
            front++;
        }
        else
        {
             cout<<"currently at  :"<<*front<<"   \n";
            front++;
        }

		}

		void getFront() {
		if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return ;
        }
         cout<<"front is : "<<*front;
		}
};

int main() {
	int choice , opt,move_haveli=0;
	string msg;
	// Set up the stack for encounters
	Stack encounters;



	Queue mansionQueue(6);
	mansionQueue.enqueue("The Gateway to Darkness");
	mansionQueue.enqueue("The Creeping Corridor");
	mansionQueue.enqueue("The Abandoned Lounge");
	mansionQueue.enqueue("The Haunted Gallery");
	mansionQueue.enqueue("The Shadowed Library");
	mansionQueue.enqueue("The Broken Window");
	cout<<"Start exploring the mansion? "<<endl;
	cout<<"1. Yes"<<endl;
	cout<<"2. No"<<endl;
	cin>>choice;
	if(choice==1) {
		// write the rest of the logic to control the mansion exploration
		mansionQueue.dequeue();
		move_haveli++;
		while (true)
		{
			cout<<"\nDid you encounterd the ghost or evil??\n1)Yes\n2)No\n";
			cin>>opt;

			if(move_haveli == 6){
              cout<<"\n hurry you are at the outside of havelii safe and soundly\n ";

			  for (int i = 0; true; i++)
			  {  
				int x = encounters.pop();
				if(x == 0 ){
					continue;
				}
				else break;
			  }
			  

			  break;
			}

			if(opt == 1){
				cout<<"What did you see?\n";
				cin>>msg;
				encounters.push(msg);

				mansionQueue.dequeue();
				move_haveli++;

			}else if(opt == 2){
				mansionQueue.dequeue();
				move_haveli++;
			} 
		}
		
	} else {
		cout<<"See you next time"<<endl;
		return 0;
	}
}