/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:33:36 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/11/24 09:45:42 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "easyfind.hpp"

int main()
{
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    try {
        std::cout << "Searching 20: ";
        std::vector<int>::const_iterator it = easyfind(v, 20);
        std::cout << "Found at = " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "Searching 42: ";
        easyfind(v, 42);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);

    try {
        std::cout << "Searching in list for 15: ";
        std::list<int>::const_iterator it = easyfind(lst, 15);
        std::cout << "Found = " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
