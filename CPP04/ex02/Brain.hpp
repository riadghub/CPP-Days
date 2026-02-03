/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 11:38:54 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/08/26 10:17:58 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cmath>
#include <iostream>
#include <string>

class Brain
{
  public:
	std::string ideas[100];
	
	Brain();
	Brain(const Brain &other);
	~Brain();
	Brain &operator=(const Brain &other);
};