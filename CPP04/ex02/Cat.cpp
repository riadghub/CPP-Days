/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:16:00 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/08/26 10:37:26 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called.\n";
	type = "Cat";
	brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat destructor called.\n";
	delete this->brain;
}

Cat::Cat(const Cat &obj)
{
	std::cout << "Cat copy constructor called\n";
	this->type = obj.getType();
	this->brain = new Brain(*obj.brain);
}

void Cat::makeSound() const
{
	std::cout << "Meow !\n";
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment operator called\n";
	if (this != &other)
	{
		this->type = other.type;
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return (*this);
}