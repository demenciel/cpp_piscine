/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:42:44 by acouture          #+#    #+#             */
/*   Updated: 2023/11/06 14:31:26 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

class Awesome
{
public:
    Awesome(void) : _n(42) { return; }
    int get(void) const { return this->_n; }

private:
    int _n;
};

void ft_print_class(Awesome const &x)
{
    std::cout << x.get() << std::endl;
}

void    convert_to_upper(std::string &str)
{
    for (unsigned long i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]);
        std::cout << str[i];
    }
    std::cout << std::endl;
}

int main()
{
    std::string tabString[] = {"Hello world !", "Hello world2 !", "Hello world3 !", "Hello world4 !", "Hello world5 !"};
    int tab[] = {0, 1, 2, 3, 4};
    Awesome tab2[1];

    std::cout << "int array:" << std::endl;
    iter(tab, 5, ft_print);

    std::cout << "class array:" << std::endl;
    iter(tab2, 1, ft_print_class);

    std::cout << "string array:" << std::endl;
    iter(tabString, 5, ft_print);
    std::cout << "string array to upper:" << std::endl;
    iter(tabString, 5, convert_to_upper);

    return 0;
}