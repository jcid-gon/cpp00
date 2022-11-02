#include <iostream>

class phonebook
{
	public:
		std::string	first_name[9];
		std::string	last_name[9];
		std::string	nickname[9];
		std::string	phone[9];
		std::string	secret[9];
};


int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while ((s1[index] != '\0' || s2[index] != '\0') && index < n)
	{
		if (s1[index] != s2[index])
			return ((unsigned char) s1[index] - (unsigned char) s2[index]);
		index++;
	}
	return (0);
}

phonebook	add_contact(phonebook contacts, int i)
{
	std::cout << "Insert fist name.\n";
	std::cin >> contacts.first_name[i];
	std::cout << "Insert last name.\n";
	std::cin >> contacts.last_name[i];
	std::cout << "Insert nickname.\n";
	std::cin >> contacts.nickname[i];
	std::cout << "Insert phone number.\n";
	std::cin >> contacts.phone[i];
	std::cout << "Insert darkest secret.\n";
	std::cin >> contacts.secret[i];

	return (contacts);
}

std::string	formatter(std::string str)
{
	int			i;
	std::string	ret;

	i = 0;
	while (i < 10 && str[i] != '\0')
	{
		ret[i] = str[i];
		i++;
	}
	if (str[i] != '\0')
		ret[9] = '.';
	while (i < 9)
	{
		ret[i] = ' ';
		i++;
	}
	return (ret);
}

void	search_contact(phonebook contacts)
{
	int i;

	std::cout << "INDEX     |FIRST NAME|LAST NAME |NICKNAME  \n";
	i = 0;
	while (i < 9)
	{
		std::cout << i << "|" << formatter(contacts.first_name[i]) << "|" << formatter(contacts.last_name[i]) << formatter(contacts.nickname[i]) << "\n";
		i++;
	}
}

int	main()
{
	char		*command;
	phonebook	contacts;
	int	i;

	i = 0;
	while (1)
	{
		std::cout << "Instert command.\n";
		std::cin >> command;
		if (ft_strncmp(command, "EXIT", 4) == 0)
			return (0);
		else if (ft_strncmp(command, "ADD", 3) == 0)
		{
			contacts = add_contact(contacts, i);
			i++;
		}
		else if (ft_strncmp(command, "SEARCH", 6) == 0)
			search_contact(contacts);
		if (i == 9)
			i = 0;
	}
}
