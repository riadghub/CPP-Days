/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:05:26 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/08/21 11:12:12 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap a("A");
	ClapTrap b("B");
	FragTrap c("C");
	
	a.attack("B");
	b.takeDamage(a.getAtk());
	b.beRepaired(3);
	a.beRepaired(15);
	a.guardGate();
	c.highFivesGuy();
	c.attack("A");
	a.takeDamage(c.getAtk());
	return (0);
}
