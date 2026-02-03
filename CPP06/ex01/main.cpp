/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:35:30 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/10/10 12:48:17 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data		data;
	uintptr_t	raw;
	Data		*restored;

	data.name = "Riad";
	data.value = 42;
	std::cout << "Original Data:\n";
	std::cout << "  name: " << data.name << "\n";
	std::cout << "  value: " << data.value << "\n";
	std::cout << "  address: " << &data << "\n\n";
	raw = Serializer::serialize(&data);
	std::cout << "Serialized value (uintptr_t): " << raw << "\n\n";
	restored = Serializer::deserialize(raw);
	std::cout << "Deserialized Data:\n";
	std::cout << "  name: " << restored->name << "\n";
	std::cout << "  value: " << restored->value << "\n";
	std::cout << "  address: " << restored << "\n";
	if (restored == &data)
		std::cout << "\nSame address restored — success!\n";
	else
		std::cout << "\nAddresses differ — error!\n";
	return (0);
}
