#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct node
{

    int info,bf;
    node *left, *right;
};

class binary_search_tree
{

private:
    node *temp, *temp1;

public:
    node *root;
    int number;

    binary_search_tree()
    {
        root = temp = temp1 = NULL;
    }

    void insert_binary_tree(node *temp)
    {

        if (root == NULL)
        {

            temp = new node;
            temp->info = number;
            temp->left = NULL;
            temp->right = NULL;
            root = temp;
            return;
        }

        if (temp->info == number)
        {

            cout << " \n Given number is already present in tree.\n";
            return;
        }

        if (temp->info > number)
        {

            if (temp->left != NULL)
            {
                insert_binary_tree(temp->left);
                return;
            }

            else
            {

                temp->left = new node;
                temp->left->info = number;
                temp->left->left = NULL;
                temp->left->right = NULL;
                return;
            }
        }

        if (temp->info < number)
        {

            if (temp->right != NULL)
            {

                insert_binary_tree(temp->right);
                return;
            }

            else
            {

                temp->right = new node;
                temp->right->info = number;
                temp->right->left = NULL;
                temp->right->right = NULL;
                return;
            }
        }
    }

  

    int height_binary_tree(node *temp){

        if (temp == NULL){
           return 0;}

            int left_height =  height_binary_tree(temp->left);
            int right_height =   height_binary_tree(temp->right);
            temp->bf = left_height - right_height;
            return max(left_height , right_height) + 1 ;
    }

    void deleting_binary_tree(node *temp)
    {
        if (root == NULL)
        {
            cout << "\nThere is no child to delete\n";
            return;
        }

        if (root->info == number)
        {

            //   case 1 having not child
            if (temp->left == NULL && temp->right == NULL)
            {
                delete root;
                root = NULL;
                cout << "\nroot case 1 done \n";
                return;
            }

            // case 2 having 1 child on left or right
            if (temp->left == NULL)
            {
                // seting pointer to right
                temp1 = root;
                root = root->right;
                delete temp1;
                temp1 = NULL;
                temp = root;
                cout << "\nroot case 2 left null  done \n";
                return;
            }
            if (temp->right == NULL)
            {
                // setting pointer to left
                temp1 = root;
                root = root->left;
                delete temp1;
                temp1 = NULL;
                temp = root;
                cout << "\nroot case 2 right null  done \n";
                return;
            }

            //   case 3 having 2 child
            if (temp->left != NULL && temp->right != NULL)
            {

                temp1 = temp->right;

                if (temp1->left != NULL)
                {

                    while (temp1->left->left != NULL)
                    {
                        temp1 = temp1->left;
                    }

                    root->info = temp1->left->info;
                    temp = temp1->left;
                    temp1->left = temp1->left->right;
                    delete temp;
                    temp == NULL;
                    cout << "\nroot case 3 throught immediate successor  done \n";
                    return;
                }
                else
                {
                    root->info = temp1->info;
                    temp->right = temp->right->right;
                    delete temp1;
                    temp1 = NULL;
                    cout << "\nroot case 3 throught immediate successor  done else portion \n";
                    return;
                }
            }
        }
        else
        {
            if (number > temp->info)
            {
                if (temp->right->info == number)
                {

                    //   case 1 having not child
                    if (temp->right->left == NULL && temp->right->right == NULL)
                    {
                        delete temp->right;
                        temp->right = NULL;
                        cout << "\ngeneral case 1 done \n";
                        return;
                    }

                    // case 2 having 1 child on left or right
                    if (temp->right->left == NULL)
                    {
                        // seting pointer to right
                        temp1 = temp->right;
                        temp->right = temp->right->right; // or temp->right = temp1->right;
                        delete temp1;
                        temp1 = NULL;
                        cout << "\ngeneral case 2 left null done \n";
                        return;
                    }
                    if (temp->right->right == NULL)
                    {
                        // setting pointer to left
                        temp1 = temp->right;
                        temp->right = temp->right->left; // or temp->right = temp1->right;
                        delete temp1;
                        temp1 = NULL;
                        cout << "\ngeneral case 2 right null done \n";
                        return;
                    }

                    //   case 3 having 2 child
                    if (temp->left != NULL && temp->right != NULL)
                    {
                        temp = temp->right;
 
                        temp1 = temp->right;
                        if (temp1->left != NULL)
                        {

                            while (temp1->left->left != NULL)
                            {
                                temp1 = temp1->left;
                            }

                            temp->info = temp1->left->info;
                            temp = temp1->left;
                            temp1->left = temp1->left->right;
                            delete temp;
                            temp == NULL;
                            cout << "\nright  case 3 throught immediate successor  done \n";
                            return;
                        }
                        else
                        {
                            temp->info = temp1->info;
                            temp->right = temp->right->right;
                            delete temp1;
                            temp1 = NULL;
                            cout << "\nright  case 3 throught immediate successor  done else portion \n";
                            return;
                        }
                    }
                }
                else
                {
                    deleting_binary_tree(temp->right);
                    return;
                }
            }

            // left
            if (number < temp->info)
            {
                if (temp->left->info == number)
                {

                    //   case 1 having not child
                    if (temp->left->left == NULL && temp->left->right == NULL)
                    {
                        delete temp->left;
                        temp->left = NULL;
                        cout << "\ngeneral case 1 done \n";
                        return;
                    }

                    // case 2 having 1 child on left or right
                    if (temp->left->left == NULL)
                    {
                        // seting pointer to right
                        temp1 = temp->left;
                        temp->left = temp->left->right; // or temp->right = temp1->right;
                        delete temp1;
                        temp1 = NULL;
                        cout << "\ngeneral case 2 left null done \n";
                        return;
                    }
                    if (temp->left->right == NULL)
                    {
                        // setting pointer to left
                        temp1 = temp->left;
                        temp->left = temp->left->left; // or temp->right = temp1->right;
                        delete temp1;
                        temp1 = NULL;
                        cout << "\ngeneral case 2 right null done \n";
                        return;
                    }

                    //   case 3 having 2 child
                    if (temp->left->left  != NULL && temp->left->right != NULL)
                    {

                        temp = temp->left;
                        temp1 = temp->right;
                        if (temp1->left != NULL)
                        {

                            while (temp1->left->left != NULL)
                            {
                                temp1 = temp1->left;
                            }

                            temp->info = temp1->left->info;
                            temp = temp1->left;
                            temp1->left = temp1->left->right;
                            delete temp;
                            temp == NULL;
                            cout << "\nleft case 3 throught immediate successor  done \n";
                            return;
                        }
                        else
                        {
                            temp->info = temp1->info;
                            temp->right = temp->right->right;
                            delete temp1;
                            temp1 = NULL;
                            cout << "\nleft case 3 throught immediate successor  done else portion \n";
                            return;
                        }
                    }
                }
                else
                {
                    deleting_binary_tree(temp->left);
                    return;
                }
            }
        }
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

        cout << temp->info << " ";

        if (temp->right != NULL)
            in_order(temp->right);

        return;
    }




