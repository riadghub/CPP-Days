/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:05:26 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/08/25 13:05:03 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::cout << "=== Zombie on the stack ===" << std::endl;
    randomChump("StackZombie");

    std::cout << std::endl;

    std::cout << "=== Zombie on the heap ===" << std::endl;
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;

    std::cout << std::endl;

    std::cout << "=== Multiple zombies ===" << std::endl;
    Zombie* z1 = newZombie("Zombie1");
    Zombie* z2 = newZombie("Zombie2");
    z1->announce();
    z2->announce();

    delete z1;
    delete z2;

    return 0;
}
