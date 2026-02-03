/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 09:47:26 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/11/28 10:43:44 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span &other)
{
    *this = other;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
    if (_numbers.size() >= _maxSize)
        throw std::runtime_error("Span is full");

    _numbers.push_back(n);
}

void Span::addRange(int* begin, int* end)
{
    size_t rangeSize = end - begin;
    if (_numbers.size() + rangeSize > _maxSize)
        throw std::runtime_error("Span is full");
    
    _numbers.insert(_numbers.end(), begin, end);
}

int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers");

    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());

    int minSpan = tmp[1] - tmp[0];
    for (size_t i = 1; i < tmp.size() - 1; i++)
    {
        int span = tmp[i + 1] - tmp[i];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers");

    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

    return maxVal - minVal;
}
