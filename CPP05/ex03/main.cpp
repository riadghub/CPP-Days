/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:21:47 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/10/09 10:16:18 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        std::cout << "=== Intern creates forms ===" << std::endl;
        Intern someRandomIntern;
        AForm *shrub = someRandomIntern.makeForm("shrubbery creation", "Home");
        AForm *robot = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm *pardon = someRandomIntern.makeForm("presidential pardon", "Marvin");
        AForm *unknown = someRandomIntern.makeForm("unknown form", "Nobody");
        (void)unknown;

        std::cout << "\n=== Bureaucrats sign and execute ===" << std::endl;
        Bureaucrat riad(1, "Riad");
        Bureaucrat sarah(50, "Sarah");
        Bureaucrat romain(140, "Romain");
        std::cout << *shrub << std::endl;
        std::cout << *robot << std::endl;
        std::cout << *pardon << std::endl;
        std::cout << "\n--- romain tries to sign Shrubbery ---" << std::endl;
        romain.signForm(*shrub);
        std::cout << "\n--- sarah tries to execute Shrubbery ---" << std::endl;
        sarah.executeForm(*shrub);
        std::cout << "\n--- riad signs everything ---" << std::endl;
        riad.signForm(*robot);
        riad.signForm(*pardon);
        std::cout << "\n--- riad executes all forms ---" << std::endl;
        riad.executeForm(*robot);
        riad.executeForm(*pardon);
        std::cout << "\n=== Cleaning up ===" << std::endl;
        delete shrub;
        delete robot;
        delete pardon;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
