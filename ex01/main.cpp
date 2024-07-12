#include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    int choice;
    int index(0);

    while (true)
    {
        std::cout << "1. ADD\n2. SEARCH\n3. EXIT\n";
        std::cout << "Enter your choice: "; 
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            phoneBook.Add(index % 8);
            index++;
            break;
        case 2:
            phoneBook.Search();
            break;
        case 3:
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    return 0;
}