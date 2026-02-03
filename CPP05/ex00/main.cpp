/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:21:47 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/10/03 12:03:14 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
    	std::cout << "\n=== " << "Constructions valides" << " ===\n";
        Bureaucrat a(42, "Riad");
        Bureaucrat b(1,  "Sarah");
        Bureaucrat c(150,"Romain");

        std::cout << a << '\n';
        std::cout << b << '\n';
        std::cout << c << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << '\n';
    }
	
    std::cout << "\n=== " << "Constructions invalides" << " ===\n";
	
    try {
        Bureaucrat badHigh(0, "Zero");
        std::cout << badHigh << '\n';
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Attendu High: " << e.what() << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Autre: " << e.what() << '\n';
    }
    try {
        Bureaucrat badLow(151, "TooLow");
        std::cout << badLow << '\n';
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Attendu Low: " << e.what() << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Autre: " << e.what() << '\n';
    }
	
    std::cout << "\n=== " << "Increment aux limites" << " ===\n";

    try {
        Bureaucrat top(2, "NearTop");
        std::cout << top << '\n';
        top.incrementGrade();
        std::cout << top << '\n';
        top.incrementGrade();
        std::cout << top << '\n';
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Attendu High: " << e.what() << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Autre: " << e.what() << '\n';
    }
	
    std::cout << "\n=== " << "Decrement aux limites" << " ===\n";
	
    try {
        Bureaucrat low(149, "NearBottom");
        std::cout << low << '\n';
        low.decrementGrade();
        std::cout << low << '\n';
        low.decrementGrade();
        std::cout << low << '\n';
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Attendu Low: " << e.what() << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Autre: " << e.what() << '\n';
    }
	
    std::cout << "\n=== " << "Copie et affectation" << " ===\n";
	
    try {
        Bureaucrat src(50, "Source");
        Bureaucrat copy(src);
        std::cout << "copy: " << copy << '\n';
        Bureaucrat dst(100, "Dest");
        std::cout << "avant assign: " << dst << '\n';
        dst = src;
        std::cout << "apres assign: " << dst << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << '\n';
    }
    return 0;
}