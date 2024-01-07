#include <iostream>
using namespace std;

class Date
{
public:
    int year;
    int month;
    int day;
    Date()
    {
        year = 0;
        month = 0;
        day = 0;
    }
};

struct node
{
    int ISBN;
    string auther, title, generation;
    Date publication_date;
    node *next;
    node *prev;

    node()
    {
        next = prev = NULL;
    }
};

class list
{
private:
    node *head;
    node *tail, *temp1, *temp2;

public:
    list()
    {
        head = NULL;
        tail = temp1 = temp2 = NULL;
    }

    void commom(node *temp1)
    {

        cout << "\n\n";
        cout << "ISBN: " << temp1->ISBN << endl;
        cout << "Author: " << temp1->auther << endl;
        cout << "Title: " << temp1->title << endl;
        cout << "Genre: " << temp1->generation << endl;
        cout << "Publication Date: " << temp1->publication_date.day << "/"
             << temp1->publication_date.month << "/" << temp1->publication_date.year << endl;
        cout << endl;
    }

    void add_new_book()
    {

        node *newBook = new node;
        char dash;
        cout << "Enter the ISBN of the book: ";
        cin >> newBook->ISBN;
        cout << "Enter the auther of the book: ";
        cin >> newBook->auther;
        cout << "Enter the title of the book: ";
        cin >> newBook->title;
        cout << "Enter the generation of the book: ";
        cin >> newBook->generation;
        cout << "Enter the publication date of the book (dd-mm-yy format): ";
        cin >> newBook->publication_date.day >> dash >> newBook->publication_date.month >> dash >> newBook->publication_date.year;

        if (head == NULL)
        {
            newBook->next = NULL;
            newBook->prev = NULL;
            head = newBook;
            tail = newBook;
        }
        else
        {
            newBook->next = NULL;
            newBook->prev = tail;
            tail->next = newBook;
            tail = newBook;
        }
    }

    void search_book()
    {
        int opt, count = 0, isbn;
        string name;
        temp1 = head;
        cout << "1)Searching Book Via Name \n2)Searching Book Via ISBN\n";
        cin >> opt;

        if (opt == 1)
        {
            count == 0;
            cout << "Enter the name of the book\n";
            cin >> name;

            while (temp1 != NULL)
            {
                if (temp1->auther == name)
                {
                    commom(temp1);
                    count++;
                }
                temp1 = temp1->next;
            }
            if (count == 0)
                cout << "\nBook not found\n";
        }
        else if (opt == 2)
        {
            count == 0;

            cout << "Enter the ISBN of the book\n";
            cin >> isbn;

            while (temp1 != NULL)
            {
                if (temp1->ISBN == isbn)
                {

                    commom(temp1);
                    count++;
                }
                temp1 = temp1->next;
            }
            if (count == 0)
                cout << "\nBook not found\n";
        }
    }

    void filter_by_auther()
    {
        int count = 0;
        temp1 = head;
        string auth;
        cout << "\nEnter the Author Name of Book:\n";
        cin >> auth;

        while (temp1 != NULL)
        {
            if (temp1->auther == auth)
            {
                commom(temp1);
                count++;
            }
            temp1 = temp1->next;
        }
        if (count == 0)
            cout << "\nBook not found\n";
    }

    void recomanded_books()
    {
        string name;
        int count = 0;
        cout << "\nEnter the book name:\n";
        cin >> name;
        temp1 = head;

        while (temp1 != NULL)
        {
            if (temp1->auther == name)
            {
                commom(temp1);
                count++;
                if (count == 3)
                    break;
            }
            temp1 = temp1->next;
        }
    }

    void deletion_book()
    {

        temp1 = temp2 = head;
        int isbn;

        cout << "\nEnter the ISBN Number\n";
        cin >> isbn;

        if (head == NULL)
        {
            cout << "\nNo Book exist which you want to delete\n";
            return;
        }

        if (head->ISBN == isbn)
        {

            temp1 = head->next;
            delete head;
            head = temp1;
            head->prev == NULL;
            return;
        }
        else if (tail->ISBN == isbn)
        {

            temp1 = tail->prev;
            delete tail;
            tail = temp1;
            tail->next = NULL;
        }
        else
        {

            while (temp1 != NULL)
            {
                if (temp1->ISBN == isbn)
                {
                    temp1->prev->next = temp1->next;
                    temp1->next->prev = temp1->prev;
                    delete temp1;
                    temp1 = NULL;
                    break;
                }
                temp1 = temp1->next;
            }
        }
    }

    void display()
    {

        temp1 = head;

        while (temp1 != NULL)
        {
            commom(temp1);
            temp1 = temp1->next;
        }

        temp1 == NULL;
    }

    ~list()
    {

        temp1 = head;
        node *rmv;
        while (temp1 != NULL)
        {

            rmv = temp1->next;
            delete temp1;
            temp1 = rmv;
        }
    }
};

int main()
{
    list l;
    int opt;

    while (true)
    {
       cout<<"\n\n\n1) Add New Book\n2) Search For Book\n3) Display Book\n4) Filter By Author\n5) Recommanded Book\n6) Delete Book\n7) Exit\n";
       cin>>opt;
       if(opt ==1)
       l.add_new_book();
       else if (opt==2)
       l.search_book();
       else if(opt == 3)
       l.display();
       else if(opt == 4)
       l.filter_by_auther();
       else if(opt == 5)
       l.recomanded_books();
       else if(opt ==6)
       l.deletion_book();
       else
       break;
    }

    return 0;
}