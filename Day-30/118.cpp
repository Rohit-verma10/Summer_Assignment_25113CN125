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
    bool getIssueStatus() const { return isIssued; }

    void issueBook() { isIssued = true; }
    void returnBook() { isIssued = false; }

    void displayBook() const {
        cout << left << setw(10) << id 
             << setw(30) << title 
             << setw(25) << author 
             << (isIssued ? "Issued" : "Available") << "\n";
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
            cout << "Invalid Input! Please enter a valid numeric ID: ";
            cin.clear();
            cin.ignore(123, '\n');
        }
        cin.ignore(); 
        for (const auto& book : books) {
            if (book.getId() == id) {
                cout << "Error: A book with ID " << id << " already exists!\n";
                return;
            }
        }

        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Book Author: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));
        cout << "Book successfully added to the catalog!\n";
    }

    void viewAllBooks() const {
        if (books.empty()) {
            cout << "\nThe library catalog is currently empty.\n";
            return;
        }

        cout << "\n----------------------------------------------------------------------\n";
        cout << left << setw(10) << "ID" << setw(30) << "Title" << setw(25) << "Author" << "Status\n";
        cout << "----------------------------------------------------------------------\n";
        for (const auto& book : books) {
            book.displayBook();
        }
        cout << "----------------------------------------------------------------------\n";
    }

    void searchBook() const {
        if (books.empty()) {
            cout << "\nNo books available to search.\n";
            return;
        }

        int id;
        cout << "\nEnter Book ID to search: ";
        cin >> id;

        for (const auto& book : books) {
            if (book.getId() == id) {
                cout << "\nBook Found:\n";
                cout << "Title: " << book.getTitle() << "\nAuthor: " << book.getAuthor() 
                     << "\nStatus: " << (book.getIssueStatus() ? "Issued" : "Available") << "\n";
                return;
            }
        }
        cout << "Book with ID " << id << " not found.\n";
    }

    void issueBook() {
        int id;
        cout << "\nEnter Book ID to issue: ";
        cin >> id;

        for (auto& book : books) {
            if (book.getId() == id) {
                if (book.getIssueStatus()) {
                    cout << "Sorry, this book is already issued to someone else.\n";
                } else {
                    book.issueBook();
                    cout << "Book successfully issued!\n";
                }
                return;
            }
        }
        cout << "Book with ID " << id << " not found.\n";
    }

    void returnBook() {
        int id;
        cout << "\nEnter Book ID to return: ";
        cin >> id;

        for (auto& book : books) {
            if (book.getId() == id) {
                if (!book.getIssueStatus()) {
                    cout << "This book is already marked as available in the library.\n";
                } else {
                    book.returnBook();
                    cout << "Book successfully returned to the library!\n";
                }
                return;
            }
        }
        cout << "Book with ID " << id << " not found.\n";
    }
};

int main() {
    Library myLibrary;
    int choice;

    while (true) {
        cout << "\n===== MINI LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add New Book\n";
        cout << "2. View All Books\n";
        cout << "3. Search Book by ID\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit Application\n";
        cout << "==========================================\n";
        cout << "Enter your choice (1-6): ";
        
        if (!(cin >> choice)) {
            cout << "Please enter a valid numeric choice.\n";
            cin.clear();
            cin.ignore(123, '\n');
            continue;
        }

        switch (choice) {
            case 1: myLibrary.addBook(); break;
            case 2: myLibrary.viewAllBooks(); break;
            case 3: myLibrary.searchBook(); break;
            case 4: myLibrary.issueBook(); break;
            case 5: myLibrary.returnBook(); break;
            case 6: cout << "\nThank you for using the Library System. Goodbye!\n"; return 0;
            default: cout << "Invalid option chosen. Try again.\n";
        }
    }
    return 0;
}