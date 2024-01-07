#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//  insertion in zig zag manner

struct node
{

    int info;
    node *left, *right;
};

class binary_search_tree
{

private:
    node *temp, *temp1;

public:
    node *root;
    int number, count;

    binary_search_tree()
    {
        root = temp = temp1 = NULL;
        count = 1;
    }

    void adding_zig_zag(node *temp)
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
        else
        {

            if (temp->left == NULL && temp->right == NULL)
            {

                if (count % 2 != 0) // odd
                {
                        temp->right = new node;
                        temp->right->info = number;
                        temp->left = NULL;
                        count++;
                        return;
                    
                }
                else  // even
                {
                     temp->left = new node;
                    temp->left->info = number;
                    temp->right = NULL;
                    count++;
                    return;
                }

             return;
            }
           else if (temp->left == NULL)
            {
                adding_zig_zag(temp->right);
                return;
            }
            else if (temp->right == NULL)
            {
                adding_zig_zag(temp->left);
                return;
            }




            
        }
    }

    	void printTree(node* temp){
			if(temp == NULL){
				cout<<"Nothing To Print In The Tree"<<endl<<endl;
				return;
			}
			
			
			
			if(temp->left != NULL){
				printTree(temp->left);
			}

         
			
			if(temp->right != NULL){
				printTree(temp->right);
			}
               cout<<temp->info<<"  ";
		}




};

int main()
{
 binary_search_tree obj;

 obj.number = 5;
 obj.adding_zig_zag(obj.root);
 obj.number = 8;
  obj.adding_zig_zag(obj.root);
 obj.number = 10;
  obj.adding_zig_zag(obj.root);
 obj.number = 12;
  obj.adding_zig_zag(obj.root);
 obj.number = 24;
  obj.adding_zig_zag(obj.root);
 obj.number = 36;
 obj.adding_zig_zag(obj.root);


 obj.printTree(obj.root);

    return 0;
}
