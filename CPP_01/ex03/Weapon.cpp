/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:08:32 by acouture          #+#    #+#             */
/*   Updated: 2023/09/19 16:50:13 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string& Weapon::getType() {
    return (type);
};
        
void Weapon::setType(std::string newValue) {
    type = newValue;
};

Weapon::~Weapon() {}