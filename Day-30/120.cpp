#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_BOOKS = 100;

void displayMenu();
void addBook(int ids[], string titles[], string authors[], bool issued[], int& count);
void displayAllBooks(const int ids[], const string titles[], const string authors[], const bool issued[], int count);
void searchBook(const int ids[], const string titles[], const string authors[], int count);
void issueOrReturnBook(const int ids[], bool issued[], int count, bool actionType);

int main() {
    int bookIDs[MAX_BOOKS];
    string bookTitles[MAX_BOOKS];
    string bookAuthors[MAX_BOOKS];
    bool isIssued[MAX_BOOKS] = {false}; 
    
    int bookCount = 0; 
    int choice;

    bookIDs[0] = 101; bookTitles[0] = "The Great Gatsby"; bookAuthors[0] = "F. Scott Fitzgerald"; isIssued[0] = false;
    bookIDs[1] = 102; bookTitles[1] = "To Kill a Mockingbird"; bookAuthors[1] = "Harper Lee"; isIssued[1] = true;
    bookCount = 2;

    cout << "=========================================\n";
    cout << "  Welcome to the Mini Library System     \n";
    cout << "=========================================\n";

    do {
        displayMenu();
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                addBook(bookIDs, bookTitles, bookAuthors, isIssued, bookCount);
                break;
            case 2:
                displayAllBooks(bookIDs, bookTitles, bookAuthors, isIssued, bookCount);
                break;
            case 3:
                searchBook(bookIDs, bookTitles, bookAuthors, bookCount);
                break;
            case 4:
                issueOrReturnBook(bookIDs, isIssued, bookCount, true); 
                break;
            case 5:
                issueOrReturnBook(bookIDs, isIssued, bookCount, false); 
                break;
            case 6:
                cout << "\nThank you for using the Library Management System. Goodbye!\n";
                break;
            default:
                cout << "Invalid option chosen! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
void displayMenu() {
    cout << "\n-----------------------------------------\n";
    cout << "1. Add a New Book\n";
    cout << "2. Display All Books\n";
    cout << "3. Search Book by Title\n";
    cout << "4. Issue a Book\n";
    cout << "5. Return a Book\n";
    cout << "6. Exit Application\n";
    cout << "-----------------------------------------\n";
}

void addBook(int ids[], string titles[], string authors[], bool issued[], int& count) {
    if (count >= MAX_BOOKS) {
        cout << "Error: Library database is full!\n";
        return;
    }
    cout << "\nEnter Book ID (Integer): ";
    cin >> ids[count];
    
    cin.ignore();
    cout << "Enter Book Title: ";
    getline(cin, titles[count]);
    
    cout << "Enter Author Name: ";
    getline(cin, authors[count]);
    
    issued[count] = false; 
    count++;
    cout << "Book successfully saved to inventory!\n";
}

void displayAllBooks(const int ids[], const string titles[], const string authors[], const bool issued[], int count) {
    if (count == 0) {
        cout << "\nThe library inventory is currently empty.\n";
        return;
    }

    cout << "\n" << left << setw(10) << "ID" << setw(30) << "TITLE" << setw(25) << "AUTHOR" << "STATUS\n";
    cout << "----------------------------------------------------------------------------\n";
    
    for (int i = 0; i < count; i++) {
        cout << left << setw(10) << ids[i] 
             << setw(30) << titles[i] 
             << setw(25) << authors[i] 
             << (issued[i] ? "Borrowed" : "Available") << "\n";
    }
}

void searchBook(const int ids[], const string titles[], const string authors[], int count) {
    if (count == 0) {
        cout << "\nNo books available to search.\n";
        return;
    }

    cin.ignore();
    string searchStr;
    cout << "\nEnter the exact Title to search: ";
    getline(cin, searchStr);

    bool found = false;
    for (int i = 0; i < count; i++) {
       
        if (titles[i] == searchStr) {
            cout << "\nBook Found!";
            cout << "\nID: " << ids[i] << "\nTitle: " << titles[i] << "\nAuthor: " << authors[i] << "\n";
            found = true;
            break; 
        }
    }
    if (!found) {
        cout << "No book matches the title: \"" << searchStr << "\"\n";
    }
}

void issueOrReturnBook(const int ids[], bool issued[], int count, bool actionType) {
    int searchID;
    cout << "\nEnter Book ID: ";
    cin >> searchID;

    for (int i = 0; i < count; i++) {
        if (ids[i] == searchID) {
            if (actionType) { 
                if (issued[i]) {
                    cout << "Sorry, this book is already checked out.\n";
                } else {
                    issued[i] = true;
                    cout << "Book successfully checked out!\n";
                }
            } else { 
                if (!issued[i]) {
                    cout << "This book is already sitting in shelves.\n";
                } else {
                    issued[i] = false;
                    cout << "Book successfully returned to inventory!\n";
                }
            }
            return;
        }
    }
    cout << "Book ID: " << searchID << " not found in system registers.\n";
}