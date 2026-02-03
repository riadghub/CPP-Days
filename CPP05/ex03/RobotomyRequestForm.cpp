/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:07:18 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/10/07 12:19:09 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
	: AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src)
	: AForm(src), target(src.target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->target = rhs.target;
	}
	return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
	return this->target;
}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "* BZZZZZZZZZ * DRILLING NOISES * BZZZZZZZZZ *" << std::endl;
	std::srand(std::time(NULL));
	if (std::rand() % 2 == 0)
		std::cout << this->target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed on " << this->target << "!" << std::endl;
}