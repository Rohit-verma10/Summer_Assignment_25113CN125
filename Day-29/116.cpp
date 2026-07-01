#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

class Product {
private:
    int id;
    string name;
    int quantity;
    double price;
public:
    Product(int p_id, string p_name, int p_qty, double p_price) 
        : id(p_id), name(p_name), quantity(p_qty), price(p_price) {}
    int getId() const { return id; }
    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }
    void setQuantity(int qty) { quantity = qty; }
    void setPrice(double prc) { price = prc; }
    void displayRow() const {
        cout << "| " << setw(8) << id << " | " << setw(20) << left << name << " | " << right
             << setw(10) << quantity << " | " << setw(10) << fixed << setprecision(2) << price << " |\n";
    }
};

class Inventory {
private:
    vector<Product> items;
public:
    void addProduct();
    void viewInventory() const;
    void searchProduct() const;
    void updateProduct();
    void deleteProduct();
};

void Inventory::addProduct() {
    int id, qty; string name; double price;
    cout << "\n--- Add New Product ---\nEnter ID: "; cin >> id;
    for (const auto& item : items) if (item.getId() == id) { cout << "ID exists!\n"; return; }
    cin.ignore(); cout << "Name: "; getline(cin, name);
    cout << "Quantity: "; cin >> qty; cout << "Price: "; cin >> price;
    items.push_back(Product(id, name, qty, price));
}

void Inventory::viewInventory() const {
    if (items.empty()) { cout << "\nEmpty.\n"; return; }
    cout << "\n-----------------------------------------------------------\n";
    cout << "| ID | Name | Quantity | Price |\n-----------------------------------------------------------\n";
    for (const auto& item : items) item.displayRow();
    cout << "-----------------------------------------------------------\n";
}

void Inventory::searchProduct() const {
    int id; cout << "\nEnter ID to search: "; cin >> id;
    for (const auto& item : items) if (item.getId() == id) { cout << "Found: " << item.getName() << "\n"; return; }
    cout << "Not found.\n";
}

void Inventory::updateProduct() {
    int id; cout << "\nEnter ID to update: "; cin >> id;
    for (auto& item : items) if (item.getId() == id) {
        int qty; cout << "New Quantity: "; cin >> qty; item.setQuantity(qty); return;
    }
    cout << "Not found.\n";
}
void Inventory::deleteProduct() {
    int id; cout << "\nEnter ID to delete: "; cin >> id;
    for (auto it = items.begin(); it != items.end(); ++it) if (it->getId() == id) { items.erase(it); return; }
    cout << "Not found.\n";
}

int main() {
    Inventory inv; int choice;
    do {
        cout << "\n1.Add 2.View 3.Search 4.Update 5.Delete 6.Exit\nChoice: "; cin >> choice;
        switch (choice) {
            case 1: inv.addProduct(); break;
            case 2: inv.viewInventory(); break;
            case 3: inv.searchProduct(); break;
            case 4: inv.updateProduct(); break;
            case 5: inv.deleteProduct(); break;
        }
    } while (choice != 6);
    return 0;
}