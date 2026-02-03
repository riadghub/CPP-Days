/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 09:47:18 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/11/28 10:44:03 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

class Span
{
public:
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int n);
    void addRange(int* begin, int* end);

    int shortestSpan() const;
    int longestSpan() const;

private:
    unsigned int _maxSize;
    std::vector<int> _numbers;
};
