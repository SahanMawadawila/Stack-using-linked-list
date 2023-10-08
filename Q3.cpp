#include "Stack.h"
int main() {
    Stack stack;
    int noOfNodes, element;
    cout << "Initial number of elements: ";
    cin >> noOfNodes;
    if (noOfNodes < 0) {
        cout << "Num of nodes should be higher than or equal to 0";
        return 1;
    }

    for (int i = 0; i < noOfNodes; i++) {
        cin >> element;
        stack.push(element);
    }
    cout << "Stack : ";
    stack.print();
    cout << endl;

    int choice, data;
    while (true) {
        cout << "1 - Push\n"
            << "2 - Pop\n"
            << "3 - Print\n"
            << "4 - Reverse\n"
            << "5 - Count\n"
            << "6 - Delete\n"
            << "Enter your choice: ";
        cin >> choice;

        system("cls");

        switch (choice) {
        case 1: {
            cout << "Enter the data to stack: ";
            cin >> data;
            stack.push(data);
            cout << "Stack : ";
            stack.print();
            cout << endl;
            break;
        }
        case 2: {
            cout << "Popped value: " << stack.pop() << endl;
            cout << "Stack : ";
            stack.print();
            cout << endl;
            break;
        }
        case 3: {
            cout << "Stack : ";
            stack.print();
            cout << endl;
            break;
        }
        case 4: {
            stack.reverse();
            cout << "Stack : ";
            stack.print();
            cout << endl;
            break;
        }
        case 5: {
            cout << "Number of elements in the stack: " << stack.count() << endl;
            break;
        }
        case 6:
        {
            stack.delete_stack();
            cout << endl;
            cout << "Exiting the program." << endl;
            return 0;
        }
        default: {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    }

    return 0;
}