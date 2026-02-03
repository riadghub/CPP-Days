/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:23:41 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/11/14 11:17:32 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdlib>
#include <iostream>
#include <string>

template <typename T> class Array
{
  public:
	T *data;
	unsigned int _size;

	Array() : data(NULL), _size(0) {}
	Array(unsigned int n) : data(n ? new T[n]() : NULL), _size(n) {}
	Array(const Array &other) : data(NULL), _size(0)
	{
		if (other._size)
		{
			data = new T[other._size];
			for (unsigned int i = 0; i < other._size; ++i)
				data[i] = other.data[i];
		}
		_size = other._size;
	}
	~Array()
	{
		delete[] data;
	}
	Array &operator=(const Array &other)
	{
		if (this != &other)
		{
			delete[] data;
			data = NULL;
			_size = other._size;
			if (_size)
			{
				data = new T[_size];
				for (unsigned int i = 0; i < _size; ++i)
					data[i] = other.data[i];
			}
		}
		return (*this);
	}
	T &operator[](unsigned int idx)
	{
		if (idx >= _size)
			throw std::out_of_range("Array index out of bounds");
		return (data[idx]);
	}
	const T &operator[](unsigned int idx) const
	{
		if (idx >= _size)
			throw std::out_of_range("Array index out of bounds");
		return (data[idx]);
	}
	unsigned int size() const
	{
		return (_size);
	}
};