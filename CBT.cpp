#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int global_height = 0;

struct node
{

    int info;
    node *left, *right;
};

class complete_search_tree
{

private:
    node *temp, *temp1;
    static int nodeCount;

public:
    node *root;
    int number;

    complete_search_tree()
    {
        root = temp = temp1 = NULL;
    }

    node *newNode()
    {
        temp = new node;
        temp->left = NULL;
        temp->right = NULL;
        temp->info = number;
        number = -1;
        nodeCount++;
        cout << "Node number " << nodeCount << "\n";
        return temp;
    }

    void insert_CBT(node *temp, int lh)
    {

        if (root == NULL)
        {
            root = newNode();
            return;
        }
        else
        {

            if ((nodeCount == pow(2, lh + 1) - 1) && number != -1)
            {

                while (temp->left != NULL)
                    temp = temp->left;

                temp->left = newNode();
                cout << "\nNew level introduced insert in most left\n";
                global_height = lh + 1;
                return;
            }

            if (temp->left != NULL)
                insert_CBT(temp->left, lh + 1);

            if ((temp->left == NULL) && (temp->right == NULL) && (global_height > lh) && number != -1)
            {
                temp->left = newNode();
                cout << "insert at left side \n";
                return;
            }

            if (temp->right != NULL)
                insert_CBT(temp->right, lh + 1);

            // cout<<"\nlocal height "<< lh;

            if ((temp->left != NULL) && (temp->right == NULL) && number != -1)
            {
                temp->right = newNode();
                cout << "insert at right side\n";
                return;
            }
        }

        return;
    }

    void in_order(node *temp)
    {
        if (root == NULL)
        {
            cout << " Tree is empty.\n";
            return;
        }

        if (temp->left != NULL)
            in_order(temp->left);

        cout << temp->info << "  ";

        if (temp->right != NULL)
            in_order(temp->right);

        return;
    }
};

int complete_search_tree::nodeCount = 0;

int main()
{

    complete_search_tree obj;
    int choise;
    int r_height;

    while (true)
    {
        cout << "\n1)Add Number\n2) in order display\n3)delete\n4)balance factor\n5)balance factor print\n6)exit\n ";
        cin >> choise;

        if (choise == 1)
        {
            cout << "Enter the number into tree\n";
            cin >> obj.number;
            obj.insert_CBT(obj.root, 0);
        }
        else if (choise == 2)
        {
            obj.in_order(obj.root);
        }
        else if (choise == 3)
        {
            break;
        }
    }

    return 0;
}
