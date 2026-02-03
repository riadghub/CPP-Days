/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:05:01 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/09/04 11:32:07 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(){
	name = "FragTrap";
	std::cout << "FragTrap default constructor called.\n";
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap assignment constructor called\n";
	this->name = name;
	health = 100;
	energy = 100;
	atk = 30;
}

std::string FragTrap::say() const
{
	return ("FragTrap " + this->name);
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called\n";
	this->atk = other.atk;
	this->health = other.health;
	this->energy = other.energy;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called\n";
}

void FragTrap::highFivesGuy()
{
	std::cout << "FragTrap " << this->name << " wants an high five !\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap copy assignment operator called\n";
	if (this != &other)
	{
		this->name = other.name;
		this->health = other.health;
		this->energy = other.energy;
		this->atk = other.atk;
	}
	return (*this);
}
