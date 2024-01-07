#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct node
{
    int num;
    node *next;

    node()
    {
        num = 0;
        next = NULL;
    }
};

class list
{
private:
    node *head, *tail, *temp1, *temp2;

public:
    list()
    {
        head = NULL;
        tail = NULL;
        temp1 = NULL;
        temp2 = NULL;
    }

    void insert(int N)
    {
        int count = 1;
        while (N >= count)
        {

            while (count <= 3)
            {

                if (head == NULL)
                {
                    head = new node;
                    cout << "\nEnter the number\n"
                         << endl;
                    cin >> head->num;
                    head->next = NULL;
                    count++;
                }
                else
                {
                    temp1 = new node;
                    cout << "\nEnter the number\n"
                         << endl;
                    cin >> temp1->num;
                    temp1->next = head;
                    head = temp1;
                    count++;
                }
            }

            temp2 = new node;
            int x = 0;

            for (int i = 0; i < 3; i++)
            {
                x = temp1->num + x;
                temp1 = temp1->next;
            }

            temp2->num = x;
            temp2->next = head;
            head = temp2;
            temp1 = head;
            count++;
        }
    }

    void display()
    {

        while (temp1 != NULL)
        {
            cout << temp1->num << " ";
            temp1 = temp1->next;
        }
    }

    ~list()
    {

        while (head != NULL)
        {

            node *delptr = head;
            head = head->next;
            delete delptr;
        }
        delete head, tail, temp1, temp2;
    }
};

int main()
{
    list l;
    l.insert(6);
    l.display();

    return 0;
}
