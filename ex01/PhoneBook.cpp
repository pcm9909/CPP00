#include "PhoneBook.hpp"

void PhoneBook::Add(int index)
{
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;

    std::cout << "FirstName >> ";
    std::cin >> firstName;
    contact.SetFirstName(firstName, index);

    std::cout << "LastName >> ";
    std::cin >> lastName;
    contact.SetLastName(lastName, index);

    std::cout << "Nickname >> ";
    std::cin >> nickname;
    contact.SetNickname(nickname, index);

    std::cout << "Number >> ";
    std::cin >> phoneNumber;
    contact.SetPhoneNumber(phoneNumber, index);
}

void PhoneBook::PrintSearch(char firstchar, std::string str, char fillchar)
{
    if (str.length() > 10)
    {
        std::cout << firstchar << std::setw(9) << std::right << str.substr(0, 9) << ".";
    }
    else
    {
        std::cout << firstchar << std::setw(10) << std::right << std::setfill(fillchar) << str;
    }
}

void PhoneBook::PrintHeader()
{
    for (int i = 0; i < 4; ++i)
    {
        PrintSearch(' ', "_", '_');
    }
    std::cout << "\n";
    PrintSearch('|', "i", ' ');
    PrintSearch('|', "First", ' ');
    PrintSearch('|', "Last", ' ');
    PrintSearch('|', "Nick", ' ');
    std::cout << "|" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        PrintSearch('|', "_", '_');
    }
    std::cout << "|" << std::endl;
}

void PhoneBook::PrintContacts()
{
    for (int i = 0; i < 8; ++i)
    {
        std::cout << "|" << std::setw(10) << std::right << std::setfill('.') << i;
        PrintSearch('|', contact.GetFirstName(i), '.');
        PrintSearch('|', contact.GetLastName(i), '.');
        PrintSearch('|', contact.GetNickname(i), '.');
        std::cout << "|" << std::endl;
    }
}

void PhoneBook::PrintFooter()
{
    for (int i = 0; i < 4; ++i)
    {
        PrintSearch('|', "_", '_');
    }
    std::cout << "|" << std::endl;
}

void PhoneBook::GetContactByIndex()
{
    int inputVal;
    std::cout << "idx >> ";
    std::cin >> inputVal;
    if (inputVal >= 0 && inputVal <= 7)
    {
        std::cout << "Number is: " << contact.GetPhoneNumber(inputVal) << std::endl;
    }
    else
    {
        std::cout << "Invalid Input val" << std::endl;
    }
}

void PhoneBook::Search()
{
    PrintHeader();
    PrintContacts();
    PrintFooter();
    GetContactByIndex();
}