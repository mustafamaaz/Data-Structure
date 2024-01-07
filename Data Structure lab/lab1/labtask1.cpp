#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void swap(int *ptr, int *ptr1)
{

    int val1 = *ptr;
    int val2 = *ptr1;
    *ptr = val2;
    *ptr1 = val1;
}

int main()
{
    int a, b;
    int *ptr1 = &a;
    int *ptr2 = &b;
    cout << "Enter the first value" << endl;
    cin >> *ptr1;

    cout << "Enter the second value\n"
         << endl;
    cin >> *ptr2;

    cout << "\nBefore swapping" << endl
         << *ptr1 << " " << *ptr2 << endl;

    swap(ptr1, ptr2);

    cout << "\nAfter swapping" << endl
         << *ptr1 << " " << *ptr2 << endl;

    return 0;
}