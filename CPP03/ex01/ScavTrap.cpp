/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:41:47 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/09/04 11:29:28 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
	name = "ScavTrap";
	std::cout << "ScavTrap default constructor called.\n";
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap assignment constructor called\n";
	this->name = name;
	health = 100;
	energy = 50;
	atk = 20;
}

std::string ScavTrap::say() const
{
	return ("ScavTrap " + this->name);
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called\n";
	this->atk = other.atk;
	this->health = other.health;
	this->energy = other.energy;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called\n";
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is now in Gate Keeper mode.\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap copy assignment operator called\n";
	if (this != &other)
	{
		this->name = other.name;
		this->health = other.health;
		this->energy = other.energy;
		this->atk = other.atk;
	}
	return (*this);
}
