#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class node {
    public:
 char info[10];

};

class trial{

private:
node obj1,*temp1,*temp2,*temp3;
int  length;
char *p,*q;

public:
trial();
~trial();
void startin();

};

int main() {
    
    trial lnk;
    lnk.startin();
    

    return 0;
}

trial::trial(){
    temp1 = temp2 = temp3 = NULL;
    p = q = NULL;
}
trial::~trial(){
    delete temp1,temp2,temp3;
    delete[]p;
}

void trial::startin(){
    cout<<"\nmaking use of /new and /delete is as follow\n";
    temp1 = new node;
    temp2 = new node;
    cout<<"\nEnter information about temp1\n";
        cin>>temp1->info;
     cout<<"\nEnter information about temp2\n";
    cin>>temp2->info;

    temp3 = &obj1;

  cout<<"\nEnter information about temp3\n";
    cin>>temp3->info;

    cout<<"\nshowing information of temp1\n"<<temp1->info;
    cout<<"\nshowing information of temp2\n"<<temp2->info;
    cout<<"\nshowing information of temp3\n"<<temp3->info;
    cout<<"\n-----------------------------\n";

    cout<<"Now enter the length of charachter array\n";
    cin>>length;

    p = new char[length];
     q=p;

     cout<<"Now enter "<<length<<" charater to fill an array\n";
     for(int i=0 ; i<length ; ++i){
        cin>>*p;
        p=p+1;
     }
     p=q;

     cout<<"\nElement of array as follow\n";
     for (int i = 0; i < length; i++)
     {
        cout<<*p<<" , ";
        p=p+1;
     
     }
     p=q;
     

    
}