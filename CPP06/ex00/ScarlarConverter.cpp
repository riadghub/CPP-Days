/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScarlarConverter.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:38:31 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/10/10 09:39:35 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScarlarConverter.hpp"

static bool isCharLiteral(const std::string &s) {
    return (s.length() == 1 && !std::isdigit(s[0]));
}

static bool isPseudoLiteral(const std::string &s) {
    return (s == "nan" || s == "nanf" || s == "+inf" || s == "-inf" || s == "+inff" || s == "-inff");
}

void ScarlarConverter::convert(std::string const &literal) {
    std::cout << std::fixed << std::setprecision(1);
    if (isCharLiteral(literal)) {
        char c = literal[0];
        std::cout << "char: '" << c << "'\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";
        std::cout << "float: " << static_cast<float>(c) << "f\n";
        std::cout << "double: " << static_cast<double>(c) << "\n";
        return;
    }
    if (isPseudoLiteral(literal)) {
        bool f = literal.find('f') != std::string::npos;
        std::string base = literal.substr(0, literal.size() - (f ? 1 : 0));
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << base << "f\n";
        std::cout << "double: " << base << "\n";
        return;
    }
    char *endptr = NULL;
    double value = std::strtod(literal.c_str(), &endptr);
    if (*endptr != '\0' && *endptr != 'f') {
        std::cout << "Invalid literal\n";
        return;
    }
    if (value >= 32 && value <= 126)
        std::cout << "char: '" << static_cast<char>(value) << "'\n";
    else if (value < 0 || value > 127)
        std::cout << "char: impossible\n";
    else
        std::cout << "char: Non displayable\n";
    if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(value) << "\n";
    std::cout << "float: " << static_cast<float>(value) << "f\n";
    std::cout << "double: " << static_cast<double>(value) << "\n";
}
