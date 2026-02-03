/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:15:56 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/09/29 09:44:34 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called.\n";
	type = "Animal";
}

Animal::~Animal()
{
	std::cout << "Animal destructor called.\n";
}

Animal::Animal(const Animal &obj)
{
	std::cout << "Animal copy constructor called\n";
	this->type = obj.getType();
}

std::string Animal::getType() const
{
	return (type);
}

void Animal::makeSound() const
{
	std::cout << "This animal doesn't make any sound.\n";
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal copy assignment operator called\n";
	if (this != &other)
		this->type = other.type;
	return (*this);
}
