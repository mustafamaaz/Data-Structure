#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;


struct node
{
        int info;
        node *next;

       
};


class list{
    private:
         node *top,*temp;

         public:
         list(){ top = temp = NULL;  }
         ~list(){ 
            delete top ,temp ;
         
           }


         void push(int a){

            if (top ==NULL) {
                top = new node;
                top->info=a;
                top->next == NULL;
            }
             else {
                temp = new node;
                temp->info=a;
                temp->next = top;
                top = temp;

             }
         }

         int pop(){
       int x;
       if(top != NULL){
          top = top->next;
           x = temp->info;
             cout << "popped out : "<<x<<endl;
             delete temp;
             temp = top;
             return x;
       } else cout<<"\nstake is under flow\n";
            
         }

};



int main()
{
   int a,b;
    list l;

    cout<<"\nEnter first number\n";
    cin>>a;
    l.push(a);
    cout<<"\nEnter second number\n";
    cin>>b;
    l.push(b);
     a=l.pop();
     b = l.pop();

     cout<<"\na = "<<a<<endl;
     cout<<"\nb = "<<b<<endl;



    
  
    return 0;
}