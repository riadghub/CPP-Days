/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:05:16 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/08/26 14:03:08 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
  private:
	std::string name;
	Weapon& weapon;

  public:
	HumanA(const std::string name, Weapon& weapon);
	std::string getName(void);
	Weapon& getWeapon(void);

	void attack(void);
	void setWeapon(Weapon& weapon);
	void setName(std::string name);
};