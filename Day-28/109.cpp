#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
class Book {
private:
    int id;
    string title;
    string author;
    bool isIssued;

public:

    Book(int bookId, string bookTitle, string bookAuthor) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        isIssued = false;
    }
    int getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool getIssuedStatus() const { return isIssued; }

    void issueBook() { isIssued = true; }
    void returnBook() { isIssued = false; }

    void displayBook() const {
        cout << left << setw(10) << id 
             << setw(30) << title 
             << setw(25) << author 
             << (isIssued ? "Issued" : "Available") << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:

    void addBook() {
        int id;
        string title, author;

        cout << "\nEnter Book ID (Integer): ";
        while (!(cin >> id)) {
            cout << "Invalid input. Enter an integer for ID: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cin.ignore();
        for (const auto& b : books) {
            if (b.getId() == id) {
                cout << "Error: A book with ID " << id << " already exists!\n";
                return;
            }
        }

        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Author Name: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));
        cout << "Book successfully added to the system!\n";
    }

  
    void viewBooks() const {
        if (books.empty()) {
            cout << "\nThe library collection is currently empty.\n";
            return;
        }
        cout << "\n--------------------------------------------------------------------------\n";
        cout << left << setw(10) << "ID" << setw(30) << "Title" << setw(25) << "Author" << "Status" << endl;
        cout << "--------------------------------------------------------------------------\n";
        for (const auto& b : books) {
            b.displayBook();
        }
        cout << "--------------------------------------------------------------------------\n";
    }

    void searchBook() const {
        if (books.empty()) {
            cout << "\nNo books available to search.\n";
            return;
        }

        int choice;
        cout << "\n1. Search by Book ID\n2. Search by Title\nEnter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            int searchId;
            cout << "Enter Book ID: ";
            cin >> searchId;
            
            for (const auto& b : books) {
                if (b.getId() == searchId) {
                    cout << "\nBook Found:\n";
                    b.displayBook();
                    return;
                }
            }
            cout << "No book found with ID " << searchId << ".\n";
        } 
        else if (choice == 2) {
            string query;
            cout << "Enter Book Title (or part of it): ";
            getline(cin, query);

            bool found = false;
            for (const auto& b : books) {
        
                if (b.getTitle().find(query) != string::npos) {
                    if (!found) {
                        cout << "\nMatching Books Found:\n";
                        found = true;
                    }
                    b.displayBook();
                }
            }
            if (!found) cout << "No books found matching \"" << query << "\".\n";
        } 
        else {
            cout << "Invalid choice selection.\n";
        }
    }

    void issueBook() {
        int id;
        cout << "\nEnter the Book ID to issue: ";
        cin >> id;
        for (auto& b : books) {
            if (b.getId() == id) {
                if (b.getIssuedStatus()) {
                    cout << "Sorry, this book is already issued to someone else.\n";
                } else {
                    b.issueBook();
                    cout << "Book \"" << b.getTitle() << "\" has been successfully issued.\n";
                }
                return;
            }
        }
        cout << "Book ID not found in system repository.\n";
    }

    void returnBook() {
        int id;
        cout << "\nEnter the Book ID to return: ";
        cin >> id;

        for (auto& b : books) {
            if (b.getId() == id) {
                if (!b.getIssuedStatus()) {
                    cout << "This book is already sitting in the library catalog.\n";
                } else {
                    b.returnBook();
                    cout << "Book \"" << b.getTitle() << "\" has been returned successfully.\n";
                }
                return;
            }
        }
        cout << "Book ID not found in system repository.\n";
    }
};

int main() {
    Library systemLibrary;
    int choice = 0;

    cout << "===========================================\n";
    cout << "Welcome to the Library Management System\n";
    cout << "===========================================\n";

    while (choice != 6) {
        cout << "\nMAIN MENU\n";
        cout << "1. Add a New Book\n";
        cout << "2. View All Books\n";
        cout << "3. Search for a Book\n";
        cout << "4. Issue a Book\n";
        cout << "5. Return a Book\n";
        cout << "6. Exit Application\n";
        cout << "Enter your choice (1-6): ";
        
        if (!(cin >> choice)) {
            cout << "Please enter a valid numeric option.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                systemLibrary.addBook();
                break;
            case 2:
                systemLibrary.viewBooks();
                break;
            case 3:
                systemLibrary.searchBook();
                break;
            case 4:
                systemLibrary.issueBook();
                break;
            case 5:
                systemLibrary.returnBook();
                break;
            case 6:
                cout << "\nThank you for using the Library Management System. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice selection! Please choose between 1 and 6.\n";
        }
    }
    return 0;
}