/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:22:50 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/12/02 12:48:43 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iomanip>

class BitcoinExchange {
private:
    std::map<std::string, double> _db;
    bool isValidDate(const std::string& date);
    bool isValidValue(double value);
    double stringToDouble(const std::string& str);
    std::string trim(const std::string& str);

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);

    void loadDatabase(const std::string& filename);
    void processInput(const std::string& filename);
    double getClosestRate(const std::string& date);
};
