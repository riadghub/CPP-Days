/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:41:37 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/09/02 10:27:24 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	std::cout << "\n=== Constructeurs ===" << std::endl;
	Fixed a;                  // Default
	Fixed const b(10);        // Int constructor
	Fixed const c(42.42f);    // Float constructor
	Fixed const d(b);         // Copy constructor

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;

	std::cout << "\n=== Assignation ===" << std::endl;
	a = Fixed(1234.4321f);
	std::cout << "a = " << a << std::endl;

	std::cout << "\n=== Comparaisons ===" << std::endl;
	std::cout << "a > b ? " << (a > b) << std::endl;
	std::cout << "a < b ? " << (a < b) << std::endl;
	std::cout << "b >= d ? " << (b >= d) << std::endl;
	std::cout << "b <= c ? " << (b <= c) << std::endl;
	std::cout << "b == d ? " << (b == d) << std::endl;
	std::cout << "b != c ? " << (b != c) << std::endl;

	std::cout << "\n=== Opérations arithmétiques ===" << std::endl;
	Fixed x(5.5f);
	Fixed y(2);

	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "x + y = " << (x + y) << std::endl;
	std::cout << "x - y = " << (x - y) << std::endl;
	std::cout << "x * y = " << (x * y) << std::endl;
	std::cout << "x / y = " << (x / y) << std::endl;

	std::cout << "\n=== Incrémentations / Décrémentations ===" << std::endl;
	Fixed z;

	std::cout << "z = " << z << std::endl;
	std::cout << "++z = " << ++z << std::endl; // pré-incrémentation
	std::cout << "z = " << z << std::endl;
	std::cout << "z++ = " << z++ << std::endl; // post-incrémentation
	std::cout << "z = " << z << std::endl;
	std::cout << "--z = " << --z << std::endl; // pré-décrémentation
	std::cout << "z = " << z << std::endl;
	std::cout << "z-- = " << z-- << std::endl; // post-décrémentation
	std::cout << "z = " << z << std::endl;

	std::cout << "\n=== Min / Max ===" << std::endl;
	Fixed e(3.3f);
	Fixed f(7.7f);

	std::cout << "min(e, f) = " << Fixed::min(e, f) << std::endl;
	std::cout << "max(e, f) = " << Fixed::max(e, f) << std::endl;
	std::cout << "min(const, const) = " << Fixed::min(b, c) << std::endl;
	std::cout << "max(const, const) = " << Fixed::max(b, c) << std::endl;

	std::cout << "\n=== Conversion ===" << std::endl;
	Fixed g(42.42f);
	std::cout << "g = " << g << std::endl;
	std::cout << "g.toInt() = " << g.toInt() << std::endl;
	std::cout << "g.toFloat() = " << g.toFloat() << std::endl;

	return 0;
}
