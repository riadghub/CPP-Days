/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:09:43 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/10/09 09:32:07 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern is hired" << std::endl;
}

Intern::Intern(Intern const &src)
{
	*this = src;
	std::cout << "Intern copy is created" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern is fired" << std::endl;
}

Intern &Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return *this;
}

AForm *Intern::createShrubberyForm(std::string const &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyForm(std::string const &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialForm(std::string const &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm *(Intern::*formCreators[3])(std::string const &) = {
		&Intern::createShrubberyForm,
		&Intern::createRobotomyForm,
		&Intern::createPresidentialForm
	};
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*formCreators[i])(target);
		}
	}
	std::cerr << "Error: Form name \"" << formName << "\" does not exist!" << std::endl;
	std::cerr << "Available forms are: shrubbery creation, robotomy request, presidential pardon" << std::endl;
	return NULL;
}