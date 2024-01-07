#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{

    srand(time(nullptr));
    int array[4][7];
    int *ptr = &array[0][0];

    //  assign value to array

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            *ptr = rand() % 21 + 10;
            ptr++;
        }
    }

    ptr = &array[0][0];

    // print array

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 7; j++)
        {

            cout << " " << *ptr;
            ptr++;
        }
        cout << "\n";
    }

    cout << "\n\n";

    ptr = &array[0][0];
    string dayname;
    int *ptr1 = &array[0][0];
    ptr1++;

    //  logic to finding greater value in week

    int day = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j < 7; j++)
        {

            //  if (*ptr >*ptr1 )
            //         {
            //             *ptr = *ptr;
            //             ptr1++;
            //             day = j;

            //         } else
            if (*ptr1 > *ptr)
            {
                *ptr = *ptr1;
                day = j;
                ptr1++;
            }
            else if (*ptr == *ptr)
            {
                ptr1++;
            }
        }

        switch (day + 1)
        {
        case 1:
            dayname = "Monday";
            break;
        case 2:
            dayname = "Tuesday";
            break;
        case 3:
            dayname = "Wednesday";
            break;
        case 4:
            dayname = "Thursday";
            break;
        case 5:
            dayname = "Friday";
            break;
        case 6:
            dayname = "Saturday";
            break;
        case 7:
            dayname = "Sunday";
            break;
        default:
            break;
        }
        cout << " Hotest day of week " << i + 1 << " is:"
             << " day " << dayname << " Having a temperature " << *ptr << endl;

        ptr = &array[i + 1][0];

        ptr1 = &array[i + 1][0];
        ptr1++;
        day = 0;
    }

    return 0;
}