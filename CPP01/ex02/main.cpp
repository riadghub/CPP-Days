/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:19:36 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/08/05 10:55:20 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
    std::string& stringREF = brain;

    std::cout << "\n";
    std::cout << "-----------Memory Addresses-----------" << std::endl;
    std::cout << "\n";
    std::cout << "Memory address of the string variable = " << &brain << std::endl;
    std::cout << "Memory address held by stringPTR      = " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF      = " << &stringREF << std::endl;
    std::cout << "\n";
    std::cout << "----------------Values----------------" << std::endl;
    std::cout << "\n";
    std::cout << "Value of the string variable          = " << brain << std::endl;
    std::cout << "Value pointed to by stringPTR         = " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF         = " << stringREF << std::endl;
}