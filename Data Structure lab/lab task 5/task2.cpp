#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    int top, size;
    char *array;

public:
    Stack(int x) {
        size = x;
        array = new char[size];
        top = -1;
    }

    ~Stack() {
        delete[] array;
    }

    void push(char x) {
        if (top < size - 1) {
            top++;
            array[top] = x;
        } else {
            cout << "Stack is overflow" << x << endl;
        }
    }

    char pop() {
        if (top >= 0) {
            char x = array[top];
            top--;
            return x;
        } else {
            cout << "Stack is underflow" << endl;
            return '\0'; 
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    void reverseString(string input) {
        for (char c : input) {
            push(c);
        }
        string str;
int i=0;
        while (!isEmpty()) {
            str[i] = pop();
            i++;

        }
              i=0;
         while (i<size) {
            
            cout <<str[i];
            i++;
        }

        cout << endl;
    }
};

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int size = input.length();
    Stack s(size);

    cout << "Reversed string: ";
    s.reverseString(input);

    return 0;
}
