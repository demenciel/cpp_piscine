/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:05:49 by acouture          #+#    #+#             */
/*   Updated: 2023/09/21 18:11:49 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl harl;
    
    harl.complain("DEBUG");
    harl.complain("DEBUG");
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("INFO");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("WARNING");
    harl.complain("WARNING");
    harl.complain("ERROR");
    harl.complain("ERROR");
    harl.complain("ERROR");
    return (0);
}