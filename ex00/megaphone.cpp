/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcid-gon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:36:33 by jcid-gon          #+#    #+#             */
/*   Updated: 2022/11/08 13:17:53 by jcid-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	size_str (char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char*	to_upper(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

int	main (int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc <= 1)
		std::cout << "* LOUD AND UNBEREABLE FEEDBACK NOISE *\n";
	else
	{
		while (argv[i] != NULL)
		{
			std::cout << to_upper(argv[i]);
			if (argv[i][size_str(argv[i] - 1)] != ' ' && (argv[i + 1] != NULL && argv[i + 1][0] != ' '))
					std::cout << " ";
			i++;
		}
		std::cout << "\n";
	}
	return 0;
}
