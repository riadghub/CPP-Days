/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:27:29 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/08/01 11:48:40 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName(std::string s)
{
	firstName = s;
}

void Contact::setLastName(std::string s)
{
	lastName = s;
}

void Contact::setNickname(std::string s)
{
	nickname = s;
}

void Contact::setPhoneNumber(std::string s)
{
	phoneNumber = s;
}

void Contact::setDarkestSecret(std::string s)
{
	darkestSecret = s;
}

std::string Contact::getFirstName(void)
{
	return (firstName);
}

std::string Contact::getLastName(void)
{
	return (lastName);
}

std::string Contact::getNickname(void)
{
	return (nickname);
}

std::string Contact::getPhoneNumber(void)
{
	return (phoneNumber);
}

std::string Contact::getDarkestSecret(void)
{
	return (darkestSecret);
}

