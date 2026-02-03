/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:52:01 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/08/01 12:14:01 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Contact.hpp"
#include <iostream>
#include <string>

class PhoneBook
{
  private:
	Contact contact[8];

  public:
	PhoneBook()
	{
	}
	~PhoneBook()
	{
	}
	Contact getContact(int index);
	void contactAdd(int index);
	void contactSearch(void);
};