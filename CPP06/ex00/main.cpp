/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:39:30 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/10/10 09:40:00 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScarlarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./convert <literal>\n";
		return (1);
	}
	ScarlarConverter::convert(av[1]);
	return (0);
}