/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:17:16 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/08/11 14:18:37 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedLike.hpp"

int main(int argc, char *argv[])
{
    if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
    SedLike a = SedLike(argv[1], argv[2], argv[3]);
    a.replaceLike();
    return (0);
}