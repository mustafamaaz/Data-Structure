#include <iostream>
using namespace std;

struct EMPLOYEE
{
    int ID, height;
    string Name, Designation;
     EMPLOYEE *left, *right;
};

class EMP_TREE
{
    EMPLOYEE *temp, *curr;

public:
    EMP_TREE()
    {
        temp = curr = NULL;   
    }


    EMPLOYEE *newNode(int id,string name , string DESI)
    {
        temp = new EMPLOYEE;
        temp->left = NULL;
        temp->right = NULL;
        temp->ID = id;
        temp->Name = name;
        temp->Designation = DESI;
        temp->height = 1;
        return temp;
    }

    int height(EMPLOYEE *temp)
    {
        if (temp == NULL)
            return 0;
        
        return temp->height;
    }

    int max(int a, int b)
    {
        if (a > b)
            return a;
        else
            return b;
    }

    void inOrder(EMPLOYEE *temp)
    {
        if (temp == NULL){
            cout << " EMP_TREE is empty." << endl;
            return;
        }
        if (temp->left != NULL){
            inOrder(temp->left);
        }
        cout << temp->ID << "\t\t\t"<<temp->Name << "\t\t\t"<< temp->Designation <<"\t\t"<<endl;
        if (temp->right != NULL)
        {
            inOrder(temp->right);
        }
        return;
    }

    void search_employee(EMPLOYEE *temp, int id)
    {
        if (temp != NULL)
        {
            if (id == temp->ID)
            {
                 cout << temp->ID << " ";
                 cout << temp->Name << " ";
                 cout << temp->Designation << " ";
                return;
            }
            else if (id < temp->ID)
            {
                return search_employee(temp->left, id);
            }
            else if (id > temp->ID)
            {
                return search_employee(temp->right, id);
            }
            else
            {
                cout << "Employee not found!" << endl;
                return;
            }
        }
        else
        {
            cout << "EMP_TREE is empty." << endl;
        }
    }

    void Update_Employee(EMPLOYEE *temp, int id)
    {
        if (temp != NULL)
        {
            // compare first node
            if (id == temp->ID)
            {
                cout << "\nEnter the new Name of Employee" << endl;
                cin>>temp->Name;
                cout << "Enter the new Designation of Employee" << endl;
                cin>>temp->Designation;
                return;
            }
            else if (id < temp->ID)
            {
                return Update_Employee(temp->left, id);
            }
            else if (id > temp->ID)
            {
                return Update_Employee(temp->right, id);
            }
            else if (temp == NULL)
            {
                cout << "Employee not found." << endl;
                return;
            }
        }
        else
        {
            cout << "EMP_TREE is empty." << endl;
        }
    }

    EMPLOYEE *Add_Employee(EMPLOYEE *temp, int id,string name,string desi)
    {
        if (temp == NULL)
        {
            temp = newNode(id , name , desi);
            return temp;
        }
        else
        {
            if (id == temp->ID)
            {
                cout << "Value already in tree!" << endl;
                return temp;
            }
            else if (id < temp->ID)
            {
                temp->left = Add_Employee(temp->left, id,name,desi);
            }
            else
            {
                temp->right = Add_Employee(temp->right, id,name,desi);
            }
        }

        //balance factor and setting height
        temp->height = 1 + max(height(temp->left), height(temp->right));
        int balancefactor = getBalanceFactor(temp);
        if (balancefactor > 1)
        {
            if (id < temp->left->ID)
                return rotate_right(temp);
            
            else if (id > temp->left->ID)
            {
                temp->left = rotate_left(temp->left);
                return rotate_right(temp);
            }
        }
        if (balancefactor < -1)
        {
            if (id > temp->right->ID)
                return rotate_left(temp);
            
            else if (id < temp->right->ID)
            {
                temp->right = rotate_right(temp->right);
                return rotate_left(temp);
            }
        }
        return temp;
    }

