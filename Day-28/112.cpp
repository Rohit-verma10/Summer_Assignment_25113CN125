#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
class Contact {
private:
    std::string name;
    std::string phone;
    std::string email;

public:
    Contact(std::string n, std::string p, std::string e) : name(n), phone(p), email(e) {}

   
    std::string getName() const { return name; }
    std::string getPhone() const { return phone; }
    std::string getEmail() const { return email; }

    void setName(const std::string& n) { name = n; }
    void setPhone(const std::string& p) { phone = p; }
    void setEmail(const std::string& e) { email = e; }

    std::string toFileFormat() const {
        return name + "," + phone + "," + email;
    }
};

class ContactManager {
private:
    std::vector<Contact> contacts;
    const std::string filename = "contacts.txt";

    void saveToFile() {
        std::ofstream outFile(filename);
        if (!outFile) {
            std::cerr << "Error writing to storage file.\n";
            return;
        }
        for (const auto& contact : contacts) {
            outFile << contact.toFileFormat() << "\n";
        }
        outFile.close();
    }

    std::string trim(const std::string& str) {
        size_t first = str.find_first_not_of(" \t");
        if (first == std::string::npos) return "";
        size_t last = str.find_last_not_of(" \t");
        return str.substr(first, (last - first + 1));
    }

public:

    ContactManager() {
        loadFromFile();
    }

    void loadFromFile() {
        contacts.clear();
        std::ifstream inFile(filename);
        if (!inFile) return;

        std::string line;
        while (std::getline(inFile, line)) {
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);
            if (pos1 != std::string::npos && pos2 != std::string::npos) {
                std::string name = line.substr(0, pos1);
                std::string phone = line.substr(pos1 + 1, pos2 - (pos1 + 1));
                std::string email = line.substr(pos2 + 1);
                contacts.emplace_back(name, phone, email);
            }
        }
        inFile.close();
    }

    void addContact() {
        std::string name, phone, email;
        std::cin.ignore();
        
        std::cout << "Enter Name: ";
        std::getline(std::cin, name);
        name = trim(name);

        std::cout << "Enter Phone Number: ";
        std::getline(std::cin, phone);
        phone = trim(phone);

        std::cout << "Enter Email Address: ";
        std::getline(std::cin, email);
        email = trim(email);

        if (name.empty() || phone.empty()) {
            std::cout << "\nError: Name and Phone Number are required fields!\n";
            return;
        }

        contacts.emplace_back(name, phone, email);
        saveToFile();
        std::cout << "\nContact added successfully!\n";
    }

    void displayAllContacts() const {
        if (contacts.empty()) {
            std::cout << "\nYour contact book is currently empty.\n";
            return;
        }

        std::cout << "\n" << std::string(65, '-') << "\n";
        std::cout << std::left << std::setw(5) << "ID" 
                  << std::setw(25) << "Name" 
                  << std::setw(15) << "Phone" 
                  << std::setw(20) << "Email" << "\n";
        std::cout << std::string(65, '-') << "\n";

        for (size_t i = 0; i < contacts.size(); ++i) {
            std::cout << std::left << std::setw(5) << (i + 1)
                      << std::setw(25) << contacts[i].getName()
                      << std::setw(15) << contacts[i].getPhone()
                      << std::setw(20) << contacts[i].getEmail() << "\n";
        }
        std::cout << std::string(65, '-') << "\n";
    }
    void searchContact() const {
        if (contacts.empty()) {
            std::cout << "\nNo records available to search.\n";
            return;
        }

        std::string query;
        std::cin.ignore();
        std::cout << "Enter Name to search: ";
        std::getline(std::cin, query);

        std::string lowerQuery = query;
        std::transform(lowerQuery.begin(), lowerQuery.end(), lowerQuery.begin(), ::tolower);

        bool found = false;
        for (const auto& contact : contacts) {
            std::string lowerName = contact.getName();
            std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

            if (lowerName.find(lowerQuery) != std::string::npos) {
                if (!found) {
                    std::cout << "\nMatching Search Results:\n";
                    std::cout << std::string(60, '-') << "\n";
                }
                std::cout << "Name:  " << contact.getName() << "\n"
                          << "Phone: " << contact.getPhone() << "\n"
                          << "Email: " << contact.getEmail() << "\n"
                          << std::string(60, '-') << "\n";
                found = true;
            }
        }
        if (!found) {
            std::cout << "\nNo contacts matching '" << query << "' were found.\n";
        }
    }

    void editContact() {
        displayAllContacts();
        if (contacts.empty()) return;

        int id;
        std::cout << "Enter the ID of the contact you want to edit: ";
        std::cin >> id;

        if (id < 1 || id > static_cast<int>(contacts.size())) {
            std::cout << "\nInvalid Contact ID selected!\n";
            return;
        }

        size_t index = static_cast<size_t>(id - 1);
        std::cin.ignore();

        std::string nextInput;
        std::cout << "Enter New Name (Leave blank to keep '" << contacts[index].getName() << "'): ";
        std::getline(std::cin, nextInput);
        if (!trim(nextInput).empty()) contacts[index].setName(trim(nextInput));

        std::cout << "Enter New Phone (Leave blank to keep '" << contacts[index].getPhone() << "'): ";
        std::getline(std::cin, nextInput);
        if (!trim(nextInput).empty()) contacts[index].setPhone(trim(nextInput));

        std::cout << "Enter New Email (Leave blank to keep '" << contacts[index].getEmail() << "'): ";
        std::getline(std::cin, nextInput);
        if (!trim(nextInput).empty()) contacts[index].setEmail(trim(nextInput));

        saveToFile();
        std::cout << "\nContact updated successfully!\n";
    }

    void deleteContact() {
        displayAllContacts();
        if (contacts.empty()) return;

        int id;
        std::cout << "Enter the ID of the contact you want to delete: ";
        std::cin >> id;

        if (id < 1 || id > static_cast<int>(contacts.size())) {
            std::cout << "\nInvalid Contact ID selected!\n";
            return;
        }

        contacts.erase(contacts.begin() + (id - 1));
        saveToFile();
        std::cout << "\nContact erased successfully!\n";
    }
};

int main() {
    ContactManager manager;
    int choice = 0;

    do {
        std::cout << "\n=================================\n";
        std::cout << "    CONTACT MANAGEMENT SYSTEM    \n";
        std::cout << "=================================\n";
        std::cout << "1. Add New Contact\n";
        std::cout << "2. Display All Contacts\n";
        std::cout << "3. Search Contact By Name\n";
        std::cout << "4. Edit an Existing Contact\n";
        std::cout << "5. Delete a Contact\n";
        std::cout << "6. Exit Application\n";
        std::cout << "=================================\n";
        std::cout << "Enter your selection (1-6): ";
        
        if (!(std::cin >> choice)) {
            std::cout << "\nInvalid entry. Please use numerical inputs only.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1: manager.addContact(); break;
            case 2: manager.displayAllContacts(); break;
            case 3: manager.searchContact(); break;
            case 4: manager.editContact(); break;
            case 5: manager.deleteContact(); break;
            case 6: std::cout << "\nClosing the application. Goodbye!\n"; break;
            default: std::cout << "\nChoice out of bounds. Select options 1 to 6.\n";
        }
    } while (choice != 6);

    return 0;
}