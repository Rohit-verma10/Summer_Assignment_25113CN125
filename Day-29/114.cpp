#include <iostream>
using namespace std;
const int MAX_SIZE = 100;

void displayArray(const int arr[], int size);
void insertElement(int arr[], int& size);
void deleteElement(int arr[], int& size);
int searchElement(const int arr[], int size, int target);

int main() {
    int arr[MAX_SIZE];
    int size = 0; 
    int choice;

    cout << "=== Initialize Array ===\n";
    cout << "Enter the initial number of elements (Max " << MAX_SIZE << "): ";
    cin >> size;

    if (size > MAX_SIZE || size < 0) {
        cout << "Invalid size! Setting initial size to 0.\n";
        size = 0;
    } else if (size > 0) {
        cout << "Enter " << size << " integers:\n";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }
    do {
        cout << "\n===============================\n";
        cout << "   ARRAY OPERATIONS SYSTEM     \n";
        cout << "===============================\n";
        cout << "1. Display Array\n";
        cout << "2. Insert Element\n";
        cout << "3. Delete Element\n";
        cout << "4. Search Element\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayArray(arr, size);
                break;
            case 2:
                insertElement(arr, size);
                break;
            case 3:
                deleteElement(arr, size);
                break;
            case 4: {
                if (size == 0) {
                    cout << "Array is empty. Nothing to search.\n";
                    break;
                }
                int target;
                cout << "Enter element to search: ";
                cin >> target;
                int index = searchElement(arr, size, target);
                if (index != -1) {
                    cout << "Element found at Index: " << index 
                         << " (Position: " << (index + 1) << ")\n";
                } else {
                    cout << "Element not found in the array.\n";
                }
                break;
            }
            case 5:
                cout << "Exiting system. Thank you!\n";
                break;
            default:
                cout << "Invalid choice! Please select between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}
void displayArray(const int arr[], int size) {
    if (size == 0) {
        cout << "Array is completely empty.\n";
        return;
    }
    cout << "Current Array: [ ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "]\n";
    cout << "Total elements: " << size << "\n";
}

void insertElement(int arr[], int& size) {
    if (size >= MAX_SIZE) {
        cout << "Error: Array Overflow! Cannot insert more elements.\n";
        return;
    }

    int index, value;
    cout << "Enter target index for insertion (0 to " << size << "): ";
    cin >> index;

    if (index < 0 || index > size) {
        cout << "Invalid index position!\n";
        return;
    }

    cout << "Enter integer value to insert: ";
    cin >> value;

    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    size++;
    cout << "Element successfully inserted.\n";
}

void deleteElement(int arr[], int& size) {
    if (size == 0) {
        cout << "Error: Array Underflow! No element to delete.\n";
        return;
    }
    int index;
    cout << "Enter target index for deletion (0 to " << (size - 1) << "): ";
    cin >> index;

    if (index < 0 || index >= size) {
        cout << "Invalid index position!\n";
        return;
    }
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
    cout << "Element successfully deleted.\n";
}

int searchElement(const int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; 
}