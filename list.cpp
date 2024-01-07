#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class list{
  
  private:
  int size=7,length;
  int listt[7];
  int *s,*c,*e,*temp;

  public:

  // ---------------------------------------
  list(){
       s=c=e = temp =  NULL;
        e=listt;
         c=listt;
         s = listt;
       
  }

// ---------------------------------------
  void next(){
    if(c!=e){
      c++;
      cout<<"\n shift forward\n";
    } else   cout<<"\n pointer is at last element \n";
    
  }

// ---------------------------------------
  void back(){
    if (s != c) {
        c--;
         cout<<"\n shift backward\n";
    } else   cout<<"\n pointer is at first element \n";
  }
   
// ---------------------------------------   
   void start(){
    c=listt;
   }

// ---------------------------------------
   void endfun(){
    e++;
   }
// ---------------------------------------


int  lengthfun (){
     length = (e - s)  ;

     return length;
}

   void add(int val,int pos){
     
     lengthfun();
      //  if(*(c +pos-1) != 0 )

      if(  length != pos-1  ){

      temp = e;

 for(int i=pos ;i<= length ;i++ ){  

      * temp = *(temp-1);
      temp--;

   }
   *temp = val;
   endfun();


      } else{


        start();
        *(c +pos-1) = val;
        endfun();

      }
   }

   void print(){
      lengthfun();
    for(int i=0 ; i<length ;i++){
       cout<<" "<<*c<<" ";
       c++;
    }
    start();
   
   }

// ---------------------------------------

};

int main() {

    list obj1;
    // obj1.endfun();
    obj1.add(1,1);
    obj1.add(2,2);
    obj1.add(3,3);
    obj1.add(4,4);
    obj1.add(5,5);
   obj1.print();
    obj1.add(20,2);
    cout<<"  \n nextt\n";
   
     obj1.add(30,7);

      obj1.print();

   
   
    return 0;
}