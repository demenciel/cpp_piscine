/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:53:17 by acouture          #+#    #+#             */
/*   Updated: 2023/09/19 16:55:34 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::setWeapon(Weapon& weapon) {
    humanWeapon = &weapon;
}

void HumanB::attack() {
    std::cout << name << " attacks with their " << humanWeapon->getType() << std::endl;
}