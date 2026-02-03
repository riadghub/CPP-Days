/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScarlarConverter.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:39:16 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/10/10 09:39:50 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <limits>
#include <cmath>

class ScarlarConverter {
private:
    ScarlarConverter();
    ~ScarlarConverter();
    ScarlarConverter(const ScarlarConverter &);
    ScarlarConverter &operator=(const ScarlarConverter &);

public:
    static void convert(std::string const &literal);
};
