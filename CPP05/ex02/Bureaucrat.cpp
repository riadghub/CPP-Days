/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:21:46 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/10/07 12:09:17 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(unsigned int grade, std::string const& name) : name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b)
{
	*this = b;
}

Bureaucrat::~Bureaucrat(void)
{
}

std::string Bureaucrat::getName(void) const
{
	return (this->name);
}

unsigned int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade(void)
{
	if (this->grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (this->grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

void Bureaucrat::signForm(AForm &form)
{
    try {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << this->name << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form)
{
    try {
        form.execute(*this);
        std::cout << this->name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception const &e) {
        std::cout << this->name << " couldn't execute " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << '.';
    return out;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		*((std::string *)&this->name) = other.name;
		this->grade = other.grade;
	}
	return (*this);
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void) throw(){}

Bureaucrat::GradeTooHighException::GradeTooHighException(void) throw(){}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("GradeTooLowException: Bureaucrat grade is too low. Grade must be between 1 and 150.");
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("GradeTooHighException: Bureaucrat grade is too high. Grade must be between 1 and 150.");
}
