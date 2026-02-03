/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:13:40 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/08/11 13:24:25 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	long n = (long)N;
	if (n <= 0 || n >= 2147483647)
		return (NULL);
	Zombie *horde = new Zombie[n];
	for (long i = 0; i < n; i++)
	{
		horde[i].setName(name);
		horde[i].announce();
	}
	return (horde);
}