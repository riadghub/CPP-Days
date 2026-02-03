/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:05:26 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/08/11 13:25:43 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

extern Zombie	*zombieHorde(int N, std::string name);

int	main(void)
{
	long N = -1;
	std::string name = "Riad";
	Zombie* horde = zombieHorde(N, name);
	if (horde)
		delete[] horde;
	return (0);
}