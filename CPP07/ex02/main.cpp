/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:23:20 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/11/14 11:20:17 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
void printArray(const Array<T>& arr) {
    for (unsigned int i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    std::cout << "-- Test 1: Empty Array --" << std::endl;
    Array<int> a;
    std::cout << "a.size(): " << a.size() << std::endl;

    std::cout << "\n-- Test 2: Sized Array --" << std::endl;
    Array<int> b(5);
    std::cout << "b.size(): " << b.size() << std::endl;
    printArray(b);

    std::cout << "\n-- Test 3: Write/Read --" << std::endl;
    for (unsigned int i = 0; i < b.size(); ++i)
        b[i] = 42 + i;
    printArray(b);

    std::cout << "\n-- Test 4: Copy Constructor --" << std::endl;
    Array<int> c(b);
    printArray(c);
    c[0] = -1;
    std::cout << "Original after modifying copy: "; printArray(b);
    std::cout << "Copy after modification: "; printArray(c);

    std::cout << "\n-- Test 5: Assignment Operator --" << std::endl;
    Array<int> d;
    d = b;
    printArray(d);
    d[1] = -99;
    std::cout << "Original after modifying assigned: "; printArray(b);
    std::cout << "Assigned after modification: "; printArray(d);

    std::cout << "\n-- Test 6: Const Array and Bounds Check --" << std::endl;
    const Array<std::string> e(2);
    try {
        std::cout << e[0] << std::endl;
        std::cout << e[2] << std::endl; // out of bounds
    } catch (std::exception& ex) {
        std::cout << "Exception: " << ex.what() << std::endl;
    }

    std::cout << "\n-- Test 7: Int Default Value --" << std::endl;
    int* ptr = new int();
    std::cout << "*new int(): " << *ptr << std::endl;
    delete ptr;
    
    return 0;
}