/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedLike.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:18:01 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/08/11 14:18:22 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedLike.hpp"

SedLike::SedLike(const char* filename, std::string s1, std::string s2)
{
	this->filename = filename;
	this->s1 = s1;
	this->s2 = s2;
}

void SedLike::replaceLike(void)
{
    std::ifstream inputFile(filename);
    size_t pos = 0;
    std::string content;
    std::string line;

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open input file: " << filename << std::endl;
        return;
    }
    while (std::getline(inputFile, line)) {
        content += line + '\n';
    }
    inputFile.close();
    while ((pos = content.find(s1, pos)) != std::string::npos) {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }
    std::string outputFilename = std::string(filename) + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Failed to open output file: " << outputFilename << std::endl;
        return;
    }
    outputFile << content;
    outputFile.close();
    
    std::cout << "Done." << std::endl;
}