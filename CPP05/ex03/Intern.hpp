/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:09:37 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/10/09 09:48:20 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

class Intern
{
  private:
	AForm *createShrubberyForm(std::string const &target);
	AForm *createRobotomyForm(std::string const &target);
	AForm *createPresidentialForm(std::string const &target);

  public:
	Intern();
	Intern(Intern const &src);
	~Intern();

	Intern &operator=(Intern const &rhs);

	AForm *makeForm(std::string const &formName, std::string const &target);
};