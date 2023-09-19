/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:08:50 by acouture          #+#    #+#             */
/*   Updated: 2023/09/19 16:48:56 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Maintenant, créez deux classes HumanA et HumanB. Toutes deux possèdent une
// Weapon et un name, ainsi qu’une fonction membre attack() affichant (sans les chevrons
// bien sûr) :
// <name> attacks with their <weapon type>
// HumanA et HumanB sont presque identiques, à l’exception de deux petits détails :
// • Alors que le constructeur de HumanA prend une Weapon comme paramètre, ce
// n’est pas le cas de celui de HumanB.
// HumanB n’aura pas toujours une Weapon, tandis que HumanA en aura forcément une

#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP
#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon &humanWeapon;
    public:
        HumanA(std::string name, Weapon& humanWeapon) : name(name), humanWeapon(humanWeapon) {};
        void    attack();
};



#endif