#include "necronomicon.hpp"

int	ft_strncmp(const std::string s1, const std::string s2, size_t n)
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

std::string	formatter(std::string str)
{
	std::string	ret;
	
	if (str.length() > 10)
	{
		ret = str.substr(0, 9);
		ret.push_back('.');
	}
	else
	{
		ret = str;
		while (ret.length() != 10)
			ret.push_back(' ');
	}
	return (ret);
}

int	main()
{
	std::string		command;
	Phonebook		contacts;
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
			contacts.add_contact(i);
			i++;
		}
		else if (ft_strncmp(command, "SEARCH", 6) == 0)
			contacts.search();
		if (i == 9)
			i = 0;
	}
}
