/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:57:14 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/08/01 13:56:48 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	Contact oho;
	PhoneBook ehe;
	std::string tmp;
	int i = 0;
	while (1)
	{
		if (i == 8)
			i = 0;
		std::cin >> tmp;
		if (std::cin.fail())
			return (0);
		if (tmp.compare("ADD") == 0)
		{
			ehe.contactAdd(i);
			i++;
		}
		else if (tmp.compare("SEARCH") == 0)
			ehe.contactSearch();
		else if (tmp.compare("EXIT") == 0)
			return (0);
	}
	return (0);
}