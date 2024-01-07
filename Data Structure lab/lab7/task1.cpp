#include <iostream>
using namespace std;

class Que
{
    int front;
    int rear;
    int size;
    string *arr;

public:


Que(int size){
        front = -1;
        rear = -1;
        this->size = size;
        arr = new string[size];}

~Que(){
        delete[] arr;  }


bool isEmpty(){

        if (front == -1 && rear == -1)
            return true;
        else
            return false;

        }


bool isFull(){

        if (((rear + 1) % size) == front)
            return true;

        else
            return false;
}


void insert(string val){

        if (isFull()){
            cout << "Que is full" << endl;
            return;}

        else if (isEmpty()){
            front = 0;
            rear = 0;}

        else
            rear = (rear + 1) % size;
        
        arr[rear] = val;
        cout << "Enqueued patient name in list : " << val << endl;
}

void dequeue(){

        string val = arr[front];
               arr[front] = " " ; 
         if (!isEmpty()){
            if(front == rear){

                front = -1;
                rear = -1;
            }
            else{
                front = (front + 1) % size;
            }
            cout<< val <<" : goes to doctor "<<endl;
        }

        else
            cout << "Que is empty" << endl;
        
}


void getFront(){
        cout << "The next patient  in this  queue is " << arr[front] << endl;
}

void display(){

        cout << "Que elements:" << endl;
        if (isEmpty())
            return;
        
        int i = front;

        do{
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }while(i !=(rear +1) % size);
        cout << endl;
}


void operations(){

        int option = 0;
        while (option != 5){

            cout << "Enter an option\n1) Enter a patient in the waiting queue\n2) Send next patient to the doctor\n3) See who's next\n4)  Display all the patients in the queue\n5)Exit" << endl;
            cin >> option;

            if( option == 1){

                string n;
                cout << "Enter the name of the patient" << endl;
                cin >> n;
                insert(n);
            }


            if(option == 2)
                dequeue();

            if   (option == 3)
                getFront();
            if(option == 4)
                display();
            
            if  (option == 5)
                exit;
            
        }
}


};

int main()
{
    int strngth;
    cout<<"Enter the number of seats in the wating area:" <<endl;
    cin>>strngth;
    Que q(strngth);
    q.operations();
    return 0;
}