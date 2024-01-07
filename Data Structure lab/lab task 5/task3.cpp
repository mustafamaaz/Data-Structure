#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

struct node
{
   char info;
   node *next;
};

class list
{
private:
   node *top, *temp;

public:
   list() { top = temp = NULL; }
   ~list()
   {
      delete top, temp;
   }

   void push(char a)
   {

      if (top == NULL)
      {
         top = new node;
         top->info = a;
         top->next == NULL;
      }
      else
      {
         temp = new node;
         temp->info = a;
         temp->next = top;
         top = temp;
      }
   }

   int pop()
   {
      char x;
      if (top != NULL)
      {
         top = top->next;
         x = temp->info;
         cout << "popped out : " << x << endl;
         delete temp;
         temp = top;
         return x;
      }
      else
         cout << "\nstake is under flow\n";
      return 0;
   }

   bool isEmpty(){
       if (top == NULL)
       {
       return true; }

       return false;
       
   }


void reverse_stake(){


}


   void display()
   {

      while (top != NULL)
      {
         cout << top->info << " " << endl;
         top = top->next;
      }
   }
};

int main()
{
   list l1 , l2;
   string str;
   cout << "\nEnter the word\n";
   cin >> str;
   char *ptr = &str[0];

   for (int i = 0; i < str.length(); i++)
   {
      l1.push(*ptr);
      ptr++;
   }

  

// while ( l1.isEmpty() != true )
// {
//     l2.push(l1.pop());
// }

//  undo
 l2.push(l1.pop());    
  l2.push(l1.pop());    

l1.push(l2.pop());
//  redo
//  l2.push(l1.pop());

 l1.display();
 

   return 0;
}