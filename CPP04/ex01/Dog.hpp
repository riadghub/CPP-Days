/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:16:04 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/08/26 11:50:47 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
  private:
	Brain* brain;
  public:
	Dog();
	Dog(const Dog &obj);
	~Dog();
	void makeSound() const;
	Dog &operator=(const Dog &other);

	Brain* getBrain() const; 
};