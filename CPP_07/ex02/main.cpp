/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:42:44 by acouture          #+#    #+#             */
/*   Updated: 2023/11/07 14:19:47 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    Array<int> b(10);
    for (unsigned int i = 0; i < b.size(); i++)
        b[i] = i;
    std::cout << "Array is size of: " << b.size() << std::endl;
    for (unsigned int i = 0; i < b.size(); i++)
        std::cout << b[i] << std::endl;

    std::cout << "copy constructor" << std::endl;
    Array<int> c(b);
    std::cout << "Index: " << c[5] << std::endl;
    std::cout << "Out of bounds" << std::endl;
    try
    {
        std::cout << c[11] << std::endl;
    }
    catch (std::exception)
    {
        std::cout << "exception" << std::endl;
    }

    return 0;
}