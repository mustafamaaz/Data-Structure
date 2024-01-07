#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

class list{

private:
char *ptr,*head,*tail;
int size;

public:

list(){}

list(int sizearray){
    ptr =head=tail =  NULL;
    size = sizearray;
    ptr = new char[size];
    head = ptr;
    tail = ptr;
}

~list(){
    delete []ptr;
}

void headfun(){
 head = ptr;
}

void insert(char val , int position){

    *(ptr + position-1) = val;
    ptr = head;
    if(position != size){
     tail++;
    }
   
}

void printlist(){   //call head in main before it call

for(int i=0 ; true ; i++){

 if(head != tail){

      cout<<" "<<*head;
      head++;
     }  else {cout<<"\nyou are at end of array\n";   break; }

}}

void deleteelement(int position){     
      *(ptr + position-1) = '_';
       ptr = head;
}
};


int main()
{
    int choise,pos;

    list obj1(7);
     char element;

 obj1.insert('f',1);
        obj1.insert('a',2);
        obj1.insert('b',3);
        obj1.insert('r',4);
        obj1.insert('a',5);
        obj1.insert('i',6);

    while (true)
    {
       cout<<"\n1)for insert element\n2)for print\n3)for remove\n4)for exit ";
       cin>> choise;

       if(choise == 1){
        cout<<"Enter the position you want to add\n";
        cin>>pos;
        cout<<"Enter the element you want to add\n";
        cin>>element;
         obj1.headfun();
        obj1.insert(element,pos);
         obj1.headfun();
        
       } else if(choise == 2){
        obj1.headfun();
        obj1.printlist();
         obj1.headfun();

       } else if(choise == 3)  {
        cout<<"\nenter the position you want to remove\n";
        cin>> pos;
         obj1.headfun();
        obj1.deleteelement(pos);
         obj1.headfun();

       } else if(choise == 4)  {
              break;
       }

    }
    


    return 0;
}