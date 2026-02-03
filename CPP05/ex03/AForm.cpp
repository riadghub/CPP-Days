/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 10:20:53 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/10/07 11:05:25 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const AForm &b) : name(b.name), isSigned(b.isSigned),
	s_grade(b.s_grade), x_grade(b.x_grade)
{
}

AForm::AForm(std::string name, unsigned int const s_grade,
	unsigned int const x_grade) : name(name), isSigned(false), s_grade(s_grade),
	x_grade(x_grade)
{
	if (s_grade < 1 || x_grade < 1)
		throw AForm::GradeTooHighException();
	if (s_grade > 150 || x_grade > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm(void)
{
}

std::string AForm::getName(void) const
{
	return (this->name);
}

bool AForm::getIsSigned() const
{
	return (this->isSigned);
}
unsigned int AForm::getSignGrade() const
{
	return (this->s_grade);
}
unsigned int AForm::getExecuteGrade() const
{
	return (this->x_grade);
}

void AForm::beSigned(Bureaucrat const &obj)
{
    if (obj.getGrade() > this->s_grade)
        throw AForm::GradeTooLowException();
    this->isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->x_grade)
		throw AForm::GradeTooLowException();
	this->executeAction();
}

std::ostream &operator<<(std::ostream &out, const AForm &b)
{
    out << "Form " << b.getName() << ", signed: " << (b.getIsSigned() ? "yes" : "no")
        << ", sign grade: " << b.getSignGrade() 
        << ", execute grade: " << b.getExecuteGrade();
    return out;
}

AForm const &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		*((unsigned char *)&this->s_grade) = other.s_grade;
		*((unsigned char *)&this->x_grade) = other.x_grade;
		*((std::string *)&this->name) = other.name;
		this->isSigned = other.isSigned;
	}
	return (*this);
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed!";
}

AForm::GradeTooLowException::GradeTooLowException(void) throw()
{
}

AForm::GradeTooHighException::GradeTooHighException(void) throw()
{
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("GradeTooLowException: grade is too low.");
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("GradeTooHighException: grade is too high.");
}