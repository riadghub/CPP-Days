/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:16:06 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/09/29 10:06:51 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	const WrongAnimal* zero = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();
	
	std::cout << meta->getType() << " : ";
	meta->makeSound();

	std::cout << j->getType() << " : ";
	j->makeSound();

	std::cout << i->getType() << " : ";
	i->makeSound();

	std::cout << zero->getType() << " : ";
	zero->makeSound();

	std::cout << k->getType() << " : ";
	k->makeSound();

	delete meta;
	delete j;
	delete i;
	
	delete zero;
	delete k;
	
	return (0);
}
