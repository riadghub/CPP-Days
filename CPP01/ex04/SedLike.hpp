/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedLike.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:18:07 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/08/11 14:18:04 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <fstream>

class SedLike
{
    private:
        const char * filename;
        std::string s1;
        std::string s2;
    public:
        SedLike(const char * filename, std::string s1, std::string s2);
        void replaceLike(void);
};