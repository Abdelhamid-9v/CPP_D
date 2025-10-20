#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook {
private:
    Contact contacts[8];
    int contactCount;
    int nextIndex;
    
    std::string truncateString(const std::string& str) const;
    std::string formatField(const std::string& str) const;
    bool isValidIndex(const std::string& input, int& index) const;

public:
    PhoneBook();
    ~PhoneBook();
    
    void addContact();
    void searchContacts() const;
    void displayContact(int index) const;
    void displayAllContacts() const;
};

#endif