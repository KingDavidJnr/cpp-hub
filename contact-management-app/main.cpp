#include <iostream>
#include <vector>
#include <string>

class Contact {
private:
    std::string name;
    std::string phone;

public:
    Contact(const std::string& name, const std::string& phone)
        : name(name), phone(phone) {}

    std::string getName() const {
        return name;
    }

    std::string getPhone() const {
        return phone;
    }
};

// Function to add a new contact to the contacts vector
void addContact(std::vector<Contact>& contacts, const std::string& name, const std::string& phone) {
    Contact contact(name, phone);
    contacts.push_back(contact);
}

// Function to display all the contacts in the contacts vector
void displayContacts(const std::vector<Contact>& contacts) {
    std::cout << "Contacts:\n";
    for (const auto& contact : contacts) {
        std::cout << "Name: " << contact.getName() << ", Phone: " << contact.getPhone() << "\n";
    }
}

int main() {
    std::vector<Contact> contacts; // Vector to store the contacts

    while (true) {
        std::cout << "Menu:\n";
        std::cout << "1. Add contact\n";
        std::cout << "2. Display contacts\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name, phone;
                std::cout << "Enter name: ";
                std::cin >> name;
                std::cout << "Enter phone number: ";
                std::cin >> phone;
                addContact(contacts, name, phone); // Call the addContact function to add the contact
                break;
            }
            case 2:
                displayContacts(contacts); // Call the displayContacts function to display all the contacts
                break;
            case 3:
                std::cout << "Exiting program...\n";
                return 0; // Terminate the program
            default:
                std::cout << "Invalid choice! Please try again.\n";
                break;
        }
    }

    return 0;
}
