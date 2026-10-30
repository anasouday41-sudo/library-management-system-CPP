#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 1. Base Class (Demonstrates Encapsulation and Inheritance)
class LibraryItem {
protected:
    string title;
    string id;
    bool isAvailable;

public:
    // Constructor
    LibraryItem(string t, string i) {
        title = t;
        id = i;
        isAvailable = true;
    }

    // Virtual Destructor for Polymorphism
    virtual ~LibraryItem() {}

    // Encapsulation: Getter and Setter methods
    string getTitle() const { return title; }
    string getId() const { return id; }
    bool getAvailability() const { return isAvailable; }

    void setAvailability(bool status) {
        isAvailable = status;
    }

    // Pure Virtual Function (Polymorphism)
    virtual void displayInfo() const = 0;

    // Function Overloading: Check-out with default or custom days
    void checkOut() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Item '" << title << "' checked out successfully.\n";
        } else {
            cout << "Sorry, '" << title << "' is already checked out.\n";
        }
    }
// Overloaded checkOut function (Function Overloading concept)
    void checkOut(int customDays) {
        if (isAvailable) {
            isAvailable = false;
            cout << "Item '" << title << "' checked out for " << customDays << " days.\n";
        } else {
            cout << "Sorry, '" << title << "' is already checked out.\n";
        }
    }

    void returnItem() {
        isAvailable = true;
        cout << "Item '" << title << "' returned successfully.\n";
    }
};

// 2. Derived Class 1: Book
class Book : public LibraryItem {
private:
    string author;
    int pageCount;

public:
    Book(string t, string i, string a, int pages) : LibraryItem(t, i) {
        author = a;
        pageCount = pages;
    }

    // Polymorphism: Overriding displayInfo
    void displayInfo() const override {
        cout << "[Book] ID: " << id << " | Title: " << title 
             << " | Author: " << author << " | Pages: " << pageCount 
             << " | Status: " << (isAvailable ? "Available" : "Checked Out") << "\n";
    }
};

// 3. Derived Class 2: Magazine
class Magazine : public LibraryItem {
private:
    int issueNumber;

public:
    Magazine(string t, string i, int issue) : LibraryItem(t, i) {
        issueNumber = issue;
    }

    // Polymorphism: Overriding displayInfo
    void displayInfo() const override {
        cout << "[Magazine] ID: " << id << " | Title: " << title 
             << " | Issue #: " << issueNumber 
             << " | Status: " << (isAvailable ? "Available" : "Checked Out") << "\n";
    }
};
// Main Program
int main() {
    // Creating objects using Polymorphism (Base class pointers)
    vector<LibraryItem*> library;

    library.push_back(new Book("C++ Programming", "B001", "Bjarne Stroustrup", 800));
    library.push_back(new Book("Data Structures", "B002", "Mark Allen", 500));
    library.push_back(new Magazine("Tech Weekly", "M001", 45));

    cout << "=== Initial Library Inventory ===" << endl;
    for (const auto& item : library) {
        item->displayInfo(); // Dynamic Polymorphism in action
    }

    cout << "\n=== Testing Check-out & Function Overloading ===" << endl;
    library[0]->checkOut();         // Normal check-out
    library[1]->checkOut(14);       // Overloaded check-out with custom days

    cout << "\n=== Updated Library Inventory ===" << endl;
    for (const auto& item : library) {
        item->displayInfo();
    }

    // Clean up dynamic memory (Destructors will be called)
    for (auto& item : library) {
        delete item;
    }

    return 0;
}
