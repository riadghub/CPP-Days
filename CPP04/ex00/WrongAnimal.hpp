/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:54:07 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/09/29 09:57:35 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class WrongAnimal
{
  protected:
	std::string type;

  public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &obj);
	virtual ~WrongAnimal();
	std::string getType() const;
	virtual void makeSound() const;
	WrongAnimal &operator=(const WrongAnimal &other);
};