#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    string str;

    cout << "Enter the string " << endl;
    getline(cin, str);

    int length = str.length();
    int condition = length / 2;

    char *ptr1 = &str[0];
    char *ptr2 = &str[0];
    ptr2 = ptr2 + length - 1;

    int count = 0;

    for (int i = 0; i < condition; i++)
    {
        if (*ptr1 == *ptr2)
        {
            count++;
        }
        ptr1++;
        ptr2--;
    }

    if (count == condition)
        cout << "\nString is palamdrome!!!!!!!!!!!!!!!!\n";
    else
        cout << "String is not plandrome";

    ptr1 = &str[0];
    ptr2 = &str[0];
    count = 0;

    char fqr;

    cout << "\nWhich character you want to check ";
    cin >> fqr;

    for (int i = 0; i < str.length(); i++)
    {

        if (*ptr1 == fqr)
        {
            count++;
            ptr1++;
        }
        else
        {
            ptr1++;
        }
    }

    cout << fqr << " exist " << count << " times\n";

    return 0;
}