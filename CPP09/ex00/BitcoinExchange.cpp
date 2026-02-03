/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:11:48 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/12/02 10:38:38 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _db(other._db) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _db = other._db;
    }
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    std::string line;

    if (!file.is_open())
        throw std::runtime_error("Error: could not open database file.");

    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, rateStr;

        std::getline(ss, date, ',');
        std::getline(ss, rateStr, ',');

        if (isValidDate(date)) {
            try {
                double rate = stringToDouble(rateStr);
                _db[date] = rate;
            } catch (...) {}
        }
    }
    file.close();
}

bool BitcoinExchange::isValidDate(const std::string& date) {
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;

    if (!isdigit(date[0]) || !isdigit(date[1]) || !isdigit(date[2]) || !isdigit(date[3])) return false;
    if (!isdigit(date[5]) || !isdigit(date[6])) return false;
    if (!isdigit(date[8]) || !isdigit(date[9])) return false;

    std::stringstream ss_year(date.substr(0,4));
    std::stringstream ss_month(date.substr(5,2));
    std::stringstream ss_day(date.substr(8,2));

    int year, month, day;
    ss_year >> year;
    ss_month >> month;
    ss_day >> day;

    if (year < 2009 || year > 2025) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
    
    return true;
}

double BitcoinExchange::stringToDouble(const std::string& str) {
    std::stringstream ss(str);
    double val;
    ss >> val;
    
    std::string rest;
    std::getline(ss, rest);
    if (!rest.empty() && rest.find_first_not_of(" \t") != std::string::npos) {
        throw std::runtime_error("Invalid value");
    }
    
    return val;
}


bool BitcoinExchange::isValidValue(double value) {
    return value >= 0 && value <= 1000;
}

double BitcoinExchange::getClosestRate(const std::string& date) {
    if (_db.empty())
        throw std::runtime_error("Database empty");

    std::map<std::string, double>::iterator it = _db.lower_bound(date);

    if (it != _db.end() && it->first == date)
        return it->second;

    if (it == _db.begin())
        return it->second;

    --it;
    return it->second;
}

std::string BitcoinExchange::trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t");
    if (start == std::string::npos) return "";
    size_t end = str.find_last_not_of(" \t");
    return str.substr(start, end - start + 1);
}

void BitcoinExchange::processInput(const std::string& filename) {
    std::ifstream file(filename.c_str());
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::getline(file, line);

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        size_t sepPos = line.find('|');
        if (sepPos == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = trim(line.substr(0, sepPos));
        std::string value_str = trim(line.substr(sepPos + 1));

        if (!isValidDate(date)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        double value;
        try {
            value = stringToDouble(value_str);
        } catch (...) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (!isValidValue(value)) {
            if (value < 0)
                std::cout << "Error: not a positive number." << std::endl;
            else
                std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        try {
            double rate = getClosestRate(date);
            double result = value * rate;
            std::cout << date << " => " << value << " = " << result << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    file.close();
}
