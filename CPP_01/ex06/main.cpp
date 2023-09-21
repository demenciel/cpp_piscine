/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:05:49 by acouture          #+#    #+#             */
/*   Updated: 2023/09/21 18:40:23 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;
    if (ac != 2)
        return (1);
    std::string level = av[1];

    int severity = harl.severityMap[level];
    switch (severity) {
        case (4):
            harl.complain("ERROR");
        case (3):
            harl.complain("WARNING");
        case (2):
            harl.complain("INFO");
        case (1):
            harl.complain("DEBUG");
            break ;
        default:
            std::cout << "Invalid level" << std::endl;
            break ;
    }
    
    
    
    return (0);
}