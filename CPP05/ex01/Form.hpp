/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:07:00 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/10/07 10:16:25 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cmath>
#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
  private:
	std::string const name;
	bool isSigned;
	unsigned int const s_grade;
	unsigned int const x_grade;

  public:
	Form(const Form &b);
	Form(std::string name, unsigned int const s_grade,
		unsigned int const x_grade);
	~Form();
	
	bool getIsSigned() const;
	unsigned int getSignGrade() const;
	unsigned int getExecuteGrade() const;
	std::string getName() const;
	void beSigned(Bureaucrat const &b);
	const Form &operator=(const Form &b);
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

std::ostream &operator<<(std::ostream &out, const Form &b);