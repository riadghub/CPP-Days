/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:23:06 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/07/31 13:49:24 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <string>

void	megaphone(char *str)
{
	std::string res = str;
	for (size_t i = 0; i < res.length(); i++)
		res[i] = std::toupper(res[i]);
	std::cout << res;
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
		megaphone(argv[i]);
	std::cout << std::endl;
	return (0);
}