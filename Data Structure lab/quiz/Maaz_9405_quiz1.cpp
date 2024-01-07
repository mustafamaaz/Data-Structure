#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *prev , *next;
};

void groupsReverse(Node **head, int group, int element)
{
    if (*head == NULL || group % element == 0)
    {
        return;
    }

    Node *current = *head;
    Node *newHead = NULL;
    Node *prevTail = NULL;
    int count = 0;

    while (current != NULL)
    {
        Node *stack[group];
        int i = 0;

        while (current != NULL && i < group)
        {
            stack[i] = current;
            current = current->next;
            i++;
        }

        if (i == group)
        {
            while (i > 0)
            {
                i--;
                Node *node = stack[i];
                if (newHead == NULL)
                {
                    newHead = node;
                }
                node->next = current;
                node->prev = prevTail;
                if (prevTail != NULL)
                {
                    prevTail->next = node;
                }
                if (current != NULL)
                {
                    current->prev = node;
                }
                prevTail = node;
            }
        }
        else
        {
            prevTail->next = stack[0];
            stack[0]->prev = prevTail;
        }
    }

    *head = newHead;
}

void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->info << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int n;
    cout << "Enter the number of boxes of linked list: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        Node *newNode = new Node();
        newNode->info = value;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    int K;

    cout<<"\nEnter the value of k\n";
    cin>>K;

    cout << "Original List: ";
    display(head);

    groupsReverse(&head, K, n);

    cout << "Reversed List: ";
    display(head);

    Node *current = head;
    while (current != NULL)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }

    return 0;
}