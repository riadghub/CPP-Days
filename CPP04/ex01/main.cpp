/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:16:06 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/08/26 11:51:19 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const int size = 10;
    Animal* animals[size];

    for (int i = 0; i < size / 2; i++)
        animals[i] = new Dog();
    for (int i = size / 2; i < size; i++)
        animals[i] = new Cat();

    std::cout << "\n--- Deleting Animals ---\n" << std::endl;

    for (int i = 0; i < size; i++)
        delete animals[i];

    std::cout << "\n--- Deep Copy Test ---\n" << std::endl;

    Dog dog1;
	dog1.getBrain()->setIdea(0, "I want a bone!");

	Dog dog2 = dog1;
	dog2.getBrain()->setIdea(0, "I want to play!");

	std::cout << "Dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;

    return 0;
}