    EMPLOYEE *rotate_left(EMPLOYEE *temp)
    {
        EMPLOYEE *parent, *child;
        parent = temp->right;
        child = parent->left;
        parent->left = temp;
        temp->right = child;
        temp->height = 1 + max(height(temp->left), height(temp->right));
        parent->height = 1 + max(height(parent->left), height(parent->right));
        return parent;
    }
    EMPLOYEE *rotate_right(EMPLOYEE *temp)
    {
        EMPLOYEE *parent, *child;
        parent = temp->left;
        child = parent->right;
        parent->right = temp;
        temp->left = child;
        temp->height = 1 + max(height(temp->left), height(temp->right));
        parent->height = 1 + max(height(parent->left), height(parent->right));
        return parent;
    }

    int getBalanceFactor(EMPLOYEE *temp)
    {
        return (height(temp->left) - height(temp->right));
    }

    EMPLOYEE *Remove_Employee(EMPLOYEE *temp, int id)
    {
        if (temp == NULL)
        {
            cout << "EMP_TREE is empty." << endl;
            return temp;
        }

        if (id < temp->ID)
            temp->left = Remove_Employee(temp->left, id);
        
        else if (id > temp->ID)
            temp->right = Remove_Employee(temp->right, id);
        
        else
        {
            if (temp->left == NULL || temp->right == NULL)
            {
                EMPLOYEE *tempChild = temp->left ? temp->left : temp->right;
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
                EMPLOYEE *successor = findMin(temp->right);
                temp->ID = successor->ID;
                temp->Name = successor->Name;
                temp->Designation = successor->Designation;
                temp->right = Remove_Employee(temp->right, successor->ID);
            }
        }

        if (temp == NULL)
            return temp;
        

        temp->height = 1 + max(height(temp->left), height(temp->right));
        int BF = getBalanceFactor(temp);

        // Rebalance the tree
        if (BF > 1 && getBalanceFactor(temp->left) >= 0)
        {
            return rotate_right(temp);
        }
        if (BF > 1 && getBalanceFactor(temp->left) < 0)
        {
            temp->left = rotate_left(temp->left);
            return rotate_right(temp);
        }
        if (BF < -1 && getBalanceFactor(temp->right) <= 0)
        {
            return rotate_left(temp);
        }
        if (BF < -1 && getBalanceFactor(temp->right) > 0)
        {
            temp->right = rotate_right(temp->right);
            return rotate_left(temp);
        }

        return temp;
    }

    EMPLOYEE *findMin(EMPLOYEE *temp)
    {
        while (temp->left != NULL)
        {
            temp=temp->left;
        }
        return temp;
    }

    EMPLOYEE *findMax(EMPLOYEE *temp)
    {
        while (temp->right != NULL)
        {
            temp=temp->right;
        }
        return temp;
    }

  
};

int main()
{

    EMP_TREE tree;
    EMPLOYEE *root = NULL;
    int opt;
    int key;
    string nam,desgi;
  
    while (true){
    cout<<"\n\n****************************";
    cout << "\n1) Add New Employee\t   *\n2) Delete Employee\t   *\n3) Display Employee Data   *\n4) Update Employee Data    *\n5) Search Employee Data    *\n6) Exit\t\t           *\n";
     cout<<"****************************\n";
    cin >> opt;


        if (opt == 1)
        {
            cout << "\nEnter Id of Employee: ";
            cin >> key;
            cout << "\nEnter Name of Employee: ";
            cin >> nam;
            cout << "\nEnter Designation of Employee: ";
            cin >> desgi;

            cout << "\t";
            root = tree.Add_Employee(root, key,nam,desgi);
          
        }
        else if (opt == 2)
        {
            cout << "Enter Id of Employee: ";
            cin >> key;
            cout << "\t";
            root = tree.Remove_Employee(root, key);
           
        }
        else if (opt == 3)
        {
              cout<<"=============================================================";
             cout << "\nID\t\t\t"<<"Name\t\t\t"<<"Designation\t\t\t"<<endl;
             cout<<"============================================================="<<endl<<endl;
            tree.inOrder(root);
          
        }
        else if (opt == 4)
        {
            cout << "Enter ID of Enployee: ";
            cin >> key;
            cout << "\t";
            tree.Update_Employee(root, key);
            cout << " Value updated." << endl;
           
        }
        else if (opt == 5)
        {
            cout << "Enter ID of Enployee: ";
            cin >> key;
            cout << "\t";
            tree.search_employee(root, key);
           
        }
        else if (opt == 6)
            break;
        else
            break;
        
    }
    return 0;
}