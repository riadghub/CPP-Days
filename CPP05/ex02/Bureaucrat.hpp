/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:35:49 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/10/07 12:09:32 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cmath>
#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
  private:
	std::string const name;
	unsigned int grade;
	
  public:
	Bureaucrat(unsigned int grade, std::string const &name);
	Bureaucrat(const Bureaucrat &obj);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &other);

	std::string getName() const;
	unsigned int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	void executeForm(AForm const &form);
	void signForm(AForm &form);

	class GradeTooHighException : public std::exception
	{
		public:
			GradeTooHighException(void) throw();
			const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			GradeTooLowException(void) throw();
			const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);