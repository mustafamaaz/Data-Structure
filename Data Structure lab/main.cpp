#include <iostream>

using namespace std;

int main() {
    int day, month, year;

    cout << "Enter date in dd-mm-yy format: ";
    char dash;

    // Input the date in dd-mm-yy format
    cin >> day >> dash >> month >> dash >> year;

    // Validate the input if needed
    if (cin.fail() || dash != '-') {
        cout << "Invalid input format. Please enter in dd-mm-yy format." << endl;
        return 1;
    }

    // Display the entered date
    cout << "Day: " << day << endl;
    cout << "Month: " << month << endl;
    cout << "Year: " << year << endl;

    return 0;
}
