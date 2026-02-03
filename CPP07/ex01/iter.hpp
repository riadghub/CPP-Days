/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:00:44 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/11/17 12:28:06 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdlib>
#include <iostream>
#include <string>

template<typename T, typename F>
void iter(T *a, const size_t length, F func)
{
    for (size_t i = 0; i < length; i++)
    {
        func(a[i]);
    }
}