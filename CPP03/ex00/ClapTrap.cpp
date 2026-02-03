/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:05:54 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/09/04 11:26:37 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called\n";
}

ClapTrap::ClapTrap(std::string n)
{
	std::cout << "Assignment constructor called\n";
	name = n;
	health = 10;
	energy = 10;
	atk = 0;
}

std::string ClapTrap::say() const
{
	return ("ClapTrap " + this->name);
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called\n";
}

unsigned int ClapTrap::getAtk()
{
	return this->atk;
}

unsigned int ClapTrap::getEnergy()
{
	return this->energy;
}

int ClapTrap::getHealth()
{
	return this->atk;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energy > 0 && this->health > 0)
	{
		std::cout << this->say() << " attacks " << target << ", causing " << atk << " points of damage!\n";
		this->energy--;
	}
	else
		std::cout << "You can't attack with " << this->name << ", no health or energy !\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->health -= amount;
	std::cout << this->say() << " took " << amount << " points of damage ! Remaining health : " << this->health << ".\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy > 0 && this->health > 0)
	{
		this->health += amount;
		this->energy--;
		std::cout << this->say() << " is repairing itself ! Remaining health : " << this->health << ".\n";
	}
	else
		std::cout << "You can't repair " << this->name << " with no health or energy !\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap copy assignment operator called\n";
	if (this != &other)
	{
		this->name = other.name;
		this->health = other.health;
		this->energy = other.energy;
		this->atk = other.atk;
	}
	return (*this);
}
