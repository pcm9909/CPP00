#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
    std::string FirstName[8];
    std::string LastName[8];
    std::string Nickname[8];
    std::string Number[8];

public:
    void SetFirstName(std::string &rFirstName, int i);
    void SetLastName(std::string &rLastName, int i);
    void SetNickname(std::string &rNickname, int i);
    void SetPhoneNumber(std::string &rNumber, int i);

    std::string GetFirstName(int i);
    std::string GetLastName(int i);
    std::string GetNickname(int i);
    std::string GetPhoneNumber(int i);
};

#endif