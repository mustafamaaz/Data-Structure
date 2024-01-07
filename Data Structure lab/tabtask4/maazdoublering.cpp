#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct node
{
    public:

   string songName;
   node *next;

    node()  {   next = NULL;   }
    ~node() { delete next; }

};

class list {
    private:
     node *head, *temp1, *temp2,*end, *tail ;

     public:
      list()
    {
        head = temp1 = temp2 =end = NULL;
        // cout << "\nlist call\n";
    }
    ~list()
    {

  node *temp;

     temp = head;
        while (head != NULL)
        {
           delete temp;
            temp = temp->next;

        }
        delete head, temp1, temp2,end;
        
    }

    void add_song()
{
    // temp2 = head;
    int opt;
    string name;

          if (head == NULL)
        {
              head = new node; 
            cout<<"\nEnter the name of the song \n";
            cin>>head->songName;
              head->next = head;
            temp1 = head;
            temp2 = head;
            end = head;
            tail = head;
        } else{
          
            temp1 = new node;
            cout<<"\nEnter the name of the song \n";
            cin>>temp1->songName;
            cout<<"\nfavorite level\n1) Top favorite\n2)lease favorite\n3)some where else\n";
            cin>>opt;
             
             if(opt == 1){
         
              temp1->next = head;
              head = temp1;
              temp2 = temp1;
               tail->next = head;  //  for ring list

               printlist();

             } else if(opt==2){

            temp1->next = NULL;
            end->next = temp1;
            end = temp1;
            tail = end;
            tail->next = head;


            printlist();
             }  else if(opt == 3){

                printlist();

            cout<<"\nEnter the song name after where you want to add song\n";
            cin >> name ;

            while (temp2 != NULL)
            {

                if(temp2->next->songName == name){

            temp1->next = temp2->next;
            temp2->next = temp1;
            break;


                }
                temp2 = temp2->next;
                
            }
             temp2 = head;
            
             }

        }




}

void printlist(){
     temp2 = head;

    while (temp2 != tail)
    {
        cout<<"\n song name is "<<temp2->songName<<endl;
        temp2 = temp2->next;
    }
     temp2 = head;
    
  
}

void listsong(){
    int g;

    temp1 = head;

while (true)
{
    


      cout<<"press 1 for next \n press 2 for exit\n";
      cin >>g;

      if(g == 1){
            cout<<"song name is "<<temp1->songName<<" \n";
            temp1 = temp1->next;
      } else{
        break;
      }


}



}

 void deletefun(){
    temp2 = head;
    temp1 = head;
    string name;

    cout<<"\nEnter the song name you want to delete\n";
    cin>>name;

    if(head != NULL){
        cout<<"there is no song\n";
    }else{

        while (temp2 != NULL)
        {
            
        if(head->songName ==  name ){
            head=head->next;
            temp1 = head;
            delete temp2;
            temp2 = head;
        } else {
           temp2=temp2->next;
            temp1 = head;
            delete temp2;
            temp2 = head;
        }
        }
    }
 }




};



int main() {

    list l;

    l.add_song();
    l.add_song();
    l.add_song();
    l.add_song();
    l.listsong();
     l.add_song();
      l.add_song();
 
    l.printlist();
   
    return 0;
}