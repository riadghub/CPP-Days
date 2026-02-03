/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:16:03 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/08/26 10:37:31 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called.\n";
	type = "Dog";
	brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog destructor called.\n";
	delete this->brain;
}

Dog::Dog(const Dog &obj)
{
	std::cout << "Dog copy constructor called\n";
	this->type = obj.getType();
	this->brain = new Brain(*obj.brain);
}

void Dog::makeSound() const
{
	std::cout << "Woof !\n";
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment operator called\n";
	if (this != &other)
	{
		this->type = other.type;
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return (*this);
}
