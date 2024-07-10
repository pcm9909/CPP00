#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
	private:
		std::string FirstName[8];
		std::string LastName[8];
		std::string Nickname[8];
		std::string Number[8];

	public:
		void SetFirstName(std::string &rFirstName, int i)
		{
			FirstName[i] = rFirstName;
		}

		void SetLastName(std::string &rLastName, int i)
		{
			LastName[i] = rLastName;
		}

		void SetNickname(std::string &rNickname, int i )
		{
			Nickname[i] = rNickname;
		}

		void SetPhoneNumber(std::string &rNumber, int i)
		{
			Number[i] = rNumber;
		}

		std::string GetFirstName(int i)
		{
			return FirstName[i];
		}
		std::string GetLastName(int i)
		{
			return LastName[i] ;
		}
		std::string GetNickname(int i)
		{
			return Nickname[i];
		}
		std::string GetPhoneNumber(int i)
		{
			if(Number[i][0] == '\0')
				return "Not Exist";
			return Number[i];
		}
};


class PhoneBook
{
	private:
		Contact contact;

	public:
		void ADD(int i)
		{

			std::string firstName;
			std::string lastName;
			std::string nickname;
			std::string phoneNumber;

			std::cout << "FirstName >> ";
			std::cin >> firstName;
			contact.SetFirstName(firstName, i);

			std::cout << "LastName >> ";
			std::cin >> lastName;
			contact.SetLastName(lastName, i);

			std::cout << "Nickname >> ";
			std::cin >> nickname;
			contact.SetNickname(nickname, i);

			std::cout << "Number >> ";
			std::cin >> phoneNumber;
			contact.SetPhoneNumber(phoneNumber, i);
		}

		void PrintSearch(char firstchar, std::string str, char fillchar)
		{
			if(str.length() > 10)
			{
				std::cout << firstchar << std::setw(9) << std::right << str.substr(0,9) << ".";
			}
			else
			{
				std::cout << firstchar << std::setw(10) << std::right << std::setfill(fillchar) << str;
			}
		}

		void SEARCH()
		{
			int i = 0;

			for(i = 0; i < 4; i++)
			{
				PrintSearch(' ',"_",'_');
			}
			std::cout << "\n";
			PrintSearch('|',"i",' ');
			PrintSearch('|',"First",' ');
			PrintSearch('|',"Last",' ');
			PrintSearch('|',"Nick",' ');
			std::cout << "|" << std::endl;
			for(i = 0; i < 4; i++)
			{
				PrintSearch('|',"_",'_');
			}
			std::cout << "|" << std::endl;
			i = 0;
			while(i < 8)
			{
				std::cout << "|" << std::setw(10) << std::right << std::setfill('.') << i;
				PrintSearch('|', contact.GetFirstName(i), '.');
				PrintSearch('|', contact.GetLastName(i), '.');
				PrintSearch('|', contact.GetNickname(i), '.');

				std::cout << "|" << std::endl;
				i++;
			}
			for(i = 0; i < 4; i++)
			{
				PrintSearch('|',"_",'_');
			}
			std::cout << "|" << std::endl;
			int inputval;
			std::cout << "idx >> " ;
			std::cin >> inputval;
			if(inputval >= 0 && inputval <= 7)
			{
				std::cout << "Number is : " << contact.GetPhoneNumber(inputval) << std::endl;
			}
			else
			{
				std::cout << "Invalid Input val" << std::endl;
			}
		}

};


int main()
{
	PhoneBook PhoneBook;
	int command;
	int i = 0;

	while(1)
	{
		std::cout << "Enter Command >> 1.ADD, 2.SEARCH, 3.EXIT" << std::endl;
		std::cin >> command;

		if(command == 1)
		{
			PhoneBook.ADD(i);
			i++;
			if(i == 8)
			{
				i = 0;
			}
		}
		else if(command == 2)
		{
			PhoneBook.SEARCH();
		}
		else if(command == 3)
		{
			std::cout << "Exit PhomeBook" << std::endl;
			break;
		}
		else
		{
			std::cout << "Error input" << std::endl;
		}
		std::cin.clear();
		std::cin.ignore(1000,'\n');
	}
	return 0;
}