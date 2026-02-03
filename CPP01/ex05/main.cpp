/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 12:09:10 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/08/11 13:36:53 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
    Harl a;
	a.complain("hey");
    a.complain("WARNING");
    a.complain("INFO");
    a.complain("DEBUG");
    a.complain("ERROR");
	return (0);
}