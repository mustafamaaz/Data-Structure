#include <iostream>
using namespace std;
// my code
struct node
{
public:
    int info, pririoty;

    node(){
        info = pririoty = 0;
    }
};

class Heap
{
private:
    node *heapArr, *currentptr, *head;
    int size;

public:
    Heap(int maxsize)
    {

        heapArr = new node[maxsize];
        size = maxsize;
    }
    Heap(){
        currentptr = NULL;
        head = &heapArr[1];
    }
    ~Heap()
    {
        delete[] heapArr;
    }

    int getParent(int child_index)
    {
        int parentnode = child_index / 2;
        return parentnode;
    }

    int getLeftChild(int parent_index)
    {
        int leftChild = parent_index * 2;
        return leftChild;
    }

    int getRightChild(int parent_index)
    {
        int rightChild = (parent_index * 2) + 1;
        return rightChild;
    }

    void swap(node *a, node *b)
    {
        node temp = *a;
        *a = *b;
        *b = temp;
    }

    void heapifyUp(int node)
    {
        int parentNode;
        if (node == 0)
            return;
        parentNode = getParent(node);
        if (heapArr[node].pririoty < heapArr[parentNode].pririoty)
        {
            swap(&heapArr[node], &heapArr[parentNode]);
            heapifyUp(parentNode);
        }
    }

    void heapifyDown(int node)
    {

        int size = getSize();
        int smallest = node;
        int left = getLeftChild(node);
        int right = getRightChild(node);


        if (left < size && heapArr[left].pririoty < heapArr[smallest].pririoty)
        {
            smallest = left;
        }
        if (right < size && heapArr[right].pririoty < heapArr[smallest].pririoty)
        {
            smallest = right;
        }
        if (smallest != node)
        {
            swap(&heapArr[node], &heapArr[smallest]);
            heapifyDown(smallest);
        }

    }

    int getSize()
    {
        head = &heapArr[1];
        int count = 1;

        if (currentptr == NULL)
            return 0;

        while (head != currentptr)
        {
            count++;
            head++;
        }

        cout<<"size is "<<count;

        return count;
    }

    void insert(node patient, int i)
    {
        cout << "Enter info: ";
        cin >> patient.info;
        cout << "Enter pririoty level: ";
        cin >> patient.pririoty;
        heapArr[i] = patient;
        currentptr = &heapArr[i];
        heapifyUp(i);
    }
    void deleteNode()
    {
        head = &heapArr[1];
        if (currentptr != head)
            currentptr--;
        else
        {
            cout << "\nthere is only 1 node in array";
            currentptr = NULL;
        }
    }
    void del(int lastNode)
    {
        if (getSize() == 0)
        {
            cout << "there is no node to delete." << endl;
            return;
        }
         if (getSize() == 1)
        {
            deleteNode();
            return;
        }

        heapArr[0] = heapArr[lastNode];
        deleteNode();
        heapifyDown(1);
    }

    void display()
    {
         head = &heapArr[1];

        int i=1;
        while (head != currentptr)
        {
            cout << "info: " << heapArr[i].info << ", pririoty: " << heapArr[i].pririoty << endl;
            i++;
            head++;
        }
          cout << "info: " << heapArr[i].info << ", pririoty: " << heapArr[i].pririoty << endl;
          head = &heapArr[1];
        
    }

    int next(int x)
    {
        x = x + 1;
        return x;
    }
    int previous(int x)
    {
        x = x - 1;
        return x;
    }
};

int main()
{
    Heap priorityQueue(10);
    int count = 0;

    while (true)
    {
        cout << "\n==== Priority Queue Menu ====" << endl;
        cout << "1. insert" << endl;
        cout << "2. Display" << endl;
        cout << "3. Deletion" << endl;
        cout << "4. size" << endl;
         cout << "5. exit" << endl;

        int choice;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            node newNode;
            if (count <= 10)
            {
                 count = priorityQueue.next(count);
                priorityQueue.insert(newNode, count);
            }
            else
            {
                cout << "\nincrease your array size \n";
            }

            break;
        }
        case 2:
            priorityQueue.display();
            break;
        case 3:
            priorityQueue.del(count);
              count = priorityQueue.previous(count);
            break;
               case 4:
           priorityQueue.getSize();
            break;
        case 5:
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
        cout << "\nCurrent Appointments:" << endl;
        priorityQueue.display();
    }
    return 0;
}