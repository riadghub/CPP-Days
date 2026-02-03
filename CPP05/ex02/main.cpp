/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:21:47 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/10/09 10:53:41 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "\n========== TEST 1: SHRUBBERY CREATION FORM ==========\n";
	try
	{
		Bureaucrat bob(140, "Bob");
		ShrubberyCreationForm shrub("home");
		std::cout << bob << std::endl;
		std::cout << shrub << std::endl;
		bob.signForm(shrub);
		bob.executeForm(shrub);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n========== TEST 2: SHRUBBERY - GRADE TOO LOW TO EXECUTE ==========\n";
	try
	{
		Bureaucrat intern(145, "Intern");
		ShrubberyCreationForm shrub("garden");
		std::cout << intern << std::endl;
		std::cout << shrub << std::endl;
		intern.signForm(shrub);
		std::cout << "Trying to execute with grade 145 (need 137)..." << std::endl;
		intern.executeForm(shrub);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n========== TEST 3: ROBOTOMY REQUEST FORM ==========\n";
	try
	{
		Bureaucrat alice(40, "Alice");
		RobotomyRequestForm robot("Bender");
		std::cout << alice << std::endl;
		std::cout << robot << std::endl;
		alice.signForm(robot);
		alice.executeForm(robot);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n========== TEST 4: ROBOTOMY - GRADE TOO LOW TO SIGN ==========\n";
	try
	{
		Bureaucrat lowGrade(100, "LowGrade");
		RobotomyRequestForm robot("Target");
		std::cout << lowGrade << std::endl;
		std::cout << robot << std::endl;
		std::cout << "Trying to sign with grade 100 (need 72)..." << std::endl;
		lowGrade.signForm(robot);
		lowGrade.executeForm(robot);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n========== TEST 5: PRESIDENTIAL PARDON FORM ==========\n";
	try
	{
		Bureaucrat president(1, "President");
		PresidentialPardonForm pardon("Arthur Dent");
		std::cout << president << std::endl;
		std::cout << pardon << std::endl;
		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n========== TEST 6: PRESIDENTIAL PARDON - GRADE TOO LOW ==========\n";
	try
	{
		Bureaucrat manager(30, "Manager");
		PresidentialPardonForm pardon("Ford Prefect");
		std::cout << manager << std::endl;
		std::cout << pardon << std::endl;
		std::cout << "Trying to sign with grade 30 (need 25)..." << std::endl;
		manager.signForm(pardon);
		manager.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n========== TEST 7: EXECUTE UNSIGNED FORM ==========\n";
	try
	{
		Bureaucrat boss(1, "Boss");
		ShrubberyCreationForm unsignedForm("unsigned");
		std::cout << boss << std::endl;
		std::cout << unsignedForm << std::endl;
		std::cout << "Trying to execute unsigned form..." << std::endl;
		boss.executeForm(unsignedForm);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n========== TEST 8: ALL THREE FORMS WITH CEO ==========\n";
	try
	{
		Bureaucrat ceo(1, "CEO");
		std::cout << ceo << std::endl << std::endl;
		ShrubberyCreationForm shrub("office");
		std::cout << shrub << std::endl;
		ceo.signForm(shrub);
		ceo.executeForm(shrub);
		std::cout << std::endl;
		RobotomyRequestForm robot("Employee");
		std::cout << robot << std::endl;
		ceo.signForm(robot);
		ceo.executeForm(robot);
		std::cout << std::endl;
		PresidentialPardonForm pardon("Criminal");
		std::cout << pardon << std::endl;
		ceo.signForm(pardon);
		ceo.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n========== TEST 9: EDGE CASE - EXACT REQUIRED GRADES ==========\n";
	try
	{
		Bureaucrat exactGrade(5, "ExactGrade");
		PresidentialPardonForm pardon("Lucky Person");
		std::cout << exactGrade << std::endl;
		std::cout << pardon << std::endl;
		std::cout << "Trying to sign with grade 5 (need 25)..." << std::endl;
		exactGrade.signForm(pardon);
		exactGrade.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}