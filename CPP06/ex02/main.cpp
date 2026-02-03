/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:38:15 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/10/21 12:50:49 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(NULL));
    std::cout << "=== Testing generate and identify ===" << std::endl;
    std::cout << std::endl;
    std::cout << "Test 1:" << std::endl;
    Base* obj1 = generate();
    std::cout << "Identify with pointer: ";
    identify(obj1);
    std::cout << "Identify with reference: ";
    identify(*obj1);
    std::cout << std::endl;
    std::cout << "Test 2:" << std::endl;
    Base* obj2 = generate();
    std::cout << "Identify with pointer: ";
    identify(obj2);
    std::cout << "Identify with reference: ";
    identify(*obj2);
    std::cout << std::endl;
    std::cout << "Test 3:" << std::endl;
    Base* obj3 = generate();
    std::cout << "Identify with pointer: ";
    identify(obj3);
    std::cout << "Identify with reference: ";
    identify(*obj3);

    delete obj1;
    delete obj2;
    delete obj3;
    
    return 0;
}