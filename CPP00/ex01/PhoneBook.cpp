/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:27:03 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/08/01 14:10:17 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact PhoneBook::getContact(int index)
{
	return (contact[index]);
}

void PhoneBook::contactAdd(int index)
{
	std::string tmp;
	std::cout << "Please enter the first name of the contact." << std::endl;
	std::cin >> tmp;
	if (std::cin.fail())
		return ;
	if (tmp.length() > 0)
		contact[index].setFirstName(tmp);
	else
		return ;
	std::cout << "Please enter his last name." << std::endl;
	std::cin >> tmp;
	if (std::cin.fail())
		return ;
	if (tmp.length() > 0)
		contact[index].setLastName(tmp);
	else
		return ;
	std::cout << "Please enter his nickname." << std::endl;
	std::cin >> tmp;
	if (std::cin.fail())
		return ;
	if (tmp.length() > 0)
		contact[index].setNickname(tmp);
	else
		return ;
	std::cout << "Please enter his phone number" << std::endl;
	std::cin >> tmp;
	if (std::cin.fail())
		return ;
	if (tmp.length() > 0)
		contact[index].setPhoneNumber(tmp);
	else
		return ;
	std::cout << "Please enter his darkest secret." << std::endl;
	std::cin >> tmp;
	if (std::cin.fail())
		return ;
	if (tmp.length() > 0)
		contact[index].setDarkestSecret(tmp);
}

std::string formatCol(std::string s)
{
	int i = 10 - s.length();
	std::string res;
    if (s.length() > 10)
	{
        return s.substr(0, 9) + ".|";
	}
	while (i != 0 && i > 0)
	{
		res += " ";
		i--;
	}
    return (res + s + "|");
}

void PhoneBook::contactSearch(void)
{
	int i;
	int x;
	std::string tmp;
	i = 0;

	std::cout << "      Index| Firstname|  Lastname|  Nickname" << std::endl;
	while (i < 8)
	{
		std::cout << "          " << i + 1 << "|" << formatCol(getContact(i).getFirstName()) << formatCol(getContact(i).getLastName()) << formatCol(getContact(i).getNickname()) << std::endl;
		i++;
	}
	std::cout << "Please enter an index." << std::endl;
	std::cin >> x;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cout << "FAIL." << std::endl;
		return ;
	}
	if (x > 0 && x < 9)
	{
		if (getContact(x - 1).getFirstName().length() != 0)
			std::cout << "Firstname : " << getContact(x - 1).getFirstName() << std::endl;
		if (getContact(x - 1).getLastName().length() != 0)
			std::cout << "Lastname : " << getContact(x - 1).getLastName() << std::endl;
		if (getContact(x - 1).getNickname().length() != 0)
			std::cout << "Nickname : " << getContact(x - 1).getNickname() << std::endl;
		if (getContact(x - 1).getPhoneNumber().length() != 0)
			std::cout << "Phone number : " << getContact(x - 1).getPhoneNumber() << std::endl;
		if (getContact(x - 1).getDarkestSecret().length() != 0)
			std::cout << "Darkest Secret : " << getContact(x - 1).getDarkestSecret() << std::endl;
	}
}