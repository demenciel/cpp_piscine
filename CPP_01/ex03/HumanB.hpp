/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:09:02 by acouture          #+#    #+#             */
/*   Updated: 2023/09/19 16:56:04 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Maintenant, créez deux classes HumanA et HumanB. Toutes deux possèdent une
// Weapon et un name, ainsi qu’une fonction membre attack() affichant (sans les chevrons
// bien sûr) :
// <name> attacks with their <weapon type>
// HumanA umanB sont presque identiques, à let H’exception de deux petits détails :
// • Alors que le constructeur de HumanA prend une Weapon comme paramètre, ce
// n’est pas le cas de celui de HumanB.
// HumanB n’aura pas toujours une Weapon, tandis que HumanA en aura forcément une


#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP
#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon* humanWeapon;
    public:
        HumanB(std::string name) : name(name) {};
        void setWeapon(Weapon& weapon);
        void attack();
};


#endif