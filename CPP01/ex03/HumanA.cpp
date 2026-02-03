/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:04:43 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/08/26 14:03:03 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string n, Weapon& wp) : name(n), weapon(wp)
{
}

void HumanA::setWeapon(Weapon& wp)
{
	weapon = wp;
}

void HumanA::setName(std::string n)
{
	name = n;
}

std::string HumanA::getName(void)
{
	return (name);
}

Weapon& HumanA::getWeapon(void)
{
	return (weapon);
}

void HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}