/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:07:33 by acouture          #+#    #+#             */
/*   Updated: 2023/08/24 15:05:07 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else {
        for (int i = 1; av[i]; i++) {
            for (int j = 0; av[i][j]; j++) {
                std::cout << (char )toupper(av[i][j]);
            }
        }
        std::cout << std::endl;
    }
    return (0);
}