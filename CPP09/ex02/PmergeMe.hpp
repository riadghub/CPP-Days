/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:55:16 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/12/03 10:43:44 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <sys/time.h>
#include <exception>
#include <algorithm>

class PmergeMe {
private:
    std::vector<int> _vector;
    std::deque<int> _deque;

    void parseArgs(int argc, char** argv);
    void fordJohnsonVector();
    void fordJohnsonDeque();
    double getTime() const;

public:
    PmergeMe(int argc, char** argv);
    ~PmergeMe();

    void run();
};