/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:31:20 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/12/02 13:01:30 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(const std::string& expression) {
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (token.length() == 1 && isOperator(token[0])) {
            if (_stack.size() < 2)
                throw std::runtime_error("Error: not enough operands");
            double b = _stack.top(); _stack.pop();
            double a = _stack.top(); _stack.pop();
            _stack.push(applyOperator(a, b, token[0]));
        } else {
            std::stringstream num_ss(token);
            double num;
            if (!(num_ss >> num) || !isValidNumber(token))
                throw std::runtime_error("Error: invalid token");
            _stack.push(num);
        }
    }
}

RPN::~RPN() {}

bool RPN::isOperator(char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool RPN::isValidNumber(const std::string& token) const {
    if (token.empty())
		return false;
    bool hasDot = false;
    bool hasDigit = false;
    for (size_t i = 0; i < token.length(); ++i) {
        char c = token[i];
        if (c >= '0' && c <= '9') {
            hasDigit = true;
        } else if (c == '.' && !hasDot) {
            hasDot = true;
        } else if (c == '-' && i == 0) {
        } else {
            return false;
        }
    }
    if (!hasDigit)
		return false;
    std::stringstream ss(token);
    double val;
    ss >> val;
    return val >= 0 && val < 10;
}

double RPN::applyOperator(double a, double b, char op) {
    switch (op) {
        case '+':
			return a + b;
        case '-':
			return a - b;
        case '*':
			return a * b;
        case '/': 
            if (b == 0.0)
                throw std::runtime_error("Error: division by zero");
            return a / b;
        default:
            throw std::runtime_error("Error: unknown operator");
    }
}

double RPN::calculate() {
    if (_stack.size() != 1)
        throw std::runtime_error("Error: invalid expression");
    return _stack.top();
}
