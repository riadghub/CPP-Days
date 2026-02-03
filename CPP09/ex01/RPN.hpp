/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:31:22 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/12/02 11:41:12 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>

class RPN {
private:
    std::stack<double> _stack;

    bool isOperator(char c) const;
    double applyOperator(double a, double b, char op);
	bool isValidNumber(const std::string& token) const;

public:
    RPN(const std::string& expression);
    ~RPN();
    double calculate();
};