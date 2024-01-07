#include <iostream>
using namespace std;

static int my_power;
static int max_power;

class Node
{
public:
    string gem;
    int power;
    Node *left;
    Node *right;

    Node(int power, string gem)
    {
        left = right = nullptr;
        this->gem = gem;
        this->power = power;
    }
};

class Tree
{
public:
    Node *root;

    Tree()
    {
        root = nullptr;
    }

    Node *insert(string gem, int power, Node *root)
    {
        if (root == nullptr)
        {
            root = new Node(power, gem);
            return root;
        }

        if (power > root->power)
        {
            root->right = insert(gem, power, root->right);
        }
        else if (power < root->power)
        {
            root->left = insert(gem, power, root->left);
        }

        return root;
    }

    void inOrder(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        inOrder(root->left);
       cout << "[  " << root->gem << ",  (" << root->power << ")"
             << "  ]" << endl;
        inOrder(root->right);
    }

    void preOrder(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        cout << "[  " << root->gem << ",  (" << root->power << ")"
             << "  ]" << endl;
        preOrder(root->left);
        preOrder(root->right);
    }

    void postOrder(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        postOrder(root->left);
        postOrder(root->right);
        cout << "[  " << root->gem << ",  (" << root->power << ")"
             << "  ]" << endl;
    }

    void order_menu(Node *root)
    {
        int option = 0;
        while (option != 4)
        {
            cout << "Which Order Do You want to Output" << endl
                 << "1.Pre-Order" << endl
                 << "2.Post Order" << endl
                 << "3.In-Order" << endl
                 << "4.Exit" << endl
                 << endl;
            cin >> option;
            if (option == 1)
            {
                cout << "Magical tree Pre-Order:" << endl;
                preOrder(root);
            }
            if (option == 2)
            {
                cout << "Magical tree Post-Order:" << endl;
                postOrder(root);
            }
            if (option == 3)
            {
                cout << "Magical tree In-Order:" << endl;
                inOrder(root);
            }
        }
    }

    Node *search(int key, Node *root)
    {
        if (root == nullptr || root->power == key)
        {
            return root;
        }
        else if (key < root->power)
        {
            return search(key, root->left);
        }
        else if (key > root->power)
        {
            return search(key, root->right);
        }
        return root;
    }

    Node *highest(Node *root)
    {
        if (root->right == nullptr)
        {
            return root;
        }
        else
        {
            return highest(root->right);
        }
    }

    Node *removeNode(Node *temp, int data)
    {
        Node *succ;
        if (temp == nullptr)
        {
            return temp;
        }

        if (data < temp->power)
        {
            temp->left = removeNode(temp->left, data);
        }
        else if (data > temp->power)
        {
            temp->right = removeNode(temp->right, data);
        }
        else
        {
            if (temp->left == nullptr)
            {
                Node *curr = temp->right;
                cout << "You plucked " << temp->gem << "[" << temp->power << "]" << endl;
                delete temp;
                return curr;
            }
            else if (temp->right == nullptr)
            {
                Node *curr = temp->left;
                cout << "You plucked " << temp->gem << "[" << temp->power << "]" << endl;
                delete temp;
                return curr;
            }
            else
            {
                Node *parent = temp;
                succ = temp->right;
                while (succ->left != nullptr)
                {
                    parent = succ;
                    succ = succ->left;
                }
                if (parent != temp)
                {
                    parent->left = succ->right;
                }
                else
                {
                    parent->right = succ->right;
                }
                temp->power = succ->power;
                temp->gem = succ->gem;
                cout << "You plucked " << succ->gem << "[" << succ->power << "]" << endl;

                delete succ;
            }
        }
        return temp;
    }

    void menu(Node *root)
    {
        int optional = 0;
        while (my_power <= max_power)
        {
            cout << "Select an Option" << endl
                 << "1.Display the Magical tree." << endl
                 << "2.Search for a gem by specifying its power." << endl
                 << "3.Gem with Highest Power on the" << endl
                 << "4.Pluck a gem from the tree" << endl
                 << "Run" << endl;
            cin >> optional;

            if (optional == 1)
            {
                order_menu(root);
            }
            if (optional == 2)
            {
                int key;
                cout << "Specify the power" << endl;
                cin >> key;
                Node *temp = search(key, root);
                if (temp != nullptr)
                {
                    cout << "Found!"
                         << "[  " << temp->gem << ",  (" << temp->power << ")"
                         << "  ]" << endl;
                }
                else
                {
                    cout << "Not Found" << endl;
                }
            }
            if (optional == 3)
            {
                Node *temp = highest(root);
                cout << "Highest Power"
                     << "[  " << temp->gem << ",  (" << temp->power << ")"
                     << "  ]" << endl;
            }
            if (optional == 4)
            {
                cout << "Magical tree In-Order:" << endl;
                inOrder(root);
                int key;
                cout << "Which gem to pluck?" << endl;
                cin >> key;
                removeNode(root, key);
            }
            if (optional == 5)
            {
                exit;
            }
        }
    }
};
int main()
{
    Node *root = new Node(30, "Ruby");
    cout << "Welcome To Magical Forest!" << endl;
    cout << "How much magical power can your bag hold?" << endl;
    cin >> max_power;
    Tree t1;
    t1.insert("Saphire", 70, root);
    t1.insert("Pearl", 40, root);
    t1.insert("Opal", 10, root);
    t1.insert("Garnet", 60, root);
    t1.insert("Zircon", 20, root);
    t1.insert("Jade", 5, root);

    t1.menu(root);
    if (my_power < max_power)
    {
        cout << "You Escaped but with Less Gems." << endl
             << "Your Gems: " << my_power << endl;
    }
    if (my_power == max_power)
    {
        cout << "You Won, Maximum Powers Collected!" << endl
             << "Your Gems: " << my_power << endl;
    }
    if (my_power > max_power)
    {
        cout << "Game Over! You Lost!" << endl
             << "Bag Bursted!" << endl;
    }
    return 0;
}