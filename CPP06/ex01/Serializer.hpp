/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 10:36:18 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/10/10 11:41:45 by reeer-aa         ###   ########.fr       */
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
#include "Data.hpp"

class Serializer
{
  private:
	Serializer();
	~Serializer();
	Serializer(const Serializer &);
	Serializer &operator=(const Serializer &);

  public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};