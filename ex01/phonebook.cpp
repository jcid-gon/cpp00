#include "necronomicon.hpp"

void	Phonebook::add_contact(int index)
{
	std::cout << "Insert first name.\n";
	std::cin.ignore(1000, '\n');
	std::getline(std::cin, first_name[index]);
	std::cout << "Insert last name.\n";
	std::getline(std::cin, last_name[index]);
	std::cout << "Insert nickname.\n";
	std::getline(std::cin, nickname[index]);
	std::cout << "Insert phone number.\n";
	std::getline(std::cin, phone[index]);
	std::cout << "Insert darkest secret.\n";
	std::getline(std::cin, secret[index]);
}

void	Phonebook::search()
{
	int	index;

	std::cout << "INDEX     |FIRST NAME|LAST NAME |NICKNAME  \n";
	for (int i = 0; i < 9; i++)
		std::cout << i + 1 << "         |" << formatter(first_name[i]) << "|" << formatter(last_name[i]) << "|" << formatter(nickname[i]) << "\n";
	std::cout << "Enter contact index.\n";
	std::cin >> index;
	index--;
	if (index < 9 && index >= 0)
		std::cout << first_name[index] << "\n" << last_name[index] << "\n" << nickname[index] << "\n" << phone[index] << "\n" << secret[index] << "\n";
	else
		std::cout << "Wrong index\n";
}
