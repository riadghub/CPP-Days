/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:25:05 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/08/18 10:08:15 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : nbr(0)
{

}

Fixed::Fixed(const int n)
{
	nbr = n << bits;
}

Fixed::Fixed(const float f)
{
	nbr = roundf(f * (1 << bits));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed::~Fixed()
{

}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		nbr = other.nbr;
	return (*this);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (nbr > other.nbr);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (nbr < other.nbr);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (nbr >= other.nbr);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (nbr <= other.nbr);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (nbr == other.nbr);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (nbr != other.nbr);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	if (other.nbr == 0)
	{
		std::cout << "Division par 0.\n";
		return (0);
	}
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed &Fixed::operator++()
{
	nbr++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	nbr++;
	return (temp);
}

Fixed &Fixed::operator--()
{
	nbr--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	nbr--;
	return (temp);
}

int Fixed::getRawBits() const
{
	return (nbr);
}

void Fixed::setRawBits(int const raw)
{
	nbr = raw;
}

float Fixed::toFloat() const
{
	return (float)nbr / (1 << bits);
}

int Fixed::toInt() const
{
	return (nbr >> bits);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return ((a < b) ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return ((a < b) ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return ((a > b) ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return ((a > b) ? a : b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
