/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:55:24 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/12/03 10:25:00 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe [numbers...]" << std::endl;
        return (1);
    }
    try {
        PmergeMe pmerge(argc, argv);
        pmerge.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}
