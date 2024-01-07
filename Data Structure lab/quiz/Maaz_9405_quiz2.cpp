#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *next;
};

class CircularList
{
private:
    Node *head;

public:
    CircularList()
    {
        head = nullptr;
    }

    void insert(int value, int position)
    {
        Node *newNode = new Node;
        newNode->info = value;

        if (position == 1)
        {
            if (head == nullptr)
            {
                head = newNode;
                newNode->next = head;
            }
            else
            {
                Node *current = head;
                while (current->next != head)
                {
                    current = current->next;
                }
                current->next = newNode;
                newNode->next = head;
                head = newNode;
            }
        }
        else
        {
            Node *current = head;
            int count = 1;

            while (count < position - 1 && current->next != head)
            {
                current = current->next;
                count++;
            }

            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void del_pos(int position)
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *current = head;
        Node *previous = nullptr;
        int count = 1;

        while (count < position)
        {
            previous = current;
            current = current->next;
            count++;
            if (current == head)
            {
                cout << "Position not found." << endl;
                return;
            }
        }

        if (previous == nullptr)
        {
            head = current->next;
        }
        else
        {
            previous->next = current->next;
        }

        delete current;
    }

    void update(int position, int newValue)
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *current = head;
        int count = 1;

        while (count < position)
        {
            current = current->next;
            count++;
            if (current == head)
            {
                cout << "Position not found." << endl;
                return;
            }
        }

        current->info = newValue;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *current = head;

        do
        {
            cout << current->info << " ";
            current = current->next;
        } while (current != head);

        cout << endl;
    }
};

int main()
{
    CircularList lst;

    while (4)
    {
        cout << "\nMenu:\n";
        cout << "1. Insert a value at a specific position\n2. Delete a value at a specific position\n3. Update a value at a specific position\n4. Check if the linked lst is a palindrome\n5. Display the linked lst\n6. Exit\n";
        cout << "Enter your option: ";

        int option;
        cin >> option;

        switch (option)
        {
        case 1:
            int value, position;
            cout << "Enter the value to insert: ";
            cin >> value;
            cout << "Enter the position to insert: ";
            cin >> position;
            lst.insert(value, position);
            break;
        case 2:
            int deletePosition;
            cout << "Enter the position to delete: ";
            cin >> deletePosition;
            lst.del_pos(deletePosition);
            break;
        case 3:
            int updatePosition, newValue;
            cout << "Enter the position to update: ";
            cin >> updatePosition;
            cout << "Enter the new value: ";
            cin >> newValue;
            lst.update(updatePosition, newValue);
            break;
        case 4:
            break;
        case 5:
            cout << "Linked List: ";
            lst.display();
            break;
        case 6:
            return 0;
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}
