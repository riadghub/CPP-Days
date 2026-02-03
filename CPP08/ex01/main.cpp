/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 09:47:05 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/11/28 10:58:53 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    std::cout << "--- Basic tests ---" << std::endl;
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span = " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span  = " << sp.longestSpan() << std::endl;

    std::cout << "\n--- 10,000 numbers test ---" << std::endl;

    Span big(10000);
    std::vector<int> v;

    for (int i = 0; i < 10000; i++)
        v.push_back(rand());

    big.addRange(v.data(), v.data() + v.size());

    std::cout << "Shortest span = " << big.shortestSpan() << std::endl;
    std::cout << "Longest span  = " << big.longestSpan() << std::endl;

    return 0;
}
