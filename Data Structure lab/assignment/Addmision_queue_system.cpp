#include <iostream>
using namespace std;

struct Student {
    string Name;
    int Merit;
};
class Node {
public:
    Student Info;
    Node* next;
};
class QUEUES_JUNK {
private:
    Node* front;
    Node* rear;

public:
    QUEUES_JUNK() {
        front=NULL;
        rear=NULL;
    }


    void Enqueue_Student(Student New_Students) {
        Node* temp=new Node;
        temp->Info=New_Students;
        temp->next=NULL;

        if (empty()) {
            front=temp;
            rear=temp;
        } else{
            rear->next=temp;
            rear=temp;
        }
    }

    Student Dequeue_Student() {


        if (empty()) {
            cout<<"queue is Empty"<<endl;
            exit(1);
        } else {

            Node* temp=front;
            Student rmv=temp->Info;
            front=front->next;
            delete temp;
            temp = NULL;
            return rmv;
        }
    }

    bool empty(){
        return front==NULL;
    }


    void Display_Student_Data(){
        Node* Curr=front;
        if (empty()) {
            cout<<"queue is Empty \n";
            return;}

        while(Curr!= NULL){
            cout<<"\n\n***************************************\n";
            cout<<"Student Name: "<<Curr->Info.Name<<endl;
            cout<<"Student Merit: "<<Curr->Info.Merit<<endl;
             cout<<"***************************************\n";
            Curr=Curr->next;}

    }


    int Get_Size(){
        int cnt=0;
        Node* Curr=front;

        while (Curr!= NULL){
            cnt++;
            Curr=Curr->next;
        }
        return cnt;
    }


    Student next_node(){
        if (empty()) {
            cout << "QUEUES List is empty." << endl;
            exit(1);
        } else {
            return front->Info;
        }
    }
};


int main(){

    QUEUES_JUNK queues[3];
    int opt;


    while(true) {
        cout<< "\n\n1) Add Student in queues" << endl<< "2) Admissions Process" << endl <<"3) Display queue" << endl<< "4) See who is next" << endl<< "5) Exit" << endl;
        cin>>opt;

     if(opt==1) {
                Student New_Students;
                cout << "Enter Student Name: ";
                cin >> New_Students.Name;
                cout << "Enter Student Merit: ";
                cin >> New_Students.Merit;

                int Queue = 0;
                int StSize = queues[0].Get_Size();


                for (int i = 1; i < 3; ++i) {

                    int size = queues[i].Get_Size();
                    if (size < StSize) {
                        StSize = size;
                        Queue = i;}
                }

                for (int i = 0; i < 3; ++i) {
                    if (queues[i].Get_Size() == StSize) {
                        Queue = i;
                    }
                }

                queues[Queue].Enqueue_Student(New_Students);
                cout << "\nStudent added to Queue List :" << Queue + 1 << endl;
              
            }
            if(opt==2){

                for (int i = 0; i < 3; ++i) {

                    cout<<"\n\n========================================\n";

                    cout<<"\nProcessing Queue System " << i + 1 << ":\n" << endl;

                    while(!queues[i].empty()) {

                        Student currentStudent = queues[i].Dequeue_Student();

                        cout<< currentStudent.Name << " & Merit: " << currentStudent.Merit << "\n";

                        if (currentStudent.Merit > 50) 
                            cout << currentStudent.Name <<" secure Addmision Successfully\n\n";

                         else 
                            cout<< currentStudent.Name <<"Addmision Lost\n";
                        
                    }
                      cout<<"\n========================================\n";
                }
               
            }
           if(opt==3){
                for (int i=0;i<3;++i) {

                    cout <<"Queue List "<< i + 1<<endl;
                    queues[i].Display_Student_Data();
                    cout<<endl;
                }
\
            }
           if(opt==4){
                int queN;

                cout<<"Enter Queue List Number: ";
                cin>>queN;

                if(queN>= 1 && queN<= 3) {

                    cout<<"Next Student in Queue list " << queN<< ":"<<endl;
                    Student nextStudent = queues[queN - 1].next_node();
                    cout<<"Student Name: " << nextStudent.Name<<", Merit: "<<nextStudent.Merit<<endl;

                } else 
                    cout<<"Invalid Queue List."<<endl;
                
            } else if (opt == 5)
            break;
    }

    return 0;
}