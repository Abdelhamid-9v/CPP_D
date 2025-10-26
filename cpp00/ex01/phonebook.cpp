#include "phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook() : contactCount(0), nextIndex(0) {
}

PhoneBook::~PhoneBook() {
}

bool PhoneBook::isPrintable(const std::string& str) const {
    for (size_t i = 0; i < str.length(); i++) {
        if (!std::isprint(str[i]))
            return false;
    }
    return true;
}

std::string PhoneBook::truncateString(const std::string& str) const {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}

std::string PhoneBook::formatField(const std::string& str) const {
    std::string truncated = truncateString(str);
    return truncated;
}

bool PhoneBook::isValidIndex(const std::string& input, int& index) const {
    if (input.empty()) {
        return false;
    }
    
    std::stringstream ss(input);
    if (!(ss >> index) || !ss.eof()) {
        return false;
    }
    
    return index >= 0 && index < contactCount;
}

void PhoneBook::addContact() {
    Contact newContact;
    std::string input;
    
    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    if (input.empty()) {
        std::cout << "Error: First name cannot be empty." << std::endl;
        return;
    }
    if (!isPrintable(input)) {
        std::cout << "Error: First name must contain only printable characters." << std::endl;
        return;
    }
    newContact.setFirstName(input);
    
    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    if (input.empty()) {
        std::cout << "Error: Last name cannot be empty." << std::endl;
        return;
    }
    if (!isPrintable(input)) {
        std::cout << "Error: Last name must contain only printable characters." << std::endl;
        return;
    }
    newContact.setLastName(input);
    
    std::cout << "Enter nickname: ";
    std::getline(std::cin, input);
    if (input.empty()) {
        std::cout << "Error: Nickname cannot be empty." << std::endl;
        return;
    }
    if (!isPrintable(input)) {
        std::cout << "Error: Nickname must contain only printable characters." << std::endl;
        return;
    }
    newContact.setNickname(input);
    
    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    if (input.empty()) {
        std::cout << "Error: Phone number cannot be empty." << std::endl;
        return;
    }
    if (!isPrintable(input)) {
        std::cout << "Error: Phone number must contain only printable characters." << std::endl;
        return;
    }
    newContact.setPhoneNumber(input);
    
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    if (input.empty()) {
        std::cout << "Error: Darkest secret cannot be empty." << std::endl;
        return;
    }
    if (!isPrintable(input)) {
        std::cout << "Error: Darkest secret must contain only printable characters." << std::endl;
        return;
    }
    newContact.setDarkestSecret(input);
    
    contacts[nextIndex] = newContact;
    nextIndex = (nextIndex + 1) % 8;
    if (contactCount < 8) {
        contactCount++;
    }
    
    std::cout << "Contact added successfully!" << std::endl;
}


void PhoneBook::displayAllContacts() const {
    if (contactCount == 0) {
        std::cout << "No contacts in phonebook." << std::endl;
        return;
    }
    
    std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|" << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << std::endl;
    
    for (int i = 0; i < contactCount; i++){
        std::cout << std::setw(10) << i << "|"<< std::setw(10) << formatField(contacts[i].getFirstName()) << "|"<< std::setw(10) << formatField(contacts[i].getLastName()) << "|"<< std::setw(10) << formatField(contacts[i].getNickname()) << std::endl;
    }
}

void PhoneBook::displayContact(int index) const {
    if (index >= 0 && index < contactCount) {
        std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
        std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
        std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
        std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
    }
}

void PhoneBook::searchContacts() const {
    if (contactCount == 0) {
        std::cout << "No contacts in phonebook." << std::endl;
        return;
    }
    
    displayAllContacts();
    
    std::cout << "Enter the index of the contact to display: ";
    std::string input;
    std::getline(std::cin, input);
    
    int index;
    if (!isValidIndex(input, index)) {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    
    displayContact(index);
}