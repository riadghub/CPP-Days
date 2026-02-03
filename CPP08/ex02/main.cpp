/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 09:55:13 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/12/01 10:04:02 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    std::cout << "=== TEST MUTANTSTACK ===" << std::endl << std::endl;
    std::cout << "--- Test 1: Constructeur vide + push/pop ---" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top(): " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "top() après pop: " << mstack.top() << std::endl;
    std::cout << "size(): " << mstack.size() << std::endl;
    std::cout << std::endl;

    std::cout << "--- Test 2: Itérateurs normaux ---" << std::endl;
    std::cout << "Avec for classique: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " \n";
    std::cout << std::endl;

    std::cout << "--- Test 3: Remplissage complet ---" << std::endl;
    MutantStack<int> mstack2;
    mstack2.push(42);
    mstack2.push(21);
    mstack2.push(84);
    mstack2.push(7);
    mstack2.push(14);

    std::cout << "Stack complet (top=14): ";
    for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "top(): " << mstack2.top() << std::endl;
    std::cout << std::endl;

    std::cout << "--- Test 4: Itérateurs inversés ---" << std::endl;
    std::cout << "Ordre inverse: ";
    for (MutantStack<int>::reverse_iterator rit = mstack2.rbegin(); rit != mstack2.rend(); ++rit)
        std::cout << *rit << " ";
    std::cout << std::endl << std::endl;

    std::cout << "--- Test 5: Copie et assignment ---" << std::endl;
    MutantStack<int> copy = mstack2;
    std::cout << "Copie - top(): " << copy.top() << std::endl;

    MutantStack<int> assign;
    assign = mstack2;
    std::cout << "Assign - top(): " << assign.top() << std::endl;

    mstack2.pop();
    std::cout << "Original après pop: " << mstack2.top() << std::endl;
    std::cout << "Copie inchangée: " << copy.top() << std::endl;
    std::cout << std::endl;

    std::cout << "--- Test 6: vs std::stack normale ---" << std::endl;
    std::stack<int> normal;
    normal.push(42);
    normal.push(21);
    std::cout << "std::stack top(): " << normal.top() << std::endl;
    std::cout << "std::stack n'a PAS d'itérateurs !" << std::endl;
    std::cout << std::endl;

    std::cout << "--- Test 7: Const MutantStack ---" << std::endl;
    const MutantStack<int> constStack = mstack2;
    std::cout << "Const stack - top(): " << constStack.top() << std::endl;
    for (MutantStack<int>::const_iterator cit = constStack.begin(); cit != constStack.end(); ++cit)
        std::cout << *cit << " "; 
    std::cout << std::endl;

    std::cout << "\n=== TOUS LES TESTS PASSÉS ! ===" << std::endl;
    return 0;
}