    void balance_factor(node *temp)
    {

        if (root == NULL)
        {
            cout << " Tree is empty.\n";
            return;
        }

        if (temp->left != NULL)
          balance_factor(temp->left);

        cout << temp->bf << " ";

        if (temp->right != NULL)
           balance_factor(temp->right);

        return;
    }






    void pre_order(node *temp)
    {

        if (root == NULL)
        {

            cout << " Tree is empty.\n";
            return;
        }

        cout << temp->info << " ";

        if (temp->left != NULL)
            in_order(temp->left);

        if (temp->right != NULL)
            in_order(temp->right);

        return;
    }

    void post_order(node *temp)
    {

        if (root == NULL)
        {

            cout << " Tree is empty.\n";
            return;
        }

        if (temp->left != NULL)
            in_order(temp->left);

        if (temp->right != NULL)
            in_order(temp->right);

        cout << temp->info << " ";

        return;
    }
};

int main()
{

    binary_search_tree obj;
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
            obj.insert_binary_tree(obj.root);
        }
        else if (choise == 2)
        {
            obj.in_order(obj.root);
        }
        else if (choise == 3)
        {
            cout << "Enter the number which you want to delete\n";
            cin >> obj.number;
            obj.deleting_binary_tree(obj.root);
        }
        else if (choise == 4)
        {
           r_height =    obj.height_binary_tree(obj.root);
           cout<<r_height -1 ;
        }
          else if (choise == 5)
        {
           obj.balance_factor(obj.root);
            
        }
           else if (choise == 6)
        {
            break;
        }
    }

    return 0;
}
