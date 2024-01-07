#include <iostream>
using namespace std;

struct Node
{
    Node *left, *right;
    int info, height;
};

class Tree
{
    Node *temp, *curr;

public:
    Tree()
    {
        temp = NULL;
        curr = NULL;
    }

    Node *newNode(int data)
    {
        temp = new Node;
        temp->left = NULL;
        temp->right = NULL;
        temp->info = data;
        temp->height = 1;
        return temp;
    }

    int height(Node *temp)
    {
        if (temp == NULL)
        {
            return 0;
        }
        return temp->height;
    }

    int max(int a, int b)
    {
        if (a > b)
        {
            return a;
        }
        else
        {
            return b;
        }
    }

    void inOrder(Node *temp)
    {
        if (temp == NULL)
        {
            cout << " Tree is empty." << endl;
            return;
        }
        if (temp->left != NULL)
        {
            inOrder(temp->left);
        }
        cout << temp->info << " ";
        if (temp->right != NULL)
        {
            inOrder(temp->right);
        }
        return;
    }

    void postOrder(Node *temp)
    {
        if (temp == NULL)
        {
            cout << " Tree is empty." << endl;
            return;
        }
        if (temp->left != NULL)
        {
            postOrder(temp->left);
        }
        if (temp->right != NULL)
        {
            postOrder(temp->right);
        }
        cout << temp->info << " ";
        return;
    }

    void preOrder(Node *temp)
    {
        if (temp == NULL)
        {
            cout << " Tree is empty." << endl;
            return;
        }
        cout << temp->info << " ";
        if (temp->left != NULL)
        {
            preOrder(temp->left);
        }
        if (temp->right != NULL)
        {
            preOrder(temp->right);
        }
        return;
    }

    void search(Node *temp, int data)
    {
        if (temp != NULL)
        {
            // compare first node
            if (data == temp->info)
            {
                cout << "Value found!" << endl;
                return;
            }
            else if (data < temp->info)
            {
                return search(temp->left, data);
            }
            else if (data > temp->info)
            {
                return search(temp->right, data);
            }
            else
            {
                cout << "Value not found!" << endl;
                return;
            }
        }
        else
        {
            cout << "Tree is empty." << endl;
        }
    }

    void updateNode(Node *temp, int data)
    {
        if (temp != NULL)
        {
            // compare first node
            if (data == temp->info)
            {
                cout << "Value found!" << endl;
                temp->info = data;
                return;
            }
            else if (data < temp->info)
            {
                return updateNode(temp->left, data);
            }
            else if (data > temp->info)
            {
                return updateNode(temp->right, data);
            }
            else if (temp == NULL)
            {
                cout << "Value not found." << endl;
                return;
            }
        }
        else
        {
            cout << "Tree is empty." << endl;
        }
    }

    Node *insertNode(Node *temp, int data)
    {
        if (temp == NULL)
        {
            temp = newNode(data);
            return temp;
        }
        else
        {
            if (data == temp->info)
            {
                cout << "Value already in tree!" << endl;
                return temp;
            }
            else if (data < temp->info)
            {
                temp->left = insertNode(temp->left, data);
            }
            else
            {
                temp->right = insertNode(temp->right, data);
            }
        }
        // code for checking balance factor and setting height
        temp->height = 1 + max(height(temp->left), height(temp->right));
        int balancefactor = getBalanceFactor(temp);
        if (balancefactor > 1)
        {
            if (data < temp->left->info)
            {
                return rotateright(temp);
            }
            else if (data > temp->left->info)
            {
                temp->left = rotateleft(temp->left);
                return rotateright(temp);
            }
        }
        if (balancefactor < -1)
        {
            if (data > temp->right->info)
            {
                return rotateleft(temp);
            }
            else if (data < temp->right->info)
            {
                temp->right = rotateright(temp->right);
                return rotateleft(temp);
            }
        }
        return temp;
    }

    Node *rotateleft(Node *temp)
    {
        Node *parent, *child;
        parent = temp->right;
        child = parent->left;
        parent->left = temp;
        temp->right = child;
        temp->height = 1 + max(height(temp->left), height(temp->right));
        parent->height = 1 + max(height(parent->left), height(parent->right));
        return parent;
    }
    Node *rotateright(Node *temp)
    {
        Node *parent, *child;
        parent = temp->left;
        child = parent->right;
        parent->right = temp;
        temp->left = child;
        temp->height = 1 + max(height(temp->left), height(temp->right));
        parent->height = 1 + max(height(parent->left), height(parent->right));
        return parent;
    }

