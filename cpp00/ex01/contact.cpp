#include "Contact.hpp"

Contact::Contact(){
}

Contact::~Contact(){
}

void Contact::setFirstName(const std::string& firstn){
    firstName = firstn;
}

void Contact::setLastName(const std::string& lastn){
    lastName = lastn;
}

void Contact::setNickname(const std::string& nickn){
    nickname = nickn;
}
void Contact::setPhoneNumber(const std::string& phoneNb){
    phoneNumber = phoneNb;
}

void Contact::setDarkestSecret(const std::string& darkestS){
    darkestSecret = darkestS;
}

std::string Contact::getFirstName() const{
    return firstName;
}

std::string Contact::getLastName() const{
    return lastName;
}

std::string Contact::getNickname() const{
    return nickname;
}

std::string Contact::getPhoneNumber() const{
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const{
    return darkestSecret;
}
// empty return true if len == 0
bool Contact::isEmpty() const{
    return firstName.empty() && lastName.empty() && nickname.empty() 
           && phoneNumber.empty() && darkestSecret.empty();
}