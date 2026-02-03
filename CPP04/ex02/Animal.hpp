/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:15:59 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/08/27 10:00:12 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cmath>
#include <iostream>
#include <string>

class Animal
{
  protected:
	std::string type;

  public:
	Animal();
	Animal(const Animal &obj);
	virtual ~Animal();
	std::string getType() const;
	virtual void makeSound() const = 0;
	Animal &operator=(const Animal &other);
};