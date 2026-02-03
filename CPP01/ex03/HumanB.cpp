/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:04:41 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/08/05 12:22:22 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string n)
{
	setName(n);
    weapon = NULL;
}

void HumanB::setWeapon(Weapon& wp)
{
	weapon = &wp;
}

void HumanB::setName(std::string n)
{
	name = n;
}

std::string HumanB::getName(void)
{
	return (name);
}

Weapon* HumanB::getWeapon(void)
{
	return (weapon);
}

void HumanB::attack(void)
{
    if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " has no weapon" << std::endl;
}