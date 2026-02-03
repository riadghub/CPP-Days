/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:07:00 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/10/07 12:08:20 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
#include <cmath>
#include <exception>
#include <iostream>
#include <string>

class	Bureaucrat;

class AForm
{
  private:
	std::string const name;
	bool isSigned;
	unsigned int const s_grade;
	unsigned int const x_grade;

  protected:
	virtual void executeAction() const = 0;

  public:
	AForm(const AForm &b);
	AForm(std::string name, unsigned int const s_grade,
		unsigned int const x_grade);
	~AForm();

	void execute(Bureaucrat const &executor) const;
	bool getIsSigned() const;
	unsigned int getSignGrade() const;
	unsigned int getExecuteGrade() const;
	std::string getName() const;
	void beSigned(Bureaucrat const &b);
	const AForm &operator=(const AForm &b);
	
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
	
	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &b);