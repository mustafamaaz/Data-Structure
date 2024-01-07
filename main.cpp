#include <iostream>

using namespace std;

class check {
  private:
  int info;

  public:

  check(){
    info = 1;
  }
   
   int adding(int x){
    if(x == 0){
        return 0 ;
    } else{
        return info = info + adding(x-1); 
    }
      return -1;
   }



};


int main() {

for (int i = -4; i < 4; i++)
{
    if(i != -1 && i != 0 && i!= 1){
      cout<<" \n"<<i;

    }
}

  
    return 0;
}