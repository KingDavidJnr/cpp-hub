#include <iostream>
#include <vector>

struct Contact {
    std::string name;
    std::string phone;
    std::string email;
};

void addContact(std::vector<Contact>& contacts) {
    Contact newContact;
    std::cout << "Enter contact name: ";
    std::cin.ignore();
    std::getline(std::cin, newContact.name);
    std::cout << "Enter contact phone number: ";
    std::getline(std::cin, newContact.phone);
    std::cout << "Enter contact email address: ";
    std::getline(std::cin, newContact.email);
    contacts.push_back(newContact);
    std::cout << "Contact added successfully!\n";
}

void displayContacts(const std::vector<Contact>& contacts) {
    std::cout << "Contacts List:\n";
    for (const auto& contact : contacts) {
        std::cout << "Name: " << contact.name << "\n";
        std::cout << "Phone: " << contact.phone << "\n";
        std::cout << "Email: " << contact.email << "\n\n";
    }
}

int main() {
    std::vector<Contact> contacts;
    int choice;

    while (true) {
        std::cout << "Contact Management System\n";
        std::cout << "1. Add Contact\n";
        std::cout << "2. Display Contacts\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2:
                displayContacts(contacts);
                break;
            case 3:
                std::cout << "Exiting program...\n";
                return 0;
            default:
                std::cout << "Invalid choice! Please try again.\n";
                break;
        }
    }

    return 0;
}
