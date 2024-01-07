#include <iostream>
using namespace std;

class Node
{
public:
    string name;
    Node *next;

    Node(string name){
        this->name = name;
        next = NULL;
    }
};

class Que  {
private:
    Node *front;
    Node *rear;

public:

Que(){
        front = NULL;
        rear = NULL;  
}


bool isEmpty(){
        return front==NULL;
}


void insert(  string name){

        Node *newNode =  new Node(name);
        if(isEmpty()){
            front=rear=newNode;
             }
        else{
            rear->next   =   newNode;
            rear=newNode; }
}


string Dequeue(){
        if (isEmpty()){
            cout << "Que is empty" << endl;
            return "";}


        Node *temp = front;
        string name = temp->name;
        front = front->next;



        if (front==  NULL) {
            rear=NULL;}
        delete temp;
        return name;
}

  ~Que() {

         
          Node *temp1 = front;
        while (temp1 !=  NULL) {
             temp1 = temp1->next; 
            delete temp1;
        }
        delete front , rear;
  }


    
};

int main()
{
    Que tic_Sale_Que , roller_Coaster , Motion_Ride , Round_Wheel;


    int opt;
    string name_person;

    do{ 
        cout<<"\n==================================================\n";
        cout << "1. Enter person name  to Ticket Purchase in queue \n2. Sell the Ticker to person in queue\n3. Process all sold ticket in queues\n4. Exit\n";
        cout<<"\n==================================================\n";
        cout << "Enter option: ";
        cin >> opt;

        if(opt == 1){
            cout << "Enter visitor name: ";
            cin >> name_person;
            tic_Sale_Que.insert(name_person);
        }
        if (opt == 2){
            if(  tic_Sale_Que.isEmpty()){

                cout << "No person in ticket purchase queue\n";}
            else{
                name_person = tic_Sale_Que.Dequeue();
                cout<< "Ticket sold to "<<name_person<<endl;
                cout<< "\n\nSelect option \n[1] Roller Coaster \n[2] Motion Ride \n[3]  Round Wheel) \n :  ";
                cin>>opt;
                if( opt == 1){
                    roller_Coaster.insert(name_person);
                }

                if( opt ==  2){
                    Motion_Ride.insert(name_person);
                }

                if(  opt == 3){
                    Round_Wheel.insert(name_person);}


                opt = 0;
            }
        }

        if (opt == 3){
            cout << "Processing all queues..." << endl;


            while (!roller_Coaster.isEmpty()){
                name_person = roller_Coaster.Dequeue();
                cout << name_person << " is enjoying the Roller Coaster jhulla " << endl;}



            while (!Motion_Ride.isEmpty()){
                name_person = Motion_Ride.Dequeue();
                cout << name_person << " is enjoying the Motion Ride jhulla" << endl;}


            while (!Round_Wheel.isEmpty()){
                name_person = Round_Wheel.Dequeue();
                cout << name_person << " is enjoying the Round Wheel jhulla" << endl;}

        }

        if (opt == 4){
            cout << "thanks for visit my application\n";
            break;
        }


        cout <<"\n";
    } while (opt != 4);

    return 0;
}