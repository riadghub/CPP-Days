/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:55:08 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/12/03 12:29:29 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char** argv) {
    parseArgs(argc, argv);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseArgs(int argc, char** argv) {
    for (int i = 1; i < argc; i++) {
        std::stringstream ss(argv[i]);
        int num;
        if (!(ss >> num) || !ss.eof())
            throw std::runtime_error("Error");
        if (num <= 0)
            throw std::runtime_error("Error");
        _vector.push_back(num);
        _deque.push_back(num);
    }
}

double PmergeMe::getTime() const {
    struct timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000000.0) + time.tv_usec;
}

void PmergeMe::fordJohnsonVector() {
    if (_vector.size() < 2)
        return;
    std::vector<int> mainChain;
    std::vector<int> pendings;
    for (size_t i = 0; i < _vector.size(); i += 2) {
        if (i + 1 < _vector.size()) {
            int a = _vector[i];
            int b = _vector[i + 1];
            if (a < b) std::swap(a, b);
            mainChain.push_back(a);
            pendings.push_back(b);
        } else {
            pendings.push_back(_vector[i]);
        }
    }
    std::sort(mainChain.begin(), mainChain.end());
    for (size_t i = 0; i < pendings.size(); i++) {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pendings[i]);
        mainChain.insert(pos, pendings[i]);
    }
    _vector = mainChain;
}

void PmergeMe::fordJohnsonDeque() {
    if (_deque.size() < 2)
        return;
    std::deque<int> mainChain;
    std::deque<int> pendings;
    for (size_t i = 0; i < _deque.size(); i += 2) {
        if (i + 1 < _deque.size()) {
            int a = _deque[i];
            int b = _deque[i + 1];
            if (a < b) std::swap(a, b);
            mainChain.push_back(a);
            pendings.push_back(b);
        } else {
            pendings.push_back(_deque[i]);
        }
    }
    std::sort(mainChain.begin(), mainChain.end());
    for (size_t i = 0; i < pendings.size(); i++) {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pendings[i]);
        mainChain.insert(pos, pendings[i]);
    }
    _deque = mainChain;
}

void PmergeMe::run() {
    std::cout << "Before: ";
    for (size_t i = 0; i < _vector.size(); ++i) {
        std::cout << _vector[i];
        if (i < _vector.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
    double timeVector = getTime();
    fordJohnsonVector();
    timeVector = getTime() - timeVector;
    double timeDeque = getTime();
    fordJohnsonDeque();
    timeDeque = getTime() - timeDeque;
    std::cout << "After:  ";
    for (size_t i = 0; i < _deque.size(); ++i) {
        std::cout << _deque[i];
        if (i < _deque.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _vector.size()
              << " elements with std::vector : " << timeVector << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size()
              << " elements with std::deque  : " << timeDeque << " us" << std::endl;
}