    int getBalanceFactor(Node *temp)
    {
        return (height(temp->left) - height(temp->right));
    }

    Node *removeNode(Node *temp, int data)
    {
        if (temp == NULL)
        {
            cout << "Tree is empty." << endl;
            return temp;
        }

        if (data < temp->info)
        {
            temp->left = removeNode(temp->left, data);
        }
        else if (data > temp->info)
        {
            temp->right = removeNode(temp->right, data);
        }
        else
        {
            if (temp->left == NULL || temp->right == NULL)
            {
                Node *tempChild = temp->left ? temp->left : temp->right;
                if (tempChild == NULL)
                {
                    tempChild = temp;
                    temp = NULL;
                }
                else
                {
                    *temp = *tempChild;
                }
                delete tempChild;
            }
            else
            {
                Node *successor = findMin(temp->right);
                temp->info = successor->info;
                temp->right = removeNode(temp->right, successor->info);
            }
        }

        if (temp == NULL)
        {
            return temp;
        }

        temp->height = 1 + max(height(temp->left), height(temp->right));
        int balanceFactor = getBalanceFactor(temp);

        // Rebalance the tree
        if (balanceFactor > 1 && getBalanceFactor(temp->left) >= 0)
        {
            return rotateright(temp);
        }
        if (balanceFactor > 1 && getBalanceFactor(temp->left) < 0)
        {
            temp->left = rotateleft(temp->left);
            return rotateright(temp);
        }
        if (balanceFactor < -1 && getBalanceFactor(temp->right) <= 0)
        {
            return rotateleft(temp);
        }
        if (balanceFactor < -1 && getBalanceFactor(temp->right) > 0)
        {
            temp->right = rotateright(temp->right);
            return rotateleft(temp);
        }

        return temp;
    }

    Node *findMin(Node *temp)
    {
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }

    Node *findMax(Node *temp)
    {
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        return temp;
    }

    void printTree(Node *temp, string indent, bool last)
    {
        if (temp != nullptr)
        {
            cout << indent;
            if (last)
            {
                cout << "R----";
                indent += "   ";
            }
            else
            {
                cout << "L----";
                indent += "|  ";
            }
            cout << temp->info << endl;
            printTree(temp->left, indent, false);
            printTree(temp->right, indent, true);
        }
    }
};

int main()
{
 

    Tree tree;
    Node *root = NULL;
    int option, tries;
    tries = 3;
    int key;
   
    while (true)
    {


 cout << "\nMenu:\n1) Insert\n2) Delete\n3) Display\n4) Update\n5) Search\n6) Find Max\n7) Find Min\n8) Exit\n" << endl;
    cin >> option;

        if (option == 1)
        {
            cout << "Enter data: ";
            cin >> key;
            cout << "\t";
            root = tree.insertNode(root, key);
           
        }
        else if (option == 2)
        {
            cout << "Enter data: ";
            cin >> key;
            cout << "\t";
            root = tree.removeNode(root, key);
          
        }
        else if (option == 3)
        {
            cout << "1) In-order\t2) Tree display" << endl;
            cin >> option;
            (option == 1) ? tree.inOrder(root) : tree.printTree(root, "", true);
           
        }
        else if (option == 4)
        {
            cout << "Enter data: ";
            cin >> key;
            cout << "\t";
            tree.updateNode(root, key);
            cout << " Value updated." << endl;
          
        }
        else if (option == 5)
        {
            cout << "Enter data: ";
            cin >> key;
            cout << "\t";
            tree.search(root, key);
        
        }
        else if (option == 6)
        {
            root = tree.findMax(root);
            cout << "Maximum value in tree is: " << root->info << endl;
          
        }
        else if (option == 7)
        {
            root = tree.findMin(root);
            cout << "Minimum value in tree is: " << root->info << endl;
          
        }
        else if (option == 8)
        {
           break;
        }
        else
        {
            tries--;
            cout << "Invalid option. " << tries << " tries left" << endl;
         
        }
    }
    return 0;
}