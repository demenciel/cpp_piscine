/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:11:04 by acouture          #+#    #+#             */
/*   Updated: 2023/11/07 16:13:34 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void easyfind(std::vector<T> vector, int n)
{
    typename std::vector<T>::iterator it;

    it = std::find(vector.begin(), vector.end(), n);
    if (it != vector.end())
        std::cout << "Found occurence: " << *it << std::endl;
    else {
        std::cout << "Could not find n in vector" << std::endl;
    }
}