/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:22:13 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/10/14 12:25:25 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <stdint.h>
#include <iostream>
#include <limits>
#include <string>

class Base
{
	public:
		virtual ~Base();
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);