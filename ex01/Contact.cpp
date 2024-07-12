#include "Contact.hpp"

void Contact::SetFirstName(std::string &rFirstName, int i)
{
    FirstName[i] = rFirstName;
}

void Contact::SetLastName(std::string &rLastName, int i)
{
    LastName[i] = rLastName;
}

void Contact::SetNickname(std::string &rNickname, int i)
{
    Nickname[i] = rNickname;
}

void Contact::SetPhoneNumber(std::string &rNumber, int i)
{
    Number[i] = rNumber;
}

std::string Contact::GetFirstName(int i)
{
    return FirstName[i];
}

std::string Contact::GetLastName(int i)
{
    return LastName[i];
}

std::string Contact::GetNickname(int i)
{
    return Nickname[i];
}

std::string Contact::GetPhoneNumber(int i)
{
    if (Number[i][0] == '\0')
        return "Not Exist";
    return Number[i];
}