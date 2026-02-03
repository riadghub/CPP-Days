/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:05:12 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/08/05 12:21:20 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB
{
  private:
	std::string name;
	Weapon* weapon;

  public:
    HumanB(std::string n);
	std::string getName(void);
	Weapon* getWeapon(void);

    void attack(void);
	void setWeapon(Weapon& weapon);
	void setName(std::string name);
};