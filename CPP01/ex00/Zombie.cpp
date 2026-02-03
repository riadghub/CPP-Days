/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:55:03 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/08/25 12:45:11 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->setName(name);
}

void Zombie::setName(std::string s)
{
	name = s;
}

Zombie::~Zombie()
{
	std::cout << "Destroyed zombie : " << this->getName() << "." << std::endl;
}
	
std::string Zombie::getName(void)
{
	return (name);
}

void Zombie::announce(void)
{
	std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}