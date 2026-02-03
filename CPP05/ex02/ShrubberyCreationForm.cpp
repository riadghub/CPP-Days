/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:07:21 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/10/07 13:49:02 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
	: AForm(src), target(src.target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->target = rhs.target;
	}
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return this->target;
}

void ShrubberyCreationForm::executeAction() const
{
	std::string filename = this->target + "_shrubbery";
	std::ofstream file(filename.c_str());

	if (!file.is_open())
	{
		std::cerr << "Error: Could not create file " << filename << std::endl;
		return;
	}

	file << "       _-_" << std::endl;
	file << "    /~~   ~~\\" << std::endl;
	file << " /~~         ~~\\" << std::endl;
	file << "{               }" << std::endl;
	file << " \\  _-     -_  /" << std::endl;
	file << "   ~  \\\\ //  ~" << std::endl;
	file << "_- -   | | _- _" << std::endl;
	file << "  _ -  | |   -_" << std::endl;
	file << "      // \\\\" << std::endl;
	file << std::endl;

	file.close();
	std::cout << "Shrubbery has been created at " << filename << std::endl;
}