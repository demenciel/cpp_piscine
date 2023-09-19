/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:59:19 by acouture          #+#    #+#             */
/*   Updated: 2023/09/18 16:43:44 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name("Unnamed") {}

Zombie::Zombie(std::string n) : name(n) {} 

void Zombie::announce (void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}