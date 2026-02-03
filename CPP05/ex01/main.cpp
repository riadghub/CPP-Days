/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:21:47 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/10/07 10:22:26 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "\n========== VALID BUREAUCRAT CONSTRUCTION ==========\n";
    try {
        Bureaucrat alice(1, "Alice");
        Bureaucrat bob(50, "Bob");
        Bureaucrat charlie(150, "Charlie");
        std::cout << alice << '\n';
        std::cout << bob << '\n';
        std::cout << charlie << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << '\n';
    }
    std::cout << "\n========== VALID FORM CONSTRUCTION ==========\n";
    try {
        Form formA("Tax Form A1", 50, 25);
        Form formB("Budget Approval", 10, 5);
        Form formC("Coffee Request", 150, 150);

        std::cout << formA << '\n';
        std::cout << formB << '\n';
        std::cout << formC << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << '\n';
    }
    std::cout << "\n========== INVALID FORM CONSTRUCTION (Grade too high) ==========\n";
    try {
        Form invalidForm1("Invalid High", 0, 25);
        std::cout << invalidForm1 << '\n';
    } catch (const Form::GradeTooHighException& e) {
        std::cerr << "Expected exception caught: " << e.what() << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Other exception: " << e.what() << '\n';
    }
    std::cout << "\n========== INVALID FORM CONSTRUCTION (Grade too low) ==========\n";
    try {
        Form invalidForm2("Invalid Low", 151, 25);
        std::cout << invalidForm2 << '\n';
    } catch (const Form::GradeTooLowException& e) {
        std::cerr << "Expected exception caught: " << e.what() << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Other exception: " << e.what() << '\n';
    }
    std::cout << "\n========== SUCCESSFUL FORM SIGNING ==========\n";
    try {
        Bureaucrat highRank(5, "Director");
        Form importantForm("Contract X42", 10, 5);
        std::cout << "Before signing: " << importantForm << '\n';
        std::cout << highRank << '\n';
        highRank.signForm(importantForm);
        std::cout << "After signing: " << importantForm << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << '\n';
    }
    std::cout << "\n========== FAILED FORM SIGNING (Grade too low) ==========\n";
    try {
        Bureaucrat lowRank(100, "Intern");
        Form restrictedForm("Top Secret Document", 20, 10);
        std::cout << "Before signing attempt: " << restrictedForm << '\n';
        std::cout << lowRank << '\n';
        lowRank.signForm(restrictedForm);
        std::cout << "After signing attempt: " << restrictedForm << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << '\n';
    }
    std::cout << "\n========== EDGE CASE: Grade 1 Bureaucrat ==========\n";
    try {
        Bureaucrat ceo(1, "CEO");
        Form anyForm("Any Document", 1, 1);
        std::cout << ceo << '\n';
        std::cout << anyForm << '\n';
        ceo.signForm(anyForm);
        std::cout << "After signing: " << anyForm << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << '\n';
    }
    std::cout << "\n========== EDGE CASE: Grade 150 Bureaucrat ==========\n";
    try {
        Bureaucrat janitor(150, "Janitor");
        Form easyForm("Simple Request", 150, 150);
        std::cout << janitor << '\n';
        std::cout << easyForm << '\n';
        janitor.signForm(easyForm);
        std::cout << "After signing: " << easyForm << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << '\n';
    }
    std::cout << "\n========== MULTIPLE SIGNING ATTEMPTS ==========\n";
    try {
        Bureaucrat manager(30, "Manager");
        Form report("Monthly Report", 50, 40);
        std::cout << report << '\n';
        manager.signForm(report);
        std::cout << "First signing successful\n";
        manager.signForm(report);
        std::cout << "Second signing attempt (already signed)\n";
        std::cout << "Final state: " << report << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << '\n';
    }
    return 0;
}