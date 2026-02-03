/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 10:20:53 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/10/07 10:32:48 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const Form &b) : name(b.name), isSigned(b.isSigned),
	s_grade(b.s_grade), x_grade(b.x_grade)
{
}

Form::Form(std::string name, unsigned int const s_grade,
	unsigned int const x_grade) : name(name), isSigned(false), s_grade(s_grade),
	x_grade(x_grade)
{
	if (s_grade < 1 || x_grade < 1)
		throw Form::GradeTooHighException();
	if (s_grade > 150 || x_grade > 150)
		throw Form::GradeTooLowException();
}

Form::~Form(void)
{
}

std::string Form::getName(void) const
{
	return (this->name);
}

bool Form::getIsSigned() const
{
	return (this->isSigned);
}
unsigned int Form::getSignGrade() const
{
	return (this->s_grade);
}
unsigned int Form::getExecuteGrade() const
{
	return (this->x_grade);
}

void Form::beSigned(Bureaucrat const &obj)
{
    if (obj.getGrade() > this->s_grade)
        throw Form::GradeTooLowException();
    this->isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const Form &obj)
{
    out << "Form " << obj.getName() << ", signed: " << (obj.getIsSigned() ? "yes" : "no")
        << ", sign grade: " << obj.getSignGrade() 
        << ", execute grade: " << obj.getExecuteGrade();
    return out;
}

Form const &Form::operator=(const Form &other)
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

Form::GradeTooLowException::GradeTooLowException(void) throw()
{
}

Form::GradeTooHighException::GradeTooHighException(void) throw()
{
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("GradeTooLowException: grade is too low.");
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("GradeTooHighException: grade is too high.");
}