#include <iostream>



using namespace std;

class Queue
{
private:
    int *data;
    int *front;
    int *rear;
    int size;

public:
Queue(){}
    Queue(int maxSize)
    {
        data = new int[maxSize];
        front = NULL;
        rear = NULL;
        size = maxSize;
    }
    ~Queue(){
        delete[] data;
    }

    bool isEmpty()
    {
        return (front == NULL && rear == NULL) ? true : false;
    }

    bool isFull()
    {
      cout<<(rear - front )<<"\n";
      
        return  ( rear - front ) + 1 == size ? true : false;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue element.\n";
            return;
        }
        else if (isEmpty())
        {
            front = rear = data;
            cout<<"empty que in enqueue\n";
        }
        else
        {
            rear++;
        }

        *rear = value;
        cout << value << " enqueued to the queue.\n";
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue element.\n";
            return;
        }
        else if (front == rear)  // dono ak hi jaga khary hen 
        {
            cout<<"when only 1 element is insert this is dequeue :"<<*front<<"   \n";
            front++;
        }
        else
        {
             cout<<"this is dequeue :"<<*front<<"   \n";
            front++;
        }
    }

    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return -1;
        }

        return *front;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements: ";
        int *i = front;
        while (i != rear)
        {
            cout << *i << " ";
          i++;
        }
        cout << *rear << "\n";



    }
};

int main()
{
    Queue queue(5);
int opt,num;

while (true)
{
     cout << "\n1)Enqueue\n2)Dequeue\n3)display\n4)exit\n";
     cin>>opt;

     if (opt == 1)
     {
        cout<<"Enter the number :";
        cin>>num;
          queue.enqueue(num);
     }  else if(opt ==2){
           queue.dequeue();
     } else if(opt ==3){
           queue.display();
     } else{
        break;
     }
     
  
}
    return 0;
}