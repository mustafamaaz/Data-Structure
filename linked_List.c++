#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct node
{
public:
    int info;
    node *next;

    node()
    {
        // cout << "\nnode call\n";
        next = NULL;
    }
    ~node() { delete next; }
};

class list
{
private:
    node *head, *temp1, *temp2;

public:
    list()
    {
        head = temp1 = temp2 = NULL;
        // cout << "\nlist call\n";
    }
    ~list()
    {
        delete head, temp1, temp2;
    }

    int add()
    {

        temp2 = head;
        int key;

        if (head == NULL)
        {
            head = new node;
            cout << "\nEnter the first value of info \n";
            cin >> head->info;
            head->next = NULL;
            temp1 = head;
            temp2 = head;
            print();
            return 0;
        }
        cout << "\nEnter the key after you want to add \n";
        cin >> key;
        if (head->info == key)
        {

            temp1 = new node;
            cout << "\nyou are at the head of list \nEnter the value of info \n";
            cin >> temp1->info;
            temp1->next = head;
            head = temp1;
            temp2 = head;
            print();
            return 0;
        }
print();
        while (temp2->next != NULL)
        {

            if (temp2->info == key)
            {
                temp1 = new node;
                cout << "\nEnter the  value of info at middle \n";
                cin >> temp1->info;
                temp1->next = temp2->next;
                temp2->next = temp1;
                temp2 = head;
                break; // agr sab key ky bad value insert krni hyto break hata do
            }
            temp2 = temp2->next;
        }
        print();

        // logic sahi krni hy idher temp2 last node pr khara hy abh dekhna hy ky  agr last node ho or key match krrhi hyto last node ky right side pr new node add krna ya left side both having different logic

        // if (temp2->info == key && temp2->next == NULL )
        // {

        //     temp1 = new node;
        //     cout << "\nEnter the  value of info at middle \n";
        //     cin >> temp1->info;
        //     temp1->next = temp2->next;
        //     temp2->next = temp1;
        //     temp2 = head;
        // } else cout<<"\nKEY doest match\n";

        return 1;
    }

    void print()
    {

            while (head->next != NULL)
            {
                cout << "\nvalue is " << head->info << " ";
                head = head->next;
            }
              cout << "\nvalue is " << head->info << "\n";

     // head = head->next;    head loss and asign null then every one time it behave as a first element of node
               cout<<"\nend of printing\n";

        if (temp2 != NULL){
              head = temp2;
        }
          



    }


};

int main()
{

    list l;

    l.add();
    // l.print();
    l.add();
    l.add();
    l.add();
    // l.print();

    return 0;
}