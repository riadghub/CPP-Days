/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:33:48 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/11/24 09:45:26 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <list>

template <typename T>
typename T::const_iterator easyfind(const T &container, int value)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);

    if (it == container.end())
        throw std::runtime_error("Value not found");

    return it;
}
