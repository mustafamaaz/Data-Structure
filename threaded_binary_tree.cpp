#include <iostream>
#include <cstdlib>
#define MAX_VALUE 65536
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
    bool leftThread, rightThread;
};

class threadedTree
{
    Node *root;

public:
    threadedTree()
    {

        root = new Node();
        root->right = root->left = root;
        root->leftThread = true;
        root->key = MAX_VALUE;
    }

    void makeEmpty()
    {
        root = new Node();
        root->right = root->left = root;
        root->leftThread = true;
        root->key = MAX_VALUE;
    }

    void insert(int key)
    {
        Node *p = root;
        while (p != NULL)
        {
            if (p->key < key)
            {
                if (p->rightThread)
                    break;
                p = p->right;
            }
            else if (p->key > key)
            {
                if (p->leftThread)
                    break;
                p = p->left;
            }
            else
            {
                cout << "Value already exists." << endl;
                return;
            }
        }
        Node *temp = new Node();
        temp->key = key;
        temp->rightThread = temp->leftThread = true;
        if (p->key < key)
        {
            temp->right = p->right;
            temp->left = p;
            p->right = temp;
            p->rightThread = false;
        }
        else
        {
            temp->right = p;
            temp->left = p->left;
            p->left = temp;
            p->leftThread = false;
        }
    }




    bool search(int key)
    {
        Node *temp = root->left;
        while (temp != NULL)
        {
            if (temp->key < key)
            {
                if (temp->rightThread)
                    return false;
                temp = temp->right;
            }
            else if (temp->key > key)
            {
                if (temp->leftThread)
                    return false;
                temp = temp->left;
            }
            else
            {
                return true;
            }
        }
    }

    bool update(int key)
    {
        Node *temp = root->left;
        int val;
        cout << "Enter value you want to update with: ";
        cin >> val;
        while (temp != NULL)
        {
            if (temp->key < key)
            {
                if (temp->rightThread)
                {
                    return false;
                }
                temp = temp->right;
            }
            else if (temp->key > key)
            {
                if (temp->leftThread)
                {
                    return false;
                }
                temp = temp->left;
            }
            else
            {
                temp->key = val;
                break;
            }
        }
        // sorting after updation
        temp = root->left;
        while (temp != NULL)
        {
            int sort = 0;
            if (temp->key < temp->left->key)
            {
                int swap;
                swap = temp->key;
                temp->key = temp->left->key;
                temp->left->key = swap;
                temp = temp->left;
                sort++;
            }
            if (temp->key > temp->right->key)
            {
                int swap;
                swap = temp->key;
                temp->key = temp->right->key;
                temp->right->key = swap;
                temp = temp->right;
                sort++;
            }
            if (sort == 0)
            {
                return true;
            }
        }
    }

    int findMax()
    {
        Node *temp = root->left;
        while (temp != NULL)
        {
            if (!temp->rightThread)
            {
                temp = temp->right;
            }
            else
            {
                break;
            }
        }
        return temp->key;
    }

    int findMin()
    {
        Node *temp = root->left;
        while (temp != NULL)
        {
            if (!temp->leftThread)
            {
                temp = temp->left;
            }
            else
            {
                break;
            }
        }
        return temp->key;
    }

    void Delete(int key)
    {
        Node *temp = root->left, *p = root;
        while (temp != NULL)
        {
            if (temp->key < key)
            {
                /* not found */
                if (temp->rightThread)
                    return;
                p = temp;
                temp = temp->right;
            }
            else if (temp->key > key)
            {
                /* not found */
                if (temp->leftThread)
                    return;
                p = temp;
                temp = temp->left;
            }
            else
            {
                /* found */
                break;
            }
        }
        Node *target = temp;
        if (!temp->rightThread && !temp->leftThread)
        {
            /* temp has two children*/
            p = temp;
            /* find largest node at left child */
            target = temp->left;
            while (!target->rightThread)
            {
                p = target;
                target = target->right;
            }
            /* using replace mode*/
            temp->key = target->key;
        }
        if (p->key >= target->key) // left cases
        {
            if (target->rightThread && target->leftThread)
            {
                p->left = target->left;
                p->leftThread = true;
                delete target;
                target = NULL;
            }
            else if (target->rightThread)
            {
                Node *largest = target->left;
                while (!largest->rightThread)
                {
                    largest = largest->right;
                }
                largest->right = p;
                p->left = target->left;
                delete target;
                target = NULL;
            }
            else
            {
                Node *smallest = target->right;
                while (!smallest->leftThread)
                {
                    smallest = smallest->left;
                }
                smallest->left = target->left;
                p->left = target->right;
                delete target;
                target = NULL;
            }
        }
        else // right cases
        {
            if (target->rightThread && target->leftThread)
            {
                p->right = target->right;
                p->rightThread = true;
                delete target;
                target = NULL;
            }
            else if (target->rightThread)
            {
                Node *largest = target->left;
                while (!largest->rightThread)
                {
                    largest = largest->right;
                }
                largest->right = target->right;
                p->right = target->left;
                delete target;
                target = NULL;
            }
            else
            {
                Node *smallest = target->right;
                while (!smallest->leftThread)
                {
                    smallest = smallest->left;
                }
                smallest->left = p;
                p->right = target->right;
                delete target;
                target = NULL;
            }
        }
    }

    void printTree()
    {
        Node *temp = root, *parent;
        while (temp != NULL)
        {
            parent = temp;
            temp = temp->right;
            if (!parent->rightThread)
            {
                while (!temp->leftThread)
                {
                    temp = temp->left;
                }
            }
            if (temp == root)
                break;
            cout << temp->key << "   ";
        }
        cout << endl;
    }
};

int main()

{
    threadedTree tree;
    char ch;
    int choice, val;
    do
    {
        cout << "\nThreaded Tree Operations\n";
        cout << "1. Insert " << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Clear" << endl;
        cout << "5. Update" << endl;
        cout << "6. Max" << endl;
        cout << "7. Min" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter integer element to insert: ";
            cin >> val;
            tree.insert(val);
            break;
        case 2:
            cout << "Enter integer element to delete: ";
            cin >> val;
            tree.Delete(val);
            break;
        case 3:
            cout << "Enter integer element to search: ";
            cin >> val;
            if (tree.search(val) == true)
                cout << "Element " << val << " found in the tree" << endl;
            else
                cout << "Element " << val << " not found in the tree" << endl;
            break;
        case 4:
            cout << "\nTree Cleared\n";
            tree.makeEmpty();
            break;
        case 5:
            cout << "Enter integer element to update: ";
            cin >> val;
            if (tree.update(val))
            {
                cout << "Value updated" << endl;
            }
            else
            {
                cout << "Value not found" << endl;
            }
            break;
        case 6:
            cout << "The maximum value in the tree is: " << tree.findMax() << endl;
            break;
        case 7:
            cout << "The minimum value in the tree is: " << tree.findMin() << endl;
            break;
        default:
            cout << "Wrong Entry \n ";
            break;
        }
        cout << "\nTree = ";
        tree.printTree();
        cout << "\nDo you want to continue (Type y or n): ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');

    return 0;
}