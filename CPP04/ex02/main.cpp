/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:16:06 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/09/29 10:20:53 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const int size = 10;
    Animal* animals[size];
    // Animal* a = new Animal();
    
    for (int i = 0; i < size / 2; i++)
        animals[i] = new Dog();
    for (int i = size / 2; i < size; i++)
        animals[i] = new Cat();

    std::cout << "\n--- Deleting Animals ---\n" << std::endl;

    for (int i = 0; i < size; i++)
        delete animals[i];

    std::cout << "\n--- Deep Copy Test ---\n" << std::endl;
    // a->makeSound();
    
    Dog dog1;
    Dog dog2 = dog1;

    return 0;
}

