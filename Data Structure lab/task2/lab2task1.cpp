#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;


int top (char *p){
    p = p-3;
   if( *p == '_' ){
    cout<<"\n you are at save position\n";
   }else if(*p == 'X'){
    cout<<"\nyou loss a game\n";
    return 1;
   }
   return 0;
}


int bottom (char *p){
    p = p+3;
   if( *p == '_' ){
    cout<<"\n you are at save position\n";
   }else if(*p == 'X'){
    cout<<"\nyou loss a game\n";
    return 1;
   }
   return 0;
}


int  right (char *p){
    p = p+1;
   if( *p == '_' ){
    cout<<"\n you are at save position\n";
   }else if(*p == 'X'){
    cout<<"\nyou loss a game\n";
    return 1;
   }
   return 0;
}

 int left (char *p){
    p = p-1;
   if( *p == '_' ){
    cout<<"\n you are at save position\n";
   }else if(*p == 'X'){
    cout<<"\nyou loss a game\n";
    return 1;
   }
   return 0;
}

void print(char *ptr){

     for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            cout << " " << *ptr;
            ptr++;
        }
        cout << "\n";
    }

}



int main()
{

    srand(time(nullptr));
    char array[3][3];
    char *ptr = &array[0][0];
    char *current;
    int choise;


    for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){

            int val = rand() % 21 + 10;
                int check =  val%2;
                *ptr = check;

            if(i==1 && j==1){
                  *ptr = 'O';
                  current =  ptr;
            }
            else if(check == 1){  // 1 = _
                *ptr = '_';
            }  else if(check == 0){  // 0 = X
                *ptr = 'X';
            }
            ptr++;


        }
    }


ptr = &array[0][0];

print(ptr);


    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {

    //         cout << " " << *ptr;
    //         ptr++;
    //     }
    //     cout << "\n";
    // }

    while (true)
    {

        cout<<"\n your position is at O\n"<<"1) for top\n2)for bottom\n3)for left\n4)for right\n5)for exit\n";
        cin>> choise;

        if(choise == 1){
          int result =  top(current);
          if(result == 1) break;
            ptr = &array[0][0];
            print(ptr);
        }  else if(choise == 2){
         int result =   bottom(current);
         if(result == 1) break;
             ptr = &array[0][0];
            print(ptr);
        }  else if(choise == 3){
          int result =  left(current);
          if(result == 1) break;
             ptr = &array[0][0];
            print(ptr);
        }  else if(choise == 4){
          int result =  right(current);
          if(result == 1) break;
             ptr = &array[0][0];
            print(ptr);
        } else if(choise == 5){
           break;
        }
      


    }
    

    
  
    return 0;
}