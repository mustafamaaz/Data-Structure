#include <iostream>
#include <string>
#include <cstring>
using namespace std;
// my code
struct node
{

    int info, bf, RTH, LTH;
    node *left, *right;
};

class tree
{

private:
    node *temp, *temp1;

public:
    node *root, *dmy;
    int number;

    tree()
    {
        root = temp = dmy = temp1 = NULL;
    }

    void dummuuy_fun()
    {

        dmy = new node;
        dmy->LTH = 1;
        dmy->RTH = 0;
        dmy->left = dmy->right = dmy;
    }

    void insert_TBT_tree(node *temp)
    {

        if (dmy == dmy->left && dmy == dmy->right)
        {
            temp = new node;
            temp->info = number;
            dmy->left = temp;
            dmy->LTH = 0;
            temp->left = temp->right = dmy;
            temp->LTH = temp->RTH = 1;
            root = temp;
            return;
        }

        if (temp->info == number)
        {

            cout << " \n Given number is already present in tree.\n";
            return;
        }

        while (temp != NULL)
        {

            if (temp->info > number)
            {

                if (temp->LTH != 1)
                {
                    temp = temp->left;
                }

                else
                {
                    cout << "\n insert in left ";
                    temp1 = new node;
                    temp1->info = number;
                    temp1->left = temp->left;
                    temp1->LTH = 1;
                    temp1->right = temp;
                    temp1->RTH = 1;
                    temp->left = temp1;
                    temp->LTH = 0;
                    break;
                }
            }

            if (temp->info < number)
            {

                if (temp->RTH != 1)
                {
                    temp = temp->right;
                }
                else
                {
                    cout << "\n insert in right ";

                    temp1 = new node;
                    temp1->info = number;
                    temp1->right = temp->right;
                    temp1->RTH = 1;
                    temp1->left = temp;
                    temp1->LTH = 1;
                    temp->right = temp1;
                    temp->RTH = 0;
                    break;
                }
            }
        }
    }

    void fastInOrder(node *p)
    {

        while ((p = nextInorder(p)) != dmy)
        {
           
                cout << " " << p->info;
      
        }
    }

    node *nextInorder(node *p)
    {

        if (dmy == dmy->left && dmy == dmy->right)
        {
            return NULL;
        }

        if (p->RTH == 1) // threaded
        {
            return p->right;
        }
        else
        {
            p = p->right;
            while (p->LTH == 0) // child
            {
                p = p->left;
            }
            return p;
        }
    }
};

int main()
{

    tree obj;
    int choise;
    int r_height;

    obj.dummuuy_fun();

    while (true)
    {
        cout << "\n1)Add Number\n2) in order display\n3)delete\n4)balance factor\n5)balance factor print\n6)exit\n ";
        cin >> choise;

        if (choise == 1)
        {
            cout << "Enter the number into tree\n";
            cin >> obj.number;
            obj.insert_TBT_tree(obj.root);
        }
        else if (choise == 2)
        {
            obj.fastInOrder(obj.dmy);
        }
        else if (choise == 3)
        {
            break;
        }
    }

    return 0;
}
