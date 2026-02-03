/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:04:23 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/08/15 11:06:17 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		this->nbr = other.nbr;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	nbr = 0;
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called\n";
	*this = obj;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called\n";
	nbr = n << bits;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called\n";
	nbr = roundf(n * (1 << bits));
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return (this->nbr);
}

void Fixed::setRawBits(int const raw)
{
	this->nbr = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

float Fixed::toFloat() const
{
	return (float)nbr / (1 << bits);
}

int Fixed::toInt() const
{
	return (nbr >> bits);
}
