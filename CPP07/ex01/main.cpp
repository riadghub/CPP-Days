/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:00:41 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/11/18 09:38:58 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	processString(std::string &s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		s[i] = toascii(s[i]);
		std::cout << static_cast<int>(s[i]) << " ";
	}
	std::cout << "\n";
}

int	main(void)
{
	std::string strArray[] = {"hello", "world"};
	iter(strArray, sizeof(strArray) / sizeof(*strArray), processString);

	return (0);
}

// class Awesome
// {
// 	public:
// 		Awesome(void): _n(42) {return;}
// 		int get(void) const {return this->_n;}
// 	private:
// 		int _n;
// };

// std::ostream & operator<<(std::ostream & o, Awesome const & rhs) 
// { 
// 	o << rhs.get(); 
// 	return o; 
// }

// template<typename T>
// void print(T const & x) 
// {
// 	std::cout << x << std::endl; 
// 	return;
// }

// int main()
// {
// 	int tab[] = {0, 1, 2, 3, 4};
// 	Awesome tab2[5];
	
// 	iter(tab, 5, print<int>);
// 	iter(tab2, 5, print<Awesome>);
	
// 	return 0;
// }