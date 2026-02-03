/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:07:15 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/10/07 12:20:15 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm",
	25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src),
	target(src.target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->target = rhs.target;
	}
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->target);
}

void PresidentialPardonForm::executeAction() const
{
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}