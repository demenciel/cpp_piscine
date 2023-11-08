/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:42:44 by acouture          #+#    #+#             */
/*   Updated: 2023/11/07 16:12:56 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

class Generator {
    private:
        int n;
    public:
        Generator() : n(0) { }
        int operator()() { return n++; }
};

int main()
{
    std::cout << "------------- VECTOR ----------------" << std::endl;
    std::vector<int> vector1 (20);
    std::generate(vector1.begin(), vector1.end(), Generator());
    
    std::vector<int>::const_iterator it, end = vector1.end();
    for ( it = vector1.begin(); it != end; ++it ) {
        (it != end - 1) ? std::cout << *it << ", " : std::cout << *it << std::endl;
    }
    std::cout << std::endl;
    
    easyfind(vector1, 12);
    easyfind(vector1, 21);
    
    return 0;
}