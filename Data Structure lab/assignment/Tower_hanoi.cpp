#include <iostream>
#include <stack>

using namespace std;

// Function to perform the Tower of Hanoi iterative solution
void towerOfHanoi(int numDisks, char source, char auxiliary, char destination) {
    // Create three stacks to represent the three pegs
    stack<int> sourceStack, auxiliaryStack, destinationStack;

    // Initialize the source stack with disks
    for (int i = numDisks; i > 0; --i) {
        sourceStack.push(i);
    }

    // Total number of moves required
    int totalMoves = (1 << numDisks) - 1; // Equivalent to 2^n - 1

    // Determine the direction of the next move
    char moveDirection;
    if (numDisks % 2 == 0) {
        moveDirection = 'C';
    } else {
        moveDirection = 'A';
    }

    // Perform the moves
    for (int move = 1; move <= totalMoves; ++move) {
        // Determine the source and destination pegs based on the move direction
        char from, to;
        if (move % 3 == 1) {
            from = source;
            to = (moveDirection == 'A') ? auxiliary : destination;
        } else if (move % 3 == 2) {
            from = auxiliary;
            to = (moveDirection == 'A') ? destination : source;
        } else {
            from = destination;
            to = (moveDirection == 'A') ? source : auxiliary;
        }

        // Perform the move and display the step
        int disk = 0;
        switch (from) {
            case 'A':
                disk = sourceStack.top();
                sourceStack.pop();
                break;
            case 'B':
                disk = auxiliaryStack.top();
                auxiliaryStack.pop();
                break;
            case 'C':
                disk = destinationStack.top();
                destinationStack.pop();
                break;
        }

        switch (to) {
            case 'A':
                sourceStack.push(disk);
                break;
            case 'B':
                auxiliaryStack.push(disk);
                break;
            case 'C':
                destinationStack.push(disk);
                break;
        }

        // Toggle the move direction
        moveDirection = (moveDirection == 'A') ? 'B' : 'A';

        // Display the move
        cout << "Move disk " << disk << " from " << from << " to " << to << endl;
    }

    // Display the total number of moves
    cout << "Total moves: " << totalMoves << endl;
}

int main() {
    // Specify the number of disks (you can choose any positive integer)
    int numDisks;
    cout << "Enter the number of disks: ";
    cin >> numDisks;

    // Specify the pegs (you can customize the peg names if needed)
    char source = 'A';
    char auxiliary = 'B';
    char destination = 'C';

    // Call the towerOfHanoi function to solve the puzzle
    towerOfHanoi(numDisks, source, auxiliary, destination);

    return 0;
}