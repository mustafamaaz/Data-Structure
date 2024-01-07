#include <iostream>
#include <string>
#include <cstring>
using namespace std;


int main() {
   
   int *intptr = new int;
   char *namestr = new char[14];
   *intptr = 357;
   strcpy(namestr,"datastructure");
   cout<<"answer is " <<static_cast<void*>(namestr)<<endl;  // for print first address of char[0]
      cout<<"answer is " <<namestr<<endl; // for printinng whole character   


delete intptr;   // Deallocate the dynamically allocated integer
delete[] namestr; // Deallocate the dynamically allocated character array


    return 0;
}