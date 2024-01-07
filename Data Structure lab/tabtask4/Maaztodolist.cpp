#include <iostream>
using namespace std;

struct node
{
    string tasks;
    bool status;
    bool completed;
    node *next;
    node *prev;

    node(){
        next = prev = NULL;
        status = false;
        completed = false;
    }
};

class list
{
private:
    node *head;
    node *tail , *temp1,*temp2;
    int count2;

public:
    list()
    {
        head = NULL;
        tail = temp1= temp2= NULL;
        count2 = 0;
    }

    void delet()
    {
        node *current = head;
        while (current != NULL)
        {
            node *next = current->next;
            delete current;
            current = next;
        }
        head = NULL;
        tail = NULL;
        cout << "All tasks deleted!" << endl;
    }

    void print()
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        int orderChoice;
        cout << "Choose the order to display tasks:" << endl;
        cout << "1 - Ascending order " << endl;
        cout << "2 - Descending order " << endl;
        cout << "Enter your choice: ";
        cin >> orderChoice;


        if (orderChoice == 1) // Ascending order
        {
            temp2 = head;

            while (temp2!=NULL)
            {
                
             cout<<"Task is "<<temp2->tasks <<" status is "<<temp2->status<<" \n";
             temp2= temp2->next;
            }
            
        }
        else if (orderChoice == 2) // Descending order
        {
            temp2 = tail;

            while (temp2!=NULL)
            {
                
             cout<<"Task is "<<temp2->tasks <<" status is "<<temp2->status<<" \n";
             temp2= temp2->prev;
            }

            temp2 = head;
            
            
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
            return;
        }
    }

    void add()
    {

 int choice2;

   if (head == NULL)
        {
              head = new node; 
            cout<<"\nEnter task Description \n";
            cin>>head->tasks;
              head->next = NULL;
              head->prev=NULL;
              tail = head;
              temp2 = head;
              count2++;
         
        } else{
        
           temp1 = new node;
            cout<<"\nEnter task Description \n";
            cin>>temp1->tasks;
           
        cout << "1) - Top Priority level" << endl;
        cin >> choice2;


        
 if (choice2 == 1)
        {
            temp1->next = head;
            head->prev = temp1;
            temp1->prev= NULL;
            head=temp1;
            temp2 = head;
        }
         else 
        {
            temp2 = head;
          
           for (int i=0 ; i<choice2;i++){

             temp2= temp2->next;
           }

         if(temp2 != NULL){


           temp1->next = temp2;
           temp1->prev = temp2->prev;
           temp2->prev->next = temp1;
           temp2->prev = temp1;

             }          

             else if(temp2 == NULL){
                  cout<<"Enter valid position";
             } 


        }
        }

    }

    void markCompleted()
    {

int z;

temp2 = head;
          
        if(head!= NULL){
            cout<<"Enter the task number you want to mark\n";
           cin>>z;

          for (int i=0 ; i<z;i++){

             temp2= temp2->next;
           }

           temp2->status = true;

        }  else{
            cout<<"card is Empty\n";
        }
  


    }


~list(){

    node *ext;
    ext = head;

while (ext != NULL)
{
    delete ext;
    ext = ext->next;
}



delete head , tail,temp1 , temp2 , ext;


}



};

int main()
{
    list l;
    int choice;

    while (true)
    {
        cout << "\n1 - Delete" << endl;
        cout << "2 - Print" << endl;
        cout << "3 - Add" << endl;
        cout << "4 - Mark Task Completed" << endl;
        cout << "5 - Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            l.delet();
            break;
        case 2:
            l.print();
            break;
        case 3:
            l.add();
            break;
        case 4:
            l.markCompleted();
            break;
        case 5:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}