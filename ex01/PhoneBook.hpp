#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook
{
private:
    Contact contact;

public:
    void Add(int index);
    void PrintSearch(char firstchar, std::string str, char fillchar);
    void PrintHeader();
    void PrintContacts();
    void PrintFooter();
    void GetContactByIndex();
    void Search();
};

#endif